// https://codeforces.com/contest/1325/problem/0

#include <bits/stdc++.h>

using namespace std;
int gcd(int m, int n) {
   int r = 0, a, b;
   a = (m > n) ? m : n;
   b = (m < n) ? m : n;
   r = b;
   while (a % b != 0) {
      r = a % b;
      a = b;
      b = r;
   }
   return r;
}

int lcm(int m, int n) {
   int a;
   a = (m > n) ? m: n;
   while (true) {
      if (a % m == 0 && a % n == 0)
         return a;
         ++a;
   }
}

int main() {
    #define int long long
    int N;
    cin >> N;

    while(N--) {
        int a;
        cin >> a;

        cout << 1 << " " << a-1 << endl;
        // cerr << gcd(1, a-1) << endl;
        // cerr << lcm(1, a-1) << endl;
        // assert(gcd(1, a-1) + lcm(1, a-1) == a);
        // cerr << endl;
    }
    // cout << gcd(1, 14) << endl;
    // cout << lcm(1, 14) << endl;
}