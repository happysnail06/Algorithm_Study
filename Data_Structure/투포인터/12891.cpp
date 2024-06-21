#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<int> count_char(string s){
    vector<int> result(4,0);
    for(char x : s){
        if(x == 'A'){
            result[0]++;
        }
        else if(x == 'C'){
            result[1]++;
        }
        else if(x == 'G'){
            result[2]++;
        }
        else{
            result[3]++;
        }
    }
    return result;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int s, p;
    cin >> s >> p;

    string str;
    cin >> str;

    int numa, numc, numg,numt;
    cin >> numa >> numc >> numg >> numt;

    int start = 0;
    int end = p - 1;
    int type = 0;
    string sub_str = str.substr(start, p);
    vector<int> result = count_char(sub_str);
    while(start <= s - p){
        if(result[0] >= numa && result[1] >= numc && result[2] >=  numg && result[3] >= numt){
            type++;
        }
        if(str[start] == 'A'){
            result[0]--;
        }
        else if(str[start] == 'C'){
            result[1]--;
        }
        else if(str[start] == 'G'){
            result[2]--;
        }
        else if(str[start] == 'T'){
            result[3]--;
        }
        start++;
        end++;
        if(str[end] == 'A'){
            result[0]++;
        }
        else if(str[end] == 'C'){
            result[1]++;
        }
        else if(str[end] == 'G'){
            result[2]++;
        }
        else if(str[end] == 'T'){
            result[3]++;
        }
    }
    cout << type << "\n";
        

    return 0;
}