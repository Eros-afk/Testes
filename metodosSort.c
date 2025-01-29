#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// BubbleSort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// InsertionSort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função auxiliar para QuickSort (recebe apenas dois argumentos)
void quickSortWrapper(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}

// MergeSort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Função auxiliar para MergeSort (recebe apenas dois argumentos)
void mergeSortWrapper(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
}

// HeapSort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Função para preencher um vetor com valores aleatórios
void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Números aleatórios entre 0 e 999999
    }
}

// Função para copiar um vetor
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Função para medir o tempo de execução de um algoritmo
double measureTime(void (*sortFunction)(int[], int), int arr[], int n) {
    clock_t start, end;
    start = clock();
    sortFunction(arr, n);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Tempo em milissegundos
}

int main() {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    int sizes[] = {100, 1000, 10000, 100000, 1000000}; // Tamanhos dos vetores
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    int numTests = 1; // Número de testes para calcular a média

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        int *temp = (int *)malloc(n * sizeof(int));

        double timeBubble = 0, timeInsertion = 0, timeQuick = 0, timeMerge = 0, timeHeap = 0;

        for (int j = 0; j < numTests; j++) {
            fillRandom(arr, n);

            // BubbleSort
            copyArray(arr, temp, n);
            timeBubble += measureTime(bubbleSort, temp, n);

            // InsertionSort
            copyArray(arr, temp, n);
            timeInsertion += measureTime(insertionSort, temp, n);

            // QuickSort
            copyArray(arr, temp, n);
            timeQuick += measureTime(quickSortWrapper, temp, n);

            // MergeSort
            copyArray(arr, temp, n);
            timeMerge += measureTime(mergeSortWrapper, temp, n);

            // HeapSort
            copyArray(arr, temp, n);
            timeHeap += measureTime(heapSort, temp, n);
        }

        // Calcula a média dos tempos
        timeBubble /= numTests;
        timeInsertion /= numTests;
        timeQuick /= numTests;
        timeMerge /= numTests;
        timeHeap /= numTests;

        // Exibe os resultados
        printf("Tamanho do vetor: %d\n", n);
        printf("BubbleSort: %.2f ms\n", timeBubble);
        printf("InsertionSort: %.2f ms\n", timeInsertion);
        printf("QuickSort: %.2f ms\n", timeQuick);
        printf("MergeSort: %.2f ms\n", timeMerge);
        printf("HeapSort: %.2f ms\n\n", timeHeap);

        free(arr);
        free(temp);
    }

    return 0;
}