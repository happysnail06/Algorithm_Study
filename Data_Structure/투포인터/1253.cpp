#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    int t;
    vector<int> numbers;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        numbers.push_back(t);
    }
    sort(numbers.begin(), numbers.end());

    int count = 0;
    int sum;
    for(int i = 0; i < n; i++)
    {
        long target = numbers[i];
        int first = 0;
        int second = n - 1;
        while(first < second){
            sum = numbers[first] + numbers[second];
            if(sum == target){
                if(first != i && second != i){
                    count++;
                    break;
                }
                else if( first == i){
                    first++;
                }
                else if(second == i){
                    second--;
                }
            }
            else if(sum < target){
                first++;
            }
            else{
                second--;
            }
        }
    }

    cout << count << "\n";

    return 0;
}