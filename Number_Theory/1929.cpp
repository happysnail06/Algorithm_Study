#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    vector<int> numbers(n+1, 0);

    for(int i = 2; i <= n; i++){
        numbers[i] = i;
    }

    for(int i = 2; i <= sqrt(n); i++){
        if(numbers[i] == 0){
            continue;
        }
        for(int j = i + i; j <= n; j+=i){
            numbers[j] = 0;
        }
    }
    for(int i = m; i <=n; i++){
        if(numbers[i] != 0){
            cout << i << "\n";
        }
    } 

    return 0;
}