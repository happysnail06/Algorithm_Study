#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//오일러의 피

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long n;
    cin >> n;

    long result = n;

    for (long i = 2; i <= sqrt(n); i++)     //제곱근 이상은 소인수일 수가 없음
    {
        if (n % i == 0) // 소인수 판별
        {
            result = result - result / i;       // (result / i)는 result보다 작은 수들 중 i로 나누어 떨어지는 수의 개수를 계산
                                                // result - (i의 배수의 개수) = 남는 수
        }
        while(n % i == 0){                      // 중복 삭제 방지
            n = n / i;                          // n이 45, i가 3일 경우, n은 5가 된다.
        }
    }

    if(n > 1){                                  // n이 1보다 클 경우, n 자신이 마지막 소인수라는 뜻.
        result = result - result / n;      
    }
    cout << result << "\n";

    return 0;
}