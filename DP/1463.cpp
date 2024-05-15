#include <iostream>

// 1로 만들기

using namespace std;

int n;
int D[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    D[1] = 0;
    D[2] = 1;
    D[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        D[i] = D[i - 1] + 1;
        if (i % 2 == 0)
        {
            D[i] = min(D[i], D[i / 2] + 1);
        }
        if (i % 3 == 0)
        {
            D[i] = min(D[i / 3] + 1, D[i]);
        }
    }
    cout << D[n] << "\n";

    return 0;
}