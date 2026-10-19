#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int leftarr[n1], rightarr[n2];
    for (i = 0; i < n1; i++)
        leftarr[i] = a[low + i];
    for (j = 0; j < n2; j++)
        rightarr[j] = a[mid + 1 + j];
    i = j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (leftarr[i] <= rightarr[j])
            a[k++] = leftarr[i++];
        else
            a[k++] = rightarr[j++];
    }
    while (i < n1)
        a[k++] = leftarr[i++];
    while (j < n2)
        a[k++] = rightarr[j++];
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int binarySearchFirst(int nums[], int n, int target)
{
    int low = 0, high = n - 1, first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1;  // Keep searching on the left side
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int binarySearchLast(int nums[], int n, int target) {
    int low = 0, high = n - 1, last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1;  // Keep searching on the right side
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

int* targetIndices(int* nums, int n, int target, int* returnSize)
{
    // Step 1: Sort the array
    mergesort(nums, 0, n - 1);

    // Step 2: Find the first and last occurrence of target
    int first = binarySearchFirst(nums, n, target);
    int last = binarySearchLast(nums, n, target);

    // If the target is not found, return an empty list
    if (first == -1 || last == -1)
    {
        *returnSize = 0;
        return NULL;
    }

    // Step 3: Allocate memory for result indices
    int count = last - first + 1;
    int *indices = (int*)malloc(count * sizeof(int));

    // Step 4: Fill the indices array
    for (int i = 0; i < count; i++)
    {
        indices[i] = first + i;
    }

    *returnSize = count;
    return indices;
}