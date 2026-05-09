#include <iostream>
#include <vector>
using namespace std;

// =======================
// CLASS BARANG
// =======================
class Barang {
public:
    string nama;
    int harga;
    int jumlah;

    Barang(string n, int h, int j) {
        nama = n;
        harga = h;
        jumlah = j;
    }

    int subtotal() {
        return harga * jumlah;
    }
};

// =======================
// CLASS TRANSAKSI
// =======================
class Transaksi {
private:
    vector<Barang> daftarBarang;

public:
    // tambah barang
    void tambahBarang(Barang b) {
        if (b.harga < 0 || b.jumlah < 0) {
            cout << "Data tidak valid!\n";
            return;
        }

        daftarBarang.push_back(b);
    }

    // hitung total
    int hitungTotal() {
        int total = 0;

        for (int i = 0; i < daftarBarang.size(); i++) {
            total += daftarBarang[i].subtotal();
        }

        return total;
    }

    // tampilkan struk
    void tampilkanStruk() {
        cout << "\n===== STRUK BELANJA =====\n";

        for (int i = 0; i < daftarBarang.size(); i++) {
            cout << daftarBarang[i].nama
                 << " | Harga: " << daftarBarang[i].harga
                 << " | Jumlah: " << daftarBarang[i].jumlah
                 << " | Subtotal: " << daftarBarang[i].subtotal()
                 << endl;
        }

        cout << "--------------------------\n";
        cout << "TOTAL BELANJA : " << hitungTotal() << endl;
        cout << "==========================\n";
    }
};

// =======================
// UNIT TEST
// =======================

// Test total belanja
bool testHitungTotal() {
    Transaksi t;

    t.tambahBarang(Barang("Beras", 10000, 2));
    t.tambahBarang(Barang("Gula", 5000, 1));

    int hasil = t.hitungTotal();

    return hasil == 25000;
}

// Test input barang
bool testInputBarang() {
    Barang b("Minyak", 15000, 2);

    if (b.nama == "Minyak" &&
        b.harga == 15000 &&
        b.jumlah == 2) {
        return true;
    }

    return false;
}

// =======================
// INTEGRATION TEST
// =======================
bool integrationTest() {
    Transaksi t;

    t.tambahBarang(Barang("Telur", 2000, 5));
    t.tambahBarang(Barang("Mie", 3000, 2));

    int total = t.hitungTotal();

    return total == 16000;
}

// =======================
// MAIN PROGRAM
// =======================
int main() {

    // ===================
    // UNIT TEST
    // ===================
    cout << "=== UNIT TEST ===\n";

    if (testHitungTotal())
        cout << "Unit Test Total Belanja: PASS\n";
    else
        cout << "Unit Test Total Belanja: FAIL\n";

    if (testInputBarang())
        cout << "Unit Test Input Barang: PASS\n";
    else
        cout << "Unit Test Input Barang: FAIL\n";

    // ===================
    // INTEGRATION TEST
    // ===================
    cout << "\n=== INTEGRATION TEST ===\n";

    if (integrationTest())
        cout << "Integration Test Toko: PASS\n";
    else
        cout << "Integration Test Toko: FAIL\n";

    // ===================
    // PROGRAM UTAMA
    // ===================
    Transaksi transaksi;

    int jumlahBarang;

    cout << "\n=== PROGRAM TOKO BAHAN MAKANAN ===\n";
    cout << "Masukkan jumlah barang: ";
    cin >> jumlahBarang;

    for (int i = 0; i < jumlahBarang; i++) {
        string nama;
        int harga, jumlah;

        cout << "\nBarang ke-" << i + 1 << endl;

        cout << "Nama Barang : ";
        cin >> nama;

        cout << "Harga Barang : ";
        cin >> harga;

        cout << "Jumlah Beli : ";
        cin >> jumlah;

        transaksi.tambahBarang(Barang(nama, harga, jumlah));
    }

    transaksi.tampilkanStruk();

    return 0;
}
