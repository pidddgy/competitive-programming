// https://dmoj.ca/problem/thicc17p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    // N == plants, M == people
    int N, M;
    cin >> N >> M;
    int cost[N];

    for(int i = 0; i < N; i++) 
        cin >> cost[i];

    sort(cost, cost+N, greater<int>());

    int exp = 0;
    unsigned long long int price = 0;
    int plantsLeftAtCurrentPrice = M;

    for(int i = 0; i < N; i++) {
        price += pow(cost[i], exp);
        plantsLeftAtCurrentPrice--;
        if(plantsLeftAtCurrentPrice == 0)  {
            exp++;
            plantsLeftAtCurrentPrice = M;
        }
    }

    cout << price % 1000000007 << "\n";
}
