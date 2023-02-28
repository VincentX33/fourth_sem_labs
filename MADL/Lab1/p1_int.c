#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
/*
3 functions
merge sort : merge, mergesort
binarysearch
*/
#define MAX 100
void merge(char[], int, int, int);
void mergesort(char arr[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}
void merge(char arr[], int low, int mid, int high)
{
  // merge the two arrays , a[low:mid] and a[mid+1:high]
  // need the low, high, mid
  int i = low;
  int h = low;
  int j = mid + 1;
  char temp[MAX]; // merge into temp array
  while ((h <= mid) && (j <= high))
  {
    // merge
    if (arr[h] < arr[j])
    {
      temp[i++] = arr[h++];
    }
    else
    {
      temp[i++] = arr[j++];
    }
  }
  if (h > mid)
  {
    // first array over
    while (j <= high)
    {
      temp[i++] = arr[j++];
    }
  }
  else
  {
    while (h <= mid)
    {
      temp[i++] = arr[h++];
    }
  }
  // now copy from temp to original array
  int l = low;
  while (l <= high)
  {
    arr[l] = temp[l];
    l++;
  }
}
int binarySearch(char arr[], int low, int high, char x)
{
  // searches for value x in sorted array a
  // base case when low==high
  if (low == high)
  {
    if (arr[low] == x)
      return low;
    else
      return -1;
  }
  else
  {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
      return mid;
    else if (arr[mid] < x)
      return binarySearch(arr, mid + 1, high, x);
    else
      return binarySearch(arr, low, mid - 1, x);
  }
}
int main()
{
  // int ages[] = {81,43,61,21,-8,96,55,77,-18,52,17};
  // char letters[] = {'I','T','B','M','Z','F','S','U','G','H','Q'};
  char letters[40];
  int n, l;
  char c;
  printf("enter number of characters:");
  scanf("%d", &n);
  printf("enter %d characters: ", n);
  for (int i = 0; i < n; i++)
    scanf(" %c", &letters[i]);
  // for (int i = 0; i < n; i++)
  // printf("%c", letters[i]);
  // before starting merge sort
  clock_t starttime, endtime;
  starttime = clock();
  printf("Starting time is %ld\n", starttime);
  mergesort(letters, 0, n - 1);
  endtime = clock();
  printf("Ending time is %ld\n",endtime);
  double total_time = (double)(endtime-starttime)/CLOCKS_PER_SEC;
  printf("Time taken to merge sort is : %f",total_time);

  // mergesort(ages,0,10);
  for (int i = 0; i < n; i++)
  {
    // printf("%d ",ages[i]);
    printf("%c ", letters[i]);
  }
  printf("\n");
  printf("Enter character to search:");
  scanf(" %c", &c);
  if ((l = binarySearch(letters, 0, n - 1, c)) >= 0)
  {
    printf("Item %c found @ index : %d\n", c, l);
  }
  else
  {
    printf("Item %c not found\n", 'Q');
  }
  return 0;
}