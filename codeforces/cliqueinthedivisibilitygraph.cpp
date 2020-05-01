// https://codeforces.com/contest/566/problem/F

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define int long long
#define endl '\n'
#define small 15
const int maxa = ((int)1e6)+5;

bool vis[(int)(1e6)+5];
int nums[maxa];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int a[N+1];
    map<int, int> cnt;

    int maxelem = 0;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        maxelem = max(maxelem, a[i]);
        cnt[a[i]]++;
        nums[a[i]]++;
    }

    int best = 1;
    for(int i = 1; i <= maxelem; i++) {
        for(int j = 2*i; j <= maxelem; j += i) {
            if(nums[j]) {
                nums[j] = max(nums[j], nums[i]+1);
                best = max(best, nums[j]);
            }
        }
    }

    cout << best << endl;
}