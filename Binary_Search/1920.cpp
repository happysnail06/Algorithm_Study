#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t;
vector<int> numbers;
bool present = false;
bool binary_search(int start, int end, int num);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    numbers = vector<int>(n, 0);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> t;
        present = binary_search(0, n-1, t);
        if(present){cout << "1\n";}
        else{
            cout << "0\n";
        }
    }

    return 0;
}

bool binary_search(int start, int end, int num){
    if(start > end){
        return false;
    }
    int mid = (start + end) / 2;
    if(numbers[mid] == num){
        return true;
    }
    if(num > numbers[mid]){
        return binary_search(mid+1, end, num);
    } 
    else{
        return binary_search(start, mid-1, num);
    }
}