#include <stdio.h>

void conquer( int *arr, int low, int mid, int high )
{
    int i,j,k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1],R[n2];

    for ( i = 0; i < n1; i++ )
    {
        L[i] = *(arr + low + i);
    }
    for ( j = 0; j < n2; j++ )
    {
        R[j] = *(arr + mid + 1 + j);
    }

    i = 0;
    j = 0;
    k = low;

    while ( i < n1 && j < n2 )
    {
        if ( L[i] <= R[j] )
        {
            *(arr + k) = L[i];
            i++;
        }
        else
        {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }

    while ( i < n1 )
    {
        *(arr + k) = L[i];
        i++;
        k++;
    }
    while ( j < n2 )
    {
        *(arr + k) = R[j];
        j++;
        k++;
    }
}

void divide( int *arr, int low, int high )
{
    if ( low < high )
    {
        int mid = ( low + high - 1 )/2;

        divide( arr, low, mid );
        divide( arr, mid + 1, high );

        conquer( arr, low, mid, high );
    }
}

void merge_sort( int n, int *arr )
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

    merge_sort(n,arr);

    printf("\n\nSorted array is:\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    return 0;
}