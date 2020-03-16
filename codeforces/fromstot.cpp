// http://codeforces.com/contest/1194/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;


// a == subseq;
bool subseq(string a, string b) {
    if(a.size() > b.size()) return false;

    int i = 0;
    int j = 0;
    for(; j < b.size() && i < a.size(); j++) {
        if(a[i] == b[j]) {
            i++;
        }
    }


    return(i == a.size());

}
int main() {
  //  cout << 'z'-'a' << endl;
    int q;
    cin >> q;
    while(q--) {
        string s, t, p;
        cin >> s >> t >> p;

        bool good = true;
        if(!subseq(s, t)) good = false;

        int cnt[30];
        int cntT[30];
        for(int i = 0; i < 30; i++) {
            cnt[i] = 0;
            cntT[i] = 0;
        }

        for(char x: t) {
            cntT[x-'a']++;
        }

        for(char x: s) {
            cnt[x-'a']++;
        }

        for(char x: p)  {
            cnt[x-'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(cntT[i] > cnt[i]) good = false;
        }


        if(good) cout << "YES" << endl;
        else cout << "NO" << endl;




        
    }
}