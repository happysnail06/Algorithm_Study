#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph(501, vector<int>(501, 0));
vector<vector<bool>> visited(501, vector<bool>(501, false));
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int num_graph = 0;
int max_size = 0;

void bfs(int x, int y, int s);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= m; j++){
            if(visited[i][j] == false && graph[i][j] == 1){
                int s = 1;
                bfs(i, j, s);
                num_graph++;
            }
        }
    }

    cout << num_graph << "\n";
    cout << max_size << "\n";

    return 0;
}

void bfs(int x, int y, int s){
    queue<pair<int,int>> myQueue;
    myQueue.push(make_pair(x, y));

    while(!myQueue.empty()){
        int now_node[2];
        now_node[0] = myQueue.front().first;
        now_node[1] = myQueue.front().second;
        myQueue.pop();
        visited[now_node[0]][now_node[1]] = true;

        for(int k = 0; k < 4; k++){
            int next_x = now_node[0] + dx[k];
            int next_y = now_node[1] + dy[k];
            if(next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= m){
                if(graph[next_x][next_y] == 1 && !visited[next_x][next_y]){
                    visited[next_x][next_y] = true;
                    s++;
                    myQueue.push(make_pair(next_x, next_y));
                }
            }
        }
    }
    if(s > max_size){
        max_size = s;
    }
}