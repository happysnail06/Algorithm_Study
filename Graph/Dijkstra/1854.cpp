#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define inf numeric_limits<int>::max()

using namespace std;

typedef pair<int, int> edge;

int n, m, k;
vector<vector<edge>> graph;
priority_queue<int> distances[1001]; // 핵심, 각 노드까지의 거리를 저장하는 벡터를 우선순위큐로 선언, 그리고 해당 노드에 도착하는 가장 작은 k개의 경로를 유지한다.

int start_, end_, weight;

void dijkstra(int node);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> start_ >> end_ >> weight;
        graph[start_].push_back(make_pair(end_, weight));
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        if (distances[i].size() < k)
        {
            cout << "-1\n";
        }
        else
        {
            cout << distances[i].top() << "\n";
        }
    }

    return 0;
}

void dijkstra(int node)
{
    priority_queue<edge, vector<edge>, greater<edge>> myQueue;
    myQueue.push(make_pair(0, node));
    distances[node].push(0);

    while (!myQueue.empty())
    {
        edge now_edge = myQueue.top();
        myQueue.pop();
        int now_city = now_edge.second;

        for (edge next : graph[now_city])
        {
            int next_city = next.first;
            int d = next.second;
            if (distances[next_city].size() < k)    // k개 이하
            {
                distances[next_city].push(now_edge.first + d);  //이전 도시까지의 거리 + 이전 도시와 다음 도시 사이의 거리 
                myQueue.push(make_pair(now_edge.first + d, next_city));
            }
            else if (distances[next_city].top() > now_edge.first + d)   // k개의 경로가 이미 존재하고, 이중 가장 긴 게 현재 경로보다 길 때
            {
                distances[next_city].pop();
                distances[next_city].push(now_edge.first + d);
                myQueue.push(make_pair(now_edge.first + d, next_city));
            }
        }
    }
}
