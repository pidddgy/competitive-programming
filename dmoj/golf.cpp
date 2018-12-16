// https://dmoj.ca/problem/ccc00s4

#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#define endl '\n'
using namespace std;

int D, N;
vector<int> clubs;
vector<int> rets;
unordered_set<int> dp;

void cuteeeeeeeeeeeeeeeeeeeeeeeeeeeee(int count = 0, int total = 0) {
    if(total == D)
        rets.push_back(count);
    else
        for(auto c: clubs) 
            if(total+c <= D)
                if(dp.find(total+c) == dp.end() || dp.empty()) {
                    dp.emplace(total+c);  
                    cuteeeeeeeeeeeeeeeeeeeeeeeeeeeee(count+1, total+c);
                }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> D >> N;

    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        clubs.push_back(a);
    }

    sort(clubs.begin(), clubs.end(), greater<int>());
    cuteeeeeeeeeeeeeeeeeeeeeeeeeeeee();

    if(rets.empty()) 
        cout << "Roberta acknowledges defeat." << endl;
    else
        cout << "Roberta wins in " << *min_element(rets.begin(), rets.end()) << " strokes." << endl;
}
