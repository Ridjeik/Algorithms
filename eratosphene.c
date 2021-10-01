#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000

int *primeness_list(int size);

int main(int argc, char const *argv[])
{
    int *prime = primeness_list(LIMIT);
    for(int i = 1; i <= LIMIT; i++){
        printf("%d: %d\n", i, prime[i]);
    }
    
    return 0;
}

int* primeness_list(int size)
{
    int *prime = (int*)calloc(size+1, sizeof(int));

    for(long long int i = 2; i <= size; ++i) prime[i] = 1;
    prime[0] = prime[1] = 0;

    for(long long int i = 2; i*i <= size; ++i){
        if(prime[i]){
            for(long long int j = i*i; j <= size; j+=i){
                prime[j] = 0;
            }
        }
    }
    
    return prime;

}