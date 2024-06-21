#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int v;
vector<vector<pair<int, int>>> tree;            //책에서 pair<int,int>를 edge로 새로 정의함:
                                                    //typedef pair<int, int> edge;
                                                    // vector<vector<edge>> tree;
vector<bool> visited;
vector<int> node_distance;
int start_node, end_node, weight;
void bfs(int start);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> v;
    tree.resize(v+1);
    visited = vector<bool>(v+1, false);
    node_distance = vector<int>(v+1, 0);
    
    //tree 구성하기
    for(int i = 0; i < v; i++){
        cin >> start_node;
        cin >> end_node;
        while(end_node != -1){
            cin >> weight;
            tree[start_node].push_back(make_pair(end_node, weight));
            cin >> end_node;
        }
    }

    // 임의의 노드를 시작점으로 설정하고, 끝점을 구한 후, 그 끝점에서 다시 다른 끝점을 구하면 답이 나온다.
    bfs(1);
    int max = 1;

    // 끝점 구하기
    for(int i = 2; i <= v; i++){
        if(node_distance[max] < node_distance[i]){
            max = i;
        }
    }

    fill(node_distance.begin(), node_distance.end(), 0);
    fill(visited.begin(), visited.end(), false);

    //끝점에서 다시 bfs 수행
    bfs(max);
    sort(node_distance.begin(), node_distance.end());
    cout << node_distance[v] << "\n";


    return 0;
}

void bfs(int start){
    queue<int> myQueue;
    myQueue.push(start);
    visited[start] = true;
    
    while(!myQueue.empty()){
        int now_node = myQueue.front();
        myQueue.pop();
        // tree[now_node][i].first == 다음 노드
        for(int i = 0; i < tree[now_node].size(); i++){             //for(edge i : tree[now_node])이렇게 더 쉽게 코딩할 수 있다.
            if(visited[tree[now_node][i].first] == false){
                visited[tree[now_node][i].first] = true;    
                myQueue.push(tree[now_node][i].first);
                node_distance[tree[now_node][i].first] = node_distance[now_node] + tree[now_node][i].second;
            }
        }
    }

}