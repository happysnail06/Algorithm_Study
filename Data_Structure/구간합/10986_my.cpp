#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m, num;
    cin >> n >> m;
    
    vector<int> first_sums;
    int sum = 0;
    int count = 0;

    first_sums.push_back(0);

    for(int i = 1; i <= n; i++){
        cin >> num;
        sum+=num;

        first_sums.push_back(sum);
        if(sum % m == 0){
            count++;
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j++){
            int temp = first_sums[j] - first_sums[i-1];
            if(temp % m == 0){
                count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}