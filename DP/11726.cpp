#include <iostream>

// 2*n 타일링

int n;
long D[1001];

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    D[1] = 1;
    D[2] = 2;
    for(int i = 3; i <= n; i++){
        D[i] = (D[i-2] + D[i-1]) % 10007;
    }
    cout << D[n];



    return 0;
}