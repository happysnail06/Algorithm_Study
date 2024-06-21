#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// 다익스트라, 최단거리 알고리즘은 우선순위 큐로 구현
// 큐에서 다음 노드를 선택할 때 값이 가장 작은, 거리가 가장 가까운 노를 선택한다.

// 책에서는 edge를 define해서 사용한다.
// typedef pair<int, int> edge;
// static priority_queue<edge, vector<edge>, greater<edge>> myQueue;
#define inf numeric_limits<int>::max()

using namespace std;
void bfs(int node); // 다익스트라

int v, e;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
vector<int> result; // 거리 저장 배열
int start_node;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    graph.resize(v + 1);
    visited = vector<bool>(v + 1, false);

    cin >> start_node;

    int start_, end_, weight;
    for (int i = 0; i < e; i++)
    {
        cin >> start_ >> end_ >> weight;
        graph[start_].push_back(make_pair(end_, weight));
    }

    result = vector<int>(v + 1, inf);
    result[start_node] = 0;

    bfs(start_node);

    for (int i = 1; i <= v; i++)
    {
        if (result[i] != inf)
        {
            cout << result[i] << "\n";
        }
        else
        {
            cout << "INF\n";
        }
    }

    return 0;
}

void bfs(int node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myQueue; // 우선순위 큐
    myQueue.push(make_pair(0, node));

    while (myQueue.empty() == false)
    {
        pair<int, int> now_node = myQueue.top();
        myQueue.pop();
        int now_city = now_node.second;
        
        if (!visited[now_city])
        {
            visited[now_city] = true;

            for (pair<int, int> next : graph[now_city])
            {
                int next_city = next.first;
                result[next_city] = min(result[next_city], result[now_city] + next.second);
                myQueue.push(make_pair(result[next_city], next_city));
            }
        }
    }
}
