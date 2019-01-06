// https://dmoj.ca/problem/dmpg17s2

#include<bits/stdc++.h>
using namespace std;

int findRoot(vector< pair<int, int> > &subsets, int findee)
{
    if(subsets[findee].first != findee)
    {
        subsets[findee].first = findRoot(subsets, subsets[findee].first);
    }
    return subsets[findee].first;
}

int main()
{
    int N; int Q;
    vector< pair<int, int> > cities = {}; // .first == parent, .second == rank
    scanf("%i%i", &N, &Q);

    for(int i = 0; i < N + 1; i++)
    {
        cities.emplace_back(i, 1);
    }

    for(int i = 0; i < Q; i++)
    {
        char typeOfQuery; int x; int y;
        scanf(" %c%i%i", &typeOfQuery, &x, &y);
        if(typeOfQuery == 'A')
        {
            int xroot = findRoot(cities, x);
            int yroot = findRoot(cities, y);
            if(cities[xroot].second > cities[yroot].second)
            {
                cities[yroot].first = xroot;
            } 
            else if (cities[yroot].second > cities[xroot].second)
            {
                cities[xroot].first = yroot;
            } else {
                cities[yroot].first = xroot;
                cities[xroot].second++;
            }
        } 
        else if (typeOfQuery == 'Q')
        {
            // If the two cities belong to same set
            if(findRoot(cities,x) == findRoot(cities,y))
            {
                printf("Y\n");
            } else {
                printf("N\n");
            }
        }
        
    }
}
