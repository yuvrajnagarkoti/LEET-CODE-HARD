int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a); // Sort in descending order
}

int maxSatisfaction(int *satisfaction, int size)
{
    qsort(satisfaction, size, sizeof(int), compare); // Sort in descending order

    int maxSum = 0, currSum = 0, total = 0;
    
    for (int i = 0; i < size; i++)
    {
        currSum += satisfaction[i];
        if (currSum + total > total) // Only add if beneficial
        {
            total += currSum;
            maxSum = total;
        }
        else
            break;
    }  
    return maxSum;
}
