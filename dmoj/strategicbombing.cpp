#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> thingy[26];

    for(;;) {
        char a; char b;
        scanf(" %c%c", &a, &b);

        if(a == '*' && b == '*') 
            break;
        else {
            thingy[a - 65].push_back(b - 65);
            thingy[b - 65].push_back(a - 65);
        }
    }

    // For every edge try bfsing without that edge and see if connection between A and B still exists (edge = i->j)
    int count = 0;
    for(int i = 0; i < 26; i++)
        for(auto j: thingy[i]) {
            queue<int> Q;
            bool vis[26]; for(int i = 0; i < 26; i++) vis[i] = false;
            bool found = false;

            Q.push('A' - 65);
            vis['A' - 65] = true;

            while(!Q.empty()) {
                int s = Q.front();
                Q.pop();
                if(s == 'B' - 65)
                    found = true;

                for(auto adj: thingy[s])
                    if(!vis[adj])
                        if(!(s == i && adj == j)) {
                            vis[adj] = true;
                            Q.push(adj);
                        }
            }
            
            if(!found) {
                printf("%c%c\n", 65+i, 65+j);
                count++;
            }
        }

    printf("There are %i disconnecting roads.\n", count);
}
