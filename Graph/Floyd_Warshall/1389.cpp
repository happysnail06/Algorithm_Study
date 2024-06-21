#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    graph = vector<vector<int>>(n+1, vector<int>(n+1, 10000));

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int s = 1; s <= n; s++){
            for(int e = 1; e <= n; e++){
                if(graph[s][e] > graph[s][k] + graph[k][e]){
                    graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);
                }
            }
        }
    }

    vector<int> su(n+1, 0);
    int min = 10000;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            su[i]+= graph[i][j];
        }
        if(su[i] < min){
            min = su[i];
        }
    }

    for(int i = 1; i <=n; i++){
        if(su[i] == min){
            cout << i << "\n";
            break;
        }
    }

    return 0;
}