// http://codeforces.com/contest/1178/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    string s;
    cin >> s;

    int N = s.size();

    int startv = 0;
    int o = 0;
    int endv = 0;

    for(int i = N-1; i >= 1; i--) {
    //     watch(i)
    //         watch(startv)
    // watch(o)
    // watch(endv)
        if(s[i] == 'v' && s[i-1] == 'v') {
          //  cout << "is w  " << endl;
            endv++;
            startv += o;
        } else if(s[i]  == 'o'){
        //    cout << "adding " << endv << endl;
            o += endv;
        }
       // cout << endl;
    }

    // watch(startv)
    // watch(o)
    // watch(endv)
    cout << startv << endl;
}