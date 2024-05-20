#include <iostream>
#include <vector>
#include <climits>

// 행렬 곱 연산 횟수의 최솟값 구하기
// D[i][j], i번째 행렬부터 j번째까지의 최소 연산 횟수 
// 점화식: D[1][n-1] + D[n][n] + a

using namespace std;

int n;
int r, c;

int D[501][501];
vector<pair<int, int>> mat;

int func(int s, int e)
{
    int result = INT_MAX;
    if (D[s][e] != -1)      // Memoization
    {
        return D[s][e];
    }
    if (s == e)             // 행렬이 하나
    {
        return 0;
    }
    if (s + 1 == e)         // 행렬이 2개 
    {
        return mat[s].first * mat[s].second * mat[e].second;
    }
    for (int i = s; i < e; i++)
    {
        result = min(result, mat[s].first * mat[i].second * mat[e].second + func(s, i) + func(i + 1, e)); 
        // 여기서 s는  항상 1. 
        // 1부터 2,3,4,5...n-1의 구간 중 가장 작은 값을 얻는다는 뜻.
        
    }
    return D[s][e] = result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    mat.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> r >> c;
        mat[i] = make_pair(r, c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            D[i][j] = -1;
        }
    }

    cout << func(1, n) << "\n";
    return 0;
}