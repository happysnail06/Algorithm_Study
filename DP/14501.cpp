#include <iostream>

// 퇴사 준비하기
using namespace std;

int n;
int D[17] = {0};
int T[16];
int P[16];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> T[i] >> P[i];
    }

    int k = 0;
    for (int i = n; i > 0; i--)
    {
        if(i + T[i] > n + 1){           // 끝나지 않는 경우
            D[i] = D[i+1];
        }
        else{
            D[i] = max(D[i+1], D[i+T[i]] + P[i]);   // 끝나는 경우
                                                    // D[i+T[i]]: 겹치지 않는 날짜.
        }
    }
    cout << D[1] << "\n";

    return 0;
}