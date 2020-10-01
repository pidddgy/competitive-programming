// https://codeforces.com/contest/978/problem/G

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr

const int maxn = 105;
int prepped[maxn];
int need[maxn];

struct exam {
    int day, need, index;

    exam(int dayy, int needd, int indexx) {
        day = dayy;
        need = needd;
        index = indexx;
    }
};

bool comp(exam &l, exam &r) {
    if(prepped[l.day] < need[l.day] != prepped[r.day] < need[r.day]) {
        return prepped[l.day] < need[l.day];
    }

    if(l.day != r.day) return l.day < r.day;
    return prepped[l.day] < prepped[r.day];
}

vector<exam> cur;
vector<exam> a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        prepped[i] = INT_MAX;
    }

    for(int i = 1; i <= m; i++) {
        int s, d, c;
        cin >> s >> d >> c;

        a[s].emplace_back(exam(d, c, i));
        need[d] = c;
        prepped[d] = 0;
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        watch(i)
        for(exam e: a[i]) {
            cur.emplace_back(e);
            cerr << "emplacing back " << e.day << "," << e.need << endl;
        }

        if(prepped[i] < need[i]) {
            cout << -1 << endl;
            return 0;
        } else if(prepped[i] == need[i]) {
            ans.emplace_back(m+1);
            continue;
        }

        sort(cur.begin(), cur.end(), comp);

        if(cur.size()) {
            if(prepped[cur[0].day] < need[cur[0].day]) {
                cerr << "preparing for exam on " << cur[0].day << endl;
                ans.emplace_back(cur[0].index);
                prepped[cur[0].day]++;
            } else {
                cerr << "relaxing" << endl;
                ans.emplace_back(0);
            }
        } else {
            cerr << "relaxing" << endl;
            ans.emplace_back(0);
        }
        cerr << endl;
    }

    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}