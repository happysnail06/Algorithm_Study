#include <iostream>

// 가장 큰 사각형
// D[i-1][j-1], D[i][j-1], D[i-1][j]에서 가장 작은 값 +1 을 D[i][j]에 저장.
    // 주변 블록을 활용해 (가장 작은 값 + 1)을 한 변의 길이로 갖는 사각형을 만들 수 있다는 뜻.
using namespace std;

int n, m;
int graph[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string str;

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> str;
        for(int j = 0; j < m; j++){
            graph[i][j+1] = str[j] - '0';
        }
    }

    int max = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            if(graph[i][j] != 0){
                graph[i][j] = min(graph[i-1][j-1], graph[i-1][j]);
                graph[i][j] = min(graph[i][j], graph[i][j-1]) + 1;
                if(graph[i][j] > max){
                    max = graph[i][j];
                }
            }
        }
    }
    
    cout << max * max << '\n';


    return 0;
}