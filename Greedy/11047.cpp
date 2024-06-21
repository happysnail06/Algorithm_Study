#include <iostream>
#include <vector>

using namespace std;

int n, k;
int t;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    vector<int> value(n, 0);

    for(int i = 0; i < n; i++){
        cin >> value[i];
    }

    int count = 0;
    while(k > 0){
        for(int i = n-1; i >= 0; i--){
            if(value[i] <= k){
                k = k - value[i];
                count++;
                break;
            }
        }
    }
    cout << count << "\n";


    return 0;
}