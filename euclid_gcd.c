#include <stdio.h>
#include <stdlib.h>

long long int gcd_recursive(long long int x, long long int y);
long long int gcd_cycle(long long int x, long long int y);

int main(int argc, char const *argv[])
{
    printf("Recursive: %lld\n", gcd_recursive(atol(argv[1]), atol(argv[2])));
    printf("Cyclic: %lld", gcd_cycle(atol(argv[1]), atol(argv[2])));
    return 0;
}

long long int gcd_cycle(long long int x, long long int y)
{
    long long temp = 0;
    while(y){
        x %= y;
        temp = x;
        x = y;
        y = temp;
    }
    return x;
}

long long int gcd_recursive(long long int x, long long int y)
{
    if(y == 0){
        return x;
    }
    else return gcd_recursive(y, x%y);
}