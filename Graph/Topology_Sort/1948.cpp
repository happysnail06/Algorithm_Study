#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 위상정렬, 역방향 그래프, 임계 경로

int n, m;
vector<vector<pair<int, int>>> forward_graph;
vector<vector<pair<int, int>>> backward_graph;
vector<int> in_degree_forward;
vector<int> in_degree_backward;
int start_city, end_city, weight;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    forward_graph.resize(n+1);
    backward_graph.resize(n+1); // 역방향 그래프

    in_degree_forward = vector<int>(n+1, 0);

    for(int i = 0; i < m; i++){
        cin >> start_city >> end_city >> weight;
        forward_graph[start_city].push_back(make_pair(end_city, weight));
        backward_graph[end_city].push_back(make_pair(start_city, weight));

        in_degree_forward[end_city]++;

    }

    cin >> start_city >> end_city;

    queue<int> myQueue;
    vector<int> result(n+1, 0);
    myQueue.push(start_city);

    // 일반 위상정렬으로, 각 도시까지의 최대 시간을 계산해서 result에 저장한다.
    while(!myQueue.empty()){
        int now_node = myQueue.front();
        myQueue.pop();

        for(pair<int, int> next : forward_graph[now_node]){
            int next_city = next.first;
            in_degree_forward[next_city]--;
            if(result[next_city] < result[now_node] + next.second){
                result[next_city] = result[now_node] + next.second;
            }

            if(in_degree_forward[next_city] == 0){
                myQueue.push(next_city);
            }
        }
    }

    //역방향 위상정렬, 여기서는 진입 차수 배열을 사용하지 않는다. 임계 경로가 포함하는 어떤한 노드와 인접한 edge만 큐의 다음 후보가 되기 때문
    vector<int> visited(n+1, false);    // 중복 카운트를 피하기 위해 방문 노드를 업뎃한다.
    myQueue.push(end_city);
    visited[end_city] = true;

    int count = 0;
    while(!myQueue.empty()){
        int now_node = myQueue.front();
        myQueue.pop();

        for(pair<int, int> next : backward_graph[now_node]){
            int next_city = next.first;
            if(result[next_city] + next.second == result[now_node]){    
                count++;
                if(visited[next_city] == false){    // 이미 방문한 노드는 큐에 삽입하지 않는다.
                    visited[next_city] = true;
                    myQueue.push(next_city);
                }
            }
        }
    }

    cout << result[end_city] << "\n";
    cout  << count << "\n";

    return 0;
}