/* Palindrome/ Reverse of a number */

#include <stdio.h>

int main () {

    int n, rev=0, temp, rem;

    printf("Enter the number: ");
    scanf("%d", &n);

    temp=n;

    while(temp != 0) {
        rem = temp % 10;
        rev = rev * 10 +rem;
        temp = temp/10;
    }

    if(rev == n)
        printf("%d is a palindrome number", n);

        else
        printf("%d is not a palindrome number", n);
        
        return 0;

}