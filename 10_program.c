/* Sum of series */

#include <stdio.h>
int main () {
    int n, i, sum=0, term=1;

    printf("Enter the term of series: ");
    scanf("%d", &n);

    for(i=1; i <= n; i++) {
        sum = sum + term;
        term = term + 3;

    }
     printf("%d", sum);
    return 0;
}

