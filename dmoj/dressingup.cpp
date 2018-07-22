#include <bits/stdc++.h>
using namespace std;
int main() {
  int bowTieHeight;
  scanf("%i", &bowTieHeight);
  for (int starNum = 1; starNum < bowTieHeight; starNum += 2) {
    for (int i = 0; i < starNum; i++) {
      printf("*");
    }
    for (int x = 0; x < (bowTieHeight - starNum) * 2; x++) {
      printf(" ");
    }
    for (int i = 0; i < starNum; i++) {
      printf("*");
    }
    printf("\n");
  }

  for (int m = 0; m < (bowTieHeight * 2); m++) {
    printf("*");
  }
  printf("\n");

  for (int starNum = bowTieHeight - 2; starNum > 0; starNum -= 2) {
    for (int i = 0; i < starNum; i++) {
      printf("*");
    }
    for (int x = 0; x < (bowTieHeight - starNum) * 2; x++) {
      printf(" ");
    }
    for (int i = 0; i < starNum; i++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
