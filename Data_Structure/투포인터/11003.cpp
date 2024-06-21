#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
typedef pair<int, int> Node;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, l;
    cin >> n >> l;

    deque<Node> numbers;
    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        while(numbers.size() && numbers.back().second > t){
            numbers.pop_back();
        }
        numbers.push_back(Node(i, t));
        if(numbers.front().first <= i - l){
            numbers.pop_front();
        }
        cout << numbers.front().second << " ";
    }

    return 0;
}