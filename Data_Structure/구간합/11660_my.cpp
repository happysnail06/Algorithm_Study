#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, x1, x2, y1, y2, t;
    cin >> n >> m;
    vector<int> numbers;
    vector<int> sums;
    int sum = 0;

    sums.push_back(0);
    for(int i = 0; i < n*n; i++){
        cin >> t;
        numbers.push_back(t);
        sum+=t;
        sums.push_back(sum);
    }

    // 2차원 배열이 아닌 1차원 배열로 생각해서, 한 줄씩 구하고 더한다.
    int answer = 0;
    for(int i = 0; i < m; i++){         //  m: 구하는 횟수
        cin >> x1 >> y1 >> x2 >> y2;    
        for(int j = x1; j <= x2; j++){  
            answer+= (sums[(j-1)*n+y2] - sums[(j-1)*n+y1-1]);   //한 줄씩 
        }
        cout << answer << "\n";
        answer = 0;
    }

    return 0;
}