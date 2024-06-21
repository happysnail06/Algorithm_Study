#include <iostream>

using namespace std;

int t, a, b;
int gcd(int x, int y);

int gcd_book(int x, int y){
    if(y == 0){
        return x;
    }
    else{
        return gcd_book(y, x%y);            //여기서 어차피 순서가 변해서 대소 비교할  필요가 없다.
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        cout << a * b / gcd_book(a, b) << "\n";
    } 

    return 0;
}

int gcd(int big, int small){
    if(big % small == 0){
        return small;
    }
    int remainder = big % small;
    if(remainder >= small){
        return gcd(remainder, small);
    }
    else{
        return gcd(small, remainder);
    }
}

