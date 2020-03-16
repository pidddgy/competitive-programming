// http://codeforces.com/contest/1169/problem/B

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A[M+1];

    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        A[i].emplace_back(a);
        A[i].emplace_back(b);

        sort(A[i].begin(), A[i].end());
    }

    vector<int> cur = A[1];
    vector<int> second;
    bool usedSecond = false;

    for(int i = 2; i <= M; i++) {
        vector<int> inter;
        vector<int> two;
        set_intersection(cur.begin(), cur.end(), A[i].begin(), A[i].end(), back_inserter(inter));
        set_intersection(cur.begin(), cur.end(), A[i].begin(), A[i].end(), back_inserter(two));

        if(!usedSecond) {
            if(inter.size() == 0) {
                for(auto a: A[i]) {
                    two.emplace_back(a);
                    usedSecond = true;
                }
            } else {
                cur = inter;
            }
        } else {
            if(inter.size() == 0 && two.size() == 0) {
                cout << "NO" << endl;
                return 0;
            } else {
                cur = inter;
                second = two;
            }
        }
    }

    cout << "YES" << endl;

}

