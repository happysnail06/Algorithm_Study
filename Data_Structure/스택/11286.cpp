#include <iostream>
#include <deque>
#include <queue>

using namespace std;

class CustomHeap {
public:
    void push(int num) {
        min_heap.push(num);
    }

    int pop() {
        int num = min_heap.top();
        min_heap.pop();
        return num;
    }

    int top() {
        return min_heap.top();
    }
    bool empty(){
        return min_heap.empty();
    }

private:
    struct Compare {
        bool operator()(int a, int b) {
            int abs_a = abs(a);
            int abs_b = abs(b);
            if (abs_a == abs_b) {
                return a > b;
            }
            return abs_a > abs_b; 
        }
    };

    priority_queue<int, vector<int>, Compare> min_heap;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n;

    CustomHeap numbers;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t == 0)
        {
            if (numbers.empty())
            {
                cout << 0 << "\n";
            }
            else    
            {
                cout << numbers.top() << "\n";
                numbers.pop();
            }
        }
        else
        {
            numbers.push(t);
        }
    }

    return 0;
}