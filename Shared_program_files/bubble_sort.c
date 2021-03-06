#include <stdio.h>

void bubble_sort( int n, int *arr )
{
    int temp;
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n-i-1; j++ )
        {
            if ( *(arr + j) > *(arr + j + 1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main()
{
    int i,arr[100],n;

    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:\n\n");

    for (i=0;i<n;i++)
    {
        printf("%d:\t",i+1);
        scanf("%d",&arr[i]);
    }

    bubble_sort(n,arr);

    printf("\n\nSorted array is:\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    return 0;
}