// https://codeforces.com/contest/231/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;

int test(deque<int> &v) {
    if(v.size() == 1) return v[0];
    int ans = 0;
    for(int i = v.size()-2; i >= 0; i--) {
        cerr << "currently on " << i << endl;
        if(i == v.size()-2) {
            ans = v[i]-v[i+1];
        } else {
            ans = v[i]-ans;
        }

        watch(ans)

    }

    return ans;
}

int testslow(deque<int> v) {
    while(v.size() >= 2) {
        int a = v[v.size()-2];
        int b = v[v.size()-1];
 
        v.pop_back();
        v.pop_back();
 
        v.emplace_back(a-b);
    }
 
    return v[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, d, l;
    cin >> n >> d >> l;
    if(l == 1) {
        if((n%2 == 0 and d == 0) or (n%2 == 1 and d == 1)) {
            for(int i = 1; i <= n; i++) {
                cout << 1 << " ";
            }
            cout << endl;
        } else cout << -1 << endl;

        return 0;
    }
    // deque<int> tteeeest = {1};
    // cerr << testslow(tteeeest) << endl;
    // cerr << test(tteeeest) << endl;
    int sum = 0;
    int used = 0;
    deque<int> ans;
    
    int target = d;

    if(d > 0) {
        target = (d*-1)+1;
    }

    watch(target)
    while(sum - (l-1) >= target) {
        ans.emplace_back(1);
        ans.emplace_back(l);

        sum -= (l-1);
        cerr << "sum is now " << sum << endl;
        used++;
    } 
    if(sum != target) {
        cerr << "adjusting" << endl;
        int secelem = (sum-target)+1;
        ans.emplace_front(secelem);
        ans.emplace_front(1);

        sum -= secelem-1;
    }

    
    watch(sum)

    if(d > 0) {
        if(ans.front() == 1) ans.pop_front();
        else ans.emplace_front(1);
        sum = 1-sum;
    }
    // how many elements to insert?
    int fillneeded = n-ans.size();
    watch(fillneeded)
    watch(ans.size())
    if(fillneeded <0) {
        cout << -1 << endl;
        return 0;
    }

    if(fillneeded) {
        if(fillneeded == 1) {
            for(int i = 0; i < ans.size(); i++) {
                if(ans[i] < l) {
                    deque<int> withfiller = ans;
                    withfiller[i]++;
                    withfiller.emplace_back(1);

                    if(test(withfiller) == d) {
                        for(int x: withfiller) {
                            cout << x << " ";
                        }
                        cout << endl;
                        return 0;
                    }

                    // withfiller.clear();
                }
            }
        } else if(fillneeded % 2 == 0) {
            for(int i = 1; i <= fillneeded; i++) {
                ans.emplace_back(1);
            }
        } else if(fillneeded % 2 == 1) {
            for(int i = 1; i <= fillneeded-2; i++) {
                ans.emplace_back(1);
            }
            ans.emplace_back(2);
            ans.emplace_back(1);
        }
    }

    // watch(sum)
    if(test(ans) == d and ans.size() == n) {
        for(int x: ans) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
  
}