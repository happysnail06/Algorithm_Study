#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge_sort(int start, int end);
vector<int> numbers;
vector<int> temp;
static long result;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    numbers = vector<int>(n+1, 0);
    temp = vector<int>(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> numbers[i];
    }

    result = 0;
    merge_sort(1, n);
    cout << result << "\n";

    return 0;
}

void merge_sort(int start, int end){
    if(end - start < 1){
        return;
    }

    int middle = start + (end - start) / 2;

    merge_sort(start, middle);
    merge_sort(middle+1, end);

    for(int i = start; i <= end; i++){
        temp[i] = numbers[i];
    }

    int k = start;
    int index1 = start;
    int index2 = middle+1;

    while(index1 <= middle && index2 <= end){
        if(temp[index1] > temp[index2]){
            numbers[k] = temp[index2];
            result = result + (index2 - k);
            k++;
            index2++;
        }
        else{
            numbers[k] = temp[index1];
            index1++;
            k++;
        }
    }
    while(index1 <= middle){
        numbers[k] = temp[index1];
        k++;
        index1++;
    }
    while(index2 <= end){
        numbers[k] = temp[index2];
        k++;
        index2++;
    }
}