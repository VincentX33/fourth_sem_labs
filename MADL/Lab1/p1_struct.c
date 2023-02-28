#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

/*
3 functions
merge sort : merge, mergesort
binarysearch
*/
#define MAX 30
struct pair
{
  float x;
  int y;
};
// using y as key for sorting
void merge(struct pair[], int, int, int);
void mergesort(struct pair arr[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}
void merge(struct pair arr[], int low, int mid, int high)
{
  // merge the two arrays , a[low:mid] and a[mid+1:high]
  // need the low, high, mid
  int i = low;
  int h = low;
  int j = mid + 1;
  struct pair temp[MAX]; // merge into temp array
  while ((h <= mid) && (j <= high))
  {
    // merge
    if (arr[h].y < arr[j].y)
    {
      temp[i].x = arr[h].x;
      temp[i].y = arr[h].y;
      i++;
      h++;
    }
    else
    {
      temp[i].x = arr[j].x;
      temp[i].y = arr[j].y;
      i++;
      j++;
    }
  }
  if (h > mid)
  {
    // first array over
    while (j <= high)
    {
      temp[i].x = arr[j].x;
      temp[i].y = arr[j].y;
      i++;
      j++;
    }
  }
  else
  {
    while (h <= mid)
    {
      temp[i].x = arr[h].x;
      temp[i].y = arr[h].y;
      i++;
      h++;
    }
  }
  // now copy from temp to original array
  int l = low;
  while (l <= high)
  {
    arr[l].x = temp[l].x;
    arr[l].y = temp[l].y;
    l++;
  }
}
int binarySearch(struct pair arr[], int low, int high, struct pair P)
{
  // searches for value x in sorted array a
  // base case when low==high
  if (low == high)
  {
    if (arr[low].x == P.x && arr[low].y == P.y)
      return low;
    else
      return -1;
  }
  else
  {
    int mid = (low + high) / 2;
    if (arr[mid].x == P.x && arr[mid].y == P.y)
      return mid;
    else if (arr[mid].y < P.y)
      return binarySearch(arr, mid + 1, high, P);
    else
      return binarySearch(arr, low, mid - 1, P);
  }
}
int main()
{
  struct pair values[10];
  int n, l, t;
  float f, tf;
  char c;
  printf("enter number of pairs:");
  scanf("%d", &n);
  printf("enter %d pairs [float int]: ", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%f %d", &f, &l);
    values[i].x = f;
    values[i].y = l;
  }
  // before starting merge sort
  clock_t starttime, endtime;
  starttime = clock();
  printf("Starting time is %ld\n", starttime);
  mergesort(values, 0, n - 1);
  endtime = clock();
  printf("Ending time is %ld\n",endtime);
  double total_time = (double)(endtime-starttime)/CLOCKS_PER_SEC;
  printf("Time taken to merge sort is : %f",total_time);

  for (int i = 0; i < n; i++)
  {
    printf("%f, %d\n", values[i].x, values[i].y);
  }
  printf("\n");
  printf("Enter pair to search:");
  scanf("%f %d", &tf, &t);
  struct pair value;
  value.x = tf;
  value.y = t;
  if ((l = binarySearch(values, 0, n - 1, value)) >= 0)
  {
    printf("Pair (%f, %d) found @ index : %d\n", tf, t, l);
  }
  else
  {
    printf("Pair (%f, %d) not found\n", tf, t);
  }
  return 0;
}