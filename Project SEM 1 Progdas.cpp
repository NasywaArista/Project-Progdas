#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Class Customer (untuk data dari customer)
class Customer {
private:
    int idCustomer;
    string name;
    string address;
    int noTelp;

public:
    Customer(int id, string n, string addr, int telp) : idCustomer(id), name(n), address(addr), noTelp(telp) {}

    int getId() { return idCustomer; }
    string getName() { return name; }
    string getAddress() { return address; }
    int getNoTelp() { return noTelp; }

    void setId(int id) { idCustomer = id; }
    void setName(string n) { name = n; }
    void setAddress(string addr) { address = addr; }
    void setNoTelp(int telp) { noTelp = telp; }
};

// Class Buku (elemen-elemen buku)
class Buku {
private:
    int idBuku;
    string judulBuku;
    string penulis;
    string penerbit;

public:
    Buku(int id, string judul, string penulisBuku, string penerbitBuku)
        : idBuku(id), judulBuku(judul), penulis(penulisBuku), penerbit(penerbitBuku) {}

    int getIdBuku() { return idBuku; }
    string getJudulBuku() { return judulBuku; }
    string getPenulis() { return penulis; }
    string getPenerbit() { return penerbit; }

    void setIdBuku(int id) { idBuku = id; }
    void setJudulBuku(string judul) { judulBuku = judul; }
    void setPenulis(string penulisBuku) { penulis = penulisBuku; }
    void setPenerbit(string penerbitBuku) { penerbit = penerbitBuku; }
};

// Class PeminjamanBuku (yang akan ditampilkan saat proses peminjaman buku selesai)
class PeminjamanBuku {
private:
    string judulBuku;
    int idBuku;
    string tanggalPinjam;
    string tanggalKembali;

public:
    PeminjamanBuku(string judul, int id, string pinjam, string kembali)
        : judulBuku(judul), idBuku(id), tanggalPinjam(pinjam), tanggalKembali(kembali) {}

    string getJudulBuku() { return judulBuku; }
    int getIdBuku() { return idBuku; }
    string getTanggalPinjam() { return tanggalPinjam; }
    string getTanggalKembali() { return tanggalKembali; }

    void setJudulBuku(string judul) { judulBuku = judul; }
    void setIdBuku(int id) { idBuku = id; }
    void setTanggalPinjam(string pinjam) { tanggalPinjam = pinjam; }
    void setTanggalKembali(string kembali) { tanggalKembali = kembali; }

    void print() {
        cout << "Judul Buku: " << judulBuku << endl;
        cout << "ID Buku: " << idBuku << endl;
        cout << "Tanggal Pinjam: " << tanggalPinjam << endl;
        cout << "Tanggal Kembali: " << tanggalKembali << endl;
    }
};

// Class Notifikasi
class Notifikasi {
public:
    static void getJudulBuku(string judul) {
        cout << "\nNotifikasi: Buku \"" << judul << "\" sedang dipinjam." << endl;
    }

    static void getTanggalKembali(string tanggal) {
        cout << "Notifikasi: Buku harus dikembalikan sebelum tanggal " << tanggal << "." << endl;
    }
};

// Fungsi untuk mendapatkan tanggal saat ini dalam format YYYY-MM-DD
string getTanggalSekarang() {
    time_t t = time(0);
    tm* now = localtime(&t);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", now);
    return string(buffer);
}

// Fungsi untuk menambahkan hari ke tanggal
string tambahHari(string tanggal, int hari) {
    tm t = {};
    sscanf(tanggal.c_str(), "%d-%d-%d", &t.tm_year, &t.tm_mon, &t.tm_mday);
    t.tm_year -= 1900;
    t.tm_mon -= 1;

    time_t waktu = mktime(&t) + hari * 24 * 60 * 60;
    tm* hasil = localtime(&waktu);

    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", hasil);
    return string(buffer);
}

// MainApp (yang akan muncul saat program di jalankan)
int main() {
    // Login sederhana
    cout << "===HALO SELAMAT DATANG===\n";
    cout << "Silahkan Masuk\n\n";
    string username, password;
    cout << "### Login ###\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username != "Aifly" || password != "0404") {
        cout << "Login gagal!" << endl;
        return 0;
    }

    cout << "Login berhasil!\n";

    // Daftar buku (memasukan elemen vector)
    vector<Buku> daftarBuku = {
        Buku(101, "Ayah Ini Arahnya Ke Mana, Ya?", "Khoirul Trian", "Gradien Mediatama"),
        Buku(102, "Kado Terbaik", "J.S. Khairen", "Gramedia Widiasarana"),
        Buku(103, "HELLO", "Tere Liye", "Sabak Grip Nusantara" ),
        Buku(104, "Laut Bercerita", "Leila S. Chudori", "Kepustakaan Populer Gramedia" ),
        Buku(105, "Teka-Teki Rumah Miring", "Uketsu", "Gramedia Pustaka"),
        Buku(106, "Toko Kelontong Namiya", "Kaigo Higashino", "Gramedia Pustaka")
    };

    // Memilih buku
    cout << "\n=== Daftar Buku ===\n";
    for (size_t i = 0; i < daftarBuku.size(); ++i) {
        cout << i + 1 << ". " << daftarBuku[i].getJudulBuku() << " oleh " << daftarBuku[i].getPenulis() << ", penerbit: "<< daftarBuku[i].getPenerbit()<< endl;
    }

    int pilihanBuku;
    cout << "\nPilih nomor buku yang ingin dipinjam: ";
    cin >> pilihanBuku;

    if (pilihanBuku < 1 || pilihanBuku > daftarBuku.size()) {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    Buku bukuDipilih = daftarBuku[pilihanBuku - 1];
    cout << "Anda memilih buku: " << bukuDipilih.getJudulBuku() << endl;

    // Menentukan tanggal peminjaman dan pengembalian secara otomatis (di sisni aku set 10 hari setelah peminjaman)
    string tanggalPinjam = getTanggalSekarang();
    string tanggalKembali = tambahHari(tanggalPinjam, 10);

    // Membuat objek peminjaman (judul buku yang dipilih, tanggal dipinjam, dan tanggal dikembalikan)
    PeminjamanBuku peminjaman(bukuDipilih.getJudulBuku(), bukuDipilih.getIdBuku(), tanggalPinjam, tanggalKembali);

    // Menampilkan informasi peminjaman
    cout << "\n=== Informasi Peminjaman ===" << endl;
    peminjaman.print();

    // Menampilkan notifikasi
    Notifikasi::getJudulBuku(bukuDipilih.getJudulBuku());
    Notifikasi::getTanggalKembali(tanggalKembali);

    cout << "\nPeminjaman berhasil!" << endl;

    return 0;
}
