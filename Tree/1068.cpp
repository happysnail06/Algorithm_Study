#include <iostream>
#include <vector>

using namespace std;

int n, parent, removed, root;
static int number;
vector<vector<int>> tree;
void dfs(int node);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    tree.resize(n);
    number = 0;
    for(int i = 0; i < n; i++){
        cin >> parent;
        if(parent == -1){
            root = i;
        }
        else{
            tree[parent].push_back(i);
        }
    }
    cin >> removed;
    tree[removed].clear();
    dfs(root);
    cout << number<< "\n";

    return 0;
}

void dfs(int node){
    if(node == removed){
        return;
    }
    for(auto it = tree[node].begin(); it != tree[node].end(); it++){
        if(*it == removed){
            tree[node].erase(it);
            break;
        }
    }
    if(tree[node].empty()){
        number++;
        return;
    }
    for(int i : tree[node]){
        dfs(i);
    }
}