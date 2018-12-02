#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    scanf("%i ", &N);
    string sentence;
    for(int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        sentence.append(line);
    }
    int S = count(sentence.begin(), sentence.end(), 'S');
    int s = count(sentence.begin(), sentence.end(), 's');

    int T = count(sentence.begin(), sentence.end(), 'T');
    int t = count(sentence.begin(), sentence.end(), 't');

    if(t+T > s+S)
        printf("English\n");
    else
        printf("French\n");
}
