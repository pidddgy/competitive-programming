// https://codeforces.com/contest/518/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define cerr if(false) cerr
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int pos = 0;

    string ans = "";
    for(;pos < s.size(); pos++) {
        ans += s[pos];
        if(t[pos] > s[pos]) {
            ans[ans.size()-1]++;
            pos++;
            break;
        }
    }

    for(;pos < s.size(); pos++) {
        if(s[pos] != 'z')
            ans += s[pos]+1;
        else ans += 'a';
    }

    watch(ans)
    if(lexicographical_compare(ans.begin(), ans.end(), t.begin(), t.end()) && 
    lexicographical_compare(s.begin(), s.end(), ans.begin(), ans.end())) {
        cout << ans << endl;
    } else {
        pos = 0;
        ans = "";

        for(;pos < s.size(); pos++) {
            ans += s[pos];
            if(t[pos] > s[pos]) {
                pos++;
                break;
            }
        }

        for(;pos < s.size(); pos++) {
            if(s[pos] != 'z')
                ans += s[pos]+1;
            else ans += 'a';
        }

        if(lexicographical_compare(ans.begin(), ans.end(), t.begin(), t.end()) &&
        lexicographical_compare(s.begin(), s.end(), ans.begin(), ans.end())) {
            cout << ans << endl;
        } else {
            cout << "No such string" << endl;
        }
    }
}

/*
vklldrxnfgyorgfpfezvhbouyaaaaa
vklldrxnfgyorgfpfezvhbouzaaadv

*/