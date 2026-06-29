/**
 *  Program Final Project
 * Mata Kuliah Pengenalan Pemrograman
 * Nama Project : Pencatatan Transaksi dan Total Pemasukan Toko Baju
 * Nama Mahasiswa : Yuwan Ranu Pratama
 * NPM : 2510631170055
 * Kelas : 2025 A
**/
#include <iostream>             // Mengimpor dari Library iostream untuk operasi (cin) dan (cout)
#include <iomanip>              // Mengimppor dari Library iomanip untuk mendukung dalam pengaturan format output
using namespace std;            //menyederhanakan kode setiap kali penggunaan objek standar tidak perlu menulis std::


const int MAX_Pakaian = 150;    // Batas Maksimum Transaksi yang dapat dimuat
const int MAX_Nama = 80;
const int kemeja = 30000;       // harga tetap kemeja per potong dalam rupiah
const int kaos = 25000;         // harga tetap kaos per potong dalam rupiah
const int hoodie = 45000;       // harga tetap hoodie per potong dalam rupiah
const int jaket = 50000;        // harga tetap jaket per potong dalam rupiah
const int blazer = 80000;       // harga tetap blazer per potong dalam rupiah

//Deklarasi dan inisialisasi Variabel
string jenisPakaian[MAX_Pakaian];   // deklarasi sekaligus untuk menyimpan jenis pakaian pada array dalam setiap transaksi
string v;                           
string ukuranPakaian[MAX_Pakaian];  // deklarasi sekaligus untuk menyimpan ukuran pakaian pada array dalam setiap transaksi
string ukuran;
string namaPembeli[MAX_Nama];
string nama;
int jumlahTerjual[MAX_Pakaian];     // deklarasi sekaligus untuk menyimpan jumlah terjualnya pakaian pada array dalam setiap transaksi
int harga[MAX_Pakaian];             // deklarasi sekaligus untuk menyimpan harga pada array dalam setiap transaksi
int subTotal[MAX_Pakaian];          // deklarasi sekaligus untuk menyimpan subtotal transaksi pada array dalam setiap transaksi
int jumlahBeli;
int jumlahTransaksi = 0;            // deklarasi dan inisialisasi pada jumlah Transaksi

void bersihkanlayar();              // deklarasi fungsi untuk Membersihkan tampilan layar dengan memberikan jarak 5 baris kosong
void daftar();                      // deklarasi fungsi untuk Menampilkan daftar lengkap pakaian dan harga satuan di toko
void tampilkanmenu();               // deklarasi fungdi untuk menampilkan menu yang bisa diakses
void inputtransaksi();              // deklarasi fungsi untuk menginput transaksi yang terjadi
void ringkasan();                   // deklarsi fungsi untuk memberikan ringkasan transaksi
void cariTransaksi();               // deklarasi fungsi untuk melakukan pencarian spesifik terhadap suatu transaksi
int shwtotal();                     // deklarasi fungsi untuk menghitung total
void reset();                       // deklarasi fungsi untuk mereset data transaksi yang ada

void  bersihkanlayar() {            // deskripsi fungsi untuk membersihkan layar
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
}

void tampilkanmenu(){               //deskripsi fungsi untuk menampilkan menu
        cout << "=========================================" << endl;
        cout << "|                                       |" << endl;
        cout << "|           YOUTZH CLOTH STORE          |" << endl;
        cout << "|                                       |" << endl;
        cout << "=========================================";
        cout << endl;
        cout << "=========================================" << endl;
        cout << "|                  MENU                 |" << endl;
        cout << "=========================================";
        cout << endl;
        cout << "=========================================" << endl;
        cout << "|1. Daftar Pakaian dan Harga            |" << endl;
        cout << "|2. Input Transaksi Pakaian             |" << endl;
        cout << "|3. Tampilkan Ringkasan Transaksi       |" << endl;
        cout << "|4. Laporan Penjualan Per Jenis Pakaian |" << endl;
        cout << "|5. Keluar                              |" << endl;
        cout << "|6. Reset Data Transaksi                |" << endl;
        cout << "=========================================" << endl;
}
void daftar(){                      //deskripsi  fungsi untuk menunjukan daftr barang yang ada
    cout << "\n=========================================" << endl;
    cout << "|1. Kemeja " << setw(15) <<"Rp." << kemeja << "         |" << endl;
    cout << "|2. Kaos   " << setw(15) <<"Rp." << kaos << "         |" << endl;
    cout << "|3. Hoodie" << setw(16) << "Rp." <<hoodie << "         |" << endl;
    cout << "|4. Jaket" << setw(17) <<  "Rp." <<jaket << "         |" << endl;
    cout << "|5. Blazer" << setw(16) << "Rp." <<blazer << "         |" << endl;
    cout << "=========================================" << endl;

}
void inputTransaksi(){              // deskripsi dungsi untuk menginput transaksi
     char lagi = 'y';               // inisialisasi untuk "lagi" yang akan digunakan pada perulangan while

    while (lagi == 'y' || lagi == 'Y') {    //melanjutkan input transaksi selama pengguna masih memasukkan'y' atau 'Y'
        if (jumlahTransaksi >= MAX_Pakaian) {
            cout << "Data Transaksi Yang Di Input Sudah Mencapai Batas Maksimum." << endl;
            break;
        }

        do                          // penggunaan looping memungkinkan pengguna menginput lebih dari sekali
        {
            int pilihan1;
            cout << "\n=====Pilih Jenis Pakaian=====\n";
            cout << "1. Kemeja" << endl;
            cout << "2. Kaos/T-shirt" << endl;
            cout << "3. Hoodie" << endl;
            cout << "4. Jaket" << endl;
            cout << "5. Blazer" << endl;
            cout << "Pilih :";
            cin >> pilihan1;

            switch (pilihan1) {     // Menentukan jenis pakaian yang dipilih pengguna berdasarkan input angka (1–5)
                                    // Lalu menyimpan data transaksi sesuai jenis pakaian yang dipilih
                case 1 :
                cout << "Masukkan Nama Anda : ";
                cin >> nama;
                cout << "----------------------------";
                cout << "\n Jenis Pakaian Yang Dipilih\n";
                cout << "----------------------------\n";
                cout << "Ada berapa Kemeja yang akan dibeli? : ";
                cin >> jumlahBeli;

                if (jumlahTransaksi + jumlahBeli > MAX_Pakaian) {
                    cout << "Melebihi kapasitas penyimpanan transaksi!\n";
                }else
                {
                    cout << "Ukuran (M/L/XL/XXL/XXXL): ";
                    cin >> ukuran;

                    // Simpan satu entri transaksi untuk jumlahBeli kemeja
                    namaPembeli[jumlahTransaksi] = nama;
                    jenisPakaian[jumlahTransaksi] = "Kemeja";
                    ukuranPakaian[jumlahTransaksi] = ukuran;
                    jumlahTerjual[jumlahTransaksi] = jumlahBeli;
                    harga[jumlahTransaksi] = kemeja;
                    subTotal[jumlahTransaksi] = jumlahBeli * kemeja;

                    jumlahTransaksi++;
                }
                break;

                case 2:
                cout << "Masukkan Nama Anda : ";
                cin >> nama;
                cout << "----------------------------";
                cout << "\n Jenis Pakaian Yang Dipilih\n";
                cout << "----------------------------\n";
                cout << "Ada berapa Kaos/T-Shirt yang akan dibeli? : ";
                cin >> jumlahBeli;

                if (jumlahTransaksi + jumlahBeli > MAX_Pakaian) {
                    cout << "Melebihi kapasitas penyimpanan transaksi!\n";
                }else
                {
                    cout << "Ukuran (M/L/XL/XXL/XXXL): ";
                    cin >> ukuran;

                    // Simpan satu entri transaksi untuk jumlahBeli kemeja
                    namaPembeli[jumlahTransaksi] = nama;
                    jenisPakaian[jumlahTransaksi] = "Kaos";
                    ukuranPakaian[jumlahTransaksi] = ukuran;
                    jumlahTerjual[jumlahTransaksi] = jumlahBeli;
                    harga[jumlahTransaksi] = kaos;
                    subTotal[jumlahTransaksi] = jumlahBeli * kaos;

                    jumlahTransaksi++;
                }
                break;
            
                case 3:
                cout << "Masukkan Nama Anda : ";
                cin >> nama;
                cout << "----------------------------";
                cout << "\n Jenis Pakaian Yang Dipilih\n";
                cout << "----------------------------\n";
                cout << "Ada berapa Hoodie yang akan dibeli? : ";
                cin >> jumlahBeli;

                if (jumlahTransaksi + jumlahBeli > MAX_Pakaian) {
                    cout << "Melebihi kapasitas penyimpanan transaksi!\n";
                }else
                {
                    cout << "Ukuran (M/L/XL/XXL/XXXL): ";
                    cin >> ukuran;

                    // Simpan satu entri transaksi untuk jumlahBeli kemeja
                    namaPembeli[jumlahTransaksi] = nama;
                    jenisPakaian[jumlahTransaksi] = "Hoodie" || "hoodie";
                    ukuranPakaian[jumlahTransaksi] = ukuran;
                    jumlahTerjual[jumlahTransaksi] = jumlahBeli;
                    harga[jumlahTransaksi] = hoodie;
                    subTotal[jumlahTransaksi] = jumlahBeli * hoodie;

                    jumlahTransaksi++;
                }
                break;

                case 4:
                cout << "Masukkan Nama Anda : ";
                cin >> nama;
                cout << "----------------------------";
                cout << "\n Jenis Pakaian Yang Dipilih\n";
                cout << "----------------------------\n";
                 cout << "Ada berapa Jaket yang akan dibeli? : ";
                cin >> jumlahBeli;

                if (jumlahTransaksi + jumlahBeli > MAX_Pakaian) {
                    cout << "Melebihi kapasitas penyimpanan transaksi!\n";
                }else
                {
                    cout << "Ukuran (M/L/XL/XXL/XXXL): ";
                    cin >> ukuran;

                    // Simpan satu entri transaksi untuk jumlahBeli kemeja
                    namaPembeli[jumlahTransaksi] = nama;
                    jenisPakaian[jumlahTransaksi] = "Jaket";
                    ukuranPakaian[jumlahTransaksi] = ukuran;
                    jumlahTerjual[jumlahTransaksi] = jumlahBeli;
                    harga[jumlahTransaksi] = jaket;
                    subTotal[jumlahTransaksi] = jumlahBeli * jaket;

                    jumlahTransaksi++;
                }
                break;

                case 5:
                cout << "Masukkan Nama Anda : ";
                cin >> nama;
                cout << "----------------------------";
                cout << "\n Jenis Pakaian Yang Dipilih\n";
                cout << "----------------------------\n";
                cout << "Ada berapa Blazer yang akan dibeli? : ";
                cin >> jumlahBeli;

                if (jumlahTransaksi + jumlahBeli > MAX_Pakaian) {
                cout << "Melebihi kapasitas penyimpanan transaksi!\n";
                }else
                {
                    cout << "Ukuran (M/L/XL/XXL/XXXL): ";
                    cin >> ukuran;

                    // Simpan satu entri transaksi untuk jumlahBeli kemeja
                    namaPembeli[jumlahTransaksi] = nama;
                    jenisPakaian[jumlahTransaksi] = "Blazer";
                    ukuranPakaian[jumlahTransaksi] = ukuran;
                    jumlahTerjual[jumlahTransaksi] = jumlahBeli;
                    harga[jumlahTransaksi] = blazer;
                    subTotal[jumlahTransaksi] = jumlahBeli * blazer;

                    jumlahTransaksi++;
                }
                break;
                
            }
            
    cout << "Input Transaksi Pakaian Lain? (y/n): ";
    cin >> lagi;
        } while (lagi == 'y');

    }
}
void ringkasan() {
    if (jumlahTransaksi == 0) {
        cout << "Belum ada transaksi yang tercatat." << endl;
        return;
    }

    cout << "\n=========== RINGKASAN TRANSAKSI ===========" << endl;
    for (int i = 0; i < jumlahTransaksi; i++) {
        cout << i + 1 << ". " << jenisPakaian[i] << endl;
        cout << " A. Nama Pembeli " << setw(7) << ": " << namaPembeli[i] << endl;
        cout << " B. Ukuran Pakaian " << setw(5) << ": " << ukuranPakaian[i] << endl;
        cout << " C. Terjual " << setw(12) << ": " << jumlahTerjual[i] << " Buah" << endl;
        cout << " D. Harga Satuan " << setw(10) << ": Rp." << harga[i] << endl;
        cout << " E. SubTotal " << setw(11) << ": " << subTotal[i] << endl;
        cout << endl;
    }

    int total = shwtotal();
    cout << "-------------------------------------------" << endl;
    cout << "Total yang harus dibayar: Rp " << total << endl;
    cout << "===========================================" << endl;
}


void cariTransaksi(){
    bool cari;
    do
    {
        cout << "\n# Masukkan Nama Pakaian Yang Ingin Dicari Data Transaksinya : ";
        cin >> v;
        cari = false;

        cout << "\n=======Data Transaksi " << v << "=======" << endl;
        for (int i = 0; i < jumlahTransaksi; i++)
        {
            if (jumlahTransaksi == 0)
            {
                cout << "Belum Ada Transaksi Yang Tersedia !!";
            }

            if (jenisPakaian[i] == v)
            {
                cout << i + 1 << ". " << jenisPakaian[i] << endl;
                cout << " A. Nama Pembeli " << setw(7) << ": " << namaPembeli[i] << endl;
                cout << " B. Ukuran Pakaian " << setw(5) << ": " << ukuranPakaian[i] << endl;
                cout << " C. Terjual " << setw(7) << ": " << jumlahTerjual[i] << " Buah" << endl;
                cout << " D. Harga " << setw(10) << ": Rp" <<harga[i] << endl;
                cout << " E. SubTotal " << setw(11) << ": " << subTotal[i] << endl;
                cout << endl;
                cari = true;
            }

        }

        if (!cari)
        {
            cout << "\nCoba Perhatikan Kembali Nama Pakaian Yang Anda Input !!" << endl;
            cout << "Huruf Besar Kecil Yang Dipakai, Tanda Baca Atau Spasi !!" << endl;
            cout << endl;

        }
    } while (!cari);
    

}


// Fungsi untuk menghitung total seluruh transaksi
int shwtotal() {
    int total = 0;
    for (int i = 0; i < jumlahTransaksi; i++) {
        total += subTotal[i];
    }
    return total;
}

// Fungsi untuk mereset data transaksi
void resetdata(){
    for (int i = 0; i < MAX_Pakaian; i++) {
        jenisPakaian[i] = "";
        jumlahTerjual[i] = 0;
        harga[i] = 0;
        subTotal[i] = 0;
    }
    jumlahTransaksi = 0;
}


// Fungsi utama
int main() {
    int pilihan;
    bool selesai = false;

    while (!selesai) {              // menjalankan menu secara berulang
                                    // hingga pengguna memilih opsi "Keluar" (menu 5)
        bersihkanlayar();
        tampilkanmenu();
        cout << "\nPilih menu: ";
        cin >> pilihan;

        switch (pilihan) {          // Menjalankan aksi sesuai pilihan menu pengguna (1–6)
                                    // Setiap case mewakili satu fitur utama program: daftar, input, ringkasan, pencarian, keluar, atau reset
            case 1:
                daftar();
                break;
            case 2:
                inputTransaksi();
                break;
            case 3:
                ringkasan();
                break;
            case 4:
                cariTransaksi();
                break;
            case 5:
                cout << "Terima Kasih Telah Menggunakan Program Admin Toko Kue." << endl;
                selesai = true;
                break;
            case 6:
                resetdata();
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        if (!selesai) {
            cout << "\nTekan ENTER untuk kembali ke menu...";
            cin.ignore();
            cin.get();
        }
    }

     return 0;
}



