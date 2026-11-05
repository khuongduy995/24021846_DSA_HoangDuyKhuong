
void merge(int arr[], int l, int mid, int r){ 
    int *b, *c; 
    b=new int[mid-l+1]; 
    c=new int[r-mid];
    for (int i=l;i<=r;i++){
        if (i<=mid) b[i-l]=arr[i]; 
        else c[i-mid-1]=arr[i]; 
    }
    int i=0, j=0, k=l; 
    while (i<mid-l+1 && j< r-mid){
        if (b[i]<c[j]) arr[k]=b[i++]; 
        else arr[k]=c[j++]; 
        k++;
    }
    while(i<mid-l+1){
        arr[k++]=b[i++];
    }
    while (j<r-mid){ 
        arr[k++]=c[j++];
    }
    delete[] b; delete[] c;
}
