#include <stdio.h>
#include <stdlib.h>

long long int binpow_recursive(long long int x, long long int y);
long long int binpow_cycle(long long int x, long long int y);

int main(int argc, char const *argv[])
{
    printf("Recursive: %lld\n", binpow_recursive(atol(argv[1]), atol(argv[2])));
    printf("Cyclic: %lld", binpow_cycle(atol(argv[1]), atol(argv[2])));
    return 0;
}

long long int binpow_cycle(long long int x, long long int y)
{
    long long int res = 1;
    while (y)
    {
        if(y & 1){
            res *= x;
        }
        x *= x;
        y >>= 1; // y /= 2;
    }
    return res;
    
}

long long int binpow_recursive(long long int x, long long int y)
{
    if(y == 1) return x;
    if(y == 2) return x*x;
    if(!(y % 2)){
        long long int a = binpow_recursive(x, y/2); 
        return a*a;
    } 
    if(y%2){
        long long int a = binpow_recursive(x, (y-1)/2);
        return a*a*x;
    }
    return 0;
}
