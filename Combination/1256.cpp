#include <iostream>
#include <vector>

// 사전
// 문제 재해석이 어려웠다. n+m개에서 m개를 선택하는 거랑 같은 뜻.

using namespace std;

long n, m, k;
static long D[202][202];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i <= 200; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){           // D[i][i] = 1;  D[i][0] = 1;
                D[i][j] = 1;
            }
            else{
                D[i][j] = D[i-1][j-1] + D[i-1][j];      // 점화식
                if(D[i][j] > 1000000000){               // 문제에서 요구하는 k 이상의 경우의 수를 저장할 시 
                    D[i][j] = 100000001;
                }
            }
        }
    }

    if(D[n+m][m] < k){          // 총 경우의 수가 k보다 작을 경우
        cout << "-1\n";
    }
    else{
        while(n != 0 || m != 0){
            if(D[n-1+m][m] >= k){              // n-1: 현재 위치에서 a를 선택했을 때
                cout << "a";                   // D[n-1+m][m] >= k: 남은 문자로 충분한 경우의 수를 만들 수 있을 경우
                n--;                           // a를 선택
            }
            else{
                cout << "z";
                k = k - D[n+m-1][m];           // z를 선택하고, k를 업뎃한다 
                m--;
            }
        }
    }
    return 0;
}