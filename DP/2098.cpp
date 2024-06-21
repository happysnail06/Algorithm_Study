#include <iostream>

// Traveling Salesman 외판원 순회

// bit pattern을 사용한다.
// v & (1 << i) == 0는 i 번째 자리를 확인해서 0일 경우 i번째 도시를 방문한 적 없다는 걸 의미함
// v | (1 << i) i번째 bit를 1로 만들어서 방문기록을 저장함


using namespace std;

int INF = 1000000000;                               // INT_MAX쓰면 오버플로우 뜸.
int w[16][16];  
int d[16][1<<16];
int n;
int tsp(int s, int v);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> w[i][j];
        }
    }

    cout << tsp(0, 1) << "\n";                      // 0번째 도시부터 시작, n이 4일 경우 방문기록은 0001에서 시작

    return 0;
}

int tsp(int s, int v){
    if(v == (1 << n) - 1){                         // 모든 도시를 방문한 경우
        return w[s][0] == 0 ? INF : w[s][0];    // 현재도시에서 출발도시로 돌아갈 수 없으면 INT_MAX
    }
    if(d[s][v] != 0){                               // 이미 계산된 경우
        return d[s][v];                             // Memoization
    }

    int min_cost = INF;
    for(int i = 0; i < n; i++){
        if(w[s][i] != 0 && ((v & (1 << i)) == 0)){                            // 길이 있고, 방문한 적이 없는 경우
            min_cost = min(min_cost, tsp(i, (v | (1 << i))) + w[s][i]);       // 재귀적으로 계산
        }
    }
    d[s][v] = min_cost;
    return d[s][v];
}