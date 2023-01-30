#include <iostream>
using namespace std;

const int length = 50;
int balance;
int i = 0;

struct Data{
    int no;
    int tanggal;
    int pemasukkan;
    int pengeluaran;
    string ket;
};
Data inputData[length];
char ulang;

void tampil();
void add();
void add2();
void edit();
void del();
void summary();

int main(){

    system("cls");
    int menu;
    enum option{ADD1 = 1, ADD2, READ, UPDATE, DELETE, FINISH};

    do{
        cout << "==========================================" << endl;
        cout << "-------------CATATAN KEUANGAN-------------" << endl;
        cout << "==========================================" << endl;
        cout << "1. Tambah pemasukkan" << endl;
        cout << "2. Tambah pengeluaran" << endl;
        cout << "3. Menampilkan laporan keuangan" << endl;
        cout << "4. Mengedit data" << endl;
        cout << "5. Menghapus data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan : ";
        cin >> menu;

        switch(menu){
            case ADD1:
                add();
                system("cls");
                break;
            case ADD2:
                add2();
                system("cls");
                break;
            case READ:
                do{
                    tampil();
                    summary();
                    cout << "\nKembali ?<y>";
                    cin >> ulang;
                    system("cls");
                }while(ulang =! 'y');
                break;
            case UPDATE:
                edit();
                system("cls");
                break;
            case DELETE:
                del();
                system("cls");
                break;
            case FINISH:
                cout << "segera keluar...";
                break;
        }
    }while (menu != FINISH);
    return 0;
}

void tampil(){
    system("cls");
    if(i > 0){
        cout << "=========================================================================\n";
        cout << "|NO\t|TGL\t|PEMASUKAN\t|PENGELUARAN\t|KETERANGAN\t\t|\n";
        cout << "-------------------------------------------------------------------------\n";
        for(int a=0; a<i; a++){
            cout << "|" << inputData[a].no << "\t|" << inputData[a].tanggal << "\t|" << inputData[a].pemasukkan << "\t\t|"
            << inputData[a].pengeluaran << "\t\t|" << inputData[a].ket << "\t\t\t|";
            cout << endl;
        }
        cout << "=========================================================================\n";

    }else {
        cout << "=========================================================================\n";
        cout << "|NO\t|TGL\t|PEMASUKAN\t|PENGELUARAN\t|KETERANGAN\t\t|\n";
        cout << "-------------------------------------------------------------------------\n";
        cout << "|       |       |               |               |                       |\n";
        cout << "=========================================================================\n";
    }
}
void add(){
    do{
        tampil();
        cout << endl;
        if(i < length){
            inputData[i].no = i+1;
            cout << "Tanggal : ";cin >> inputData[i].tanggal;
            cout << "Jumlah pemasukkan : ";cin >> inputData[i].pemasukkan;
            inputData[i].pengeluaran = 0;
            cout << "Keterangan : ";cin >> inputData[i].ket;
            i++;
            tampil();
            cout << endl << endl;
            cout << "Tambah lagi?<y/n>";cin >> ulang;
        }else{
            cout << "Memori penuh\n";
            cout << "Ketik n untuk kembali ";
            cin >> ulang;
        }
    }while (ulang == 'y');
}
void add2(){
    do{
        tampil();
        cout << endl;
        if(i < length){
            inputData[i].no = i+1;
            cout << "Tanggal : ";cin >> inputData[i].tanggal;
            cout << "Jumlah pengeluaran : ";cin >> inputData[i].pengeluaran;
            inputData[i].pemasukkan = 0;
            cout << "Keterangan : ";cin >> inputData[i].ket;
            i++;
            tampil();
            cout << endl << endl;
            cout << "Tambah lagi?<y/n>";cin >> ulang;
        }else{
            cout << "Memori penuh\n";
            cout << "Ketik n untuk kembali ";
            cin >> ulang;
        }
    }while (ulang == 'y');
}
void edit(){
    do{
        tampil();
        int pilih;
        atas :
        cout << "\nMasukkan no yg akan diedit: ";
        cin >> pilih;
        if(pilih > i || pilih < i){
            cout << "data tidak ditemukan" << endl;
        }
        for(int a=0; a<i; a++){
            if(pilih == inputData[a].no){
                cout << "Masukkan pemasukkan yg baru: ";
                cin >> inputData[a].pemasukkan;
                cout << "Masukkan pengeluaran yg baru: ";
                cin >> inputData[a].pengeluaran;
                tampil();
                break;
            }
        }

        cout << "edit lagi<y/n>?";
        cin >> ulang;
    }while(ulang=='y');
}
void del(){
    do{
        tampil();
        int pilih;
        cout << "hapus data no: ";
        cin >> pilih;
        for(int a=0; a<i; a++){
            if(pilih == inputData[a].no){
                for(int b=a; b<i; b++){
                    inputData[b].tanggal = inputData[b+1].tanggal;
                    inputData[b].pemasukkan = inputData[b+1].pemasukkan;
                    inputData[b].pengeluaran = inputData[b+1].pengeluaran;
                    inputData[b].ket = inputData[b+1].ket;
                }
            }
        }
        i--;
        tampil();
        cout << "hapus lagi?<y/n>";
        cin >> ulang;
    }while(ulang == 'y');
}
void summary(){
    float debit= 0, kredit = 0, saldo;
    for(int a=0; a<i; a++){
        debit  += inputData[a].pemasukkan;
        kredit += inputData[a].pengeluaran;
    }
    saldo = debit - kredit;
    float persen = kredit/debit * 100;
    cout << "SALDO : " << saldo << endl;
    cout << "Terjadi pengeluaran sebesar "<< persen << "% dari total pemasukkan" << endl;
}
