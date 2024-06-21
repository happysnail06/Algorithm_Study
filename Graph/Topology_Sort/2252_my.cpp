#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> in_degree_vector;
vector<int> sort_vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    graph.resize(n + 1);
    in_degree_vector = vector<int>(n + 1, 0);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree_vector[b]++;
    }

    int now_node;
    while (sort_vec.size() < n)
    {
        int now_node;
        for (int i = 1; i < n + 1; i++)
        {
            if (in_degree_vector[i] == 0)
            {
                now_node = i;
                in_degree_vector[now_node] = -1;
                break;
            }
        }

        sort_vec.push_back(now_node);
        for(int i = 0; i < graph[now_node].size(); i++){
            in_degree_vector[graph[now_node][i]]--;
        }
    }

    for(int i = 0; i < sort_vec.size(); i++){
        cout << sort_vec[i] << " ";
    }

    return 0;
}