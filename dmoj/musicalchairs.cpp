// https://dmoj.ca/problem/dmpg18g1

#include <bits/stdc++.h>
#define MAXINT 2147483647
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

vector<int> stu[1000005];
int main() {
    int N, K;
    cin >> N >> K;

    int empcnt = K;
    
    for(int i = 1; i <= N; i++) {
        stu[i].push_back(MAXINT);
    }

    for(int i = 1; i <= K; i++) {
        int a;
        cin >> a;
        
        stu[a].pop_back();
    }

    for(int i = 1; i <= K+1; i++) {
        int a;
        cin >> a;

        if(stu[a].empty()) empcnt--;
        stu[a].push_back(i);
    }


    stack<int> S;
    int i = 0;

    while(empcnt > 0) {
        i++;
        if(i == N+1) i = 1;

        if(!stu[i].empty()) {
            while(!stu[i].empty()) {
                S.push(stu[i].back());
                stu[i].pop_back();
            }
            empcnt++;
        }

        if(stu[i].empty() && !S.empty()) {
            stu[i].push_back(S.top());
            S.pop();
            empcnt--;
        }
    }

    cout << S.top() << endl;
}