// https://dmoj.ca/problem/ccc16s2

#include <bits/stdc++.h>
using namespace std;
int main() {
    int question, N;
    cin >> question >> N;
    int D[N]; int P[N];

    for(int i = 0; i < N; i++)
        cin >> D[i];
    for(int i = 0; i < N; i++)
        cin >> P[i];

    sort(D, D+N);
    sort(P, P+N);

    int count = 0;
    if(question == 2)
        for(int i = 0; i < N; i++)
            count += max(D[i], P[N-i-1]);
    else
        for(int i = 0; i < N; i++)
            count += max(D[i], P[i]);
    cout << count << "\n";
}
