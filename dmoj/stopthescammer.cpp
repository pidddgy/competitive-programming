#include <bits/stdc++.h>
using namespace std;
int main() {
  int totalClaps = 0;
  int articlesNeeded = 0; // return this
  int clapsRequired, clapsPerArticle, clapsDecrement;
  scanf("%i %i %i", &clapsRequired, &clapsPerArticle, &clapsDecrement); 

  while(totalClaps < clapsRequired && clapsPerArticle > 0) {
    totalClaps += 2 * clapsPerArticle;
    clapsPerArticle -= clapsDecrement;
    articlesNeeded++;
  }
  printf("%i\n",articlesNeeded);
  return 0;
}