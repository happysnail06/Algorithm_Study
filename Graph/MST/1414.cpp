#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct edge{
    int start;
    int end;
    int weight;

    bool operator > (const edge &temp) const{
        return weight > temp.weight;
    }
}edge;

int n;
priority_queue<edge, vector<edge>, greater<edge>> edges;
vector<int> parent;

int find(int a);
void munion(int a, int b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    parent = vector<int>(n);

    string input;
    int total = 0;
    for(int i = 0; i < n; i++){
        cin >> input;
        for(int j = 0; j < n; j++){
            if(input[j]>= 'a' && input[j] <= 'z'){
                edges.push(edge{i, j, input[j] - 'a' + 1});
                total+=input[j] - 'a' + 1;
            }
            else if(input[j] >= 'A' && input[j] <= 'Z'){
                edges.push(edge{i, j, input[j] - 'A' + 27});
                total+=input[j] - 'A' + 27;
            }
            else{
                continue;
            }
        }
    }

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    int use = 0;
    int value = 0;
    while(!edges.empty()){
        edge now = edges.top();
        edges.pop();
        int start = now.start;
        int end = now.end;
        int weight = now.weight;
        if(find(start) != find(end)){
            munion(start, end);
            value+=weight;
            use++;
        }
    }
    if(use == n - 1){
        cout << total - value << "\n";
    }
    else{
        cout << "-1\n";
    }
    



    return 0;
}

int find(int a){
    if(parent[a] == a){
        return a;
    }
    else{
        return parent[a] = find(parent[a]);
    }
}

void munion(int a, int b){
    a = find(a);
    b = find(b);

    if(a!= b){
        parent[b] = a;
    }
}