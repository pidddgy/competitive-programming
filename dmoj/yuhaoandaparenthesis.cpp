// http://codeforces.com/contest/1097/problem/C

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    unordered_multiset<int> aqt;
    unordered_set<string> seen;
    unordered_set<int> used;

    int zero = 0;
    for(int i = 0; i < N; i++) {
        string cute;
        cin >> cute;
        int bqt = 0;

        for(auto chr: cute) {
            if(chr == '(') bqt++;
            if(chr == ')') bqt--;
        }

        if(seen.find(cute) == seen.end()) {
            aqt.insert(bqt);
            seen.insert(cute);
        }

        if(bqt == 0) zero++;
    }

    int ret = 0;
    ret += (zero * (zero-1)) / 2;
    for(auto itr = aqt.begin(); itr != aqt.end(); itr++) {
        int v = *itr;
        if(aqt.find(v * -1) != aqt.end() && used.find(v*-1) == used.end() && v != 0) {
            ret+= aqt.count(v*-1);
        }
        used.insert(v);
    }

    cout << ret << "\n";
}
