//heap max tree

void swim(int *a, int k) { 
    while (k > 1 && a[k / 2] < a[k])
        swap(a[k / 2], a[k]);
        k = k / 2;
    }
}

void insert(int *a, int &n, int x) {
    n++;
    a[n] = x;
    swim(a, n);
}


void sink(int *a, int n, int k) {
    while (2 * k <= n) {
        int j = 2 * k; 
        if (j < n && a[j] < a[j + 1]) j++;
        if (a[k] >= a[j]) break;          
        swap(a[k], a[j]);
        k = j;
    }
}

int delMax(int *a, int &n) {
    if (n == 0) return -1; 
    int maxVal = a[1];
    swap(a[1], a[n]);
    n--;
    sink(a, n, 1);
    return maxVal;
}


void heapSort(int *a, int n) { 
   
    for (int k = n / 2; k >= 1; k--) {
        sink(a, n, k);
    }
 
    while (n > 1) {
        swap(a[1], a[n]); 
        n--;              
        sink(a, n, 1);   
    }
}

