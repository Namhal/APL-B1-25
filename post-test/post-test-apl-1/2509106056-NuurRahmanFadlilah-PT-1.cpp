#include <iostream>
#include <string>
using namespace std;

int main() {
    string User, pwUser;
    string User_benar = "Rahman";
    string pwBenar = "056";
    int kesempatanLogin;
    int loginBerhasil = 0;

    cout <<"\n"<< string(5, '=')<<" LOGIN TERLEBIH DAHULU " << string(5, '=') << endl;
    for (kesempatanLogin = 1; kesempatanLogin <= 3; kesempatanLogin++) {
        cout << "Nama     : "; cin >> User;
        cout << "Password : "; cin >> pwUser;
        if (User == User_benar && pwUser == pwBenar) {
            loginBerhasil = 1;
            cout << "Login Berhasil\n";
            break;
        }
        else{
            cout << "Username atau password salah, percobaan ke-" << kesempatanLogin << endl << endl << endl;
        }
    }

    if (loginBerhasil == 0) {
        cout << "Login gagal 3 kali. Program selesai" << endl;
        return 0;
    }

    int memilihMenu = 0;
    for (;;){
        cout <<"\n\n"<< string(5, '=')<< " MENU KONVERSI " << string(5, '=') << endl;
        cout << "1. Jam ke menit dan detik" << endl;
        cout << "2. Menit ke jam dan detik" << endl;
        cout << "3. Detik ke jam dan menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> memilihMenu;
        cout << endl;
        if (memilihMenu == 1) {
            int jumlahJam;
            cout << "Masukkan total jam yang ingin dikonversi : ";
            cin >> jumlahJam;
            int hasilMenit = jumlahJam * 60;
            int hasilDetik = jumlahJam * 3600;
            cout << jumlahJam << " Jam = " << hasilMenit << " Menit dan " << hasilDetik << " Detik" << endl;
        }
        else if (memilihMenu == 2) {
            int jumlahMenit;
            cout << "Masukkan total menit yang ingin dikonversi : ";
            cin >> jumlahMenit;
            double hasilJam = jumlahMenit / 60.0;
            int sisaDetik = jumlahMenit * 60;
            cout << jumlahMenit << " Menit = " << hasilJam << " Jam dan " << sisaDetik << " Detik" << endl;
        }
        else if (memilihMenu == 3) {
            int jumlahDetik;
            cout << "Masukkan total detik yang ingin dikonversi : ";
            cin >> jumlahDetik;
            double hasilJam = jumlahDetik / 3600.0;
            double hasilMenit = jumlahDetik / 60.0;
            cout << jumlahDetik << " Detik = " << hasilJam << " Jam dan " << hasilMenit << " Menit" << endl;
        }
        else if (memilihMenu == 4) {
            cout << "Program selesai" << endl;
            break;
        }
        else {
            cout << "Menu tidak tersedia" << endl;
        }
    }
    return 0;
}