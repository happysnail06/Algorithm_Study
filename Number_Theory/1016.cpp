#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long min, max;
    cin >> min >> max;

    vector<bool> numbers(max - min + 1);

    for(long i = 2; i * i <= max; i++){
        long power = i * i;
        long start_index = min / power;

        if(min % power != 0){
            start_index++;
        }
        for(long j = start_index; j * power <= max; j++){
            numbers[(int)((j*power) - min)] = true;
        }
    }
    int count = 0;
    for(int i = 0; i < numbers.size(); i++){
        if(!numbers[i]){
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}