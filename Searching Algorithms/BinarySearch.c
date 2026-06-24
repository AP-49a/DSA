#include <stdio.h>

int BinarySearch(int a[], int n, int data)
{
    int l = 0, r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (data == a[mid])
        {
            return mid;
        }
        else if (data < a[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    int data;

    printf("Enter the number to search: ");
    scanf("%d", &data);

    int pos = BinarySearch(a, n, data);

    if (pos != -1)
        printf("Element found at index %d\n", pos);
    else
        printf("Element not found\n");

    return 0;
}