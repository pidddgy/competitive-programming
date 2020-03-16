#include <bits/stdc++.h>
using namespace std;

int main() {
    #define int long long
    int q;
    cin >> q;

    while(q--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        s = "."+s;
        s = s+"........";

        int ind = 1;

        while(s[ind] == '0') {
            ind++;
            if(s[ind] == '1') break;
            if(ind == n) break;
        }
        for(int i = ind+1; i <= n; i++) {
            if(s[i] == '0') {
                if(i-ind <= k) {
                    s[ind] = '0';
                    s[i] = '1';
                    k -= i-ind;
                } else {
                    for(int j = ind+1; j <= i-1; j++) {
                        if(i-j <= k and s[j] == '1') {
                            s[j] = '0';
                            s[i] = '1';
                            k -= i-j;
                            break;
                        }
                    }
                }
            }

            if(k == 0) break;
        while(s[ind] == '0') ind++;

        }

        assert(s.size() >= n+1);
        for(int i = 1; i <= n; i++) cout << s[i];
        cout<<endl;
    }
}