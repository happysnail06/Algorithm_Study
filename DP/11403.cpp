#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    graph = vector<vector<int>>(n+1, vector<int>(n+1));

    int t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }

    for(int k = 1; k <= n; k++){
        for(int s = 1; s <= n; s++){
            for(int e = 1; e <= n; e++){
                if(graph[s][k] > 0 && graph[k][e] > 0){
                    graph[s][e] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}