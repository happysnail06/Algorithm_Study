#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

int n, m, k;
int height = 0;
vector<long> tree;

long MOD = 1000000007;

void update(long a, long b);
long get_product(long a, long b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    
    long temp = n;
    while(temp != 0){
        temp/=2;
        height++;
    }

    int tree_size = pow(2, height+1);
    int start_index = pow(2, height);
    int pad = start_index - 1;
    tree = vector<long>(tree_size, 1);
    for(int i = 0; i < n; i++){
        cin >> tree[i+start_index];
    }

    for(int i = pad; i > 0; i--){
        tree[i] = tree[i * 2 + 1] * tree[i * 2] % MOD;
    }

    long a, b;
    for(int i = 0; i < m + k; i++){
        cin >> temp >> a >> b;
        a+=pad;
        if(temp == 1){
            update(a, b);
        }
        else{
            b+=pad;
            long result = get_product(a, b);
            cout << result << "\n";
        }
    }

    return 0;
}

void update(long a, long b){
    tree[a] = b;
    while(a > 1){
        a/=2;
        tree[a] = tree[a * 2] % MOD * tree[a * 2 + 1] % MOD;
    }
}

long get_product(long a, long b){
    long result = 1;
    while(a <= b){
        if(a % 2 == 1){
            result = result * tree[a] % MOD;
            a++;
        }
        if(b % 2 == 0){
            result = result * tree[b] % MOD;
            b--;
        }
        a/=2;
        b/=2;
    }
    return result;
}