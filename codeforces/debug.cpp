#include <bits/stdc++.h>
using namespace std;
int t,n,a[300005],b[300005];
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        int cnt=0,ans=0x3f3f3f3f;
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        if (n<=3) {cout<<"0\n"; continue;}
        for (int i=1; i<n-1; i++) {
            if (a[i]>a[i-1] and a[i]>a[i+1]) {cnt++; b[i]=1;}
            if (a[i]<a[i-1] and a[i]<a[i+1]) {cnt++; b[i]=1;}
        }
        ans=cnt;
        for (int i=1; i<n-1; i++) {
            int val=a[i-1],sub=b[i],sub2=b[i];
            if (i!=1) sub+=(b[i-1]);
            if (i!=n-2) {
                if ((val<=a[i+1] and a[i+1]<=a[i+2]) or (val>=a[i+1] and a[i+1]>=a[i+2])) sub+=(b[i+1]);
            }
            ans=min(ans,cnt-sub);
            val=a[i+1];
            if (i!=1) {
                if ((a[i-2]<=a[i-1] and a[i-1]<=val) or (a[i-2]>=a[i-1] and a[i-1]>=val)) sub2+=(b[i-1]);
            }
            if (i!=n-2) sub2+=(b[i+1]);
            ans=min(ans,cnt-sub2);
        }
        cout<<max(0,ans)<<'\n';
        for (int i=0; i<n; i++) b[i]=0;
    }
}