#include <bits/stdc++.h>
#define maxn 1000500
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int dp[maxn];

signed main() {
	int N;
	cin >> N;

	string st, end;
	cin >> st >> end;

	st = "."+st;
	end = "."+end;

	dp[0] = 0;
	for(int i = 1; i <= N; i++) {
		dp[i] = INT_MAX;

		if(st[i] == end[i]) dp[i] = min(dp[i], dp[i-1]);
		if(st[i] == '0' and end[i] == '1') dp[i] = min(dp[i], dp[i-1]+1);

		for(int d = 3; d <= 4; d++) {
			bool clear = false;
			bool close = false;
			int st1 = 0, st0 = 0, end1 = 0, end0 = 0;

			int l = i-d;
			int r = i;
			if(l <= 0) {
				close = true;
				r += l*-1;
				l = 1;
			} else l++;

			// watch(d)
			// watch(l)
			// watch(r)
			// watch(i)


			for(int j = l; j <= r; j++) {
				if(st[j] == '1' and end[j] == '0') clear = true;
				st1 += st[j] == '1';
				st0 += st[j] == '0';
				end1 += end[j] == '1';
				end0 += end[j] == '0';
			}

			// if(clear) cout << "need clear" << endl;

			if(close) {
				if(clear) {
					dp[i] = min(dp[i], st0 + 1 + end1);
				} else {
					dp[i] = min(dp[i], end1 - st1);
				}
			} else if(clear) {
				dp[i] = min(dp[i], dp[i-d] + st0 + 1 + end1);
				// cout << "setting dp[i] to " << dp[i] << endl;
				// watch(dp[i-d])
				// watch(st0)
			} else {
				dp[i] = min(dp[i], end1-st1);
			}


			// cout<<endl;


		}
		// cout<<endl;
	}

	for(int i = 1; i <= N; i++) cout << dp[i] << " ";
	cout << endl;
	cout << dp[N] << endl;
}