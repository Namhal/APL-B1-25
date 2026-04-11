// #include <iostream>
// #include <utility>
#include <stdlib.h>
// using namespace std;

// // Inisialisasi Array Global
// int arr[] = {64, 34, 25, 12, 22, 11, 90};
// int n = sizeof(arr) / sizeof(arr[0]);

// void bubbleSort(int arr[], int n) {
//     bool swapped;
//     // Loop luar untuk jumlah lintasan (pass)
//     for (int i = 0; i < n - 1; i++) {
//         swapped = false;
//         // Loop dalam untuk membandingkan elemen yang bersebelahan
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 // Tukar elemen jika elemen kiri lebih besar dari kanan
//                 swap(arr[j], arr[j + 1]);
//                 swapped = true;
//             }
//         }
//         // Optimasi: Jika tidak ada pertukaran, berarti array sudah urut
//         if (!swapped)
//             break;
//     }
// }

// void tampilkanArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
    // system("cls");
//     cout << "Data Sebelum Bubble Sort: ";
//     tampilkanArray(arr, n);
//     bubbleSort(arr, n);
//     cout << "Data Setelah Bubble Sort : ";
//     tampilkanArray(arr, n);
//     return 0;
// }

// #include <iostream>
// #include <utility>
// using namespace std;

// // Inisialisasi Array Global
// int arr[] = {29, 10, 14, 37, 13};
// int n = sizeof(arr) / sizeof(arr[0]);

// void selectionSort(int arr[], int n) {
//     // Loop luar untuk memindahkan batas sub-array yang belum urut
//     for (int i = 0; i < n - 1; i++) {
//         // Anggap elemen pertama dari bagian belum urut sebagai yang terkecil
//         int indeksMin = i;

//         // Loop dalam untuk mencari elemen terkecil di sisa array
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[indeksMin]) {
//                 indeksMin = j; // Simpan indeks elemen yang lebih kecil
//             }
//         }

//         // Tukar elemen terkecil yang ditemukan dengan elemen di posisi i
//         if (indeksMin != i) {
//             swap(arr[i], arr[indeksMin]);
//         }
//     }
// }

// void tampilkanArray(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     system("cls");
//     cout << "Sebelum Selection Sort: ";
//     tampilkanArray(arr, n);
//     selectionSort(arr, n);
//     cout << "Sesudah Selection Sort : ";
//     tampilkanArray(arr, n);
//     return 0;
// }

#include <iostream>
#include <utility>
using namespace std;

// Inisialisasi Array Global
int arr[] = {1,2,3,4,5,6,7,9,8};
int n = sizeof(arr) / sizeof(arr[0]);

void quickSort(int arr[], int low, int high) {
    // Base case: jika pointer low melewati high, berhenti
    if (low >= high) return;

    // Menentukan data tengah sebagai pivot (Strategi yang lebih stabil)
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];

    int i = low, j = high;

    // Proses Partisi (Hoare Partition Scheme)
    while (i <= j) {
        // Cari elemen di kiri yang >= pivot
        while (arr[i] < pivot) {
            i++;
        }
        // Cari elemen di kanan yang <= pivot
        while (arr[j] > pivot) {
            j--;
        }
        // Tukar elemen jika ditemukan posisi yang salah
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Rekursi untuk sub-array bagian kiri (dari low sampai j)
    if (low < j) {
        quickSort(arr, low, j);
    }
    // Rekursi untuk sub-array bagian kanan (dari i sampai high)
    if (i < high) {
        quickSort(arr, i, high);
    }
}

int main() {
    system("cls");
    cout << "Data Belum Terurut: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Memanggil fungsi Quick Sort
    quickSort(arr, 0, n - 1);

    cout << "Hasil Quick Sort : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}