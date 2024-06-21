#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, t;
    cin >> n;

    stack<int> numbers;
    numbers.push(0);
    queue<char> answer;
    
    int count = 1;
    bool can = true;
    for(int i = 1; i <= n; i++){
        cin >> t;
        while(numbers.top() != t && count <= n){
            numbers.push(count);
            answer.push('+');
            count++;
        }
        if(count > n+1) {can = false; break;}
        else{
            if(numbers.top() != t){
                can = false; break;
            }
            numbers.pop();
            answer.push('-');
        }

    }
    if(can){
        while(!answer.empty()){
            cout << answer.front() << " ";
            answer.pop();
        }
    }
    else{
        cout << "NO\n";
    }

    return 0;
}