#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}
int main()
{
    int num;
    int denom;
    scanf("%i%i", &num, &denom);

    double dividedThing = (double)num / (double)denom;

    int intpart = (int)dividedThing;
    double fractpart = dividedThing - (double)intpart;

    int fractMultiplied = fractpart*100;
    int GCD = gcd(fractMultiplied, 100);

    if(intpart != 0)
    {
        printf("%d ", intpart);
    }
    if(fractMultiplied / GCD != 0)
    {
        if (fractMultiplied / GCD == 33)
        {
            printf("1/3");
        } else if (fractMultiplied / GCD == 66)
        {
            printf("2/3");
        }
        else {
            printf("%d/%d", fractMultiplied / GCD, 100 / GCD);
        }
    }
    printf("\n");
}