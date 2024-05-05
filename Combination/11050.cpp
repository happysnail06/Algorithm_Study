#include <iostream>
#include <vector>

using namespace std;

//이항계수 구하기 1
// 조합의 기초
// 점화식: D[i][j] = D[i-1][j] + D[i-1][j-1];

vector<vector<int>> D;
int n, k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    D = vector<vector<int>>(n+1, vector<int>(n+1, 0));

    for(int i = 1; i <= n; i++){
        D[i][i] = 1;            // i개 중 i개를 선택하는 경우의 수
        D[i][1] = i;            // i개 중 하나를 선택하는 경우의 수
        D[i][0] = 1;            // i개 중 선택을 안하는 경우의 수
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            D[i][j] = D[i-1][j] + D[i-1][j-1];  // 점화식: D[i][j] = D[i-1][j] + D[i-1][j-1];
        }
    }
    cout << D[n][k] << "\n";

    return 0;
}