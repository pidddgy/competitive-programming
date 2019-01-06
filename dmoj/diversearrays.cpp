// https://dmoj.ca/problem/acc3p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    int A[N];
    unordered_map<int, int> freq;
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }

    int total = 0;

    for(int i = 1; i < N; i++) {
        cout << "currently on elem " << i << endl;
        unordered_map<int, int> freqi = freq;
        for(int j = 0; j < i; j++) {
            freqi.erase(freqi[A[j]]);
            if(freqi.size() < K) {
                cout << "leftmost element is " << j << endl;
                cout << "adding " << N-freqi.size() << endl;
                total += N-freqi.size();
                break;
            }
        }
    }
    cout << "total subarrays is " << ((pow(N, 2) + N)/2) << endl;
    cout << ((pow(N, 2) + N)/2)-total << endl;
}
