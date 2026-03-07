#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct user{
    string nama;
    string nim;
};

struct produsen{
    string perusahaan;
    string tahun_pembuatan;
};

struct mesin{
    string nama_mesin;
    double harga_perjam;
    int ketersediaan_jumlah;
    produsen Produsen_;
};

int main(){
    user dataUser;
    dataUser.nama = "rahman";
    dataUser.nim = "056";
    string namaInput;
    string nimInput;
    int percobaanLogin = 0;
    bool loginBerhasil = false;
    mesin dataMesin[100] = {
        {"Excavator PC200", 350000, 3, {"Komatsu", "2021"}},
        {"Bulldozer D85", 420000, 2, {"Komatsu", "2020"}},
        {"Crawler Crane XCMG", 750000, 1, {"XCMG", "2022"}},
        {"Wheel Loader WA320", 300000, 4, {"Komatsu", "2019"}},
        {"Motor Grader CAT140K", 500000, 2, {"Caterpillar", "2021"}}
    };
    int jumlahMesin = 5;
    int pilihan;

    cout << "============\n";
    cout << "LOGIN SISTEM\n";
    cout << "============\n";
    while(percobaanLogin < 3){
        cout << "Nama : ";
        cin >> namaInput;
        cout << "NIM  : ";
        cin >> nimInput;
        if(namaInput == dataUser.nama && nimInput == dataUser.nim){
            loginBerhasil = true;
            break;
        }
        else{
            cout << "Login gagal\n\n";
            percobaanLogin++;
        }
    }
    if(loginBerhasil == false){
        cout << "Gagal login 3 kali, program berhenti\n";
        return 0;
    }

    while(true){
        cout << "\n------------------------------------------------------------\n";
        cout << "|        SELAMAT DATANG DI MENU RENTAL ALAT BERAT          |\n";
        cout << "------------------------------------------------------------\n";
        cout << "| 1. Registrasi Alat Baru                                  |\n";
        cout << "| 2. Katalog & Status Unit                                 |\n";
        cout << "| 3. Pembaruan Status Unit                                 |\n";
        cout << "| 4. Penghapusan Unit                                      |\n";
        cout << "| 5. Keluar Program                                        |\n";
        cout << "------------------------------------------------------------\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        if(pilihan == 1){
            cin.ignore();
            if(jumlahMesin >= 100){
                cout << "Kapasitas mesin sudah penuh\n\n";}
            else{
                cout << "\nRegistrasi Alat Baru\n";
                cout << "Nama Mesin          : ";
                getline(cin, dataMesin[jumlahMesin].nama_mesin);
                cout << "Harga per jam       : ";
                cin >> dataMesin[jumlahMesin].harga_perjam;
                cout << "Jumlah tersedia     : ";
                cin >> dataMesin[jumlahMesin].ketersediaan_jumlah;
                cout << "Perusahaan Produsen : ";
                cin >> dataMesin[jumlahMesin].Produsen_.perusahaan;
                cout << "Tahun Pembuatan     : ";
                cin >> dataMesin[jumlahMesin].Produsen_.tahun_pembuatan;
                jumlahMesin++;
                cout << "Data berhasil ditambahkan\n\n";
            }
        }

        else if(pilihan == 2){
            cout << "\nKATALOG MESIN\n";
            cout << left << setw(5)  << "No" << setw(25) << "Nama Mesin" << setw(15) << "Harga/Jam" << setw(10) << "Jumlah" << setw(18) << "Perusahaan" << setw(10) << "Tahun" << endl;
            for(int i = 0; i < jumlahMesin; i++){
                cout << left << setw(5)  << i+1 << setw(25) << dataMesin[i].nama_mesin << setw(15) << dataMesin[i].harga_perjam << setw(10) << dataMesin[i].ketersediaan_jumlah << setw(18) << dataMesin[i].Produsen_.perusahaan << setw(10) << dataMesin[i].Produsen_.tahun_pembuatan << endl;
            }
            cout << endl;
        }

        else if(pilihan == 3){
            int update_;
            cout << "\nMasukkan nomor mesin yang ingin diganti jumlahnya : ";
            cin >> update_;
            update_--;
            if(update_ >= 0 && update_ < jumlahMesin){
                cout << "Masukkan jumlah terbaru : ";
                cin >> dataMesin[update_].ketersediaan_jumlah;
                cout << "Status berhasil diperbarui\n\n";
            }
            else{
                cout << "Data tidak ditemukan\n\n";
            }
        }

        else if(pilihan == 4){
            int delete_;
            cout << "\nMasukkan nomor mesin yang ingin dihapus : ";
            cin >> delete_;
            delete_--;
            if(delete_ >= 0 && delete_ < jumlahMesin){
                for(int i = delete_; i < jumlahMesin - 1; i++){
                    dataMesin[i] = dataMesin[i+1];
                }
                jumlahMesin--;
                cout << "Data berhasil dihapus\n\n";
            }
            else{
                cout << "Data tidak ditemukan\n\n";
            }
        }

        else if(pilihan == 5){
            cout << "Program selesai.\n";
            break;
        }

        else{
            cout << "Pilihan tidak valid\n";
        }
    }
    return 0;
}