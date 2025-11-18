#include <iostream>
#include <cstdlib>
using namespace std;

// Deklarasi data global
const int JUMLAH_MENU = 6;
string menuMakanan[JUMLAH_MENU] = {
    "Nasi Goreng", "Mie Ayam", "Ayam Geprek", "Es Teh", "Es Jeruk", "Kopi Americano"
};
int hargaMenu[JUMLAH_MENU] = {20000, 15000, 18000, 5000, 7000, 8000};
int pesanan[JUMLAH_MENU] = {0};

// Deklarasi fungsi
void tampilMenu();
void tambahPesanan();
void hitungTotal();
void hapusPesanan();

// Fungsi utama
int main() {
    int pilihan;

    do {
        system("cls"); // Bersihkan layar
        cout << "=====================================\n";
        cout << "          RESTORAN MAHASIGMA\n";
        cout << "=====================================\n";
        cout << "1. Lihat Menu\n";
        cout << "2. Tambah Pesanan\n";
        cout << "3. Lihat Total Pembayaran\n";
        cout << "4. Hapus Pesanan\n";
        cout << "5. Keluar\n";
        cout << "-------------------------------------\n";
        cout << "Pilih Opsi (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilMenu();
                break;
            case 2:
                tambahPesanan();
                break;
            case 3:
                hitungTotal();
                break;
            case 4:
                hapusPesanan();
                break;
            case 5:
                cout << "\nMakasih sudah berkunjung bang.\n";
                break;
            default:
                cout << "\nPilih yang bener!\n";
        }

        if (pilihan != 5) {
            cout << "\nTekan ENTER untuk kembali ke menu utama";
            cin.ignore();
            cin.get();
        }

    } while (pilihan != 5);

    return 0;
}

// Untuk menampilkan daftar menu
void tampilMenu() {
    system("cls");
    cout << "========== DAFTAR MENU ==========\n";
    for (int i = 0; i < JUMLAH_MENU; i++) {
        cout << i + 1 << ". " << menuMakanan[i] << " - Rp" << hargaMenu[i] << endl;
    }
    cout << "=================================\n";
}

// Untuk menambah pesanan
void tambahPesanan() {
    system("cls");
    int pilih, jumlah;
    char lanjut;

    do {
        tampilMenu();
        cout << "Pilih menu yang mana : ";
        cin >> pilih;

        if (pilih >= 1 && pilih <= JUMLAH_MENU) {
            cout << "Masukkan jumlah pesanan: ";
            cin >> jumlah;
            pesanan[pilih - 1] += jumlah;
            cout << "Pesanan telah ditambahkan.\n";
        } else {
            cout << "Pilih nomor menu yang benar!\n";
        }

        cout << "Mau tambah lagi? (y/n): ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');
}

// Untuk menghitung total pembayaran
void hitungTotal() {
    system("cls");
    int total = 0;

    cout << "========== RINCIAN PESANAN ==========\n";
    for (int i = 0; i < JUMLAH_MENU; i++) {
        if (pesanan[i] > 0) {
            int subtotal = pesanan[i] * hargaMenu[i];
            cout << menuMakanan[i] << " x " << pesanan[i] << " = Rp" << subtotal << endl;
            total += subtotal;
        }
    }

    cout << "------------------------------------\n";
    cout << "Total Sebelum Diskon: Rp" << total << endl;

    if (total > 100000) {
        float diskon = total * 0.1;
        total -= diskon;
        cout << "Diskon 10% cuy: Rp" << diskon << endl;
    }

    cout << "Total Akhirnya: Rp" << total << endl;
    cout << "=====================================\n";
}

// Untuk hapus pesanan
void hapusPesanan() {
    system("cls");
    for (int i = 0; i < JUMLAH_MENU; i++) {
        pesanan[i] = 0;
    }
    cout << "Semua pesanan sudah dihapus.\n";
}