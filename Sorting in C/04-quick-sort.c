#include <stdio.h>

// Function to print an array
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Function to partition the array for Quick Sort
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            // Swap A[i] and A[j]
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j; // Index of the pivot after partition
}

// Function to perform Quick Sort
void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // Sort the left sub array
        quickSort(A, partitionIndex + 1, high); // Sort the right sub array
    }
}

int main()
{
    // int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    // Input array
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3
    int n = 9; // Number of elements in the array
    n = 7;

    printf("Array Before Sorting: ");
    printArray(A, n);

    // Call the Quick Sort function
    quickSort(A, 0, n - 1); 

    printf("Sorted Array: ");
    printArray(A, n);

    return 0;
}

/* Understanding the Code
1. First we make a function for displaying the array's content. This just helps a lot seeing the contents of the array before and after the sorting.
2. The next step is to define an array of elements. As always, we define an array of integers.
3. Define an integer variable for storing the size/length of the array.

4. If we recall what we did every time we were given an unsorted sub array, we just applied a partition on it. Now, since partition is a different job, we will have a different function for that. But the quicksort function just intends to follow things to partition. Like, if we pass an array to quicksort, it further passes it to the partition function, and the partition returns the pivot index after applying all the steps we discussed earlier. Quicksort stores this index and recursively calls itself with smaller sub arrays which lie on the left and the right of the pivot index.
For example, if we call quicksort passing the above array, It would pass it further to the partition, and the partition would return the new index of the pivot element, which is 4. Partition returns 3, the new position of 4. Now, quicksort recursively calls itself on the left and the right sub arrays highlighted below.

5. Create a void function quickSort and pass the address of the array and the lower index, which would be 0 for the first time, and the higher index, which would be length -1 for the first time, as parameters. Create an integer variable partitionIndex for holding the index provided by the partition. Now recursively call the quickSort function twice but with parameters changed to (low, partitionIndex-1) for the left sub array and (partitionIndex+1, high) for the right sub array, instead of just (low, high). But ain’t we forgetting something? The basics of recursion demand a base condition to stop the recursion. Hence, the base condition here would be when our low becomes greater than or equal to our high. This is when our recursion stops.

6. Create a void function partition, and pass the address of the array and the low and the high of the sub array as parameters. Create an integer variable pivot that takes the element at the low index. Create two index variables, i and j, and make them hold low+1 and high.
Create a while loop and run until the index i reaches an element greater than or equal to the pivot or the array finishes. Till then, keep increasing i by 1.  Similarly, create another while loop and run until our index j reaches an element smaller than the pivot or the array finishes. Till then, keep decreasing j by 1. After finishing all the above tasks, we swap the elements at indices i and j.
The above process is repeated using a do-while loop until i becomes greater than j. And when it does, the loop breaks, and before we return, we swap our pivot with the element at index j. And that should finish our job.
*/