#include <iostream>
using namespace std;
/*
#define MAX_MAHASISWA 100 // Ukuran maksimum array

int main() {

    int panjang = 0; // Jumlah data mahasiswa saat ini
    string mahasiswa[MAX_MAHASISWA]; // Array 1 dimensi

    int pilihan, index;
    
    do {
        cout << "\n=== MENU PROGRAM DATA MAHASISWA ===" << endl;
        cout << "1. Tampilkan Mahasiswa" << endl;
        cout << "2. Tambah Mahasiswa" << endl;
        cout << "3. Ubah Mahasiswa" << endl;
        cout << "4. Hapus Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1: // READ
        if (panjang == 0) {
                cout << "Belum ada mahasiswa." << endl;
            } else {
                for (int i = 0; i < panjang; i++) {
                    cout << "Mahasiswa ke-" << i + 1 
                         << ": " << mahasiswa[i] << endl;
                }
            }
            break;

        case 2: // CREATE
        if (panjang < MAX_MAHASISWA) {
            cout << "Masukkan nama mahasiswa: ";
                cin.ignore();
                getline(cin, mahasiswa[panjang]);
                panjang++;
                cout << "Mahasiswa berhasil ditambahkan." << endl;
            } else {
                cout << "Kapasitas penuh!" << endl;
            }
            break;

            case 3: // UPDATE
            if (panjang == 0) {
                cout << "Belum ada mahasiswa untuk diubah." << endl;
            } else {
                for (int i = 0; i < panjang; i++) {
                    cout << "Mahasiswa ke-" << i + 1 
                         << ": " << mahasiswa[i] << endl;
                }

                cout << "Masukkan nomor mahasiswa yang akan diubah: ";
                cin >> index;
                
                if (index > 0 && index <= panjang) {
                    cout << "Masukkan nama baru: ";
                    cin.ignore();
                    getline(cin, mahasiswa[index - 1]);
                    cout << "Data berhasil diubah." << endl;
                } else {
                    cout << "Nomor tidak valid." << endl;
            }
        }
        break;
        
        case 4: // DELETE
        if (panjang == 0) {
            cout << "Belum ada mahasiswa untuk dihapus." << endl;
        } else {
                for (int i = 0; i < panjang; i++) {
            cout << "Mahasiswa ke-" << i + 1 
            << ": " << mahasiswa[i] << endl;
        }
        
        cout << "Masukkan nomor mahasiswa yang akan dihapus: ";
        cin >> index;
        
        if (index > 0 && index <= panjang) {
            for (int i = index - 1; i < panjang - 1; i++) {
                mahasiswa[i] = mahasiswa[i + 1]; 
            }
            panjang--;
            cout << "Mahasiswa berhasil dihapus." << endl;
        } else {
            cout << "Nomor tidak valid." << endl;
    }
            }
            break;
            
            case 5:
            cout << "Program selesai." << endl;
            break;
            
            default:
            cout << "Pilihan tidak valid." << endl;
        }
        
    } while (pilihan != 5);

    return 0;
}

*/

// nested struct
/*
struct Alamat {
string jalan;
int nomor;
string kota;
};
struct Mahasiswa {
string nama;
int umur;
string jurusan;
Alamat alamat; / Nested struct
};
/ Penggunaan
Mahasiswa mhs;
mhs.nama = "Intan";
mhs.umur = 18;
mhs.jurusan = "Informatika";
mhs.alamat.jalan = "Jl. Kuaro";
mhs.alamat.nomor = 12;
mhs.alamat.kota = "Balikpapan";
*/

#include <iostream>
#include <string>

using namespace std;

// Definisi struktur tanggal
struct Date {
    int month;
    int day;
    int year;
};

// Definisi struktur mahasiswa
struct Mahasiswa {
    string name;
    Date birthday; // Di C++ tidak perlu tulis 'struct Date' lagi
};

int main() {
    // Deklarasi struct of array dengan kapasitas 10
    Mahasiswa mhs[10];

    // Mengisi data untuk indeks ke-0
    mhs[0].name = "Ihsan";
    mhs[0].birthday.day = 30;
    mhs[0].birthday.month = 1;
    mhs[0].birthday.year = 2007;

    // Menampilkan data indeks ke-0
    cout << "--- Data Mahasiswa Indeks 0 ---" << endl;
    cout << "Nama           : " << mhs[0].name << endl;
    cout << "Tanggal Lahir  : " << mhs[0].birthday.day << "-"  << mhs[0].birthday.month << "-"  << mhs[0].birthday.year << endl;

    return 0;
}
