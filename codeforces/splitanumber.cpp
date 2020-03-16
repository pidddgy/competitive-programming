// http://codeforces.com/contest/1181/problem/B
//sdf

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int N;
    cin >> N;
    string s;
    cin >> s;

    int mi = 2147483647;

    int l = 0;
    int r = stoi(s);

    watch(l)
    watch(r)
    cout<<endl;
    // i = last digit in l
    for(int i = 0; i < N-1; i++) {
        l *= 10;
        l += s[i]-'0';

        r %= (int)pow(10, N-i-1);

        watch(l)
        watch(r)

        if(s[i+1] == '0') continue;
        mi = min(mi, l+r);

        watch(l+r)
        watch(mi)


        cout<<endl;
    }
    cout << mi << endl;
}