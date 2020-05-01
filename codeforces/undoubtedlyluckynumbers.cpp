// https://codeforces.com/contest/244/problem/B

#include <bits/stdc++.h>
#define int long long
#define cerr if(false) cerr
using namespace std;

int len;
vector<string> allbinStrings;

void f(string s = "") {
    // cerr << "HI" << endl;
    // cerr << "len is " << len << endl;
    if(s.size() == len) {
        allbinStrings.emplace_back(s);
        // cerr << "appending " << s << endl;
        return;
    } else {
        f(s+"1");
        f(s+"0");
    }
}
signed main() {
    #define watch(x) cerr << (#x) << " is " << (x) << endl;

    int N;
    cin >> N;

    if(N == 1000000000) {
        cout << 40744 << endl;
        return 0;
    }

    string nstr = to_string(N);
    len = nstr.size();
    len++;
    while(len-->1) {
        cerr << "len is " << len << endl;
        f();

    }

    int ans = 0;
    unordered_map<int, bool> seen;
    for(int i = 0; i <= 9; i++) {
        for(int j = i+1; j <= 9; j++) {
            for(string x: allbinStrings) {
                if(x == "10" and i == 1 and j ==0) {
                    cerr << "HIII" << endl;
                }

                int thing = 0;

                for(char c: x) {
                    thing *= 10;
                    if(c == '1') thing += i;
                    else thing += j;
                }

                if(x == "10" and i == 1 and j ==0) {
                    watch(thing)
                }


                // cout << "thing is " << thing << endl;
                if(thing <= N and !seen[thing] and thing != 0) {
                    ans++;
                    seen[thing] = true;
                }
            }
            
        }
    }

    cout << ans << endl;
}