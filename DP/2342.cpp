#include <iostream>
#include <vector>
#include <climits>

// Dance Dance Revolution
// 모든 경우의 수를 구하는 특별한 문제
// 한발만 움직여  D[L][R][S] 상태를 만들 수 있는 모든 경우의 수를 비교한다.
using namespace std;

int e[5][5] = {0};
long D[5][5][100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for(int i = 1; i <= 4; i++){
        e[0][i] = 2;
        e[i][0] = 2;
        for(int j = 1; j <= 4; j++){
            if(i == j){
                e[i][j] = 1;
            }
            else if(abs(abs(j) - abs(i)) == 2){
                e[i][j] = 4;
            }
            else{
                e[i][j] = 3;
            }
        }
    }

    for(int i = 0; i <= 4; i++){
        for(int j = 0; j<= 4; j++){
            for(int k = 0; k < 100001; k++){
                D[i][j][k] = 100001 * 4;
            }
        }
    }

    D[0][0][0] = 0;

    int n;
    int s = 1;
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i = 0; i < 5; i++){
            if(n == i){
                continue;
            }
            for(int j = 0; j <= 4; j++){
                D[i][n][s] = min(D[i][j][s-1] + e[j][n], D[i][n][s]);       // 오른쪽 다리를 움직이는 경우
            }
        }
        for(int i = 0; i < 5; i++){
            if(n == i){
                continue;
            }
            for(int j = 0; j <= 4; j++){
                D[n][i][s] = min(D[j][i][s-1] + e[j][n], D[n][i][s]);       // 왼쪽 다리를 움직이는 경우
            }
        }
        s++;
    }

    s--;
    long minVal = INT_MAX;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            minVal = min(minVal, D[i][j][s]);
        }
    }
    cout << minVal << "\n";
    return 0;
}