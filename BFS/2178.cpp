#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, m;
string num;
vector<vector<int>> maze;
vector<vector<bool>> visited;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void bfs(int x, int y);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    maze = vector<vector<int>>(n+1, vector<int>(m+1, 0));
    visited = vector<vector<bool>>(n+1, vector<bool>(m+1, false));
    for(int i = 1 ; i <= n; i++){
        cin >> num;
        for(int j = 0; j < num.length(); j++){
            maze[i][j+1] = int(num[j]) - 48;
        }
    }

    bfs(1, 1);
    cout << maze[n][m] << "\n";


    return 0;
}

void bfs(int x, int y){
    queue<pair<int, int>> myQueue;
    myQueue.push(make_pair(x, y));

    while(!myQueue.empty()){
        int curr[2];
        curr[0] = myQueue.front().first;
        curr[1] = myQueue.front().second;
        visited[x][y] = true;

        myQueue.pop();
        for(int i = 0; i < 4; i++){
            int next_x = curr[0] + dx[i];
            int next_y = curr[1] + dy[i];

            if(next_x >= 0 && next_y >= 0 && next_x <= n && next_y <= m){
                if(maze[next_x][next_y] != 0 && visited[next_x][next_y] == false){
                    visited[next_x][next_y] = true;
                    maze[next_x][next_y] = maze[curr[0]][curr[1]] + 1;
                    myQueue.push(make_pair(next_x, next_y));
                }
            }
        }
    }

}