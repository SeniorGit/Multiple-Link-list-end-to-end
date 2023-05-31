#include <iostream>
#include "Perpustakaan.h"

using namespace std;

int main()
{
    bool exit = true;
    infotype_P x;
    adr_perpustakaan P;
    List_P L1;
    List_p L2;
    createlist(L1,L2);
    int pilihan1,n;
    char pilihan2;
    while(exit){
        cout<<"===========================MENU======================================="<<endl;
        cout<<"1. Menambah buku baru"<<endl;
        cout<<"2. Menampilkan semua List Buku"<<endl;
        cout<<"3. Menambah member Perpustakaan"<<endl;
        cout<<"4. Menampilkan semua List Member"<<endl;
        cout<<"5. Apakah anda ingin meminjam Buku ?"<<endl;
        cout<<"6. Menampilkan semua List Member Yang meminjam Buku dan tidak"<<endl;
        cout<<"7. Mengtembalikan Buku"<<endl;
        cout<<"8. Berhenti jadi member"<<endl;
        cout<<"9. Menghapus Buku"<<endl;
        cout<<"10. Jumlah Buku yang dipinjam"<<endl;
        cout<<"======================================================================="<<endl;
        cout<<"Masukkan Menu: ";
        cin>>pilihan1;
        cout << endl;
        switch(pilihan1){
            case 0 :
                {
                exit = false;
            break;
                }
            case 1 :
                {
                cout<<"Banyak Buku yang akan ditambahkan: ";
                cin>>n;
                cout << endl;
                for (int i = 1; i <= n; i++){
                    cout<<"Masukkan id Buku: ";
                    cin>>x.IDbuku;
                    cout<<"Masukkan Nama Buku: ";
                    cin>>x.Nama;
                    cout<<"Masukkan Jenis Buku: ";
                    cin>>x.jenis;
                    cout<<"Masukkan total Buku: ";
                    cin>>x.total;
                    P = create_elmntPerpus(x);
                    insert_last_perpustakaan(L1, P);
                    cout << endl;
                }
                cout<<"Kembali ke menu utama? (Y/N) :";
                cin>>pilihan2;
                switch(pilihan2){
                    case 'Y':
                        exit = true;
                        break;
                    case 'N':
                        exit = false;
                        break;
                }
            break;
            }
            case 2 :
                {
                print_perpus(L1);
                cout << endl;
            break;
                }
            case 3 :
                {
                adr_peminjam Q;
                int masukan;
                infotype_p y;
                cout << "Masukan Berapa Member : ";
                cin >> masukan;
                for(int h = 1;h<=masukan;h++){
                    cout << "Masukan Id Peminjam : ";
                    cin >> y.id_peminjam;
                    cout << "Masukan Nama: ";
                    cin >> y.nama;
                    Q = create_elmntpeminjam(y);
                    insert_last_peminjam(L2,Q);
                    cout << endl;
                }
                cout << endl;
            break;
            }
            case 4 :
                {
                print_peminjam(L2);
                cout << endl;
                }
            break;
            case 5:
                {
                string nama_buku,nama;
                cout<<"Nama Peminjam : ";
                cin >> nama;
                cout<< "Buku yang ingin dipinjam : ";
                cin >> nama_buku;
                add_peminjam(L1,L2, nama_buku,nama);
                cout << endl;
                }
            break;
            case 6:
                {
                print_ALL(L2);
                cout << endl;
                }
            break;
            case 7:
                {
                string nama_peminjam,buku_dipinjam;
                cout<<"Masukkan Nama Anda: ";
                cin>>nama_peminjam;
                cout<<"Buku yang akan dikembalikan: ";
                cin>>buku_dipinjam;
                mengembalikan(L2, buku_dipinjam, nama_peminjam);
                cout<<"Terima kasih"<<endl;
                cout << endl;
                }
            break;
            case 8:
                {
                string nama_peminjam1;
                cout<< "Masukkan Nama Anda: ";
                cin>> nama_peminjam1;
                cout<< "Kembalikan Buku yang anda pinjam"<< endl;
                delete_member(L2, nama_peminjam1);
                cout << endl;
                }
            break;
            case 9:
                {
                string nama_parent, nama_child;
                cout<<"Masukkan Nama: ";
                cin>>nama_parent;
                cout<<"Masukkan Nama Buku: ";
                cin>>nama_child;
                delete_child_and_allrelation_to_child(L1, L2, nama_child);
                cout << endl;
                }
            break;
            case 10:
                {
                string nama;
                cout << "Masukan Nama: ";
                cin >> nama;
                int i = Total_pinjam(L2,nama);
                cout << i <<endl;
                }
            break;
        }
    }
    return 0;
}
