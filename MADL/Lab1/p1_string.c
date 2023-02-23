#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
/*
3 functions
merge sort : merge, mergesort
binarysearch
*/
#define MAX 50
void merge(char[][MAX], int, int, int);
void mergesort(char arr[][MAX], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}
void merge(char arr[][MAX], int low, int mid, int high)
{
  // merge the two arrays , a[low:mid] and a[mid+1:high]
  // need the low, high, mid
  int i = low;
  int h = low;
  int j = mid + 1;
  char temp[MAX][MAX]; // merge into temp array
  while ((h <= mid) && (j <= high))
  {
    // merge
    if ((strcmp(arr[h], arr[j])) < 0)
    {
      strcpy(temp[i], arr[h]);
      i++;
      h++;
      // temp[i++][] = arr[h++];
    }
    else
    {
      strcpy(temp[i], arr[j]);
      i++;
      j++;
      // temp[i++] = arr[j++];
    }
  }
  if (h > mid)
  {
    // first array over
    while (j <= high)
    {
      // temp[i++] = arr[j++];
      strcpy(temp[i], arr[j]);
      j++;
      i++;
    }
  }
  else
  {
    while (h <= mid)
    {
      // temp[i++] = arr[h++];
      strcpy(temp[i], arr[h]);
      h++;
      i++;
    }
  }
  // now copy from temp to original array
  int l = low;
  while (l <= high)
  {
    arr[l][0] = '\0';
    strcpy(arr[l], temp[l]);
    l++;
  }
}
int binarySearch(char arr[][MAX], int low, int high, char * x)
{
  // searches for string x in sorted array a
  // base case when low==high
  if (low == high)
  {
    if (strcmp(arr[low],x) == 0)
      return low;
    else
      return -1;
  }
  else
  {
    int mid = (low + high) / 2;
    if (strcmp(arr[mid],x)==0)
      return mid;
    else if (strcmp(arr[mid],x) < 0)
      return binarySearch(arr, mid + 1, high, x);
    else
      return binarySearch(arr, low, mid - 1, x);
  }
}
int main()
{
  // int ages[] = {81,43,61,21,-8,96,55,77,-18,52,17};
  // char letters[] = {'I','T','B','M','Z','F','S','U','G','H','Q'};
  char words[40][MAX];
  int n, l;
  char c[MAX];
  printf("enter number of strings:");
  scanf("%d", &n);
  printf("enter %d strings: ", n);
  for (int i = 0; i < n; i++)
    scanf(" %s", words[i]);
  printf("\nBefore sorting: ");
  for (int i = 0; i < n; i++)
    printf("%s ", words[i]);
  mergesort(words, 0, n - 1);
  printf("\nAfter sorting: ");
  for (int i = 0; i < n; i++)
  {
    printf("%s ", words[i]);
  }
  printf("\n");
  printf("Enter string to search:");
  scanf(" %s", c);
  if ((l = binarySearch(words, 0, n - 1,c)) >= 0)
  {
    printf("Item %s found @ index : %d\n", c, l);
  }
  else
  {
    printf("Item %s not found\n", c);
  }
  return 0;
}