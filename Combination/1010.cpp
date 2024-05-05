#include <iostream>
#include <vector>

// 다리 놓기, 문제를 재해석할 수 있는가를 묻는 문제
// 겹칠 수 없다는 의미를 잘 파악해야 된다. 

using namespace std;

int t, n, m;
vector<vector<int>> D(31, vector<int>(31, 0));


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for(int i = 1; i <= 30; i++){
        D[i][1] = i;
        D[i][i] = 1;
        D[i][0] = 1;
    }
    
    for(int i = 2; i <= 30; i++){
        for(int j = 1; j <= 30; j++){
            D[i][j] = D[i-1][j] + D[i-1][j-1];
        }
    }

    cin >> t;
    for(int i = 0 ; i < t; i++){
        cin >> n >> m;
        cout << D[m][n] << "\n";
    }


    return 0;
}
