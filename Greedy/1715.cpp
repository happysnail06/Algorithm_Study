#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    priority_queue<int, vector<int>, greater<int> > min_heap;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        min_heap.push(t);
    }

    int sum = 0;
    while (!min_heap.empty())
    {
        if (min_heap.size() == 1)
        {
            min_heap.pop();
            break;
        }
        else
        {
            int a = min_heap.top();
            min_heap.pop();
            int b = min_heap.top();
            min_heap.pop();

            sum = sum + (a + b);
            min_heap.push(a + b);
        }
    }
    cout << sum << "\n";

    return 0;
}