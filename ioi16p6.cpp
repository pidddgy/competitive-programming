#include <bits/stdc++.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define sq(x) (x)*(x)

using ll = long long;
using ld = long double;
using pii = std::pair<int, int>;
const int MM = 1e5+2;
const ld eps = 1e-4;

int n, q[MM], cnt[MM], K, ab, bb;
ld dp[MM];
pii a[MM], b[MM];

inline bool cmp(pii x, pii y){
	if(x.first != y.first)
		return x.first < y.first;
	return x.second > y.second;
}

inline ld eval(int l, int i){
	return dp[l] + sq((ll)(a[i].second - a[l+1].first + 1)) - sq((ll)max(0, a[l].second - a[l+1].first + 1));
}

inline int inter(int i, int f, int s){
	static int l, m, r;
	l = i+1, r = n;
	while(l <= r){
		m = (l+r)/2;
		if(eval(f, m) < eval(s, m))
			l = m+1;
		else
			r = m-1;
	}
	return l;
}

inline void run(ld cost){
	static int l, r, i;
	for(i = 1, l = r = 0; i <= n; i++){
		
		while(r-l >= 1 && (eval(q[l], i) >= eval(q[l+1], i)))
			l++;
		
		dp[i] = eval(q[l], i) + cost;
		cnt[i] = cnt[q[l]] + 1;
		
		while(r-l >= 1 && inter(i, q[r-1], q[r]) >= inter(i, q[r], i))
			r--;
		
		q[++r] = i;
	}
}

long long take_photos(int Ln, int M, int Lk, int *R, int *C){
	
	n = Ln, K = Lk;
	
	for(int i = 0; i < n; i++){
		if(R[i] < C[i])
			b[bb++] = {R[i], C[i]};
		else
			b[bb++] = {C[i], R[i]};
	}
	
	sort(b, b+bb, cmp);
	
	a[ab++] = {-1, -1};
	
	int high = -1;
	for(const auto &i: b){
		if(i.second > high){
			high = i.second;
			a[ab++] = i;
		}
	}
	
	n = ab-1;
	
	if(n < K)
		K = n;
	
	ld l = 0, m, r = 1e12+1;
	while(r-l >= eps){
		m = (l+r)/2;
		run(m);
		
		if(cnt[n] == K)
			return round(dp[n] - m*K);
		
		if(cnt[n] > K)
			l = m;
		else
			r = m;
	}
	
	run(r);
	
	return (ll)round(dp[n] - r*K);
}