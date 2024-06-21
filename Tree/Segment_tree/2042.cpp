#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// segment tree
// 알아야 될 것: tree size, 입력 start index, tree 초기 값 채우는 거, 

long n, m, k;
int height = 0;
vector<long> tree;

void update(int b, long c);
long get_sum(int b, int c);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    long temp = 1;
    while(temp < n){
        temp*=2;
        height++;
    }

    temp = pow(2, height+1);
    tree = vector<long>(temp+1, 0);
    int start_index = pow(2, height);
    for(int i = 0; i < n; i++){
        cin >> tree[start_index + i];
    }

    // 배열 채우기
    for(int i = start_index - 1; i > 0; i--){
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    long a, b, c;
    for(int i = 0; i < m + k; i++){
        cin >> a >> b >> c;
        if(a == 1){
            update(b, c);
        }
        else{
            long result = get_sum(b, c);
            cout << result << "\n";
        }
    }

    return 0;
}

void update(int b, long c){
    int seg_b = b + pow(2, height) - 1;
    long diff = c - tree[seg_b];
    while(seg_b > 0){
        tree[seg_b] = tree[seg_b] + diff;
        seg_b/=2;
    }
}

long get_sum(int b, int c){
    int seg_b = b + pow(2, height) - 1;
    int seg_c = c + pow(2, height) - 1;
    long result = 0;
    while(seg_b <= seg_c){
        if(seg_b % 2 == 1){
            result+=tree[seg_b];
        }
        if(seg_c % 2 == 0){
            result+=tree[seg_c];
        }
        seg_b = (seg_b+1) / 2;
        seg_c = (seg_c-1) / 2;
    }
    return result;
}