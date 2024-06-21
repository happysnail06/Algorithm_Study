#include <iostream>
#include <vector>

using namespace std;

long n, k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    long start = 1;
    long end = k;
    long ans;

    // k개의 작은 수를 가지는 *중앙값*을 찾는 문제
    // 중간값보다 작은 수의 개수를 센다. 
    while(start <= end){
        long middle = (start + end) / 2;    // 중간값 계산
        long count = 0;
        for(int i = 1; i <= n; i++){        // 중간값보다 작은 수를 세는 로직
            count = count + min(n, middle / i);  // 각 행은 i의 배수 형태이다. 중간값을 i로 나누면, k개의 i의 합이 중간값보다 작은 걸 알 수 있다. 
                                                 // 각 행은 최대 n개의 수를 갖기 때문에 k>n이면 n으로 보정
        }
        if(count < k){              //  개수가 부족하면 중간값을 더 크게 잡아야됨
            start = middle+1;
        }
        else{                       // 개수가 충분하면 중간값을 더 작게 잡는다.
            ans = middle;
            end = middle - 1;
        }
    }  
    cout << ans << "\n";

    return 0;
}