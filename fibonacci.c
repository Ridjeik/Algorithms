#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMES 20000000LL
#define ELEM 80

long long int fib_matrix(int n);
long long int fib_linear(int n);

int main(int argc, char const *argv[])
{
    printf("Calculating %dth fibonacci number %lld times:\n", ELEM, TIMES);
    //--------------------------------------------------------------------------------------
    clock_t start = clock();

    for(int i = 0; i < TIMES; i++){
        fib_linear(ELEM);
    }

    clock_t end = clock();
    printf("[Fibonacci]Linear realization: %.3lfs\n", ((double)(end-start))/CLOCKS_PER_SEC);
    //--------------------------------------------------------------------------------------
    start = clock();
    
    for(int i = 0; i < TIMES; i++){
        fib_matrix(ELEM);
    }

    end = clock();
    printf("[Fibonacci]Matrix realization: %.3lfs\n", ((double)(end-start))/CLOCKS_PER_SEC);
    //--------------------------------------------------------------------------------------
    return 0;
}

long long int fib_linear(int n)
{
    long long int n1 = 1, n2 = 1;
    for(int i = 3; i <= n; i++){
        if(n2 >= n1) n1 += n2;
        else n2 += n1;  
    }
    return n1 > n2 ? n1 : n2;
    
}

long long int fib_matrix(int n)
{
    long long int result_a = 0, result_b = 1,
        a = 0, b = 1, ta = a, tb = b,
        c = 1, d = 1, tc = c,
        temp_result_a = result_a;
    
    while (n)
    {
        if(n & 1){
            temp_result_a = result_a;
            result_a = result_a * a + result_b * c;
            result_b = temp_result_a * b + result_b * d;  
        }

        ta = a;
        tb = b;
        tc = c;
        a = a*a + b*c;
        b = ta*b + b*d;
        c = c*ta + d*c;
        d = tc*tb + d*d;

        n >>= 1;
    }
    return result_a;
}