// https://codeforces.com/contest/576/problem/A

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
int main() {
    int n;
    cin >> n;

    vector<int> S;
    for(int x = 1; x <= n; x++) {
        if(!isPrime(x)) continue;
        int k = 1;
        while(pow(x, k) <= n) {
            S.emplace_back(pow(x, k));
            k++;
        }
    }

    cout << S.size() << endl;
    for(int x: S) {
        cout << x << " ";
    }
    cout << endl;
}