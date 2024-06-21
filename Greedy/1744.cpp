#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    priority_queue<int, vector<int>, less<int>> positive;       //max_heap      양수
    priority_queue<int, vector<int>, greater<int>> negative;    //min_heap      음수

    int t;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(t == 1){     // 1이면 바로 결과값에 더한다.
            sum+=1;
        }
        else if(t > 0){ positive.push(t); }     //양수 저장
        else if(t <= 0 ){ negative.push(t); }   // 음수저장 
    }

    // 양수를 2개씩 곱해서 더한다, 배열에는 결국 1개 또는 0개의 숫자가 남는다.
    while(positive.size() != 1 && !positive.empty()){
        int a = positive.top();
        positive.pop();
        int b = positive.top();
        positive.pop();
        sum = sum + a*b;
    }

    // 음수를 2개씩 곱해서 더한다, 배열에는 결국 1개 또는 0개의 숫자가 남는다.
    // 0도 존재하니 음수 1개와 0이 남을 경우, 결국에는 둘이 곱해져서 0이됨
    while(negative.size() != 1 && !negative.empty()){
        int a = negative.top();
        negative.pop();
        int b = negative.top();
        negative.pop();
        sum = sum + a*b;
    }

    //마지막 숫자 처리
    if(!positive.empty()){sum = sum + positive.top();}
    if(!negative.empty()){sum = sum + negative.top();}

    cout << sum << "\n";

    return 0;
}