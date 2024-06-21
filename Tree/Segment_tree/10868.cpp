#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

int n, m;
vector<int> tree;
int pad;
int height = 0;

int get_min(int a, int b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    int temp = n;
    while(temp != 0){
        temp/=2;
        height++;
    }
    int start_index = pow(2, height);
    int tree_size = pow(2, height+1);
    tree = vector<int>(tree_size, INT_MAX);
    for(int i = 0; i < n; i++){
        cin >> tree[i+start_index];
    }
    for(int i = start_index - 1;i > 0; i--){
        tree[i] = min(tree[i*2+1], tree[i*2]);
    }
    
    pad = start_index - 1;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a = a + pad;
        b = b + pad;
        int result = get_min(a, b);
        cout << result << "\n";
    }

    return 0;
}

int get_min(int a, int b){
    int Min = INT_MAX;
    while(a <= b){
        if(a % 2 == 1){
            if(tree[a] < Min){
                Min = tree[a];
            }
            a++;
        }
        if(b % 2 == 0){
            if(tree[b] < Min){
                Min = tree[b];
            }
            b--;
        }
        a = a / 2; 
        b = b / 2;
    }
    return Min;
}