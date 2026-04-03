#include<iostream>
using namespace std;

// struct Address{
//     string kota;
//     string provinsi;
//     string negara;
// };

// int main(){
//     Address address1, address2;
//     address1.kota = "Samarinda";
//     address1.provinsi = "Kalimantan Timur";
//     address1.negara = "Indonesia";

//     address2 = address1;
//     address2.kota = "IKN";

//     cout << address1.kota << endl;
//     cout << address2.kota << endl;
//     return 0;
// }

int ubahNilai(int a, int b){
    return a = b;
}

int main(){
    int a, b;
    a = 5;
    b = 20;
    ubahNilai(a, b);
    cout << "Nilai a setelah fungsi: " << a << endl;
    return 0;
}