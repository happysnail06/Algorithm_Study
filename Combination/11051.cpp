#include <iostream>
#include <vector>

// 이항계수 구하기 2

using namespace std; 

vector<vector<int>> D;
int n, k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    D = vector<vector<int>>(n+1, vector<int>(n+1, 0));
    
    for(int i = 1; i <= n; i++){
        D[i][i] = 1;
        D[i][1] = i;
        D[i][0] = 1;
    }

    for(int i = 2; i <=n; i++){
        for(int j = 1; j <= n; j++){
            D[i][j] = (D[i-1][j] + D[i-1][j-1]) % 10007;
        }
    }
    cout << D[n][k] << "\n";

    return 0;
}