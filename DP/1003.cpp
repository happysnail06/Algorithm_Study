#include <iostream>

using namespace std;

int D[41][2];

int t, n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    D[0][0] = 1;
    D[0][1] = 0;
    D[1][0] = 0;
    D[1][1] = 1;
    
    D[2][0] = 1;
    D[2][1] = 1;

    for(int i = 3; i <= 40; i++){
        D[i][0] = D[i-1][0] + D[i-2][0];
        D[i][1] = D[i-1][1] + D[i-2][1];
    }

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << D[n][0] << " " << D[n][1] << "\n";
    }
    

    return 0;
}