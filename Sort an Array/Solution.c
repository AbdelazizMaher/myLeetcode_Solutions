void merge(int* sortedArray, int* nums, int lb, int mid, int ub) 
{
    int i =lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub) 
    {
        if (nums[i] <= nums[j]) 
        {
            sortedArray[k] = nums[i];
            i++;
        } 
        else 
        {
            sortedArray[k] = nums[j];
            j++;
        }
        k++;
    }

    if( i > mid )
    {
        while (j <= ub) 
        {
            sortedArray[k] = nums[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid) 
        {
            sortedArray[k] = nums[i];
            i++;
            k++;
        }
    } 

    for (i = lb; i <= ub; i++) 
        nums[i] = sortedArray[i];
}

void mergeSort(int* sortedArray, int* nums, int lb, int ub)
 {
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;

        mergeSort(sortedArray,nums, lb, mid);
        mergeSort(sortedArray, nums, mid + 1, ub);

        merge(sortedArray, nums, lb, mid, ub);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* sortedArray = (int*)malloc(numsSize * sizeof(int));
    
    mergeSort(sortedArray, nums, 0, numsSize - 1);

    for (int i = 0; i < numsSize; i++) 
        sortedArray[i] = nums[i];

    *returnSize = numsSize;
    return sortedArray;        
}