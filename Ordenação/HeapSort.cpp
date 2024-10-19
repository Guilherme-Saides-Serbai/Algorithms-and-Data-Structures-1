void heapify(int arr[], int n, int i) {
    int largest = i;  // Inicializa o maior como raiz
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Se o filho esquerdo for maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Se o filho direito for maior que o maior elemento encontrado
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não for a raiz
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursivamente faz heapify na subárvore afetada
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai um elemento do heap de cada vez
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama heapify no heap reduzido
        heapify(arr, i, 0);
    }
}
