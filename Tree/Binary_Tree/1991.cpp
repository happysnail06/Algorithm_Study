#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> tree;
vector<bool> visited;


void preorder(int node);
void inorder(int node);
void postorder(int node);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    tree.resize(n+1);
    visited.resize(n+1, false);
    for(int i = 0; i < n; i++){
        char parent, left, right;
        cin >> parent >> left >> right;
        if(left != '.'){
            tree[parent - 'A' + 1].push_back(left - 'A' + 1);
        }
        else{
            tree[parent - 'A' + 1].push_back(-1);
        }
        if(right != '.'){
            tree[parent - 'A' + 1].push_back(right - 'A' + 1);
        }
        else{
            tree[parent - 'A' + 1].push_back(-1);
        }
        
    }

    preorder(1);
    fill(visited.begin(), visited.end(), false);
    cout << "\n";
    inorder(1);
    cout << "\n";
    //postorder();
    postorder(1);



    return 0;
}

void preorder(int node){
    if(node == -1){
        return;
    }
    cout << char(node - 1 + 'A');
    preorder(tree[node][0]);
    preorder(tree[node][1]);

}

void inorder(int node){
    if(node == -1){
        return;
    }
    inorder(tree[node][0]);
    cout << char(node - 1 + 'A');
    inorder(tree[node][1]);
}

void postorder(int node){
    if(node == -1){
        return;
    }
    postorder(tree[node][0]);
    postorder(tree[node][1]);
    cout << char(node - 1 + 'A');
}
