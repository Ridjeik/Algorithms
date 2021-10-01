#include <stdio.h>
#include <stdlib.h>

int phi(int x);

int main(int argc, char const *argv[])
{
    printf("%d", phi(atoi(argv[1])));
    return 0;
}

int phi(int x)
{
    int res = x;
    for(int i = 2; i*i <= x; ++i){
        if(x % i == 0){
            while(x % i == 0){
                x /= i;
            }
            res -= res/i;
        }
    }
    if (x > 1)
		res -= res / x;
	return res;

    return res;
}