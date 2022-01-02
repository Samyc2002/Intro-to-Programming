#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int palindrome(long int v) {
    long int reverse = 0,n,i,j;
    n=v;
    while (n != 0) {
        reverse = reverse * 10;
        reverse = reverse + n%10;
        n = n/10;
    }
    if(reverse == v) {
        for(i=100;i<=999;i++) {
            for(j=100;j<=999;j++) {
                if(i*j==v) return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        long int val;
        scanf("%ld",&val);
        int f=0;
        while(f==0) {
            f=palindrome(--val);
        }
        printf("%ld\n",val);
    }
    return 0;
}