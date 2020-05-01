#include <bits/stdc++.h>
/*
TASK: hidden
LANG: C++11
*/
using namespace std;
typedef long long ll;
typedef pair<long long, int> pair2;
typedef pair<int, pair<int, int> > pair3;
typedef pair<int, pair<int, pair<int, int> > > pair4;
#define MAXN 300000
//#define INFINITY 1000000000000000LL
#define mp make_pair
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define add push_back
#define remove pop
    
int n, coordinates[MAXN];
int main() {
    //freopen("shufflegold.in", "r", stdin);
    //freopen("shufflegold.out", "w", stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> coordinates[i];
    }
    
    sort(coordinates, coordinates + n);
    /*
    for (int i = 0; i < n; i++) {
        cout << coordinates[i] << endl;
    }*/
    
    ll twoSum = 0;
    
    ll answer = 0;
    ll previous = 0;
    for (int i = 1; i < n; i++) {
        ll diff = coordinates[i] - coordinates[i - 1];
    
        twoSum = twoSum * 2 + 1;

        twoSum %= 1000000007;
        previous = (previous) * 2 + twoSum * diff;
        previous %= 1000000007;

        answer += previous;//previous = answer;
        answer %= 1000000007;	

        watch(answer)
    }
    
    cout << answer << '\n';
}