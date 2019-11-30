// https://dmoj.ca/problem/dmpg18s5

#include <bits/stdc++.h>
#define maxn 200500
#define sqrtmaxn 448
#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int a[maxn];
// at most 448 blocks
int blk[sqrtmaxn][200005];
int N, K;
int blksz;

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    blksz = sqrt(N);
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        watch(a[i])
    }
    watch(blksz)
    int blkind = 1;
    for(int i = 1; i <= N; i++) {

        cout << i << " goes into block " << blkind << endl;
        if(i % blksz == 0) blkind++;

        watch(a[i])
        for(int j = 1; j <= sqrt(a[i]); j++) {
            if(a[i]%j == 0) {
                blk[blkind][j]++;
                cout << "adding to " << j << endl;

                if(a[i]/j != j) {
                    cout << "adddding to " << a[i]/j << endl;
                    blk[blkind][a[i]/j]++;
                }

            }
        }
    }






}