#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, num;
    cin >> n >> m;

    unordered_map<int, int> count_map;      //특정 나머지 값을 마주친 횟수를 저장하는 map

    int sum = 0;
    long long count = 0;

    for (int i = 1; i <= n; i++) {
        cin >> num; 

        sum = (sum + num) % m; 
        count += (sum == 0); // 나머지가 0이면, count 1 증가

        count += count_map[sum];
        count_map[sum]++;
    }

    cout << count << "\n";

    return 0;
}
