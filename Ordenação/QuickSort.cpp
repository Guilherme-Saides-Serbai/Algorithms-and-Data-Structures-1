int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivô
    int i = (low - 1);     // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Troca arr[i] e arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Troca arr[i + 1] e arr[high] (ou o pivô)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // partIdx é o índice de partição
        int partIdx = partition(arr, low, high);

        // Ordena os elementos separadamente antes e depois da partição
        quickSort(arr, low, partIdx - 1);
        quickSort(arr, partIdx + 1, high);
    }
}
