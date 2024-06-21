#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, t, sum = 0;
    vector<int> numbers;
    vector<int> sums;
    sums.push_back(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> t;
        numbers.push_back(t);
        sum+=t;
        sums.push_back(sum);
    }
    int start, end, answer;
    for(int i = 0; i < m;i++){
        cin >> start >> end;
        answer = sums[end] - sums[start-1];
        cout << answer << "\n";
    }

    return 0;
}