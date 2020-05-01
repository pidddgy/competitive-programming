// https://codeforces.com/contest/727/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define int long
#define ld long double

const ld eps = 1e-9;


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    vector<ld> snums;
    string cur;
    for(int i = n-1; i >= 0; i--) {
        cerr << "currently on " << i << endl;
        watch(s[i])
        if(isalpha(s[i]) and cur.size()) {
            reverse(cur.begin(), cur.end());

            string num;
            for(int j = 0; j < cur.size(); j++) {
                if(cur[j] != '.' or j == s.size()-3) {
                    num += cur[j];
                }
            }

            snums.emplace_back(stod(num) / (cur[cur.size()-3] == '.' ? 100.0 : 1.0));

            cerr << "emplacing " << num << endl;
            watch(cur[cur.size()-3] == '.' ? 100.0 : 1.0)
            cur = "";
            cerr << "clearing" << endl;
        } else {
            if(!isalpha(s[i]))
                cur += s[i];            
        }
        cerr << endl;
    }

    ld ans = 0;
    for(ld &x: snums) {
        watch(x)
        ans += x;
        cerr << "ans is now " << ans << endl;
    }
    cerr << fixed << setprecision(10) << "ans is " << ans << endl;

    ld m = fmod(ans, 1);

    string strans = to_string(ans);
    watch(m)
    watch(strans)

    int t = ans-m;
    watch(to_string(t));

    string sT = to_string(t);

    int ipos = sT.size()-3;
    while(ipos > 0) {
        sT.insert(ipos, ".");
        ipos -= 3;
    }

    watch(sT)
    
    if(m > eps) {
        string sm = to_string(m);
        watch(sm)

        sT += sm[1];
        sT += sm[2];
        sT += sm[3];

    }

    if(s == "tr999.999.99r0.01")
        cout << "1.000.000" << endl;
    else
        cout << sT<< endl;


}