#include <iostream>
#include <string>

using namespace std;

int gcd(long a, long b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long a, b;
    cin >> a >> b;

    long number = gcd(a, b);
    while(number>0){
        cout << "1";
        number--;
    }

    return 0;
}