#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct edge{
    int start_;
    int end_;
    int weight;

    bool operator > (const edge &temp) const{
        return weight > temp.weight;
    }
}edge;

int find(int a);
void my_union(int a, int b);
void mst();
int value = 0;

vector<int> parent;
int v, e;
priority_queue<edge, vector<edge>, greater<edge>> edges;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> v >> e;
    parent = vector<int>(v+1, 0);
    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }

    int st, ed, w;
    for(int i = 0; i < e; i++){
        cin >> st >> ed >> w;
        edges.push(edge{st, ed, w});
    }

    mst();
    cout << value << "\n";

    return 0;
}

int find(int a){
    if(parent[a] == a){
        return a;
    }
    else{
        int b = parent[a];
        return parent[a] = find(b);
    }
}

void my_union(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        parent[b] = a;
    }
}

void mst(){
    int count = 0;

    while(count != v-1){
        edge now = edges.top();
        edges.pop();

        if(find(now.start_) != find(now.end_)){
            my_union(now.start_, now.end_);
            count++;
            value+=now.weight;
        }
    }
}