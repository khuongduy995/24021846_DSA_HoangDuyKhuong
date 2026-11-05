
int partition(int arr[],int left,int right){
        int pivot = arr[(left+right)/2];
        int i=left;
        int j = right;
        while(i<=j){
            while(arr[i] < pivot) i++;
            while(arr[j] >pivot) j--;
            if(i<=j){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
        return i;
}
void quick_sort(int arr[],int left,int right){
    if(left >=right) return;
    int p = partition(arr,left,right);
    quick_sort(arr,left,p-1);
    quick_sort(arr,p,right);
}
