// https://codeforces.com/contest/49/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

int manum = INT_MIN;


int fpow(int a, int exp){
    if(exp == 0) return 1;
    int t = fpow(a,exp/2);
    if(exp%2) return t*t*a;
    return t*t;
}

vector<int> f(int num, int base) {
    vector<int> arr;

    while(num) {
        int dig = num%base;

        arr.emplace_back(dig);
        num /= base;
    }

    return arr;
}

int g(int num, int base) {
    string s = to_string(num);
    
    // cout << "doing " << num << " " << base << endl;
    int res = 0;
    for(int i = 1; i <= s.size(); i++) {
        // cout << "adding " << s[s.size()-i]-'0' << " times " << fpow(base, i-1) << endl;
        // cout << "added " << (s[s.size()-i]-'0') * fpow(base, i-1) << endl;
        res += (s[s.size()-i]-'0') * fpow(base, i-1);
        // cout << "res is " << res << endl;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    for(char x: to_string(a)+to_string(b)) {
        manum = max(manum, (int)x-'0');
    }

    int ma = 0LL;
    for(int i = manum+1; i <= 10; i++) {
        int ab = g(a, i);
        int bb = g(b, i);

        // watch(i)
        // watch(ab+bb)

        // watch(f(ab+bb, i).size())

        ma = max(ma, (int)f(ab+bb, i).size());
    }

    cout << ma << endl;
}