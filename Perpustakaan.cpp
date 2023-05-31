#include "Perpustakaan.h"
void createlist(List_P &L1, List_p &L2){
    first(L1) = NULL;
    first(L2) = NULL;
}
adr_perpustakaan create_elmntPerpus(infotype_P x){
    adr_perpustakaan P = new elmnt_perpustakaan;
    info(P) = x;
    next(P) = NULL;
    return P;
}
adr_peminjam create_elmntpeminjam(infotype_p x){
    adr_peminjam P = new elmnt_peminjam;
    info(P) = x;
    next(P) = NULL;
    child(P) = NULL;
    return P;
}
void insert_last_perpustakaan(List_P &L1, adr_perpustakaan P){
    if (first(L1) == NULL){
        first(L1) = P;
        next(P) = first(L1);
    }else{
        adr_perpustakaan Q = first(L1);
        while(next(Q) != first(L1)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L1);
    }
}
void insert_last_peminjam(List_p &L2, adr_peminjam P){
    if (first(L2) == NULL){
        first(L2) = P;
    }else{
        adr_peminjam Q = first(L2);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
adr_perpustakaan search_buku(List_P L1, string nama){
    adr_perpustakaan P = first(L1);
    while (info(P).Nama != nama && next(P) != first(L1)){
        P = next(P);
    }
    return P;
}
adr_peminjam search_peminjam(List_p L2, string nama){
    adr_peminjam P = first(L2);
    while (P != NULL && info(P).nama != nama){
        P = next(P);
    }
    return P;
}

void add_peminjam(List_P L1, List_p L2, string nama_buku, string nama_peminjam){
    adr_perpustakaan P = search_buku(L1,nama_buku);
    adr_peminjam Q = search_peminjam(L2,nama_peminjam);
    if (P!= NULL && Q != NULL){
        if(info(P).total == 0){
            cout<<"Buku sudah habis terpinjam"<<endl;
        }else{
            adr_relation R;
            R = new elmnt_relation;
            next_p(R) = P;
            next_r(R)= NULL;
            if (child(Q) == NULL){
                child(Q) = R;
                info(P).total = info(P).total - 1;
            }else{
                adr_relation K = child(Q);
                while(next_r(K) != NULL){
                    K = next_r(K);
                }
                next_r(K) = R;
                info(P).total = info(P).total - 1;
            }
        }
   }
}

void print_perpus(List_P L1){
    adr_perpustakaan P = first(L1);

    if(P != NULL){
        int i = 1;
        cout<< "[" << "List Buku ke-" << i << "]"<<endl;
        cout<< "ID Buku: " << info(P).IDbuku << endl;
        cout<< "Nama Buku: " << info(P).Nama << endl;
        cout<< "Jenis Buku: " << info(P).jenis << endl;
        cout<< "Total Buku: " << info(P).total << endl;
        while (next(P) != first(L1)){
            i++;
            P = next(P);
            cout<< "[" << "List Buku ke-" << i << "]"<<endl;
            cout<< "ID Buku: " << info(P).IDbuku << endl;
            cout<< "Nama Buku: " << info(P).Nama << endl;
            cout<< "Jenis Buku: " << info(P).jenis << endl;
            cout<< "Total Buku: " << info(P).total << endl;
        }
    }else{
        cout<< "List Buku Kosong" <<endl;
    }
}
void print_peminjam(List_p L2){
    adr_peminjam P = first(L2);
    if (P != NULL){
        while(P != NULL){
            cout << "Nama Peminjam :"<<info(P).nama<<endl;
            cout << "Dengan ID Peminjam : "<<info(P).id_peminjam<<endl;
            P = next(P);
            cout << endl;
        }
    }else{
        cout<< "List Member Kosong" <<endl;
    }
}
void print_ALL(List_p L1){
    adr_peminjam P;
    P = first(L1);
    while(P != NULL){
        cout << "Nama Peminjam :"<<info(P).nama<<endl;
        cout << "Dengan ID Peminjam : "<<info(P).id_peminjam<<endl;
        adr_relation Q = child(P);
        while(Q != NULL){
            cout << "ID Buku Yang dipinjam : "<<info(next_p(Q)).IDbuku<<endl;
            cout << "Buku yang dipinjam : "<<info(next_p(Q)).Nama<<endl;
            cout << "Jenisnya : "<<info(next_p(Q)).jenis<<endl;
            cout << "Total Buku di Perpustakaan : " << info(next_p(Q)).total<<endl;
            Q = next_r(Q);
            cout << endl;
        }
        P = next(P);
        cout << endl;
    }
}
void mengembalikan(List_p &L1, string nama_buku, string nama_peminjam){
    adr_peminjam P = search_peminjam(L1, nama_peminjam);
    if (P != NULL){
        if(child(P) != NULL){
            adr_relation R = child(P);
            while(R != NULL && info(next_p(R)).Nama != nama_buku){
                R = next_r(R);
            }
            if(R == NULL){
                cout<<"Anda tidak meminjam Buku "<< nama_buku<<endl;
            }
            else if (next_r(R) == NULL){
                child(P) = NULL;
                info(next_p(R)).total = info(next_p(R)).total + 1;
                next_p(R) = NULL;
            }else{
                if(R == child(P)){
                    child(P) = next_r(R);
                    next_r(R) = NULL;
                    info(next_p(R)).total = info(next_p(R)).total + 1;
                    next_p(R) = NULL;
                }else if(next_r(R) == NULL){
                    adr_relation K = child(P);
                    while(next_r(next_r(K)) != NULL){
                        K = next_r(K);
                    }
                    next_r(K) = NULL;
                    info(next_p(R)).total = info(next_p(R)).total + 1;
                    next_p(R) = NULL;
                }else{
                    adr_relation Q = child(P);
                    while(next_r(Q) != R){
                        Q = next_r(Q);
                    }
                    next_r(Q) = next_r(R);
                    next_r(R) = NULL;
                    info(next_p(R)).total = info(next_p(R)).total + 1;
                    next_p(R) = NULL;
                }
            }
        }else{
            cout<<"Anda tidak meminjam buku apapun"<< endl;
        }
    }
}
void delete_member(List_p &L1, string nama_member){
    if(next(first(L1)) == NULL){
        first(L1) = NULL;
    }else if(first(L1) == NULL){
        cout << "list kosong" << endl;
    }else{
        adr_peminjam P = search_peminjam(L1, nama_member);
        if(P != NULL){
            if(child(P) == NULL){
                if(P == first(L1)){
                    first(L1) = next(P);
                    next(P) = NULL;
                }else if(next(P) == NULL){
                    adr_peminjam Q = first(L1);
                    while(next(next(Q)) != NULL){
                        Q = next(Q);
                    }
                    next(Q) = NULL;
                }else{
                    adr_peminjam K = first(L1);
                    while(next(K) != P){
                        K = next(K);
                    }
                    next(K) = next(P);
                    next(P) = NULL;
                }
            }else{
                adr_relation R = child(P);
                while(R != NULL){
                    info(next_p(R)).total = info(next_p(R)).total + 1;
                    next_p(R) = NULL;
                    R = next_r(R);
                }
                child(P) =  NULL;
                if(P == first(L1)){
                    first(L1) = next(P);
                    next(P) = NULL;
                }else if(next(P) == NULL){
                    adr_peminjam Q = first(L1);
                    while(next(next(Q)) != NULL){
                        Q = next(Q);
                    }
                    next(Q) = NULL;
                }else{
                    adr_peminjam K = first(L1);
                    while(next(K) != P){
                        K = next(K);
                    }
                    next(K) = next(P);
                    next(P) = NULL;
                }

            }
        }else{
            cout << "member tidak ditemukan" << endl;
        }
    }
}
void search_child(List_p L2, string nama_buku, string nama_peminjam, adr_relation &R, adr_perpustakaan &Q){
    adr_peminjam P = search_peminjam(L2, nama_peminjam);
    if(P != NULL){
        if(child(P) != NULL){
            R = child(P);
            while(R != NULL && info(next_p(R)).Nama != nama_buku){
                R = next_r(R);
            }
            if(R != NULL){
                Q = next_p(R);
            }
        }
    }
}
void delete_child(List_P &L1, List_p L2, string nama_buku, string nama_peminjam){
    adr_peminjam P = search_peminjam(L2, nama_peminjam);
    adr_perpustakaan Q;
    adr_relation R;
    search_child(L2,nama_buku, nama_peminjam, R, Q);
    if(R == NULL){
        cout<<"Data buku tidak ada" <<endl;
    }else if (next_r(R) == NULL){
        child(P) = NULL;
        next_p(R) = NULL;
    }else{
        if(R == child(P)){
            child(P) = next_r(R);
            next_r(R) = NULL;
            next_p(R) = NULL;
        }else if(next_r(R) == NULL){
            adr_relation K = child(P);
            while(next_r(next_r(K)) != NULL){
                K = next_r(K);
            }
            next_r(K) = NULL;
            next_p(R) = NULL;
        }else{
            adr_relation X = child(P);
            while(next_r(X) != R){
                X = next_r(X);
            }
            next_r(X) = next_r(R);
            next_r(R) = NULL;
            next_p(R) = NULL;
        }
    }
    if(first(L1) == NULL){
        cout<< "List Buku kosong"<<endl;
    }else if(next(first(L1)) == NULL){
        next(first(L1)) = NULL;
        first(L1) = NULL;
    }else{
        adr_perpustakaan S = first(L1);
        while(next(S) != Q){
            S = next(S);
        }
        if(Q == first(L1)){
            next(S) = next(Q);
            first(L1) = next(Q);
            next(Q) = NULL;
        }else{
            next(S) = next(Q);
            next(Q) = NULL;
    }
    }
}
int Total_pinjam(List_p L1, string nama){
    int total = 0;
    adr_peminjam P=search_peminjam(L1,nama);
    P = first(L1);
    if (child(P)!= NULL){
        adr_relation Q = child(P);
        while(Q != NULL){
            total = total + 1;
            Q = next_r(Q);
        }
        return total;
    } else {
        return 0;
    }
}
void delete_child_and_allrelation_to_child(List_P &L1, List_p L2, string nama_buku){
    adr_peminjam P = first(L2);
    adr_perpustakaan Q;
    while(P != NULL){
        if(child(P) != NULL){
            adr_relation R = child(P);
            while(R != NULL && info(next_p(R)).Nama != nama_buku){
                R = next_r(R);
            }
            if(R != NULL){
                Q = next_p(R);
                if (next_r(R) == NULL){
                    child(P) = NULL;
                    next_p(R) = NULL;
                }else{
                    if(R == child(P)){
                        child(P) = next_r(R);
                        next_r(R) = NULL;
                        next_p(R) = NULL;
                    }else if(next_r(R) == NULL){
                        adr_relation K = child(P);
                        while(next_r(next_r(K)) != NULL){
                            K = next_r(K);
                        }
                        next_r(K) = NULL;
                        next_p(R) = NULL;
                    }else{
                        adr_relation X = child(P);
                        while(next_r(X) != R){
                            X = next_r(X);
                        }
                        next_r(X) = next_r(R);
                        next_r(R) = NULL;
                        next_p(R) = NULL;
                    }
                }
            }
        }
        P = next(P);
    }
    if(first(L1) == NULL){
        cout<< "List Buku kosong"<<endl;
    }else if(next(first(L1)) == NULL){
        next(first(L1)) = NULL;
        first(L1) = NULL;
    }else{
        adr_perpustakaan S = first(L1);
        while(next(S) != Q){
            S = next(S);
        }
        if(Q == first(L1)){
            next(S) = next(Q);
            first(L1) = next(Q);
            next(Q) = NULL;
        }else{
            next(S) = next(Q);
            next(Q) = NULL;
        }
    }
}
