#include <iostream>
#include <vector>
#include <cmath>

// 연속된 정수의 합 구하기

using namespace std;

int n;
vector<int> numbers(100001, 0);
vector<int> L(100001, 0);
vector<int> R(100001, 0);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> numbers[i];
    }

    L[1] = numbers[1];
    int result = numbers[1];
    for(int i = 2; i <=n; i++){
        L[i] = max(numbers[i], L[i-1] + numbers[i]);
        result = max(result, L[i]);
    }
    
    R[n] = numbers[n];
    for(int i = n - 1; i >= 1; i--){
        R[i] = max(numbers[i], R[i+1] + numbers[i]);
    }

    // 각 i를 제거하는 모든 경우의 수 중에서 가장 큰 것을 선택한다
    for(int i = 2; i <= n; i++){        // L[0], R[0]은 없다. 그래서 i-1이 최소 1이 돼야 됨
        int temp = L[i-1] + R[i+1];
        result = max(result, temp);
    }
    cout << result << "\n";

    return 0;
}