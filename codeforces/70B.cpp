// https://codeforces.com/contest/70/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<char> endchr = {'.', '?', '!'};

    string cur;
    int len = 0;
    vector<int> arr;
    while(cin >> cur) {
        watch(cur)

        len += cur.size()+1;

        if(endchr.count(cur[cur.size()-1])) {
            arr.emplace_back(len-1);
            len = 0;
        }
    }

    for(int x: arr) {
        // watch(x)
        if(x>n) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    int ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        len = arr[i];

        while(i+1 < arr.size() and len+arr[i+1]+1 <= n) {
            i++;
            len += arr[i]+1;
        }

        ans++;
    }

    cout << ans << endl;
}