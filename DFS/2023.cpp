#include <iostream>
#include <vector>

using namespace std;

int n;
void dfs(int number, int jarisu);
bool isPrime(int num);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> first = {2, 3, 5, 7};
    for(int i = 0; i < first.size(); i++){
        dfs(first[i], 1);
    }


    return 0;
}

void dfs(int number, int jarisu){
    if(jarisu == n){
        if(isPrime(number)){
            cout << number << "\n";
        }
        return;
    }
    for(int i = 1; i <= 9; i+=2){
        if(isPrime(number * 10 + i)){
            dfs(number * 10 + i, jarisu+1);
        }
    }
}

bool isPrime(int num){
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}