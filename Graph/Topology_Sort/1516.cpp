#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int t;

vector<int> need_time;
vector<int> least_time;
vector<vector<int>> graph;
vector<int> in_degree;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    need_time = vector<int>(n+1, 0);
    in_degree = vector<int>(n+1, 0);
    least_time = vector<int>(n+1, 0);

    graph.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> need_time[i];
        while(cin >> t && t != -1){
            graph[t].push_back(i);
            in_degree[i]++;
        }
    }

    queue<int> myQueue;
    for(int i = 1; i <=n ; i++){
        if(in_degree[i] == 0){
            myQueue.push(i);
        }
    }
    while(!myQueue.empty()){
        int now = myQueue.front();
        myQueue.pop();
        
        for(int i : graph[now]){
            in_degree[i]--;
            least_time[i] = max(least_time[i], least_time[now] + need_time[now]); // 이게 핵심.
            if(in_degree[i] == 0){
                myQueue.push(i);
            }
        }
    }

    for(int i = 1; i <=n; i++){
        cout << least_time[i] + need_time[i] << "\n";
    }

    return 0;
}