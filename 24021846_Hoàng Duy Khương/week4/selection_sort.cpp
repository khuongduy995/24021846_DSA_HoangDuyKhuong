void selectionSort(int arr[], int n)
{
  int min_index = i;
//tim min
  for (int j = i + 1; j < n; j++)
  {
    if(arr[j] < arr[min_index])
    min_index = j;
  }
  //hoan doi vi tri min voi vi tri hien tai
if(min_index != i)
  swap(arr[min_index], arr[i]);
}





  
