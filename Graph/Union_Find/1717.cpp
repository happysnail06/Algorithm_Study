#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> parent;

int find(int node);
void my_union(int a, int b);
bool check(int a, int b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    parent = vector<int>(n+1);
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }

    int t, a, b;
    for(int i = 0; i < m; i++){
        cin >> t >> a >> b;
        if(t == 0){
            my_union(a, b);
        }
        else{
            if(check(a, b)){ cout << "YES\n";}
            else{cout << "NO\n";}
        }

    }

    return 0;
}

int find(int node){
    if(node == parent[node]){
        return node;
    }
    else{
        return parent[node] = find(parent[node]);
    }
}

void my_union(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        parent[b] = a;
    }
}

bool check(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b){
        return true;
    }
    else{
        return false;
    }
}