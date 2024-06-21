#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> relation;
void dfs(int curr, int count);
vector<bool> visited;
bool arrive;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    relation.resize(n);
    visited = vector<bool>(n, false);
    arrive = false;
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        relation[s].push_back(e);
        relation[e].push_back(s);
    }

    for(int i = 0; i < n; i++){
        dfs(i, 1);
        if(arrive){
            break;
        }
    }
    if(arrive){cout << 1 << "\n";}
    else{cout << 0 << "\n";}
    return 0;
}

void dfs(int start, int count){
    if(count >= 5 || arrive){
        arrive = true;
        return;
    }
    visited[start] = true;

    for(int i : relation[start]){
        if(visited[i] == false){
            dfs(i, count+1);
        }
    }
    visited[start] = false;  // 한 번의 재귀가 끝날 때 visited를 속 값을 모두 false로 되돌려준다.
}