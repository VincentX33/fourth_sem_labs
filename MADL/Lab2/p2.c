#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], int l, int h)
{
  printf("low = %d, high = %d => [ ", l, h);
  for (int i = l; i <= h; i++)
    printf("%d ", arr[i]);
  printf(" ]\n");
}
void minMax(int arr[], int i, int j, int *min, int *max)
{
  // first two base cases, for 1, 2 element arrays
  if (i == j)
  {
    *min = i;
    *max = j;
  }
  else if (i == j - 1)
  {
    if (arr[i] > arr[j])
    {
      *max = i;
      *min = j;
    }
    else
    {
      *max = j;
      *min = i;
    }
  }
  else
  {
    // for more than two elements, split problem into two
    int mx1, mx2, mn1, mn2, mid;
    mid = (i + j) / 2;
    minMax(arr, i, mid, &mn1, &mx1);
    minMax(arr, mid + 1, j, &mn2, &mx2);
    if (arr[mx1] > arr[mx2])
    {
      *max = mx1;
    }
    else
    {
      *max = mx2;
    }
    if (arr[mn1] < arr[mn2])
    {
      *min = mn1;
    }
    else
    {
      *min = mn2;
    }
  }
  printArray(arr, i, j);
}

int main()
{
  int nums[30], n;
  printf("enter number of elements:");
  scanf("%d", &n);
  printf("Enter %d elements:\n", n);
  for (int i = 0; i < n; i++)
    scanf("%d", nums + i);
  int min, max;
  minMax(nums, 0, n-1, &min, &max);
  printf("Minimum = %d, Maximum = %d\n", nums[min], nums[max]);
  // printArray(nums, 0, n-1);
  return 0;
}