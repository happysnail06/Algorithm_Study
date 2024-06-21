#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int removed = 0;;
int count_leaf = 0;
void dfs(int node);

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    graph.resize(n);
    visited.resize(n);

    int t;
    int root = 0;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(t == -1){
            root = i;
        }
        else{
            graph[i].push_back(t);
            graph[t].push_back(i);
        }
    }  
    cin >> removed;
    if(removed == root){
        cout << "0\n";
    }
    else{
        dfs(root);
        cout << count_leaf << "\n";
    }


    return 0;
}

void dfs(int node){
    visited[node] = true;
    int child_count = 0;

    for(int next : graph[node]){
        if(visited[next] == false && next != removed){
            child_count++;
            dfs(next);
        }
    }
    if(child_count == 0){
        count_leaf++;
    }
}