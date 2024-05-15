#include <iostream>
#include <vector>

// 동물원
using namespace std;

vector<int> D(100001, 0);
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;
    D[1] = 3;
    D[2] = 7;
    for(int i = 3; i <= n; i++){
        D[i] = (2 * D[i-1] + D[i-2]) % 9901;
    }
    cout << D[n];


    return 0;
}