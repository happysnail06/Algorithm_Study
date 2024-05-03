#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int n, m;

vector<vector<int>> parent;
vector<int> depth;
vector<bool> visited;
vector<vector<int>> graph;
int k = 0;

void bfs(int node);
int lca(int a, int b);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    depth.resize(n+1);
    graph.resize(n+1);
    visited = vector<bool>(n+1, false);

    int temp = n;
    while(temp != 1){
        temp/=2;
        k++;
    }
    
    parent = vector<vector<int>>(k+1, vector<int>(n+1));

    int s, e;
    for(int i = 0; i < n - 1; i++){
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    bfs(1);

    //부모배열 채우기
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> s >> e;
        cout << lca(s, e) << "\n";
    }
    


    return 0;
}

////////핵심/////////
int lca(int a, int b){
    if(depth[a] > depth[b]){
        int t = a;
        a = b;
        b = t;
    }
    for(int i = k; i >= 0; i--){
        if(pow(2, i) <= depth[b] - depth[a]){   // 높이 차이가 20이라면, 2^4 <= 20이니까 k값은 4가 되고, parent[4][b]를 찾은 후,
                                                // 다음 루프에서 높이 차이가 4고, 2^2 <= 4이니까, parent[2][b]를 또 찾으면 됨. 
            if(depth[a] <= depth[parent[i][b]]){
                b = parent[i][b];
            }
        }
    }
    for(int i = k; i >= 0 && a != b; i--){
        if(parent[i][a] != parent[i][b]){
            a = parent[i][a];
            b = parent[i][b];
        }
    }

    int answer = a;
    if(a != b){
        answer = parent[0][answer];
    }
    return answer;
}

void bfs(int node){
    queue<int> myQueue;
    myQueue.push(node);
    visited[node] = true;
    int dep = 1;
    int count = 0;
    int node_in_current_level = 1;


    while(myQueue.empty() == false){
        int now_node = myQueue.front();
        myQueue.pop();

        for(int next : graph[now_node]){
            if(!visited[next]){
                visited[next] = true;
                depth[next] = dep;
                parent[0][next] = now_node;
                myQueue.push(next);
            }
        }

        count++;
        if(count == node_in_current_level){
            count = 0;
            dep++;
            node_in_current_level = myQueue.size();
        }
    }

}