#include <iostream>

// 쉬운 계단 수
using namespace std;

int n;
long D[101][10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    
    for(int i = 1; i <= 9; i++){
        D[1][i] = 1;
    }
    D[1][0] = 0;
    
    for(int i = 2; i <= n; i++){
        D[i][0] = D[i-1][1] % (long)1000000000;
        for(int j = 1; j <= 8; j++){
            D[i][j] = (D[i-1][j-1] + D[i-1][j+1]) % (long)1000000000;
        }
        D[i][9] = D[i-1][8] % (long)1000000000;
    }
    long result = 0;
    for(int i = 0; i <= 9; i++){
        result+=D[n][i] % 1000000000;
        result%=1000000000;
    }
    cout << result << "\n";
    return 0;
}