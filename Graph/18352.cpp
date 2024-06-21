#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int n, m, k, x;
vector<vector<int>> graph;
vector<int> visited;
vector<int> answer;

void bfs(int node);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> x;
    graph.resize(n+1);
    visited = vector<int>(n+1, -1);

    int start, end;
    for(int i = 0; i < m; i++){
        cin >> start >> end;
        graph[start].push_back(end);
    }

    bfs(x);

    int count = 0;
    for(int i = 1; i < visited.size(); i++){
        if(visited[i] == k){
            count++;
            cout << i << "\n";
        }
    }

    if(count==0){
        cout << "-1";
    }
    return 0;
}

void bfs(int node){
    queue<int> myQueue;
    myQueue.push(node);
    visited[node]++;

    while(!myQueue.empty()){
        int now_node = myQueue.front();
        myQueue.pop();

        for(int i : graph[now_node]){
            if(visited[i] == -1){
                visited[i] = visited[now_node] + 1;         //*** 이전에 탐색한 노드까지의 거리를 visited에 저장한다, 
                                                            //next_node는 visited[i] + 1로 해결
                myQueue.push(i);
            }
        }
    }
}