// https://dmoj.ca/problem/ccc20s4

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    srand(time(0));
    clock_t z = clock();

    string S;
    cin >> S;

    int acnt = 0;
    int bcnt = 0;
    int ccnt = 0;

    for(char x: S) {
        if(x == 'A') {
            acnt++;
        }

        if(x == 'B') {
            bcnt++;
        }
        if(x == 'C') {
            ccnt++;
        }
    }

    int lol = 0;
    int ans = INT_MAX;
    for(;;) {
        lol++;
        string match;

        int out = (rand()%3)+1;

        cerr << "out is " << out << endl;

        for(;;) {
            if(out == 3 and ccnt == 0) {
                out = (rand()%3)+1;
            } else if(out == 2 and bcnt == 0) {
                out = (rand()%3)+1;
            } else if(out == 1 and acnt == 0) {
                out = (rand()%3)+1;
            } else break;
        }


        if((out == 1) and acnt) {
            int l = (rand()%acnt)+1;
            int r = acnt-l;

            for(int i = 1; i <= l; i++) {
                match += "A";
            }

            if((rand()%2) == 0) {
                for(int i = 1; i <= bcnt; i++) {
                    match += "B";
                }

                for(int i = 1; i <= ccnt; i++) {
                    match += "C";
                }
            } else {
                for(int i = 1; i <= ccnt; i++) {
                    match += "C";
                }
                
                for(int i = 1; i <= bcnt; i++) {
                    match += "B";
                }
            }

            for(int i = 1; i <= r; i++) {
                match += "A";
            }

            cerr << "match is now " << match << endl;
        } else if ((out == 2) and bcnt) {
            int l = (rand()%bcnt)+1;
            int r = bcnt-l;

            for(int i = 1; i <= l; i++) {
                match += "B";
            }

            if((rand()%2) == 0) {
                for(int i = 1; i <= acnt; i++) {
                    match += "A";
                }

                for(int i = 1; i <= ccnt; i++) {
                    match += "C";
                }
            } else {
                for(int i = 1; i <= ccnt; i++) {
                    match += "C";
                }
                
                for(int i = 1; i <= acnt; i++) {
                    match += "A";
                }
            }

            for(int i = 1; i <= r; i++) {
                match += "B";
            }

            cerr << "match is now " << match << endl;

        } else if ((out == 3)) {
            int l = (rand()%ccnt)+1;
            int r = ccnt-l;

            cerr << "l is " << l << endl;
            cerr << "r is " << r << endl;

            for(int i = 1; i <= l; i++) {
                match += "C";
            }

            if((rand()%2) == 0) {
                for(int i = 1; i <= acnt; i++) {
                    match += "A";
                }

                for(int i = 1; i <= bcnt; i++) {
                    match += "B";
                }
            } else {
                for(int i = 1; i <= bcnt; i++) {
                    match += "B";
                }
                
                for(int i = 1; i <= acnt; i++) {
                    match += "A";
                }
            }

            for(int i = 1; i <= r; i++) {
                match += "C";
            }

            cerr << "match is now " << match << endl;
            
        }

        // match = "ACBAB";
        if(match.size() != S.size()) {
            cerr << "oh no" << endl;
            cerr << match << endl;
        }
        assert(match.size() == S.size());
        cerr << "match is " << match << endl;

        int cost = 0;
        for(int i = 0; i < match.size(); i++) {
            if(S[i] != match[i]) {
                cost++;
            }
        }

        cost--;
        // cost /= 2;

        cerr << "cost is " << cost << endl;
        ans = min(ans, cost);

        if(lol % 3 ==0)
        if(((clock()-z) / (double)CLOCKS_PER_SEC) > 0.8) break;

    }

    cout << ans << endl;

    
}

        
// if(((clock()-z) / (double)CLOCKS_PER_SEC) > 2.5) break;