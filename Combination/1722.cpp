#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited(21, false);
vector<long> F(21);
vector<int> ans(21);

int n, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 경우의 수를 저장하는 배열.
    F[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        F[i] = F[i - 1] * i;
    }

    cin >> n;
    cin >> q;
    if (q == 1)
    {
        long k;
        cin >> k;
        for (int i = 1; i <= n; i++)
        { // 정답 배열을 채우기 위한 루프, 각 자릿수에 대해서
            for (int j = 1, count = 1; j <= n; j++)
            { // 사용하지 않은 숫자를 추적하기 위한 루프
                if (visited[j])
                { // 사용했으면 넘어간다.
                    continue;
                }

                if (k <= F[n - i] * count)
                {                                   // F[n-i]에는 특정 자릿수에서 특정 수로 시작하는 순열의 경우의 수를 뜻한다.
                                                    //  [n-i]는 F를 [1,2,6,24]처럼 역순으로 채웠기 때문
                    k = k - F[n - i] * (count - 1); // count에서 1을 빼주는 이유는 1로 시작할 경우 가장 앞에 위치한 6개 중에 정답 순열이 존재하기 때문
                                                    // 예시로 k가 7이고, 1로 시작하는 순열이 6개 일 때, k에서 6을 빼고, 2로 시작하는 경우의 수로 넘어간다.
                    ans[i] = j;                     // 현재 자릿수에 오는 숫자를 저장하고
                    visited[j] = true;              // 다시 사용되지 않게 방문기록을 남긴다.
                    break;
                }
                count++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        long k = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> ans[i];

            int cnt = 0;
            for (int j = 1; j < ans[i]; j++)    // 1부터 입력의 크기까지. 입력이 1이면 skip됨 
            {
                if (visited[j] == false)
                {
                    cnt++;
                }
            }
            k = k + F[n-i] * cnt;               
            visited[ans[i]] = true;
        }
        cout << k << "\n";
    }

    return 0;
}