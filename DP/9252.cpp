#include <iostream>
#include <vector>

// LCS
// 각 string의 문자를 row와 column으로한 n * m 크기의 매트릭스를 사용
// 인덱스 i까지의 LCS를 구하고, 그 길이를 테이블에 저장한다.
//              같으면 왼쪽 대각선 위 + 1, 다르면 위쪽 혹은 왼쪽에서 큰값을 저장
using namespace std;

string str1, str2;
int D[1001][1001];
vector<char> ans;

void get_string(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return;
    }
    else
    {
        if (str1[a-1] == str2[b-1])
        {
            ans.push_back(str1[a-1]);
            get_string(a - 1, b - 1);       // 같으면 저장 후 대각선으로 이동
        }
        else
            if (D[a - 1][b] > D[a][b - 1]) {    // 다르면 큰 쪽으로 이동
                get_string(a - 1, b);       
            } else {
                get_string(a, b - 1);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str1 >> str2;
    int x = str1.size();
    int y = str2.size();

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                D[i][j] = D[i - 1][j - 1] + 1;
            }
            else
            {
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
            }
        }
    }

    cout << D[x][y] << "\n";
    get_string(x, y);
    for(int i = ans.size()- 1; i >= 0; i--){
        cout << ans[i];
    }

    return 0;
}