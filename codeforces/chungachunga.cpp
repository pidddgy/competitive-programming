// http://codeforces.com/contest/1181/problem/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll x, y, z;
    cin >> x >> y >> z;
    
    ll c = 0;
    ll g = 0;
    c += x / z;
    c += y / z;
    
    if(((x%z) + (y%z) >= z)) {
        c += ((x%z) + (y%z)) / z;
        g = z - (max(x%z, y%z));
    } 

    cout << c << " " << g << endl;
}