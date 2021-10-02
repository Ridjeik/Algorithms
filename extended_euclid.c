#include <stdio.h>
#include <stdlib.h>

long long int gcd(long long int x, long long int y, long long int *a, long long int *b);

int main(int argc, char const *argv[])
{
    long long int coef1, coef2;
    long long int gcd_res = gcd(atol(argv[1]), atol(argv[2]), &coef1, &coef2);
    printf("%lld: %lld %lld", gcd_res, coef1, coef2);
}


long long int gcd(long long int x, long long int y, long long int *a, long long int *b)
{
    if(x == 0){
        *a = 0; *b = 1;
        return y;
    }
    long long int a1, b1;
    long long int res = gcd(y%x, x, &a1, &b1);
    *a = b1 - (y/x)*a1;
    *b = a1;
    return res;
}
