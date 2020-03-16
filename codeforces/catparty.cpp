#include <bits/stdc++.h>
#define MAXN 100003

int psa[13][MAXN];
int a[MAXN];
using namespace std;

int main() {
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++) cin >> a[i];

    for(int i = 1; i <= N; i++) {
        psa[a[i]][i]++;
    }

    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= N; j++) {
            psa[i][j] += psa[i][j-1];
        }
    }

    int ans = 1231233;
    for(int i = N; i >= 1; i--) {
        //cout << "i is " << i << endl;
        int cnt[N+1];
        for(int j = 1; j <= N; j++) {
            cnt[j] = psa[j][i];
          //  cout << "cnt of " << j << " is " << cnt[j] << endl;
        }

        int freqCount[11];
        fill(freqCount, freqCount+11, 0);
        for(int j = 1; j <= N; j++) {
            if(cnt[j] != 0) {
                freqCount[cnt[j]]++;
            }
        }

        int fi = -1;
        int se = -1;
        bool cont = false;
        for(int j = 1; j<=N; j++) {
            if(freqCount[j] != 0) {
                if(fi == -1) fi = j;
                else if(se == -1) se = j;
                else {
                    cont = true;
                    break;
                }
            }
        }

        if(cont) continue;
     //   cout << "fi is " << fi << endl;
    //    cout << "se is " << se << endl;
        // cout << endl;

        // difference beween both is 1
        if(abs(fi-se) == 1) {
            cout << i << endl;
            return 0;
        } 
        
        else if(fi == 1 && freqCount[fi] == 1) {
            cout << i << endl;
            return 0;
        } else if(se == 1 && freqCount[se]==1) {
            cout << i << endl;
            return 0;
        }

        else if (fi == -1 && se == 1) {
            cout << i << endl;
            return 0;
        } else if(se == -1 && fi == 1) {
            cout << i << endl;
            return 0;
        }

        
    }

 //   cout << ans << endl;
    

}