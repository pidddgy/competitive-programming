// https://codeforces.com/contest/1366/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

// source -> https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
#define MAXN 10000500
// stores smallest prime factor for every number 
int spf[MAXN]; 
  
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
  
        // marking smallest prime factor for every 
        // number to be itself. 
        spf[i] = i; 
  
    // separately marking spf for every even 
    // number as 2 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        // checking if i is prime 
        if (spf[i] == i) 
        { 
            // marking SPF for all numbers divisible by i 
            for (int j=i*i; j<MAXN; j+=i) 
  
                // marking spf[j] if it is not  
                // previously marked 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
set<int> getFactorization(int x) 
{ 
    set<int> ret; 
    while (x != 1) 
    { 
        ret.emplace(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    sieve(); 

    // set<int> test = getFactorization(3);

    // for(int x: test) {
    //     cerr << x << " ";
    // }
    // cerr << endl;

    int n;
    cin >> n;

    int ans1[n+1], ans2[n+1], a[n+1];

    for(int i = 1; i <= n; i++) {
        ans1[i] = ans2[i] = -1;

        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        set<int> S = getFactorization(a[i]);

        for(int x: S) {
            for(int y: S) {
                if(x == y) continue;

                set<int> p = getFactorization(x+y);
                bool ok = true;

                for(int x: p) {
                    if(S.count(x)) {
                        ok = false;
                        break;
                    }
                }

                if(ok) {
                    ans1[i] = x;
                    ans2[i] = y;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;

    for(int i = 1; i <= n; i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;
}
