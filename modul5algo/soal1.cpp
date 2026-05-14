#include <iostream>
#include <string>

using namespace std;

void insertionSort(string str) {
    int n = str.length();
    for (int i = 1; i < n; i++) {
        char key = str[i];
        int j = i - 1;
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j = j - 1;
        }
        str[j + 1] = key;
    }
    cout << "\n--- HASIL SORTING ---" << endl;
    cout << "Nama setelah diurutkan: " << str << endl;
}

void merge(string &str, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    string L = "", R = "";
    for (int i = 0; i < n1; i++) L += str[l + i];
    for (int j = 0; j < n2; j++) R += str[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) str[k++] = L[i++];
        else str[k++] = R[j++];
    }
    while (i < n1) str[k++] = L[i++];
    while (j < n2) str[k++] = R[j++];
}

void mergeSortHelper(string &str, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortHelper(str, l, m);
    mergeSortHelper(str, m + 1, r);
    merge(str, l, m, r);
}

void mergeSort(string str) {
    mergeSortHelper(str, 0, str.length() - 1);
    cout << "\n--- HASIL SORTING ---" << endl;
    cout << "Nama setelah diurutkan: " << str << endl;
}

void shellSort(string str) {
    int n = str.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            char temp = str[i];
            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap)
                str[j] = str[j - gap];
            str[j] = temp;
        }
    }
    cout << "\n--- HASIL SORTING ---" << endl;
    cout << "Nama setelah diurutkan: " << str << endl;
}

int partition(string &arr, int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortHelper(string &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(string nim) {
    quickSortHelper(nim, 0, nim.length() - 1);
    cout << "\n--- HASIL SORTING ---" << endl;
    cout << "NIM setelah diurutkan: " << nim << endl;
}

void bubbleSort(string nim) {
    int n = nim.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nim[j] > nim[j + 1]) {
                swap(nim[j], nim[j + 1]);
            }
        }
    }
    cout << "\n--- HASIL SORTING ---" << endl;
    cout << "NIM setelah diurutkan: " << nim << endl;
}

void selectionSort(string nim) {
    int n = nim.length();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (nim[j] < nim[min_idx])
                min_idx = j;
        }
        swap(nim[min_idx], nim[i]);
    }
    cout << "\n--- HASIL SORTING ---" << endl;
    cout << "NIM setelah diurutkan: " << nim << endl;
}

int main() {
    string nama, nim;
    int pilihan;

    do {
        cout << "\n===============================" << endl;
        cout << "           SORTING             " << endl;
        cout << "===============================" << endl;
        cout << "1. Insertion Sort" << endl;
        cout << "2. Merge Sort" << endl;
        cout << "3. Shell Sort" << endl;
        cout << "4. Quick Sort" << endl;
        cout << "5. Bubble Sort" << endl;
        cout << "6. Selection Sort" << endl;
        cout << "7. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            cout << "Masukkan Nama Anda (tanpa spasi): ";
            cin >> nama;
        } else if (pilihan >= 4 && pilihan <= 6) {
            cout << "Masukkan NIM Anda: ";
            cin >> nim;
        }

        switch (pilihan) {
            case 1:
                insertionSort(nama);
                break;
            case 2:
                mergeSort(nama);
                break;
            case 3:
                shellSort(nama);
                break;
            case 4:
                quickSort(nim);
                break;
            case 5:
                bubbleSort(nim);
                break;
            case 6:
                selectionSort(nim);
                break;
            case 7:
                cout << "Keluar dari program. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 7);

    return 0;
}