#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<pair<int, int>> meetings;

    int start, end;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        meetings.push_back(make_pair(end, start));
    }

    sort(meetings.begin(), meetings.end());

    int count = 0;
    int end_time = -1;
    for (int i = 0; i < n; i++)
    {
        if (meetings[i].second >= end_time)
        {
            end_time = meetings[i].first;
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}