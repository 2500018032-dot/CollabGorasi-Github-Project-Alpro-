#include "Buku.h"

int main()
{
    string username;
    string password;

    bacaFile();

    cout << "===== LOGIN DIGILIB =====\n";

    cout << "Username : ";
    getline(cin,username);

    cout << "Password : ";
    getline(cin,password);

    // GANTI SESUAI DATA ANDA
    if(username != "Talitha" ||
       password != "23123456")
    {
        cout << "\nLogin Gagal!\n";
        return 0;
    }

    cout << "\nLogin Berhasil!\n";

    int pilih;

    do
    {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Hapus Buku\n";
        cout << "3. Lihat Buku\n";
        cout << "4. Keluar\n";
        cout << "Pilih Menu : ";
        cin >> pilih;

        switch(pilih)
        {
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
                cout << "\nTerima kasih telah menggunakan DIGILIB\n";
                break;

            default:
                cout << "\nMenu tidak tersedia!\n";
        }

    }while(pilih != 4);

    return 0;
}
