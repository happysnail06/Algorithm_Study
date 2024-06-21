#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int n;

bool pelindrome(int number);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    vector<int> prime_numbers(20000001, 0);
    for(int i = 2; i <= 20000001; i++){
        prime_numbers[i] = i;
    }

    for(int i = 2; i <= sqrt(20000001); i++){
        if(prime_numbers[i] == 0){
            continue;
        }
        for(int j = i + i; j <= 20000001; j = j + i){
            prime_numbers[j] = 0; 
        }
    }
    for(int i = n; i <= 20000001; i++){
        if(prime_numbers[i] != 0 && pelindrome(prime_numbers[i])){
            cout << prime_numbers[i] << "\n";
            break;
        }
    }

    return 0;
}

bool pelindrome(int number){
    string num = to_string(number);
    int index = 0;
    bool is_pelindrome = true;
    int half = num.length() / 2;
    int length = num.length() - 1;
    while(index < half){
        if(num[index] != num[length - index]){
            is_pelindrome = false;
            break;
        }
        index++;
    }
    return is_pelindrome;
}