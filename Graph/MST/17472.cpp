#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

// MST문제, 처음에 섬을 분리하는 것이 제일 어려움, bfs로 해야 정확하고 시간초과가 안난다.

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

typedef struct edge
{
    int start;
    int end;
    int weight;

    bool operator>(const edge &temp) const
    {
        return weight > temp.weight;
    }
} edge;


vector<int> parent;
priority_queue<edge, vector<edge>, greater<edge>> edges;
vector<vector<int>> graph;
set<int> node;
int sNum = 1;

int find(int a);
void munion(int a, int b);
void BFS(int i, int j);
static bool visited[101][101] = {
    false,
};

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    edge temp{5, 5, 3};
    
    cin >> n >> m;
    graph = vector<vector<int>>(n, vector<int>(m, 0));

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    { // 각 자리에서 BFS 탐색을 이용하여 섬들을 분리하여 줍니다.
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] != 0 && visited[i][j] != true)
            {
                BFS(i, j);
                sNum++;
            }
        }
    }

    ////// edge를 추가하는 과정, 수평, 수직으로 탐색////
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] != 0)
            {
                int start = graph[i][j];
                int count = 0;
                int k = j + 1;
                while (k < m && graph[i][k] != start && graph[i][k] == 0)
                {
                    count++;
                    k++;
                }
                if (k < m && graph[i][k] != 0 && graph[i][k] != start && count >= 2)
                {
                    edges.push(edge{start, graph[i][k], count});
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[j][i] != 0)
            {
                int start = graph[j][i];
                int count = 0;
                int k = j + 1;
                while (k < n && graph[k][i] != start && graph[k][i] == 0)
                {
                    count++;
                    k++;
                }

                if (k < n && graph[k][i] != 0 && graph[k][i] != start && count >= 2)
                {
                    edges.push(edge{start, graph[k][i], count});
                }
            }
        }
    }
    ////// edge를 추가하는 과정, 수평, 수직으로 탐색////

    // parent배열 초기화
    parent = vector<int>(sNum + 1, 0);
    for (int i = 1; i <= sNum; i++)
    {
        parent[i] = i;
    }

    // MST알고리즘
    int use = 0;
    int value = 0;
    while (!edges.empty())
    {
        edge now = edges.top();
        edges.pop();
        if (find(now.start) != find(now.end))
        {
            munion(now.start, now.end);
            value += now.weight;
            use++;
        }
    }

    if (use == sNum - 2)
    {
        cout << value << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}

int find(int a)
{
    if (a == parent[a])
    {
        return a;
    }
    else
    {
        return parent[a] = find(parent[a]);
    }
}

void munion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        parent[b] = a;
    }
}

void BFS(int i, int j)
{ // BFS를 통하여 연결된 섬을 찾아줍니다.
    queue<pair<int, int>> myQueue;
    myQueue.push(make_pair(i, j));
    visited[i][j] = true;
    graph[i][j] = sNum;

    while (!myQueue.empty())
    {
        pair<int, int> now = myQueue.front();

        myQueue.pop();
        int x = now.first;
        int y = now.second;

        for (int d = 0; d < 4; d++)
        {
            int next_x = x + dx[d];
            int next_y = y + dy[d];
            while (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)  // 주의, 범위 안에 있을 때만 
            {
                if (visited[next_x][next_y] == false && graph[next_x][next_y] != 0)
                {
                    visited[next_x][next_y] = true;
                    graph[next_x][next_y] = sNum;
                    myQueue.push(make_pair(next_x, next_y));
                }
                else
                {
                    break;
                }
            }
        }
    }
}