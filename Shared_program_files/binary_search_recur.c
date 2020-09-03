#include <stdio.h>

void sort (int *arr, int n)
{
    int select;
    for ( int i = 0; i < n - 1; i++ )
    {
        for ( int j = i + 1; j < n; j++ )
        {
            select = *( arr + i );
            if ( select > *(arr + j ) )
            {
                *( arr + i ) = *( arr + j );
                *( arr + j ) = select;
            }
        }
    }  
}

int recursion( int search, int *arr, int first, int last )
{
    int mid = ( first + last )/2;

    if ( *(arr + mid) == search )
    {
        return mid;
    }
    else if ( first >= last )
    {
        return -1;
    }
    else if ( search > *(arr + mid) )
    {
        first = mid + 1;
        recursion( search, arr, first, last );
    }
    else if ( search < *(arr + mid) )
    {
        last = mid - 1;
        recursion( search, arr, first, last );
    }
}

void recursive_binary_search( int x, int n, int *arr)
{
    sort( arr, n );
    int found = recursion( x, arr, 0, n-1 );

    if ( found >= 0 )
    {
        printf("The element is present.");
    }
    else
    {
        printf("The element is not found.");
    }
}

int main()
{
    int i,arr[100],n,search;

    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:\n\n");

    for (i=0;i<n;i++)
    {
        printf("%d:\t",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nElement to search:");
    scanf("%d",&search);

    recursive_binary_search(search,n,arr);
    return 0;
}