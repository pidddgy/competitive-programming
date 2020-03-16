// https://codeforces.com/contest/1241/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;

int gcd(int a, int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
}

int lcm(int a, int b) { 
    return (a*b)/gcd(a, b);  
}  

int main() {
    #define int long long
    #define ld long double
    
    // ld a = ((double)38 / (double)100) * 300;
    // cout << a << endl;

    int q;
    cin >> q;

    while(q--) {
        int n; cin >> n;

        int p[n+1];
        for(int i = 1; i <= n; i++) cin >> p[i];

        int x, a, y, b;
        cin >> x >> a >> y >> b;

        int k;
        cin >> k;

        sort(p+1, p+n+1, greater<int>());
        // for(int i = 1; i <= n; i++) cout << p[i] << " ";
        bool foundans = false;


        for(int i = 1; i <= n; i++) {
            // i = number of tickets sold

            int overlap = i / (lcm(a, b)); // land on both a and b
            int xs = (i/a) - overlap; // land on a only
            int ys = (i/b) - overlap; // land on b only
            int have = 0;

            // watch(overlap);
            // watch(xs)
            // watch(ys)

            for(int j = 1; j <= i; j++) {
                // POSSIBLE BUGS
                if(overlap) {
                    int cute = ((ld)(x+y) / 100.0) * (ld)p[j];
                    // cout << "adding " << cute << endl;
                    have += cute;
                    overlap--;
                } else if(x > y) {
                    if(xs) {
                        int cute = ((ld)x / 100.0) * (ld)p[j];
                        // cout << "adding " << cute << endl;
                        have += cute;
                        xs--;
                    } else if (ys) {
                        int cute = ((ld)y / 100.0) * (ld)p[j];
                        // cout << "adding " << cute << endl;
                        have += cute;
                        ys--;
                    }
                } else {
                    if(ys) {
                        int cute = ((ld)y / 100.0) * (ld)p[j];
                        // cout << "adding " << cute << endl;

                        have += cute;
                        ys--;
                    } else if(xs) {
                        int cute = ((ld)x / 100.0) * (ld)p[j];
                        have += cute;
                        // cout << "adding " << cute << endl;

                        xs--;
                    }
                }
            }
            if(have >= k) {
                cout << i << endl;
                foundans = true;
                break;
            }
        }

        if(!foundans) {
            cout << -1 << endl;
        }
    }
}