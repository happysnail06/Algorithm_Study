#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    auto max_it = max_element(arr.begin(), arr.end());
    int max = *max_it;
    double total = 0;
    for(int i = 0; i < n; i++){
        total+=arr[i]/(double)max * 100;
    }
    cout << total/n;
    return 0;
}