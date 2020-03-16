// http://codeforces.com/problemset/problem/1157/C1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fi first
#define se second
#define pis pair<int, string>
using namespace std;
int main() {
    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) {
        int b;
        cin >> b;

        a[i] = b;
    }

    string ans;
    int prev = 0;

    int l = 1;
    int r = N;

    while(l <= r) {
        // watch(l)
        // watch(r)
        vector<pis> cur;
        if(a[l] > prev) cur.emplace_back(a[l], "L");
        if(a[r] > prev) cur.emplace_back(a[r], "R");
    //    cout<<"HI"<<endl;

        sort(cur.begin(), cur.end());
        if(cur.size()==2) cur.pop_back();

        
        if(cur.size()==1) {
            
            if(cur[0].se == "L") l++;
            else r--;

            ans += cur[0].se;
            prev = cur[0].fi;
        } else break;
       // cout<<endl;
    }

    
    cout << ans.size() << endl;
    cout << ans << endl;
}