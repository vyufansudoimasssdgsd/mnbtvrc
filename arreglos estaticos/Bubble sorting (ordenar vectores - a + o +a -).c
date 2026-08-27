

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int intercambiado;
    
    for (i = 0; i < n - 1; i++) {
        intercambiado = 0;
        
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                intercambiado = 1;
            }
        }
        
        if (intercambiado == 0)
            break;
    }
}
