#include <stdio.h>

void selection_sort( int n, int *arr )
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

    selection_sort(n,arr);

    printf("\n\nSorted array is:\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    return 0;
}