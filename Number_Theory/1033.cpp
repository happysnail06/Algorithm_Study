#include <iostream>
#include <vector>

using namespace std;


//  long을 사용해야 되는 부분이 있어서 계속 오류남

/// dfs사용해서 푼다
// 모든 수의 최소 공배수 k를 우선 구해서, k를 사용하며 각 재료의 비율을 업데이트 한다. 
// 마지막에 재료값이 최소가 되게 각 비율은 최대 공약수로 나눠준다.
struct info
{
    int material;
    int ratio_host;
    int ratio_this;

    info(int a, int b, int c) : material(a), ratio_host(b), ratio_this(c) {}
};

vector<vector<info>> relation(10);
bool visited[10];
long ratios[10];
long t_lcm = 1;

long gcd(long a, long b);
long lcm(long a, long b, long gcd);
void dfs(int node);

int n;
long m1, m2, r1, r2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> m1 >> m2 >> r1 >> r2;

        relation[m1].push_back(info(m2, r1, r2));
        relation[m2].push_back(info(m1, r2, r1));

        long gcd_of_two = gcd(r1, r2);

        t_lcm = t_lcm * lcm(r1, r2, gcd_of_two);
    }

    ratios[0] = t_lcm;
    dfs(0);
    long mgcd = ratios[0];

    for(int i = 1; i < n; i++){
        mgcd = gcd(mgcd, ratios[i]);
    }
    
    for(int i = 0; i < n; i++){
        cout << ratios[i] / mgcd << ' ';
    }

    return 0;
}

long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

long lcm(long a, long b, long gcd)
{
    return a * b / gcd;
}

void dfs(int node)
{
    visited[node] = true;
    for (info i : relation[node]){
        int next = i.material;
        if(visited[next] == false){
            ratios[next] =  ratios[node] / i.ratio_host * i.ratio_this;
            dfs(next);
        }
    }
}