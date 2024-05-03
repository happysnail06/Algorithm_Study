#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> tree;
vector<int> parent;
vector<int> depth;
vector<bool> visited;

void bfs(int node);
int lca(int a, int b);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    tree.resize(n+1);
    parent.resize(n+1);
    depth.resize(n+1);
    visited = vector<bool>(n+1, false);

    int from, to;
    for(int i = 0; i < n - 1; i++){
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    bfs(1);

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        cout << lca(from, to) << "\n";
    }


    return 0;
}

void bfs(int node){
    queue<int> myQueue;
    myQueue.push(node);

    visited[node] = true;

    int dep = 1;
    int count = 0;
    int node_in_current_level = 1;

    while(!myQueue.empty()){
        int now = myQueue.front();
        myQueue.pop();

        for(int next : tree[now]){
            if(visited[next] == false){
                visited[next] = true;
                parent[next] = now;
                depth[next] = dep;
                myQueue.push(next);
            }
        }

        //// key,
        count++;
        if(count == node_in_current_level){
            dep++;
            count = 0;
            node_in_current_level = myQueue.size();
        }

    }
}


int lca(int a, int b){
    // 깊은 걸 기준으로
    if(depth[a] < depth[b]){
        int temp = a;
        a = b;
        b = temp;
    }

    //같은 깊이로 일단 끌어올린다.
    while(depth[a] != depth[b]){
        a = parent[a];
    }

    //같은 깊이에서 부모가 같을 때까지 찾아올라같다.
    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}