#include <iostream>
#include <vector>

using namespace std;

int find(int node);
void my_union(int a, int b);

int n, m, k;
vector<int>parent;
vector<int> told_truth;
vector<vector<int>> party_record;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    parent = vector<int>(n+1);
    party_record.resize(m+1); 

    // parent  초기화
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    // 아는 사람수
    cin >> k;

    int t;
    for(int i = 0; i < k; i++){
        cin >> t;
        told_truth.push_back(t);
    }
    int num_come_party;
    for(int i = 1; i <= m; i++){
        cin >> num_come_party;
        for(int j = 1; j <= num_come_party; j++){
            cin >> t;
            party_record[i].push_back(t);
        }
    }

    for(int i = 1; i <= m; i++){
        int first_person = party_record[i][0];
        for(int j = 1; j < party_record[i].size(); j++){
            my_union(first_person, party_record[i][j]);
        }
    }

    int count = 0;
    for(int i = 1; i <= m; i++){
        bool can_tell_lie = true;
        int first_person = party_record[i][0];
        for(int j = 0; j < told_truth.size(); j++){
            if(find(first_person) == find(told_truth[j])){
                can_tell_lie = false;
                break;
            }
        }
        if(can_tell_lie){
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}

int find(int node){
    if(parent[node] == node){
        return node;
    }
    else{
        return parent[node] = find(parent[node]);
    }
}

void my_union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        parent[b] = a;
    }
}