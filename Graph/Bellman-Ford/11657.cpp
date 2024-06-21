#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#define inf numeric_limits<long>::max()

using namespace std;

typedef tuple<int, int, int> edge;
vector<edge> edges;
vector<long> distances;

int n, m;
int start_, end_, weight;
bool has_negative = false;

void bellman_ford(int node);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    distances = vector<long>(n + 1, inf);

    for (int i = 0; i < m; i++)
    {
        cin >> start_ >> end_ >> weight;
        edges.push_back(make_tuple(start_, end_, weight));
    }

    bellman_ford(1);
    
    if(has_negative){
        cout << "-1\n";
    }
    else{
        for(int i = 2; i <= n; i++){
            if (distances[i] == inf)
            {
                cout << "-1\n";
            }
            else{
                cout << distances[i] << "\n";
            }
            
        }
    }

    return 0;
}

void bellman_ford(int node)
{
    distances[node] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            edge now = edges[j];
            int start = get<0>(now);
            int end = get<1>(now);
            int weight = get<2>(now);

            if (distances[start] != inf && distances[end] > distances[start] + weight)
            {
                distances[end] = distances[start] + weight;
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        edge now = edges[j];
        int start = get<0>(now);
        int end = get<1>(now);
        int weight = get<2>(now);

        if (distances[start] != inf && distances[end] > distances[start] + weight)
        {
            has_negative = true;
        }
    }
}