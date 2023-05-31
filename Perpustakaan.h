#ifndef PERPUSTAKAAN_H_INCLUDED
#define PERPUSTAKAAN_H_INCLUDED
#include <iostream>
#define info(P) P->info
#define next(P) P->next
#define next_p(P) P->next_p
#define next_r(P) P->next_r
#define child(P) P->child
#define first(L) ((L).first)

using namespace std;


struct perpustakaan{
    int IDbuku;
    string Nama;
    string jenis;
    int total;
};
typedef perpustakaan infotype_P;
typedef struct elmnt_perpustakaan *adr_perpustakaan;
typedef struct elmnt_relation *adr_relation;
typedef struct elmnt_peminjam *adr_peminjam;
struct elmnt_perpustakaan{
    infotype_P info;
    adr_perpustakaan next;
};
struct peminjam{
    int id_peminjam;
    string nama;
};
typedef peminjam infotype_p;
struct elmnt_peminjam{
    infotype_p info;
    adr_relation child;
    adr_peminjam next;

};
struct elmnt_relation{
    adr_perpustakaan next_p;
    adr_relation next_r;
};
struct List_P{
    adr_perpustakaan first;
};
struct List_p{
    adr_peminjam first;
};
void createlist(List_P &L1, List_p &L2);
adr_perpustakaan create_elmntPerpus(infotype_P x);
adr_peminjam create_elmntpeminjam(infotype_p x);
void insert_last_perpustakaan(List_P &L1, adr_perpustakaan P);
void insert_last_peminjam(List_p &L2, adr_peminjam P);
adr_perpustakaan search_buku(List_P L1, string nama);
adr_peminjam search_peminjam(List_p L2, string nama);
void add_peminjam(List_P L1, List_p L2, string nama_buku, string nama_peminjam);
void print_perpus(List_P L1);
void print_ALL(List_p L1);
void print_peminjam(List_p L2);
void mengembalikan(List_p &L1, string nama_buku, string nama_peminjam);
void delete_member(List_p &L1, string nama_member);
void search_child(List_p L2, string nama_buku, string nama_peminjam, adr_relation &R, adr_perpustakaan &Q);
void delete_child(List_P &L1, List_p L2, string nama_buku, string nama_peminjam);
int Total_pinjam(List_p L1, string nama);
void delete_child_and_allrelation_to_child(List_P &L1, List_p L2, string nama_buku);
#endif // PERPUSTAKAAN_H_INCLUDED
