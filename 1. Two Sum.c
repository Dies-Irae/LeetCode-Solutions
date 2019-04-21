/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target) {
	int *p,*p2, i, j, k, tmp, find, mid;
	p = malloc(2 * sizeof(int));
	p2=malloc(numsSize*sizeof(int));
	for(i=0;i<numsSize;i++)
	    p2[i]=i;
	for (i = 0; i<numsSize - 1; i++)
	{
		k = i;
		for (j = i + 1; j<numsSize; j++)
		{
			if (nums[k]>nums[j])
				k = j;
		}
		if (k != i)
		{
			tmp = nums[k];
			nums[k] = nums[i];
			nums[i] = tmp;
			tmp=p2[k];
			p2[k]=p2[i];
			p2[i]=tmp;
		}
	}
	tmp = 0;
	k = 0, j = numsSize - 1;
	do {
		find = target - nums[k];
		i = k + 1;
		while (j-i>2)
		{
			if (nums[j] == find)
			{
				mid = j;
				break;
			}
			if (nums[i] == find)
			{
				mid = i;
				break;
			}
			mid = (i + j) / 2;
			if (find>nums[mid])
				i = mid;
			else if (find<nums[mid])
				j = mid;
			else
				break;
		}
		mid=(i+j)/2;
		if (nums[j] == find)
			{
				mid = j;
				break;
			}
		if (nums[i] == find)
			{
				mid = i;
				break;
			}
		if (nums[mid] == find)
			break;
		else
			k++;
	} while (1);
	p[0] = p2[k];
	p[1] = p2[mid];
	return p;
}