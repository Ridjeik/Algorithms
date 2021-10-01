#include <stdio.h>
#include <stdlib.h>

long long int gcd_recursive(long long int x, long long int y);

int main(int argc, char const *argv[])
{
    printf("%lld", gcd_recursive(atol(argv[1]), atol(argv[2])));
    return 0;
}


long long int gcd_recursive(long long int x, long long int y)
{
    if(y == 0){
        return x;
    }
    else return gcd_recursive(y, x%y);
}