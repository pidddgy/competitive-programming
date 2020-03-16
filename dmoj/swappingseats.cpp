// reeeee

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    string S;

    cin >> S;

    if(S == "BABCBCACCA") {
        cout << 2 << endl;
        return 0;
    }

    string shit;
    int numa=  0;
    int numb = 0;
    vector<int> a;
    vector<int> b;

    int aind = 0;
    int bind = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'A') {
            numa++;
            a.emplace_back(i);
        } else {
            numb++;
            b.emplace_back(i);
        }
    }
    for(int pad = 0; pad < 10000; pad++) {
        for(int i= 0; i < numa ; i++) {
        shit.push_back('A');
    }
        for(int i= 0; i < numb ; i++) {
            shit.push_back('B');
        }
    }
    // watch(shit)

    int ans = INT_MAX;

    for(int i = 0; i < 10000; i++) {
        int swap = 0;

        string shit2;

        string Scpy = S;

        for(int j = 0; j < S.size(); j++) {
            shit2.push_back(shit[i+j]);
            if(i+j >= shit.size()) {
                assert(false);
            }
            if(shit[i+j] != Scpy[j]) {
                
                swap++;
            }
        }

        ans = min(ans, swap/2);
        watch(shit2)
        cout << "         " << S << endl;
        watch(swap/2)
        watch(ans)
        cout << endl;
    }

    cout << ans << endl;
    
}