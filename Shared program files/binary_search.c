

#include <stdio.h>

void sort ( int *arr, int n )
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

int binary_search( int x, int n, int *arr )
{
    sort( arr, n );
    int mid,max,min;

    min = 0;
    max = n - 1;
    mid = ( ( min + max)/2);

    while (min <= max)
    {
        if ( mid == x)
        {
            printf("The element is present in %d",mid);
            return 0;
        }
        else if ( mid < x)
        {
            min = mid - 1;
            mid = ( ( min + max)/2);
        }
        else if ( mid > x)
        {
            max = mid + 1;
            mid = ( ( min + max)/2);
        }
    }
    printf("The element is not found.");
    return 0;
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

    binary_search(search,n,arr);
    return 0;
}