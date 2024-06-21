#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> Node;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<Node> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i].first;
        numbers[i].second = i;
    }

    sort(numbers.begin(), numbers.end());
    int max_diff = 0;
    for(int i = 0; i < n; i++){
        int diff = numbers[i].second - i;
        if(max_diff < diff){max_diff = diff;}
    }
    cout << max_diff + 1 << "\n";

    return 0;
}