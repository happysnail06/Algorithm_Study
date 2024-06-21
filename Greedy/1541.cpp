#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

string formula;

// string split 함수
vector<string> split(const string &s, char delimiter){
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while(getline(tokenStream, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> formula;

    vector<int> operands;       // 파트별 합 저장소
    vector<string> parts = split(formula, '-');     //"=" 기준으로  split

    for(int i = 0 ; i < parts.size(); i++){
        vector<string> numbers = split(parts[i], '+');      // 합을 구할 때 사용되는 숫자를 얻기 위해 '+'기준 split
        int sum = 0;
        for(int j = 0; j < numbers.size(); j++){
            sum+=stoi(numbers[j]);
        }
        operands.push_back(sum);        // 각 파트 합 저장
    }

    int ans = operands[0];  
    if(operands.size()>1){          // 크기가 1 이상일 경우
        for(int i = 1; i < operands.size(); i++){
            ans-=operands[i];
        }
    }
    cout << ans << "\n";

    return 0;
}