// https://codeforces.com/contest/1326/problem/0
    
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    
    while(n--) {
        int a;
        cin >> a;
    
        if(a == 1) {
            cout << -1 << endl;
        } else if(a == 2) {
            cout << 43 << endl;
        } else {
            vector<int> ans;
            long long int sum = 0;
            for(int i = 1; i <= a-2; i++) {
                ans.emplace_back(4);
                sum += 4;
            }
            
            ans.emplace_back(3);
            ans.emplace_back(3);
            sum += 6;

            for(int i = 0; i < ans.size(); i++) {
                // cerr << ans[i] << " ";
                if(sum % 3 == 0) {
                    sum--;
                    ans[i] = 3;
                }

                if(sum % 3 != 0) {
                    for(int i = 0; i < ans.size(); i++) {
                        cout << ans[i];
                    }
                    cout << endl;

                    break;
                }
            }
            // cerr << endl;
        }
    }
}