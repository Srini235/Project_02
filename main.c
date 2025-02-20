/* Includes */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Function prototypes */
void binary_search_copilot(void);
void binary_search_manual(void);
uint8_t storeArrayData(uint8_t *array);
void printArrayData(uint8_t search_index_u8, uint8_t *array);
void binarySearch(void);
uint8_t binarySearchNew(uint8_t num_elements_u8,uint8_t *array, uint8_t search_value_u8);

int array_check[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main()
{
    //binary_search_copilot();
    binary_search_manual();
    return 0;
}

void binary_search_copilot(void)
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
}

uint8_t array_for_search[]; //array used for binary search
uint8_t search_value_u8; //value used for binary search
uint8_t searchStatus_u8;    //binary search status

void binary_search_manual(void)
{
    //Binary search algorithm in a generic way
    // uint8_t left_index_u8 = 0;
    // uint8_t right_index_u8 = 0;
     uint8_t search_index_u8 = 0;

    //Get array data to be searched
    search_index_u8 = storeArrayData(array_for_search);

    //for debug purpose
    printArrayData(search_index_u8, array_for_search);


    //get value for search in array
    printf("Enter value for search: \n");
    scanf("%hhd", &search_value_u8);

    searchStatus_u8 = binarySearchNew(search_index_u8, array_for_search, search_value_u8);

    if(searchStatus_u8 == 0)
    {
        printf("Element not found\n");
    }


}


uint8_t storeArrayData(uint8_t *array)
{
    //Note: This code has error, which has to be corrected. Unit test failure for value < 0 and value > 255

    uint8_t index_u8;
    for(index_u8 = 0; index_u8 < 10; index_u8++)
    {
        printf("Enter value to be stored in array, enter value 0 to end receiving input values \n");
        scanf("%hhd", &array[index_u8]);
        if(array[index_u8] == 0)
        {
            printf("Ending value received\n");
            break;
        }
        else if((array[index_u8] < 0) || (array[index_u8] > 255))
        {
            printf("Invalid value entered, please enter a value between 0 and 255\n");
            index_u8--;
        }
        else
        {
            printf("Value stored in array\n");
        }
    }
    return index_u8;
}

void printArrayData(uint8_t search_index_u8, uint8_t *array)
{
    //print stored array data
    uint8_t index_u8;
    for(index_u8 = 0; index_u8 < search_index_u8; index_u8++)
    {
        printf("Array index = %hhd; Value = %hhd \n", index_u8, array[index_u8]);
    }
}

uint8_t binarySearchNew(uint8_t num_elements_u8, uint8_t *array, uint8_t search_value_u8)
{
    //finally, binary search algorithm
    uint8_t first_u8 = 0;
    uint8_t last_u8 = num_elements_u8;
    uint8_t mid_u8;
    uint8_t searchStatusLocal_u8;
    searchStatusLocal_u8 = 0;
    
    while (first_u8 <= last_u8)
    {
        mid_u8 = first_u8 + (last_u8 - first_u8)/2;
        if(array[mid_u8] == search_value_u8)
        {
            //Found the search element. Report it along with index
            printf("%d found at index %d", search_value_u8, mid_u8);
            searchStatusLocal_u8 = 1;
            break;
        }
        else if(array[mid_u8] < search_value_u8)
        {
            //Value to be searched is more than current value. Shift right
            first_u8 = mid_u8 + 1;
        }
        else if(array[mid_u8] > search_value_u8)
        {
            //Value to be searched is less than current value. Shift left
            last_u8 = mid_u8 - 1;
        }
    }
    return searchStatusLocal_u8;
}