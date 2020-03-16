// http://codeforces.com/contest/1189/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << numeric_limits<int>::max() << endl;
    int n;
    cin >> n;

    int a[n];
    for (auto &x: a) cin >> x;

    deque<int> ans;
    sort(a, a+n, greater<int>());

    ans.push_back(a[0]);
    if(n >= 2) ans.push_front(a[1]);

    for(int i = 2; i < n; i++) {
        ans.push_back(a[i]);
    }

    bool bad = false;
    if(ans.front() + ans.back() <= a[1]) {
     //   cout << "failed " << endl;
        bad = true;
    }
    if(ans[n-1] >= ans[n-2] + ans[0]) {
        bad = true;
    }
    for(int i = 1; i < n-1; i++) {
        if(ans[i] >= ans[i-1] + ans[i+1]) bad = true;
    }

    if(bad)
        cout << "NO" << endl;
    else
    {   
        cout << "YES" << endl;
        for(auto x: ans) cout << x << " ";
        cout << endl;
    }
  //  for(auto x: ans) cout << x << endl;
    
}

//2147483647
//1000000000