#include "Buku.h"

vector<Buku> daftarBuku;

// REKURSIF
int hitungTotalStok(int index)
{
    if(index >= daftarBuku.size())
        return 0;

    return daftarBuku[index].stok +
           hitungTotalStok(index + 1);
}

// BACA FILE
void bacaFile()
{
    ifstream file("buku.txt");

    if(!file.is_open())
        return;

    Buku b;

    while(getline(file,b.kode))
    {
        getline(file,b.judul);
        getline(file,b.penulis);

        file >> b.stok;
        file.ignore();

        daftarBuku.push_back(b);
    }

    file.close();
}

// SIMPAN FILE
void simpanFile()
{
    ofstream file("buku.txt");

    for(int i=0;i<daftarBuku.size();i++)
    {
        file << daftarBuku[i].kode << endl;
        file << daftarBuku[i].judul << endl;
        file << daftarBuku[i].penulis << endl;
        file << daftarBuku[i].stok << endl;
    }

    file.close();
}

// TAMBAH BUKU
void tambahBuku()
{
    Buku b;

    cin.ignore();

    cout << "\n=== TAMBAH BUKU ===\n";

    cout << "Kode Buku : ";
    getline(cin,b.kode);

    cout << "Judul Buku : ";
    getline(cin,b.judul);

    cout << "Penulis : ";
    getline(cin,b.penulis);

    cout << "Stok Buku : ";
    cin >> b.stok;

    daftarBuku.push_back(b);

    simpanFile();

    cout << "\nData berhasil ditambahkan!\n";
}

// HAPUS BUKU
void hapusBuku()
{
    string kode;
    bool ditemukan = false;

    cin.ignore();

    cout << "\n=== HAPUS BUKU ===\n";
    cout << "Masukkan Kode Buku : ";
    getline(cin,kode);

    for(int i=0;i<daftarBuku.size();i++)
    {
        if(daftarBuku[i].kode == kode)
        {
            daftarBuku.erase(
                daftarBuku.begin()+i
            );

            ditemukan = true;
            break;
        }
    }

    if(ditemukan)
    {
        simpanFile();
        cout << "\nData berhasil dihapus!\n";
    }
    else
    {
        cout << "\nKode buku tidak ditemukan!\n";
    }
}

void lihatBuku()
{
    cout << "\n===== DATA BUKU =====\n";

    if(daftarBuku.empty())
    {
        cout << "Belum ada data buku.\n";
        return;
    }

    for(int i=0;i<daftarBuku.size();i++)
    {
        cout << "\nData Buku Ke-" << i+1 << endl;
        cout << "Kode Buku : "
             << daftarBuku[i].kode << endl;

        cout << "Judul Buku : "
             << daftarBuku[i].judul << endl;

        cout << "Penulis : "
             << daftarBuku[i].penulis << endl;

        cout << "Stok : "
             << daftarBuku[i].stok << endl;
    }

    cout << "\nTotal Stok Buku : "
         << hitungTotalStok(0)
         << endl;
}
