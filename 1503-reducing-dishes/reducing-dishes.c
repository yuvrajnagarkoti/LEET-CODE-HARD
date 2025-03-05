int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int getMax(int arr[], int size)
{
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int maxSatisfaction(int *satisfaction, int size)
{
    qsort(satisfaction, size, sizeof(int), compare); // Sort in ascending order
    int index = 0;
    while (index < size && satisfaction[index] <= 0)
    {
        index++; // Find the first positive element
    }
    if (index == size)
    {
        return 0; // If all elements are non-positive
    }
    int *sums = (int *)malloc(size * sizeof(int));
    int count = 0;
    for (int i = 0; index - i >= 0; i++)
    {
        int sum = 0, factor = 0;
        for (int j = index - i; j < size; j++)
        {
            factor++;
            sum += satisfaction[j] * factor;
        }
        sums[count++] = sum;
    }
    return getMax(sums, count);
}