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

// Classic Bubble Sort algorithm
void bubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For the number of passes
    {
        printf("Working on Pass Number %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++) // For comparisons in each pass
        {
            if (A[j] > A[j + 1])
            {
                // Swap two elements if they are in the wrong order
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// Bubble Sort algorithm with an adaptive flag
void bubbleSortAdaptive(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For the number of passes
    {
        printf("Working on Pass Number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // For comparisons in each pass
        {
            if (A[j] > A[j + 1])
            {
                // Swap two elements if they are in the wrong order
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            // If the array is already sorted, exit early
            return;
        }
    }
}

int main()
{
    // Initialize an array of integers
    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 955, 986, 987};
    int n = 11;

    // Print the array before sorting
    printf("Array Before Sorting: ");
    printArray(A, n);

    // Sort the array using the bubbleSort function
    bubbleSortAdaptive(A, n);

    // Print the sorted array
    printf("Sorted Array: ");
    printArray(A, n);

    return 0;
}

/* Understanding the Code:
1. The first step is to define an array of elements, such as integers or characters. We are taking an array of integers.
2. Define an integer variable for storing the size/length of the array.
3. Before we proceed to write the function for Bubble Sort, we would first make a function for displaying the contents of the array.
4. Create a void function printArray, and pass the address of the array and its length as its parameters. It doesn't take much to use a for loop to print the array elements.

5. Create another void function bubbleSort and pass the address of the array and its length as its parameters. Now, create a for loop which would track the number of passes. If we can recall, to sort an array of length 6, we made a total of 5 passes, which is obviously, 6-1. So, for length n, we would make (n-1) passes. So, make this loop run from 0 to (n-1). Inside this loop, make another for loop to track the index we are making a comparison at.
Can we decode the limit of this loop? It is obvious that we start from 0, but to which index? We saw that with each pass, we reduced the size of the unsorted array by 1. In the first pass, we had the size of the unsorted array, 6, hence we made 5 comparisons. And for every subsequent pass, we made 4, 3, 2, and 1 comparison. Let i be the variable to store the pass we are at. Then the number of comparisons for i th pass would be (n-i), where n is the length of the array. Since we started from i=0 in the program, it would be (n-i-1) number of comparisons.
Inside this nested for loop, check if the jth element of the array is greater than the (j+1)th element. Here, j is the counter variable of the second for loop. So, if the jth element of the array is greater than the (j+1)th element, then swap their positions, since we want these to be sorted. Swapping needs you to define a temporary integer variable temp. Use it to swap the jth and the (j+1)th element.
And the array would itself get sorted. All we had to do was this.

6. What would an adaptive bubble sort do? Once it detects that our array has already been sorted, it will not perform any more comparisons. So, just a single pass should do the job.
Therefore, the catch here is that the array is already sorted if we didn't have to perform any swapping during any of the passes. This is where we will stop making any more passes.
Create another void function bubbleSortAdaptive, and pass the address of the array and its length as its parameters. Create the same two loops, one nested in the other. First one runs from 0 to n-1, and another from 0 to n-i-1. We will make an integer variable isSorted which would hold 1 if our array is sorted and 0 otherwise. Make isSorted equal to 1 prior to starting any comparison in each pass. If any of our comparisons demands swapping of elements, we switch isSorted to 0.
At the end of each pass, check if the isSorted changed to 0. If it did, our array was not yet sorted; otherwise, end the comparison there itself, since our array was already sorted.
And this makes our bubble sort algorithm adaptive.
*/
