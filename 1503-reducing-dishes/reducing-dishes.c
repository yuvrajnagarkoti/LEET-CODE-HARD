int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int maxSatisfaction(int *satisfaction, int n)
{
    qsort(satisfaction, n, sizeof(int), compare);
    
    int i, j, k, sum, current;
    int *a = (int *)malloc(n * sizeof(int));
    if (!a) return 0; // Memory allocation check

    int key = 0;
    while (key < n && satisfaction[key] <= 0) // Prevent out-of-bounds access
    {
        key++;
    }

    if (key == n) // All elements are non-positive
    {
        free(a);
        return 0;
    }

    j = 0;
    for (i = 0; key - i >= 0; i++) // Fixing the loop condition
    {
        sum = 0;
        current = 0;
        for (k = key - i; k < n; k++)
        {
            current++;
            sum += satisfaction[k] * current; // Fix index usage
        }
        a[j++] = sum;
    }

    int maxVal = findMax(a, j); // Only consider filled elements
    free(a); // Free allocated memory
    return maxVal;
}
