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
  // if (i==j)return i; check if this code works later
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
  printArray(arr, low, high);
  return j;
}
/* debug notes*/
/*
im taking one extra ie if there are 9 elements, j starts from 9
maybe that is the problem: or maybe not because at every comparision it checks the last element
this might lead to error with low:j-1, as instead of giving
j-1 to the lh quicksort, i have to give low,j: automatically it will handle the j-1 part

*/
/* debug notes*/
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
    printf("Partition is %d\n",j);
    quicksort(arr, low, j);
    quicksort(arr, j+1, high); //+1 to handle errors
    //+1 ensures the a[j] comparison starts from last element, not second last
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
  nums[n] = 1000;
  quicksort(nums, 0, n);
  for (int i = 0; i < n; i++)
    printf("%d ", nums[i]);
  return 0;
}