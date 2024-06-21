#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int> &numbers, int start, int end){
    if(start+1 == end){
        if(numbers[start] > numbers[end]){
            swap(numbers[start], numbers[end]);
        }
        return end;
    }

    int middle = (start + end) / 2;
    swap(numbers[start], numbers[middle]);
    int pivot = numbers[start];
    int right = start + 1;
    int left = end;

    while(right <= left){
        while (right >= start+1 && pivot < numbers[left]){
            left--;
        }
        while(right <= end && pivot > numbers[right]){
            right++;
        }
        if(right < left){
            swap(numbers[right++], numbers[left--]);
        }
        else{
            break;
        }
    }
    numbers[start] = numbers[left];
    numbers[left] = pivot;
    return left;
}

void quickSort(vector<int> &numbers, int start, int end, int k){
    int pivot = partition(numbers, start, end);
    if(pivot == k){
        return;
    }
    else if (k < pivot){
        quickSort(numbers, start, pivot-1, k);
    }
    else{
        quickSort(numbers, pivot+1, end, k);
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> numbers(n, 0);

    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }

    quickSort(numbers, 0, n-1, k-1);
    cout << numbers[k-1];

    return 0;
}