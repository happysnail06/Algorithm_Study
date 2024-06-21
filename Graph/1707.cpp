#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int k;
int v, e;
int from, to;

vector<vector<int>> graph;
vector<bool> visited;
vector<char> group;
bool bipartite = true;

void dfs(int node);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> v >> e;

        for (int j = 0; j < e; j++)
        {
            cin >> from >> to;
            graph.resize(v + 1);
            visited = vector<bool>(v + 1, false);
            group = vector<char>(v + 1, 1);         // 그룹 확인용

            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        for (int t = 1; t <= v; t++)
        {
            if (bipartite)
            {
                dfs(t);
            }
            else
            {
                break;
            }
        }

        if(bipartite){cout << "YES\n";}
        else{cout << "NO\n";}

        graph.clear();
        visited.clear();
        group.clear();
        bipartite = true;
    }

    return 0;
}

void dfs(int node)
{
    visited[node] = true;
    for (int i : graph[node])
    {
        if (visited[i] == false)
        {
            group[i] = group[node] * (-1);      // 1 *(-1)를 사용해서 그룹을 나눈다.
            dfs(i);
        }
        else if (group[node] == group[i])
        {
            bipartite = false;
            break;
        }
    }
}