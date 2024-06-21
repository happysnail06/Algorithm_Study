#include <iostream>
#include <vector>

using namespace std;

int n, m;
int u, v;
static vector<vector<int>> graph;
static vector<bool> visited;
void dfs(int v);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph.resize(n+1);
    visited = vector<bool>(n+1, false);

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    
    int count = 0;
    for(int i = 1; i < n+1; i++){
        if(!visited[i]){
            count++;
            dfs(i);
        }
    }
    cout << count << "\n";
    return 0;
}

void dfs(int v){
    if(visited[v]){return;}
    visited[v] = true;
    for(int i : graph[v]){
        if(visited[i] == false){
            dfs(i);  
        }
    }
}