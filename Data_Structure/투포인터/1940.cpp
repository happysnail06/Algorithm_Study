#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    int t, sum;
    int count = 0;
    int* arr = new int[n];

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    
    int start = 0;
    int end = n-1;
    while(start < end){
        sum = arr[start] + arr[end];
        if( sum== m){
            count++;
            start++;
            end--;
        }
        else if(sum > m){
            end--;
        }
        else{
            start++;
        }
    }

    cout << count << "\n";

    return 0;
}