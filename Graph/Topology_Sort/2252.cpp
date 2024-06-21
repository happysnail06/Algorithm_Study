#include <iostream>
#include <vector>
#include <queue>

// 위상정렬

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> in_degree_vector;

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

    queue<int> myQueue;
    for(int i = 1; i <= n; i++){
        if(in_degree_vector[i] == 0){
            myQueue.push(i);
        }
    }
    while(!myQueue.empty()){
        int now_node = myQueue.front();
        myQueue.pop();
        cout << now_node << " ";
        for(int next : graph[now_node]){
            in_degree_vector[next]--;
            if(in_degree_vector[next] == 0){
                myQueue.push(next);
            }
        }
    }
    return 0;
}