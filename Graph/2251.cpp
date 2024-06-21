#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs();

static int sender[] = {0, 0, 1, 1, 2, 2};
static int receiver[] = {1, 2, 0, 2, 1, 0};
vector<int> capacity(3);
vector<bool> answer(201);
vector<vector<bool>> visited(201, vector<bool>(201, false));


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> capacity[0] >> capacity[1] >> capacity[2];

    bfs();

    for(int i = 0; i < 201; i++){
        if(answer[i]){
            cout << i << " ";
        }
    }

    return 0;
}

void bfs(){
    queue<pair<int, int>> myQueue;
    myQueue.push(make_pair(0, 0));
    visited[0][0] = true;
    answer[capacity[2]] = true;

    while(!myQueue.empty()){
        pair<int, int> current_state = myQueue.front();
        myQueue.pop();
        int a = current_state.first;
        int b = current_state.second;
        int c = capacity[2] - a - b;

        for(int i = 0; i < 6; i++){
            int next[] = {a, b, c};

            next[receiver[i]] += next[sender[i]];
            next[sender[i]] = 0;

            if(next[receiver[i]] > capacity[receiver[i]]){
                next[sender[i]] = next[receiver[i]] - capacity[receiver[i]];
                next[receiver[i]] = capacity[receiver[i]];
            }

            if(!visited[next[0]][next[1]]){
                visited[next[0]][next[1]] = true;
                myQueue.push(make_pair(next[0], next[1]));
            }
            if(next[0] == 0){
                answer[next[2]] = true;
            } 
        }
    }
}