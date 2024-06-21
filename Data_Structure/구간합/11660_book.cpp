#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m, x1, y1, x2, y2;
    cin >> n >> m;
    vector<vector<int>> numbers(n+1, vector<int>(n+1, 0));
    vector<vector<int>> sums(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            cin >> numbers[i][j];
            sums[i][j] = sums[i-1][j] + sums[i][j-1] + numbers[i][j] - sums[i-1][j-1];
        }
    }

    for(int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int answer = sums[x2][y2] - sums[x1-1][y2] - sums[x2][y1-1] + sums[x1-1][y1-1];
        cout << answer << "\n";
    }

    return 0;
}