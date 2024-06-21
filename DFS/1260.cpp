#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int n, m, v;
int start_node, end_node;
void dfs(int s);
void bfs(int s);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> v;
    graph.resize(n+1);
    visited = vector<bool>(n+1, false);

    // 간선 연결하기
    for(int i = 0; i < m; i++){
        cin >> start_node >> end_node;
        graph[start_node].push_back(end_node);
        graph[end_node].push_back(start_node);
    }

    for(int i = 1; i <= n; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << "\n";
    fill(visited.begin(), visited.end(), false);
    bfs(v);
    return 0;
}

void dfs(int s){

    visited[s] = true;
    cout << s << " ";
    for(int i : graph[s]){
        if(visited[i] == false){
            dfs(i);
        }
    }
}

void bfs(int s){
    queue<int> to_visit;

    visited[s] = true;

    to_visit.push(s);     // 현재 노드를 넣고
    while(!to_visit.empty()){
        int curr = to_visit.front();
        to_visit.pop();
        cout << curr << " ";
        for(int i : graph[curr]){
            if(!visited[i]){
                visited[i] = true;
                to_visit.push(i);
            }
        }
    }

}