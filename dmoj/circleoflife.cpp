// https://dmoj.ca/problem/ccc16s5

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define GOODSUM 97
#define maxn 4005
#define ll long long
using namespace std;

ll N, T;

ll cntBit(ll n) {return (int)log2(n)+1;}
string out;

void tobin(ll n)
{
    if (n / 2 != 0) {
        tobin(n / 2);
    }
    out.push_back((n%2+'0'));
}

ll tf(ll s) {
    ll l, r;
    l = s << 1;
    r = s >> 1;

    if(s & (1 << (N-1))) {
        l ^= 1;
        l ^= 1 << N;
    }

    if(s & 1) {
        r ^= 1 << (N-1);
    }

    return l ^ r;
}

int main() {
    #define ll long long
    cin >> N >> T;

    string inp;
    cin >> inp;
    
    ll s = stoll(inp, 0, 2);


    vector<ll> pattern;
    cout << inp << endl;
    for(ll i = 0; i < T; i++) {
        s = tf(s);

        // pattern.emplace_back(s);

        // if(pattern.size()%2 == 0) {
        //     ll incr = pattern.size()/2;

        //     bool same = true;
        //     for(ll i = 0; i < pattern.size()/2; i++) {
        //         if(pattern[i] != pattern[i+incr]) {
        //             same = false;
        //             break;
        //         }
        //     }   

        //     if(same) {
        //         ll rem = (T-pattern.size()) % (pattern.size()/2);
        //         for(ll j = 0; j < rem; j++) {
        //             s = tf(s);
        //         }

                
        //         tobin(s);
        //         while(out.size() != N) out = "0"+out;
        //         cout << out << endl;
        //         return 0;
        //     }
        // }

        out = "";
        tobin(s);
        while(out.size() != N) out = "0"+out;
        cout << out << endl;
    }

    // tobin(s);
    // while(out.size() != N) out = "0"+out;
    // cout << out << endl;
}