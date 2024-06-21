#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int t;
    vector<int> numbers(10001, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        numbers[t]++;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != 0)
        {
            for (int j = 0; j < numbers[i]; j++)
            {
                cout << i << "\n";
            }
        }
    }

    return 0;
}