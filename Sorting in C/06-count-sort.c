#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Function to print an array
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Function to find the maximum element in an array
int maximum(int A[], int n)
{
    int max = INT_MIN; // Initialize max to the smallest possible integer value
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i]; // Update max if a larger element is found
        }
    }
    return max; // Return the maximum element
}

// Function to perform counting sort
void countSort(int *A, int n)
{
    int i, j;
    // Find the maximum element in A
    int max = maximum(A, n);

    // Create the count array to store the count of each element
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Initialize the count array elements to 0
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Increment the count of each element in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0; // Counter for the count array
    j = 0; // Counter for the given array A

    // Reconstruct the original array based on the counts
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;                // Place the element in its correct position
            count[i] = count[i] - 1; // Decrement the count
            j++;                     // Move to the next position in the original array
        }
        else
        {
            i++; // Move to the next element in the count array
        }
    }
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    // Print the array before sorting
    printf("Array Before Sorting: ");
    printArray(A, n);
    countSort(A, n); // Call countSort to sort the array
    // Print the sorted array
    printf("Sorted Array: ");
    printArray(A, n);
    return 0;
}

/* Understanding the Code:
1. First we make a function for displaying the array's content. This just helps a lot seeing the contents of the array before and after the sorting.
2. Now, to proceed with the countSort function, we would need a maximum function, which would return the maximum of all elements in the array given.

3. Creating the maximum function:
Create an integer function maximum and pass the array and its length as its parameters. Create an integer variable max to store the maximum element. Initialize this max with the least possible number we have, which is to use this identifier; we must include <limits.h>. Now iterate through the whole array using a for loop, and if we find an element greater than the current max, update max. At the end, return max.

4. Create a void function countSort and pass the array and its length as its parameters. Create an integer variable max to store the maximum element which you get by calling the maximum function we made above. Next, create an integer array count and assign it memory dynamically using malloc of the size max+1. Don’t forget to include <stdlib.h> to be able to use malloc.
Initialize the whole count array by simply using a for a loop.
Run another for loop to iterate through the given array and increase the value of the corresponding element index in the count array by 1.

5. Now, since the count array has been populated, create two index variables, i and j, to iterate through the count and the given array, respectively. Run a while loop until we reach the end of the count array. Inside the loop, check if the element at the current index in the count array is non-zero. If it is, insert i at the jth index of the given array and decrement the element in the count array at ith index by 1 and simultaneously increase the value of j by 1. Repeat this until the element at the ith index becomes zero or if it is already zero, increase i by 1.
The array becomes sorted once all the processes listed above are complete.
*/