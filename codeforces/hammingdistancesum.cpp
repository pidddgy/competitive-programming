// https://codeforces.com/contest/608/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    string a, b;
    cin >> a >> b;
    
    int N = a.size();
    int M = b.size();

    int l = 1;
    int r = M-N+1;

    a = "."+a;
    b = "."+b;

    int num1 = 0;
    int num0 = 0;

    for(int i = l; i <= r; i++) {
        if(b[i] == '1') num1++;
        else num0++;
    }
    
    int i = 1;
    int ans = 0;
    while(r <= M) {
        // cerr << "r is " << r << endl;
        // cerr << i << " contributes: ";
        if(a[i] == '1') {
            ans += num0;
            // cerr << num0 << endl;
        } else {
            ans += num1;
            // cerr << num1 << endl;
        }

        if(b[l] == '0') num0--;
        else num1--;

        l++;
        r++;


        if(r <= M) {
            if(b[r] == '0') num0++;
            else num1++;  
        }
            
        i++;
    }   

    cout << ans << endl;
}