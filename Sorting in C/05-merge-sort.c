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

// Function to merge two sorted sub arrays into one sorted array
void mergeSort(int A[], int mid, int low, int high)
{
    int i, j, k, B[100]; // B is a temporary array to store merged data
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i]; // Place the smaller value in B
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    // If there are remaining elements in the left sub array, copy them to B
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    // If there are remaining elements in the right sub array, copy them to B
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    // Copy the merged data from B back to A
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

// Recursive function to perform merge sort
void mergeSortRecursive(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;               // Calculate the middle of the array
        mergeSortRecursive(A, low, mid);      // Recursively sort the left sub array
        mergeSortRecursive(A, mid + 1, high); // Recursively sort the right sub array
        merge(A, mid, low, high);             // Merge the two sorted sub arrays
    }
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;

    printf("Array Before Sorting: ");
    printArray(A, n);

    mergeSortRecursive(A, 0, 6);

    printf("Sorted Array: ");
    printArray(A, n);
    return 0;
}

/* Understanding the Code:
1. First we make a function for displaying the array's content. This just helps a lot seeing the contents of the array before and after the sorting.
2. The next step is to define an array of elements. Define an integer variable for storing the size/length of the array.

3. Creating the merge function:
This is just the merge function, whose only job is to merge two sorted arrays into a bigger sorted array. Create a void function merge that takes the array and the integer indices low, mid, and high as its parameters. Create integer variables i, j, and k for iterating through the array A and an auxiliary array B. Create this integer array B of size, but for now, we would choose some larger size, say 100. Initialize i with low, j with mid+1, and k with low Here, i marks the current element of the first sub array of array A, and j marks the first element of the second sub array. And, k is the iterator for array B to insert the smaller of elements at indices i and j.
Run a while loop until either i or j or both reaches the threshold of their corresponding sub array. Inside the loop, see if the element at index i is smaller than the one at index j. If it is, insert element at index i in index k of array B as example, B[k] = A[i] and increment both i and k by 1, else, insert element at index j in index k of array B as example, B[k] = A[j] and increment both j and k by 1.
The above ends when either i or j or both reach its corresponding sub array’s end. Now, run two separate while loops for inserting the remaining elements, if left, in both the sub arrays. And this would finish filling all the elements in sorted order in array B. The only thing left is just to copy the sorted array back again to array A. And we are done.

4. Create a void function mergeSort and pass the address of the array and the index variables low and high as its parameters. Here, the lower index would be 0 for the first time, and the higher index would be length -1 for the first time.
We would recursively call this function only if low is less than high; that is, there are at least two elements in the sub array. Otherwise, we break off from the loop.
Create an integer variable mid for holding the index of the mid element, which would be. Now recursively call the mergeSort function twice but with parameters changed to (low, mid-1) for the left sub array and (mid+1, high) for the right sub array. Applying mergeSort sorts the left half and the right half separately. This is where we would merge them back in the array. Call the merge function and pass the array, its index variables low, mid, and high. And this would return a sorted array.
*/