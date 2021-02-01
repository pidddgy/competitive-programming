#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve(string s, string t) {
    cerr << "doing " << s << " " << t << endl;
    map<int, int> have, need;

    for(char x: s) have[x]++;
    for(char x: t) need[x]++;

    int op = 0;
    queue<char> Q; // characters we need to put in
    for(int i = 0; i < 26; i++) {
        char x = 'A'+i;
        for(int j = 1; j <= max(0LL, need[x]-have[x]); j++) {
            cerr << "need more of " << x << endl;
            Q.push(x);
            op++;
        }
    }

    map<char, int> cur;
    vector<int> ind(sz(s));

    for(int i = sz(s)-1; i >= 0; i--) {
        char x = s[i];
        ind[i] = ++cur[x];
    }


    // try to improve
    for(int i = 0; i < sz(s); i++) {
        char x = s[i];
        if(have[x] > need[x]) {
            int rem = have[x]-need[x]; 
            if(ind[i] <= rem or Q.front() < x) {
                have[x]--;
                s[i] = Q.front();
                Q.pop();
                have[s[i]]++;
                cerr << "replacing " << i << " with " << s[i] << endl;;
            }
        }
    }

    cout << op << endl;
    cout << s << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s, t;
    cin >> s >> t;

    solve(s, t);

    // auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    // mt19937 mt(seed);

    // for(int i = 1; i <= 100; i++) {
    //     int n = mt()%10+1;
    //     string s, t;
        
    //     for(int j = 1; j <= n; j++) {
    //         char x = 'A'+(mt()%26);
    //         char y = 'A'+(mt()%26);
    //         s += x;
    //         t += y;
    //     }

    //     solve(s, t);
    // }



}

/*
CDBABC
ADBADC

first try to improve
then try to make it less bad

replace if it improves or if will be forced to anyway

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?