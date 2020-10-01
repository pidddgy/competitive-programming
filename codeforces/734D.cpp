// https://codeforces.com/contest/734/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second
int X0, Y0;

struct piece {
    int x, y;
    char type;

    piece(int xx, int yy, char typee) {
        x = xx;
        y = yy;
        type = typee;
    }
};

struct Compare {
    bool operator()(piece l, piece r) {
        int ldis = abs(l.x-X0) + abs(l.y-Y0);
        int rdis = abs(r.x-X0) + abs(r.y-Y0);

        return ldis < rdis;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cin >> X0 >> Y0;

    vector<piece> up, down, left, right, tl, tr, bl, br;
    for(int i = 1; i <= n; i++) {
        char type;
        cin >> type;
        int x, y;
        cin >> x >> y;

        if(x == X0) {
            if(y > Y0) {
                up.emplace_back(x, y, type);
            } else if(y < Y0) {
                down.emplace_back(x, y, type);
            }
        }

        if(y == Y0) {
            if(x > X0) {
                right.emplace_back(x, y, type);
            } else {
                left.emplace_back(x, y, type);
            }
        }

        if(abs(x-X0) == abs(y-Y0)) {
            if(x > X0) {
                if(y > Y0) {
                    tr.emplace_back(x, y, type);
                } else {
                    br.emplace_back(x, y, type);
                }
            } else if(x < X0) {
                if(y > Y0) {
                    tl.emplace_back(x, y, type);
                } else {
                    bl.emplace_back(x, y, type);
                }
            }
        }
    }


    sort(up.begin(), up.end(), Compare());
    sort(down.begin(), down.end(), Compare());
    sort(left.begin(), left.end(), Compare());
    sort(right.begin(), right.end(), Compare());
    sort(tl.begin(), tl.end(), Compare());
    sort(tr.begin(), tr.end(), Compare());
    sort(bl.begin(), bl.end(), Compare());
    sort(br.begin(), br.end(), Compare());

    // for(piece x: tl) {
    //     cout << x.x << " " << x.y << " " << x.type << endl;
    // }

    // watch(tr.size())
    string ans = "NO";
    for(vector<piece> x: vector<vector<piece>>({up, down, left, right})) {
        if(x.size()) {
            if(x[0].type == 'R' or x[0].type == 'Q') ans = "YES";
        }
    }

    for(vector<piece> x: vector<vector<piece>>({tl, tr, bl, br})) {
        if(x.size()) {
            if(x[0].type == 'B' or x[0].type == 'Q') ans = "YES";
        }
    }

    cout << ans << endl;




}