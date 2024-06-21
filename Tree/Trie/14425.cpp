#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

map<string, int> dict;
string str;
int n, m;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        dict.insert({str, 1});
    }
    
    int count = 0;
    for(int i = 0; i < m; i++){
        cin >> str;
        if(dict.find(str) != dict.end()){
            count++;
        }
    }
    cout << count << "\n";



    return 0;
}