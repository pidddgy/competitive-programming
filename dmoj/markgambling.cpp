// https://dmoj.ca/problem/globexcup18j2

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    double a[N];

    double sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }

    double avg = sum / (double)N;
    sort(a, a+N);
    int mid;
    if(N % 2 == 0) mid = (N / 2) - 1;
    else mid = N / 2;

    if(a[mid] > avg)
        cout << "Winnie should take the risk" << endl;
    else
    {
        cout << "That's too risky" << endl;
    }
    
}


