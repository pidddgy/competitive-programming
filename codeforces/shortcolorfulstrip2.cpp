// http://codeforces.com/contest/1178/problem/F1

#include <bits/stdc++.h>
#define MOD 998244353
#define ll long long
using namespace std;

// its from geeksforgeeks but im desperate
unsigned long int catalanDP(unsigned int n) 
{ 
    // Table to store results of subproblems 
    unsigned long int catalan[n+1]; 
  
    // Initialize first two values in table 
    catalan[0] = catalan[1] = 1; 
  
    // Fill entries in catalan[] using recursive formula 
    for (int i=2; i<=n; i++) 
    { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++) 
            catalan[i] += catalan[j] * catalan[i-j-1]; 
    } 
  
    // Return last entry 
    return catalan[n]; 
} 


int main() {
    ll n;
    cin >> n;

    cout << fact(n*2) / (fact(n+1) * fact(n)) << endl;
}


