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

// Insertion Sort algorithm
void insertionSort(int *A, int n)
{
    int key, j;

    // Loop for passes
    for (int i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;

        // Loop for each pass, moving elements to the right
        // until the correct position is found for the key
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }
}

int main()
{
    // -1   0    1   2   3   4   5
    //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
    //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

    //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
    //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

    //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
    //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
    //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
    //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
    //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

    // Fast forwarding and 4th and 5th pass will give:
    //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
    //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

    //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
    //      07, 09, 12, 23, 54, 65| --> After the 5th pass

    // Initialize an array of integers
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;

    // Print the array before sorting
    printf("Array Before Sorting: ");
    printArray(A, n);

    // Sort the array using the insertionSort function
    insertionSort(A, n);

    // Print the sorted array
    printf("Sorted Array: ");
    printArray(A, n);

    return 0;
}

/* Understanding the Code:
1. The first step is to define an array of elements. We are defining an array of integers.
2. Define an integer variable for storing the size/length of the array.
3. Before we proceed to write the function for Insertion Sort, we would first make a function for displaying the contents of the array.

4. Create a void function insertionSort and pass the address of the array and its length as its parameters. Now, create a for loop which would track the number of passes. If you recall, to sort an array of length 5 using insertion sort algorithm, we made a total of 4 passes, which is obviously, 5-1. So, for an array of length n, we would make (n-1) passes. But this time the loop starts from the 1st index, and not from the 0th since the first element is sorted whatsoever. So, make this loop run from 1 to (n-1).
Inside this loop, collect the element at the index i in an integer variable key. This key is the element we would insert in the sorted sub array.
Create another index variable j, which would be used to iterate through the sorted sub array, and to find a perfect position for the key. The index variable j holds the value i-1.
Make a while loop run until either we finish through the sorted sub array and reach the last position, or else we find an index fit for the key. And until we come out of the loop, keep shifting the elements to their right and reduce j by 1. And once we come out, insert the key at the current value of j+1. And this would go on for n-1 passes.
Here, i=2, and the element we have at index i is 1. No, this element needs to be given a position in the sorted sub array. So, j = i - 1 which is 1. We run a while loop up until j becomes 0 or we find a position for the key 1. So, when j=1, we check if the element at the jth index is smaller than the key or not. Since it's not, we shift it to the right and reduce j by 1.
And now j=0, and we have element 2 at the j th index, and it is bigger than the key, hence, we shift even this. And then reducing j makes it equal to -1. So, we stop there itself. And insert the key at j+1 which is at 0.
*/