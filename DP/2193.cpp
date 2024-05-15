#include <iostream>

// 이친수 구하기
// 각 n값에서 1로 끝나는 경우와 0으로 끝나는 경우를 나눈다.
//  1로 끝날 경우 다음 n에서 0만 붙일 수 있다, 0으로 끝날 경우 1과 0을 모두 붙일 수 있다.
using namespace std;

int n;
long D[91][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    D[1][1] = 1;
    D[1][0] = 0;

    for(int i = 2; i <=n; i++){
        D[i][1] = D[i-1][0];
        D[i][0] = D[i-1][0] + D[i-1][1];
    }
    cout << D[n][1] + D[n][0] << "\n";



    return 0;
}