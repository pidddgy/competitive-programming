// https://dmoj.ca/problem/coci06c5p3

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define cerr if(false) cerr
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

vector<string> split(string s, char delim) {
    vector<string> res;
    string cur;
    for(char x: s) {
        if(x != delim) {
            cur += x;
        } else {
            res.emplace_back(cur);
            cur = "";
        }
    }
    res.emplace_back(cur);

    return res;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string n1, n2;
    cin >> n1 >> n2;

    int N;
    cin >> N;

    cin.ignore();

    for(int i = 1; i <= N; i++) {
        bool valid = true;
        string l;
        getline(cin, l);
        // cout << l << endl;

        vector<string> sets = split(l, ' ');
        vector<pii> parsed;

        for(string x: sets) {
            watch(x)
            vector<string> spl = split(x, ':');

            parsed.emplace_back(pii(stoi(spl[0]), stoi(spl[1])));
        }

        // if(parsed.size() == 3) {
        //     if(not (parsed[0] == pii(6, 6) or parsed[1] == pii(6, 6))) {
        //         valid = false;
        //     }
        // }

        int aw = 0, bw = 0;
        int at = 0, bt = 0;
        for(int i = 0; i <parsed.size(); i++) {
            pii x = parsed[i];
            // no winner
            // if((x.fi > 7 or x.se > 7) and i != 2) {
            //     cerr << "failed on " << x.fi << "," << x.se << endl;
            //     valid = false;
            // }
            cerr << x.fi << "," << x.se << endl;
            bool haveWinner = false;

            if(x.fi >= 6 and x.fi-x.se >= 2) {
                haveWinner = true;
            }

            if(x.se >= 6 and x.se-x.fi >= 2) {
                haveWinner = true;
            }

            if((x == pii(7, 6) or x == pii(6, 7)) and i != 2) haveWinner = true;

            if(!haveWinner) {
                valid = false;
                cerr << "no winner" << endl;
            } 

            if(x.fi > 6 and x.se > 6 and i != 2) valid = false;


            if(x.fi > x.se) {
                aw++;
            } else if(x.se > x.fi){
                bw++;
            } else {
                valid = false;
            }
            at += x.fi;
            bt += x.se;
        }

        if(bw and n1 == "federer") valid = false;
        if(aw and n2 == "federer") valid = false;

        if(!(aw == 2 or bw == 2)) {
        // if(abs(aw-bw) < 2) {
            cerr << "failed" << endl;
            valid = false;
        }

        // if(abs(at-bt) < 6) {
        //     cerr << "not big enough difference" << endl;
        //     valid = false;
        // }
        
        watch(aw)
        watch(bw)
        if(aw > 2 or bw > 2 or aw+bw > 3) {
            valid = false;
        }
        if(valid) {
            cout << "da" << endl;
        } else {
            cout << "ne" << endl;
        }
    }
}