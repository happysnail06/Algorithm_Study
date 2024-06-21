#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> parent;
vector<int> want_to_visit;
int t;
bool possible = true;

int find(int node);
void my_union(int a, int b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    graph = vector<vector<int>>(n+1, vector<int>(n+1, 0));
    parent = vector<int>(n+1);
    want_to_visit = vector<int>(m);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        cin >> want_to_visit[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == 1){
                my_union(i, j);
            }
        }
    }


    int top = find(want_to_visit[0]);
    for(int i = 1; i < m; i++){
        if(find(want_to_visit[i]) != top){
            possible = false;
            break;
        }
    }

    if(possible){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    
    return 0;
}

int find(int node){
    if(node == parent[node]){
        return node;
    }
    else{
        return parent[node] = find(parent[node]);
    }
}

void my_union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        parent[b] = a;
    }
}