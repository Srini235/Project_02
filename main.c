#include <stdio.h>

int array_check[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
    //binary search algorithm
    int left = 0;   
    int right = 9;
    int mid;
    int search = 5;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (array_check[mid] == search)
        {
            printf("Element found at index %d\n", mid);
            break;
        }
        else if (array_check[mid] < search)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return 0;
}
// int main()
// {
//     printf("Hello World\n");
//     return 0;
// }
