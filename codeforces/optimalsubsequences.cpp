// 


#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 1;i <= n; i++) cin >> a[i];

        int b[n+1];
        for(int i = 1; i <= n; i++) {
            b[i] = a[i];
        }

        sort(b+1, b+n+1, greater<int>());

    int m;
    cin >> m;

    for(int i = 1; i <= m; i++) {
        int kj, posj;
        cin >> kj >> posj;

        map<int, int> cnt;
        for(int i = 1; i <= kj; i++) {
            cnt[b[i]]++;
        }
        
        int pos = 0;
        for(int i = 1; i <= n; i++) {
            if(cnt[a[i]]) {
                cnt[a[i]]--;
                pos++;

                if(pos == posj) {
                    cout << a[i] << endl;
                }
            }
        }
    }

}