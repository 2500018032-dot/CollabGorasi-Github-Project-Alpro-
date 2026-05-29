#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Buku {
    string kode;
    string judul;
    string penulis;
    int stok;
};

vector<Buku> daftarBuku;

// REKURSIF MENGHITUNG TOTAL STOK
int hitungTotalStok(int index) {
    if (index >= daftarBuku.size()) {
        return 0;
    }

    return daftarBuku[index].stok + hitungTotalStok(index + 1);
}

// MEMBACA FILE
void bacaFile() {
    ifstream file("buku.txt");

    if (!file.is_open()) {
        return;
    }

    Buku b;

    while (getline(file, b.kode)) {
        getline(file, b.judul);
        getline(file, b.penulis);
        file >> b.stok;
        file.ignore();

        daftarBuku.push_back(b);
    }

    file.close();
}

// MENYIMPAN FILE
void simpanFile() {
    ofstream file("buku.txt");

    for (int i = 0; i < daftarBuku.size(); i++) {
        file << daftarBuku[i].kode << endl;
        file << daftarBuku[i].judul << endl;
        file << daftarBuku[i].penulis << endl;
        file << daftarBuku[i].stok << endl;
    }

    file.close();
}

// TAMBAH BUKU
void tambahBuku() {
    Buku b;

    cin.ignore();

    cout << "\n===== TAMBAH BUKU =====" << endl;

    cout << "Kode Buku   : ";
    getline(cin, b.kode);

    cout << "Judul Buku  : ";
    getline(cin, b.judul);

    cout << "Penulis     : ";
    getline(cin, b.penulis);

    cout << "Stok Buku   : ";
    cin >> b.stok;

    daftarBuku.push_back(b);

    simpanFile();

    cout << "\nData buku berhasil ditambahkan!" << endl;
}

// HAPUS BUKU
void hapusBuku() {
    string kode;
    bool ditemukan = false;

    cin.ignore();

    cout << "\n===== HAPUS BUKU =====" << endl;
    cout << "Masukkan Kode Buku : ";
    getline(cin, kode);

    for (int i = 0; i < daftarBuku.size(); i++) {
        if (daftarBuku[i].kode == kode) {

            daftarBuku.erase(daftarBuku.begin() + i);

            ditemukan = true;
            break;
        }
    }

    if (ditemukan) {
        simpanFile();
        cout << "\nData buku berhasil dihapus!" << endl;
    }
    else {
        cout << "\nKode buku tidak ditemukan!" << endl;
    }
}

// LIHAT BUKU
void lihatBuku() {

    cout << "\n===== DATA BUKU =====" << endl;

    if (daftarBuku.empty()) {
        cout << "Belum ada data buku." << endl;
        return;
    }

    for (int i = 0; i < daftarBuku.size(); i++) {

        cout << "\nData Buku Ke-" << i + 1 << endl;
        cout << "Kode Buku : " << daftarBuku[i].kode << endl;
        cout << "Judul     : " << daftarBuku[i].judul << endl;
        cout << "Penulis   : " << daftarBuku[i].penulis << endl;
        cout << "Stok      : " << daftarBuku[i].stok << endl;
    }

    cout << "\n=========================" << endl;
    cout << "Total Stok Buku : "
         << hitungTotalStok(0) << endl;
}

// MAIN PROGRAM
int main() {

    string username;
    string password;

    bacaFile();

    cout << "================================" << endl;
    cout << "         LOGIN DIGILIB          " << endl;
    cout << "================================" << endl;

    cout << "Username : ";
    getline(cin, username);

    cout << "Password : ";
    getline(cin, password);

    // GANTI DENGAN NAMA DAN NIM ANDA
    if (username != "Talitha" ||
        password != "2500018032") {

        cout << "\nLogin Gagal!" << endl;
        return 0;
    }

    cout << "\nLogin Berhasil!" << endl;

    int pilih;

    do {

        cout << "\n===== MENU UTAMA =====" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Lihat Buku" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih Menu : ";
        cin >> pilih;

        switch (pilih) {

        case 1:
            tambahBuku();
            break;

        case 2:
            hapusBuku();
            break;

        case 3:
            lihatBuku();
            break;

        case 4:
            cout << "\nTerima kasih telah menggunakan DIGILIB." << endl;
            break;

        default:
            cout << "\nMenu tidak tersedia!" << endl;
        }

    } while (pilih != 4);

    return 0;
}
