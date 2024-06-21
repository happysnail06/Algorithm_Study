#include <iostream>
#include <vector>

// 조약돌 꺼내기
// 상황에 따라 배열이 아닌 단순 계산으로 정답을 구한다.
using namespace std;

int m, k;
vector<int> rock(51, 0);
vector<double> p(51, 1.0);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> m;

    int total_rocks = 0;
    for(int i = 1; i <= m; i++){
        cin >> rock[i];
        total_rocks+= rock[i];
    }

    cin >> k;
    int temp = k;

    double answer = 0.0;
    for(int i = 1; i <= m; i++){
        if(rock[i] >= k){
            for(int j = 0; j < k; j++){
                p[i] = p[i] * ((double)(rock[i] - j) / (total_rocks-j));
            }
            answer+=p[i];
        }
    }

    cout << fixed;
    cout.precision(9);

    cout << answer << "\n";

    return 0;
}