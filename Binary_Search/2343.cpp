#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t;
int m;
int high = 0;
int low = 0;
vector<int> sizes;
int binary_search(int low, int high, int k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    sizes = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        sizes[i] = t;
        if (t > low)
        {
            low = t;
        }
        high += t;
    }

    int ans = binary_search(low, high, m);
    cout << ans << "\n";
    return 0;
}

int binary_search(int start, int end, int k)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + sizes[i] > mid)
            {
                count++;
                sum = 0;
            }
            sum = sum + sizes[i];
        }
        if (sum != 0)
        {
            count++;
        }
        if (count > k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return start;
}