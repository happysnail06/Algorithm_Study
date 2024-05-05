#include <iostream>
#include <vector>

// 선물 전달하기
// 점화식을 도출할 수 있는지를 묻는 문제

using namespace std;

int n;
long D[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    D[1] = 0;
    D[2] = 1;
    for(int i = 3; i <= n; i++){
        D[i] = (i - 1) * (D[i-2] + D[i-1]) % 1000000000; 
    }
    cout << D[n];


    return 0;
}