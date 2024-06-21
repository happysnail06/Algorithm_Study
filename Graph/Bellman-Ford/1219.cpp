#include <iostream>
#include <tuple>
#include <vector>
#include <climits>

// 벨멘포드 변형, 추가적인 루프를 도는 이유를 알아야 된다.
// 기본 벨멘포드에서는 한 번의 루프를 더 돌아서 음수 싸이클이 있는지 판단한다.
// 이 문제에서는 추가적인 루프를 도는 중 노드가 업뎃 됐을 시 해당 노드는 양수싸이클에 포함된다는 걸 파악한다.
using namespace std;

typedef tuple<int, int, int> edge;
vector<edge> edges;
int n, m, start_city, end_city;
vector<long> income;
int start_, end_, weight;
vector<long> profit;
bool has_cycle = false;

void bellman_ford(int node);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> start_city >> end_city >> m;
    income = vector<long>(n);
    profit = vector<long>(n,LONG_MIN);

    for (int i = 0; i < m; i++)
    {
        cin >> start_ >> end_ >> weight;
        edges.push_back(make_tuple(start_, end_, weight));
    }
    for (int i = 0; i < n; i++)
    {
        cin >> income[i];
    }

    bellman_ford(start_city);

    if(profit[end_city] == LONG_MIN){
        cout << "gg\n";
    }
    else if(profit[end_city] == LONG_MAX){
        cout << "Gee\n";
    }
    else{
        cout << profit[end_city] << "\n";
    }
    return 0;
}

void bellman_ford(int node)
{
    profit[node] = income[node];
    for (int i = 0; i <= n + 50; i++)       // 문제에서 총 노드가 50개 이하, 50번 추가적으로 돈다
    {
        for (int j = 0; j < m; j++)
        {
            edge now = edges[j];
            int start = get<0>(now);
            int end = get<1>(now);
            int weight = get<2>(now);

            if(profit[start] == LONG_MIN){
                continue;
            } 
            else if(profit[start] == LONG_MAX){
                profit[end] = LONG_MAX;
            }
            else if (profit[end] < profit[start] - weight + income[end])
            {
                profit[end] = profit[start] - weight + income[end];
                if(i >= n-1){       // 추가적인 50번의 업뎃 과정에서 갱신되는 노드가 있다면, 양수 싸이클에 연결된 노드다.
                    profit[end] = LONG_MAX;
                }
            }
        }
    }
}