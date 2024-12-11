/**
 * Project Untitled
 */


#ifndef _BUKU_H
#define _BUKU_H

class Buku {
public: 
    
void getidBuku();
    
void setidBuku();
    
void getjudulBuku();
    
void setjudulBuku();
    
void setpenulis();
    
void getpenulis();
    
void setpenerbit();
    
void getpenerbit();
private: 
    int idBuku;
    string judulBuku;
    string penulis;
    string penerbit;
};

#endif //_BUKU_H