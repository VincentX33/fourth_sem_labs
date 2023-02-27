#include <stdio.h>
#include <stdlib.h>
//quicksort for integer array
void printArray(int arr[], int l, int h);

int partition(int arr[], int low, int high)
{
  // partitions, returns partition index
  // default at first position
  int pivot = arr[low];
  int i = low;
  int j = high;
  int t;
  /*
  to determine the correct position of pivot element, we have
  to find how many items there are smaller than it, and how many larger than it
  */
  do
  {
    do
    {
      i++;
    } while (arr[i] <= pivot);
    do
    {
      j--;
    } while (arr[j] > pivot);
    // if somehow this condition, swap
    if (i < j)
    {
      t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
    }
  } while (i < j);
  arr[low] = arr[j];
  arr[j] = pivot;
  // printArray(arr, low, high);
  return j;
}
void printArray(int arr[], int l, int h)
{
  printf("low = %d, high = %d => [ ", l, h);
  for (int i = l; i < h; i++)
    printf("%d ", arr[i]);
  printf(" ]\n");
}
void quicksort(int arr[], int low, int high)
{
  int j;
  if (low < high)
  {
    j = partition(arr, low, high);
    quicksort(arr, low, j);
    quicksort(arr, j+1, high);
    printArray(arr, low, high);
  }
}
int main()
{
  int nums[30], n;
  printf("enter number of elements:");
  scanf("%d", &n);
  printf("Enter %d elements:\n", n);
  for (int i = 0; i < n; i++)
    scanf("%d", nums + i);
  // printf("partition index for %d is %d\n",nums[0],partition(nums,0,8));
  quicksort(nums, 0, n);
  for (int i = 0; i < n; i++)
    printf("%d ", nums[i]);
  return 0;
}