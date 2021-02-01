#include <bits/stdc++.h>
using namespace std;
int n, ans; 
int main() {
    cin >> n; 
    int snowballs[n+1]; 
    for(int i = 1; i <= n; i++) {
        cin >> snowballs[i]; 
    }
    sort(snowballs, snowballs+n+1); 
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            int found = 0; 
            int l = j+1, r = n; 
            while(l<=r) {
                int mid = (l+r)/2; 
                if(snowballs[mid]-snowballs[j] == snowballs[j] - snowballs[i]) {
                    found = mid; 
                    break; 
                }
                else if (snowballs[mid] - snowballs[j] > snowballs[j] - snowballs[i]) {
                    r = mid - 1; 
                }
                else {
                    l = mid + 1; 
                }
            }
            if(found != 0) {
                if(snowballs[i] + snowballs[j] + snowballs[found] > ans) ans = snowballs[i] + snowballs[j] + snowballs[found]; 
            }
        }
    }
    cout << ans; 
}