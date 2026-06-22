#include <stdio.h>
int main()
{
    int arr[]= {10, 20,30, 40, 50};
    int key;
    printf("Enter the key: ", key);
    scanf("%d", &key);
    int found =0;

    for(int i = 0; i<=5; i++)
    {
        if(arr[i]==key)
        {
            found = 1;
            printf("Found at index %d", i);
            break;
        }
    }
    if(found==0)
    {
        printf("Not Found");
    }
    return 0;
}