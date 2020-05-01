// https://codeforces.com/contest/1101/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define watch(x) cerr << (#x) << " is " << (x) << endl;
// #define cerr if(false) cerr
#define maxlr (int)(2 * 1e5) + 500

struct Segment {
    int ind;
    int l;
    int r;

    Segment(int indd, int ll, int rr) {
        ind = indd;
        l = ll;
        r = rr;
    }
};

bool comp(Segment l, Segment r) {
    return l.r < r.r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<Segment> segs;
        
        for(int i = 1; i <= n; i++) {
            int l, r;
            cin >> l >> r;

            segs.emplace_back(i, l, r);
        }

        sort(segs.begin(), segs.end(), comp);

        bool found = false;
        int mil = segs[n-1].l;
        for(int i = segs.size()-2; i >= 0; i--) {
            if(segs[i].r < mil and !found) {
                int ans[n+1];
                for(int j = 0; j <= i; j++) {
                    ans[segs[j].ind] = 1;
                }

                for(int j = i+1; j < n; j++) {
                    ans[segs[j].ind] = 2;
                }

                for(int i = 1; i <= n; i++) {
                    cout << ans[i] << " ";
                }
                cout << endl;

                found = true;
            }

            mil = min(mil, segs[i].l);
        }
        if(!found) {
            cout << -1 << endl;
        }
    }
}