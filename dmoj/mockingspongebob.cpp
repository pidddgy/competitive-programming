#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%i ", &N); 
    for(int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        bool lower = true;
        for(int j = 0; j < line.size(); j++)
            if(isalpha(line[j])) {
                if(lower) printf("%c", tolower(line[j]));
                else printf("%c", toupper(line[j]));
                lower = !lower;
            } else
                printf("%c",line[j]);

        printf("\n");
    }
}
