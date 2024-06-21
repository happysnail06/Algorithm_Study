#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

//  플로이드 워셜, 벨멘포드 처럼 LONG_MAX로 하면 오버플로우나서 적당히 큰 값으로 초기화.
int n, m;
vector<vector<long>> graph;

void floyd_warshall();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    graph = vector<vector<long>>(n+1, vector<long>(n+1, 10000001));

    for(int i = 1; i <= n; i++){
        graph[i][i] = 0;
    }

    int start_, end_, cost;
    for(int i = 1; i <= m; i++){
        cin >> start_ >> end_ >> cost;
        if(graph[start_][end_] > cost)      // 같은 ab값이 여러번 나올 수 있다
        {
            graph[start_][end_] = cost;
        }
    }

    floyd_warshall();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == 10000001){
                cout << 0 << " ";
            }
            else{ 
                cout << graph[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}

void floyd_warshall(){
    for(int k = 1; k <= n; k++){
        for(int s = 1; s <= n; s++){
            for(int e = 1; e <=n; e++){
                graph[s][e] = min(graph[s][e], graph[s][k] + graph[k][e]);
            }
        }
    }
}

