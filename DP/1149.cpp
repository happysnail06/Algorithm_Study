#include <iostream>
#include <limits.h>

using namespace std;


// RGB거리
int n;
int D[1001][3];
int costs[1001][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            cin >> D[i][j];
        }
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){
                D[i][j] += min(D[i-1][j+1], D[i-1][j+2]);
            }
            else if(j == 1){
                D[i][j] += min(D[i-1][j+1], D[i-1][j-1]);
            }
            else{
                D[i][j] += min(D[i-1][j-1], D[i-1][j-2]);
            }
        }
    }

    
    int min = INT_MAX;
    for(int i = 0; i < 3; i++){
        if(D[n][i] < min){
            min = D[n][i];
        }
    }
    cout << min;

    return 0;
}