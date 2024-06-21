#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    vector<int> times(n ,0);
    for(int i = 0; i < n; i++){
        cin >> times[i];
    }
    int sum = 0;
    int ans = 0;
    sort(times.begin(), times.end());
    for(int i = 0; i < n; i++){
        sum = sum + times[i];
        ans = ans + sum;
    }
    cout << ans << "\n";


    return 0;
}