#include <iostream>
#include <vector>
#include <cmath>

//고층 빌딩

using namespace std;

long D[101][101][101] = {0};
int n, l, r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    D[1][1][1] = 1;
    cin >> n >> l >> r;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= l; j++){            // 왼쪽에서 보이는 개수
            for(int k= 1; k <= r; k++){         // 오른쪽에서 보이는 개수
                D[i][j][k] = ((D[i-1][j-1][k] + 
                                D[i-1][j][k-1]) + 
                                (D[i-1][j][k] * (i-2))) % long(1000000007);
            }
        }
    }

    cout << D[n][l][r] << "\n";


    return 0;
}