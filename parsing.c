#include "push_swap.h"

// Simple sorting algorithm (e.g., bubble sort) to replace qsort
void simple_sort(int *array, int size) {
    int sorted = 0;
    while (!sorted) 
    {
        sorted = 1;
        int i = 0;
        while (i < size - 1)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = 0;
            }
            i++;
        }
    }
}
// Function to compare integers for sorting
int compare_ints(const void *a, const void *b) 
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void rank_numbers(int *nums, int size) {
    int *sorted_nums = malloc(size * sizeof(int));
    int *ranks = malloc(size * sizeof(int));
    if (!sorted_nums || !ranks) 
    {
        // Handle memory allocation error
        return ;
    }

    memcpy(sorted_nums, nums, size * sizeof(int)); // to do
    simple_sort(sorted_nums, size); // Using simple_sort instead of qsort

    int i = 0;
    while (i < size)
    {
        int j = 0;
        while (j < size)
         {
            if (nums[i] == sorted_nums[j]) 
            {
                ranks[i] = j + 1; // Rank starts from 1
                break;
            }
            j++;
        }
        i++;
    }

    memcpy(nums, ranks, size * sizeof(int));

    free(sorted_nums);
    free(ranks);
}

int is_valid_int(const char *str) {
    // Handle potential leading sign
    if (*str == '+' || *str == '-') {
        str++;
    }

    // Check for empty string after the sign
    if (*str == '\0') {
        return 0;
    }

    // Check each character
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;  // Not a valid digit
        }
        str++;
    }

    return 1;  // Valid integer
}

int *extract_numbers(char **argv, int *size) 
{
    int count; 
    int i;
    long val;
    int *nums;

    count = 0;
    while (argv[count] != NULL)
        count++;

    nums = malloc(count * sizeof(int));
    i = 0;
    while (i < count) {
        if (!is_valid_int(argv[i])) {
            error_free(NULL, "Error\n");
        }
        val = atol(argv[i]);
        if (val > INT_MAX || val < INT_MIN) {
            error_free(NULL, "Error\n");
        }
        nums[i] = (int)val;
        i++;
    }
    *size = count;
    return nums;
}
