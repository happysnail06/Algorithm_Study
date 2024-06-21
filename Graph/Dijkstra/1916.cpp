#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#define inf numeric_limits<int>::max()

using namespace std;


int n, m;
int start_, end_, weight;
typedef pair<int, int> edge;
vector<vector<edge>> graph;
vector<bool> visited;
vector<int> distances;

void dijkstra(int node);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    graph.resize(n+1);
    visited = vector<bool>(n+1, false);
    distances = vector<int>(n+1, inf);

    for(int i = 0; i < m; i++){
        cin >> start_ >> end_ >> weight;
        graph[start_].push_back(make_pair(end_, weight));
    }
    cin >> start_ >> end_;

    dijkstra(start_);
    cout << distances[end_] << "\n";




    return 0;
}

void dijkstra(int node){
    priority_queue<edge, vector<edge>, greater<edge>> myQueue;
    myQueue.push(make_pair(0, node));
    distances[node] = 0;

    while(!myQueue.empty()){
        pair<int, int> now_node = myQueue.top();
        myQueue.pop();
        int now_city = now_node.second;

        if(!visited[now_city]){     // 방문 여부를 먼저 확인
            visited[now_city] = true;
            for(edge next : graph[now_city]){

                int next_city = next.first;
                int d = next.second;
                distances[next_city] = min(distances[next_city], distances[now_city] + d);
                myQueue.push(make_pair(distances[next_city], next_city));   // 가장 가까운 거리를 push
            }
        }
    }
}