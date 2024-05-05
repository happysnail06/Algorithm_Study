#include <iostream>
#include <vector>

using namespace std;
//부녀회장이 될 테야

int n, k, t;
vector<vector<int>> D;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    D = vector<vector<int>>(15, vector<int>(15, 0));
    for(int i = 1; i <= 15; i++){
        D[0][i] = i;
    }
    for(int i = 1; i <= 14; i++){
        for(int j = 1; j <=14; j++){
            D[i][j] = D[i-1][j] + D[i][j-1];    // 점화식
        }
    }
    for(int i = 0; i < t; i++){
        cin >> n >> k;
        cout << D[n][k] << "\n";
    }


    return 0;
}