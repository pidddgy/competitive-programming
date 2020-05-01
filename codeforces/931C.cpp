// https://codeforces.com/contest/931/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr

const int maxn = 100500;

int a[maxn];
map<int, int> cnt;
set<int> S;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        S.emplace(a[i]);
    }

    if(*max_element(a+1, a+n+1) - *min_element(a+1, a+n+1) < 2) {
        cout << n << endl;
        for(int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return 0;
    }

    int mid = (*min_element(a+1, a+n+1))+1;

    for(int i = 1; i <= n; i++) {
        cnt[a[i]-mid]++;
    }
    cerr << "sdfsd" << endl;
    int maxmidc = 0;
    vector<int> maxmid;
    map<int, int> maxmidm;
    map<int, int> cpy = cnt;
    while(cpy[-1] and cpy[1]) {
        cerr << "sdf" << endl;
        maxmid.emplace_back(0);
        maxmid.emplace_back(0);
        maxmidm[0] += 2;
        cpy[-1]--;
        cpy[1]--;
    }

    while(cpy[0]--) {
        maxmidm[0]++;
        maxmid.emplace_back(0);
    }

    while(cpy[-1]) {
        maxmid.emplace_back(-1);
        maxmidm[-1]++;
        cpy[-1]--;
    }

    while(cpy[1]) {
        maxmid.emplace_back(1);
        maxmidm[1]++;
        cpy[1]--;
    }

    for(int x: set<int>({-1, 0, 1})) {
        maxmidc += min(maxmidm[x], cnt[x]);
    }

    int maxouterc = 0;
    vector<int> maxouter;
    map<int, int> maxouterm;
    cpy = cnt;

    while(cpy[0] >= 2) {
        maxouter.emplace_back(-1);
        maxouter.emplace_back(1);

        maxouterm[1]++;
        maxouterm[-1]++;

        cpy[0] -= 2;
    }

    while(cpy[0]) {
        maxouter.emplace_back(0);
        maxouterm[0]++;
        cpy[0]--;
    }

    while(cpy[1]) {
        maxouter.emplace_back(1);
        maxouterm[1]++;
        cpy[1]--;
    }

    while(cpy[-1]) {
        maxouter.emplace_back(-1);
        maxouterm[-1]++;
        cpy[-1]--;
    }

    for(int x: set<int>({-1, 0, 1})) {
        maxouterc += min(maxouterm[x], cnt[x]);
    }

    if(maxouterc < maxmidc) {
        cerr << "dfdfdddddd" << endl;
        cout << maxouterc << endl;
        for(int x: maxouter) {
            cout << x+mid << " ";
        }
        cout << endl;
    } else {
        cout << maxmidc << endl;
        for(int x: maxmid) {
            cout << x+mid << " ";
        }
        cout << endl;
    }



    




}