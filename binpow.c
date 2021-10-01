#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TIMES 100000000LL
#define POWER 16

long long int binpow_recursive(long long int x, long long int y);
long long int binpow_cycle(long long int x, long long int y);

int main(int argc, char const *argv[])
{
    const int BASE = 2; // We need a const here because C compiler optimizes pow(10, 10), but doesn't optimize pow(BASE, 10);
    printf("Calculating %d^%d %lld times:\n", BASE, POWER, TIMES);
    //--------------------------------------------------------------------------------------
    clock_t start = clock();

    for(long long int i = 0; i < TIMES; i++){
        pow(BASE, POWER);
    }

    clock_t end = clock();
    printf("[Power]C realization: %.3lfs\n", ((double)(end-start))/CLOCKS_PER_SEC);
    //--------------------------------------------------------------------------------------
    start = clock();
    
    for(long long int i = 0; i < TIMES; i++){
        binpow_cycle(BASE, POWER);
    }

    end = clock();
    printf("[Power]Binary(cycle) algo: %.3lfs\n", ((double)(end-start))/CLOCKS_PER_SEC);
    //--------------------------------------------------------------------------------------
    start = clock();
    
    for(long long int i = 0; i < TIMES; i++){
        binpow_recursive(BASE, POWER);
    }

    end = clock();
    printf("[Power]Binary(recursive) algo: %.3lfs\n", ((double)(end-start))/CLOCKS_PER_SEC);
    //--------------------------------------------------------------------------------------
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
