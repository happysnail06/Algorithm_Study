#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> connected;
int n, m;

int bfs(int node, int count);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    graph.resize(n+1);
    visited = vector<bool>(n+1, false);
    connected = vector<int>(n+1, 0);

    int start, end;
    for(int i = 0; i < m; i++){
        cin >> start >> end;
        graph[end].push_back(start);
    }

    for(int i = 1; i <= n; i++){
        int count;
        count = bfs(i, 0);
        connected[i] = count;
        fill(visited.begin(), visited.end(), false);
    }

    auto it = max_element(connected.begin(), connected.end());
    int max = *it;
    for(int i = 1; i <= connected.size(); i++){
        if(connected[i] == max){
            cout << i << " ";
        }
    }

    return 0;
}

int bfs(int node, int count){
    queue<int> myQueue;
    myQueue.push(node);
    visited[node] = true;

    while(!myQueue.empty()){
        int now_node = myQueue.front();
        myQueue.pop();
        
        for(int i : graph[now_node]){
            if(visited[i] == false){
                count++;            //몇 개의 노드와 연결됐는지 확인
                visited[i] = true;
                myQueue.push(i);
            }
        }
    }
    return count;
}

