// https://dmoj.ca/problem/dmopc16c2p2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a[M+1]; // contents of class i
    vector<int> b[N+1]; // all classes person i is in
    bool in[N+1]; fill(in, in+N+1, false);

    for(int i = 1; i <= M; i++) {
        int k;
        cin >> k;

        while(k--) {
            int c;
            cin >> c;

            a[i].emplace_back(c);
            b[c].emplace_back(i);
        }
    }

    queue<int> Q;
    Q.push(1);
    in[1] = true;

    while(!Q.empty()) {
        int S = Q.front();
        Q.pop();

        for(auto cla: b[S]) {
            for(auto per: a[cla]) {
                if(!in[per]) {
                    Q.push(per);
                    in[per] = true;
                }
            }
        }
    }

    vector<int> ret;
    for(int x = 1; x <= N; x++) {
        if(in[x]) {
            ret.emplace_back(x);
        }
    }

    cout << ret.size() << endl;
    for(auto x: ret) cout << x << " ";

    cout << endl;
}
