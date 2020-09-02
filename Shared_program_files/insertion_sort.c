#include <stdio.h>

void insertion_sort( int n, int *arr )
{
    int key,j;
    for ( int i = 1; i < n; i++ )
    {
        key = *(arr + i);
        j = i - 1;

        while ( j >= 0 && *(arr + j) > key )
        {
            *(arr + j + 1) =  *(arr + j);
            --j; 
        }
        *(arr + j + 1) = key;
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

    insertion_sort(n,arr);

    printf("\n\nSorted array is:\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    return 0;
}