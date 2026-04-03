#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct produsen{
    string perusahaan;
    string tahun_pembuatan;
};

struct mesin{
    string nama_mesin;
    double harga_perjam;
    int ketersediaan_jumlah;
    produsen dataProdusen;
};

struct user{
    string nama;
    string nim;
};

bool prosesLogin(user *dataUser){
    string namaInput;
    string nimInput;
    int percobaanLogin = 0;
    while(percobaanLogin < 3){
        cout<<"Nama : ";
        cin>>namaInput;
        cout<<"NIM  : ";
        cin>>nimInput;
        if(namaInput == dataUser->nama && nimInput == dataUser->nim){
            return true;
        }
        else{
            cout<<"Login gagal\n\n";
            percobaanLogin++;
        }
    }
    return false;
}

void tampilkanMenu(){
    cout<<"\n------------------------------------------------------------\n";
    cout<<"|        SELAMAT DATANG DI MENU RENTAL ALAT BERAT          |\n";
    cout<<"------------------------------------------------------------\n";
    cout<<"| 1. Registrasi Alat Baru                                  |\n";
    cout<<"| 2. Katalog & Status Unit                                 |\n";
    cout<<"| 3. Pembaruan Status Unit                                 |\n";
    cout<<"| 4. Penghapusan Unit                                      |\n";
    cout<<"| 5. Total Semua Unit                                      |\n";
    cout<<"| 6. Keluar Program                                        |\n";
    cout<<"------------------------------------------------------------\n";
    cout<<"Pilih menu : ";
}

void registrasiMesin(mesin *dataMesin, int *jumlahMesin){
    cin.ignore();
    cout<<"Nama Mesin      : ";
    getline(cin,dataMesin[*jumlahMesin].nama_mesin);
    cout<<"Harga per jam   : ";
    cin>>dataMesin[*jumlahMesin].harga_perjam;
    cout<<"Jumlah tersedia : ";
    cin>>dataMesin[*jumlahMesin].ketersediaan_jumlah;
    cin.ignore();
    cout<<"Perusahaan      : ";
    getline(cin,dataMesin[*jumlahMesin].dataProdusen.perusahaan);
    cout<<"Tahun pembuatan : ";
    cin>>dataMesin[*jumlahMesin].dataProdusen.tahun_pembuatan;
    (*jumlahMesin)++;
    cout<<"Data mesin berhasil ditambahkan\n";
}

void tampilkanKatalog(mesin *dataMesin, int *jumlahMesin){
    cout<<left<<setw(5)<<"No" <<setw(25)<<"Nama Mesin" <<setw(15)<<"Harga/Jam"
        <<setw(10)<<"Jumlah" <<setw(18)<<"Perusahaan" <<setw(10)<<"Tahun"<<endl;
    for(int i=0;i<*jumlahMesin;i++){
        cout<<left<<setw(5)<<i+1
            <<setw(25)<<dataMesin[i].nama_mesin
            <<setw(15)<<dataMesin[i].harga_perjam
            <<setw(10)<<dataMesin[i].ketersediaan_jumlah
            <<setw(18)<<dataMesin[i].dataProdusen.perusahaan
            <<setw(10)<<dataMesin[i].dataProdusen.tahun_pembuatan
            <<endl;
    }
}

void tampilkanKatalog(mesin *dataMesin, int *jumlahMesin, string judul){
    cout<<"\n"<<judul<<"\n";
    tampilkanKatalog(dataMesin,jumlahMesin);
}

void updateJumlahMesin(mesin *dataMesin, int *jumlahMesin){
    int update_;
    tampilkanKatalog(dataMesin,jumlahMesin,"DATA KATALOG");
    cout<<"Masukkan nomor mesin yang ingin diupdate : ";
    cin>>update_;
    update_--;
    if(update_>=0 && update_<*jumlahMesin){
        cout<<"Jumlah terbaru : ";
        cin>>dataMesin[update_].ketersediaan_jumlah;
        cout<<"Data berhasil diperbarui\n";
    }
    else{
        cout<<"Data tidak ditemukan\n";
    }
}

void hapusMesin(mesin *dataMesin, int *jumlahMesin){
    int delete_;
    tampilkanKatalog(dataMesin,jumlahMesin,"DATA KATALOG");
    cout<<"Masukkan nomor mesin yang ingin dihapus : ";
    cin>>delete_;
    delete_--;
    if(delete_>=0 && delete_<*jumlahMesin){
        for(int i=delete_; i<(*jumlahMesin)-1; i++){
            dataMesin[i] = dataMesin[i+1];
        }
        (*jumlahMesin)--;
        cout<<"Data berhasil dihapus\n";
    }
    else{
        cout<<"Data tidak ditemukan\n";
    }
}

int hitungTotalMesin(mesin *dataMesin, int *hitung){
    if(*hitung < 0){
        return 0;
    }
    int indexSekarang = *hitung;
    int indexSebelumnya = *hitung - 1;
    return dataMesin[indexSekarang].ketersediaan_jumlah + hitungTotalMesin(dataMesin, &indexSebelumnya);
}

void tampilkanInfoProdusen(produsen *ptrProdusen){
    cout<<"\nINFO PRODUSEN MESIN PERTAMA\n";
    cout<<"Perusahaan      : " << ptrProdusen->perusahaan << "\n";
    cout<<"Tahun Pembuatan : " << ptrProdusen->tahun_pembuatan << "\n";
}

int main(){
    user dataUser = {"rahman","056"};
    mesin dataMesin[100] = {
        {"Excavator PC200",350000,3,{"Komatsu","2021"}},
        {"Bulldozer D85",420000,2,{"Komatsu","2020"}},
        {"Crawler Crane XCMG",750000,1,{"XCMG","2022"}},
        {"Wheel Loader WA320",300000,4,{"Komatsu","2019"}},
        {"Motor Grader CAT140K",500000,2,{"Caterpillar","2021"}}
    };
    int jumlahMesin = 5;
    int pilihanMenu;
    mesin *ptrMesin = dataMesin;
    user  *ptrUser  = &dataUser;
    cout<<"============\n";
    cout<<"LOGIN SISTEM\n";
    cout<<"============\n";
    if(!prosesLogin(ptrUser)){
        cout<<"Gagal login sebanyak 3 kali, program berhenti\n";
        return 0;
    }

    do{
        tampilkanMenu();
        cin>>pilihanMenu;
        if(pilihanMenu==1){
            registrasiMesin(ptrMesin, &jumlahMesin);
        }
        else if(pilihanMenu==2){
            tampilkanKatalog(ptrMesin, &jumlahMesin, "DATA KATALOG");
        }
        else if(pilihanMenu==3){
            updateJumlahMesin(ptrMesin, &jumlahMesin);
        }
        else if(pilihanMenu==4){
            hapusMesin(ptrMesin, &jumlahMesin);
        }
        else if(pilihanMenu==5){
            int indexAwal = jumlahMesin - 1;
            int totalMesin = hitungTotalMesin(ptrMesin, &indexAwal);
            cout<<"Total seluruh unit mesin : " << totalMesin << endl;
            tampilkanInfoProdusen(&ptrMesin[0].dataProdusen);
        }
    } while(pilihanMenu!=6);
    cout<<"Program selesai\n";
    return 0;
}