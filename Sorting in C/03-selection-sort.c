#include <stdio.h>

// Function to print an array of integers
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Selection Sort Algorithm
void selectionSort(int *A, int n)
{
    int indexOfMin, temp;
    printf("Running Selection Sort...\n");

    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;

        // Find the index of the minimum element in the unsorted portion of the array
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }

        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    // Initialize an array of integers
    int A[] = {3, 5, 2, 13, 12};
    int n = 5;

    printf("Array Before Sorting: ");
    printArray(A, n);

    selectionSort(A, n);

    printf("Sorted Array: ");
    printArray(A, n);

    return 0;
}

/* Understanding the Code:
1. The first step is to define an array of elements. We define an array of integers.
2. Define an integer variable for storing the size/length of the array.
3. Before we proceed to write the function for Selection Sort, we would first make a function for displaying the array's content.
4. Create a void function selectionSort and pass the array's address and the array's length as its parameters. Create two integer variables, one for maintaining the min index, called the indexOfMin, and another for swapping purposes called the Now; create a for loop that tracks the number of passes. If we can recall, to sort an array of length 5 using the selection sort algorithm, we made a total of 4 passes. So, for an array of length n, we would make (n-1) passes. And the loop starts from the 0th index and ends at (n-1)th.
And if we remember, at each pass, we first initialize the indexOfMin to be the first index of the unsorted part. So, inside this loop, initialize the indexOfMin to be i, which is always the first index of the unsorted part of the array.
Create another loop to iterate over the rest of the elements in the unsorted part to find if there is any lesser element than the one at indexOfMin. Make this loop run from i+1 to the last. And compare the elements at every index. If you find an element at index j, which is less than the element at indexOfMin, then update indexOfMin to j.
And finally, when we finish iterating through the second loop, just swap the elements at indices i & indexOfMin. Swap using the temp variable. Follow the same steps at each pass.
And at the end, when we finish iterating through both the i and the j loops, you would receive a sorted array. All we had to do was this.
*/