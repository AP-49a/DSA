//currently doesnot work because of integer overflow.
#include<stdio.h> // not needed in leetcode.
#include<stdbool.h>

bool isPalindrome(int x)
{
    if(x < 0)
    {
        return false;
    }

    int original = x;
    int reverse = 0;

    while (x!=0)
    {
        int digit = x % 10;
        reverse = reverse * 10 + digit;
        x /= 10;
    }

    return original == reverse;
}

int main() // main function is not needed in leetcode, i did it just to run the code in my IDE.
{
    int n;

    printf("Enter the integer: ");
    scanf("%d", &n);

    if(isPalindrome(n))
    {
        printf("%d is a palindrome number.\n", n);
    }
    else
    {
        printf("%d is not a palindrome number.\n", n);
    }

    return 0;
}