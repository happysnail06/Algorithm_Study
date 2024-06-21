#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> numbers(n, 0);      
    stack<int> answer;
    // 입력을 받아서 저장한다.
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }


    //오른쪽에서 왼쪽으로 가면서 오큰수를 구한다.
    stack<int> nges;          // 오큰수를 저장하는 스택
    for(int i = n - 1; i >= 0; i--){
        if(nges.empty()){           // 가장 왼쪽에 있는 경우 스택은 비어있다.
            nges.push(numbers[i]);  // 이미 확인한 수는 스택에 푸쉬한다
            answer.push(-1);        // 가장 왼쪽에 있는 수의 오큰수는  -1이다.
        }
        else{
            while(!nges.empty() && numbers[i] >= nges.top()){   //오른쪽으로 가면서, 스택에서 현재 숫자의 오큰수를 찾을 때까지 pop한다.
                nges.pop();                                     
            }
            if(nges.empty()){           //스택이 비어있다면 현재 숫자가 가장 큰 수이다.
                nges.push(numbers[i]);  //스택에 현재 숫자 추가
                answer.push(-1);        //현재 숫자의 오큰수 추가.
            }
            else{
                answer.push(nges.top());   //비어있지 않으면 오큰수를 찾았다는 뜻이고, 해당 숫자를 answer에 추가해준다.
                nges.push(numbers[i]);
            }
        }
    }

    while(!answer.empty()){
        cout << answer.top() << " ";
        answer.pop();
    }

    return 0;
}