#include <stdio.h>

void swap( int *arr, int l, int h )
{
    int temp = *( arr + l );
    *( arr + l ) = *( arr + h );
    *( arr + h ) = temp;

}

int partition( int *arr, int low, int high )
{
    int pivot = *( arr + high );
    int i = low - 1;

    for ( int j = low; j <= high - 1; j++ )
    {
        if ( *( arr + j ) < pivot )
        {
            i++;
            swap( arr, i, j );
        }
    }
    swap( arr, i + 1, high );
    return i + 1;
}

void divide( int *arr, int low, int high )
{
    if ( low < high )
    {
        int pivot = partition( arr, low, high );

        divide( arr, low, pivot - 1 );
        divide( arr, pivot + 1, high );
    }
}

void quick_sort( int n, int *arr )
{
   int low = 0;
   int high = n - 1;

   divide( arr, low, high );
}

int main()
{
    int i,arr[100],n;

    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:\n\n");

    for ( i = 0; i < n; i++)
    {
        printf("%d:\t",i+1);
        scanf("%d",&arr[i]);
    }

    quick_sort(n,arr);

    printf("\n\nSorted array is:\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    return 0;
}