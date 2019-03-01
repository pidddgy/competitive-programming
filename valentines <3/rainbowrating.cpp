// https://dmoj.ca/problem/valentines19j1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        if(a < 1000) cout << "Newbie";
        else if(a < 1200) cout << "Amateur";
        else if(a < 1500) cout << "Expert";
        else if(a < 1800) cout << "Candidate Master";
        else if(a < 2200) cout << "Master";
        else if(a < 3000) cout << "Grandmaster";
        else if(a < 4000) cout << "Target";
        else cout << "Rainbow Master";
        cout << endl;
    }
}
