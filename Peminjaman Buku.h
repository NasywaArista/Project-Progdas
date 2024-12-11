/**
 * Project Untitled
 */


#ifndef _PEMINJAMAN BUKU_H
#define _PEMINJAMAN BUKU_H

class Peminjaman Buku {
public: 
    
void getjudulBuku();
    
void getidBuku();
    
void settanggalPinjam();
    
void gettanggalPinjam();
    
void settanggalKembali();
    
void gettanggalkembali();
    
void print();
private: 
    string judulBuku;
    int idBuku;
    date tanggalPinjam;
    date tanggalKembali;
};

#endif //_PEMINJAMAN BUKU_H