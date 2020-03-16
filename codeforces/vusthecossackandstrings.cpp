// http://codeforces.com/contest/1186/problem/C

#include <bits/stdc++.h>
#define maxn 1000006
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int psa[maxn];

int main() {
    string a, b;
    cin >> a >> b;
    a = "."+a;
    b = "."+b;

    psa[0] = 0;
    psa[1] = a[1]-'0';
    for(int i = 2; i < a.size(); i++) {
        psa[i] = a[i]-'0' + psa[i-1];
    }

    // for(int i = 1; i < a.size(); i++) {
    //     watch(i)
    //     watch(psa[i])
    // }

    int sum = 0;
    for(int i = 1; i < b.size(); i++) {
        sum += b[i]-'0';
    }

    int parity = sum % 2;
    
    // watch(parity)
    int ans = 0;
    for(int i = 1; i <= a.size()-b.size(); i++) {
        // watch(i)
        //watch(i+b.size()-1)
        // for(int j = i; j < i+b.size()-1; j++) {
            // cout << a[j];
        // }
      //  cout << endl;
    //    watch(psa[i+b.size()-2] - psa[i-1])
        if(((psa[i+b.size()-2] - psa[i-1]) % 2) == parity) {
            ans++;
        }
        // cout << endl;
    }

    cout << ans << endl;
    
}