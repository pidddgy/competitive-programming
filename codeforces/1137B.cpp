// https://codeforces.com/contest/1137/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr

// Returns length of the longest prefix 
// which is also suffix and the two do 
// not overlap. This function mainly is 
// copy computeLPSArray() of in below post 
// https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/ 
int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    int lps[n]; 
    lps[0] = 0; // lps[0] is always 0 
  
    // length of the previous 
    // longest prefix suffix 
    int len = 0; 
  
    // the loop calculates lps[i] 
    // for i = 1 to n-1 
    int i = 1; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider 
            // the example. AAACAAAA 
            // and i = 7. The idea is 
            // similar to search step. 
            if (len != 0) 
            { 
                len = lps[len-1]; 
  
                // Also, note that we do 
                // not increment i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 
  
    return res;
} 
  
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int s0 = 0, s1 = 0;
    for(char x: s) {
        if(x == '0') {
            s0++;
        } else {
            s1++;
        }
    }

    int l = 0;
    int r = t.size();
    int lastgood = -1;

    while(l <= r) {
        int m = (l+r)/2;
        string fi, se;

        for(int i = 0; i < m; i++) {
            fi+= t[i];
        }

        for(int i = t.size()-m; i < t.size(); i++) {
            se += t[i];
        }

        if(fi == se) {
            lastgood = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    lastgood = longestPrefixSuffix(t);
    watch(lastgood)

    if(t.size()==1) lastgood = 0;


    int t0tot = 0, t1tot = 0;

    for(char x: t) {
        if(x == '0') {
            t0tot++;
        } else {
            t1tot++;
        }
    }
    if(t0tot == 0 or t1tot == 0) {
        lastgood = t.size()-1;
    }


    int t0 = 0, t1 = 0;
    for(int i = lastgood; i < t.size(); i++) {
        if(t[i] == '0') t0++;
        else t1++;
    }

 


    watch(s0)
    watch(s1)
    string ans = "";
    if(s0 >= t0tot and s1 >= t1tot) {
        ans += t;
        s0 -= t0tot;
        s1 -= t1tot;
    }

    string rpart;
    for(int i = lastgood; i < t.size(); i++) {
        rpart += t[i];
    }

    watch(t0)
    while(s0 >= t0 and s1 >= t1) {
        ans += rpart;
        s0 -= t0;
        s1 -= t1;
    }

    while(s0--) {
        ans += '0';
    }

    while(s1--) {
        ans += '1';
    }

    cout << ans << endl;
}