#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> tree;
vector<bool> visited;
vector<int> parent;

void dfs(int node);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    tree.resize(n+1);
    visited = vector<bool>(n+1, false);
    parent.resize(n+1);

    int start, end;
    for(int i = 1; i < n; i++){
        cin >> start >> end;
        tree[start].push_back(end);
        tree[end].push_back(start);
    }

    dfs(1);

    for(int i = 2; i <=n; i++){
        cout << parent[i] << "\n";
    }

    return 0;
}

void dfs(int node){
    if(visited[node]){
        return;
    }
    visited[node] = true;
    for(int next : tree[node]){
        if(visited[next] == false){
            parent[next] = node;
            dfs(next);
        }
    }
}
