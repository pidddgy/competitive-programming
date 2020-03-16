// https://dmoj.ca/problem/wac3p4
// orz chadliam
#include <bits/stdc++.h>
using namespace std;

int disj[100000];


int main() {
    int N, Q;
    cin >> N >> Q;

    int deg[N+1];
    for(int i = 1; i <= N; i++) {
        deg[i] = 0;
    }

    vector<int> G[N+1];
    set<int> nonzero;
    for(int shit = 1; shit <= Q; shit++) {
        int a, b, x;
        cin >> a >> b >> x;

        deg[a] += x;
        deg[b] += x;

        G[a].emplace_back(b);
        G[b].emplace_back(a);

        int odd = 0;
        for(int i = 1; i <= N; i++) {
            if(deg[i] % 2 == 1) {
                odd++;
            }
        }

        bool good = false;
        if(shit == 1) {
            nonzero.emplace(a);
            nonzero.emplace(b);
            good = true;
        } else {
            for(int x: G[a]) {
                if(nonzero.find(x) != nonzero.end()) {
                    nonzero.emplace(a);
                    nonzero.emplace(b);
                    good = true;
                }
            }

            for(int x: G[b]) {
                if(nonzero.find(x) != nonzero.end()) {
                    nonzero.emplace(a);
                    nonzero.emplace(b);
                    good = true;
                }
            }
        }

        if((odd == 2 or odd == 0) and good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}