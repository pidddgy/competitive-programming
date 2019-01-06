// http://codeforces.com/contest/1095/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int> Q;
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < 31; i++) {
        if((N & (1 << i))) {
            Q.push(i);
        }
    }

    if(Q.size() > K) {
        cout << "NO" << endl;
        return 0;
    }
    
    while(Q.size() < K && Q.top() > 0) {
        int v = Q.top();
        Q.pop();
        Q.push(v-1);
        Q.push(v-1);
    }

    if(Q.size() == K) {
        cout << "YES" << endl;
        while(!Q.empty()) {
            cout << (1<<(int)Q.top()) << " ";
            Q.pop();
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
