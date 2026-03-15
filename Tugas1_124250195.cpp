#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Produk{
    char nama[50];
    float harga;
    char kategori[30];
    int stok;
};

void tambahProduk(Produk data[], int &n){

    FILE *lele = fopen("lelele.csv","a");

    int jumlah;

    cout << "Masukkan jumlah produk: ";
    cin >> jumlah;
    cin.ignore();

    for(int i = 0; i < jumlah; i++){

        cout << "\nProduk ke-" << i+1 << endl;

        cout << "Nama: ";
        cin.getline(data[n].nama,50);

        cout << "Harga: ";
        cin >> data[n].harga;

        cout << "Kategori: ";
        cin >> data[n].kategori;

        cout << "Stok: ";
        cin >> data[n].stok;
        cin.ignore();

        fprintf(lele,"%s,%.1f,%s,%d\n",
                data[n].nama,
                data[n].harga,
                data[n].kategori,
                data[n].stok);

        n++;
    }

    fclose(lele);

    cout << "\nData berhasil disimpan ke file.\n";
}

void tampilProduk(){

    FILE *lele = fopen("lelele.csv","r");

    if(lele == NULL){
        cout << "Data belum ada\n";
        return;
    }

    Produk temp;

    cout<<"\n===== DAFTAR PRODUK =====\n";

    while(fscanf(lele,"%[^,],%f,%[^,],%d\n",
        temp.nama,
        &temp.harga,
        temp.kategori,
        &temp.stok) != EOF){

        cout<<"Nama : "<<temp.nama<<endl;
        cout<<"Harga : "<<temp.harga<<endl;
        cout<<"Kategori : "<<temp.kategori<<endl;
        cout<<"Stok : "<<temp.stok<<endl;
        cout<<"--------------------\n";
    }

    fclose(lele);
}

void bubbleSort(Produk data[], int n){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){

            if(strcmp(data[j].nama,data[j+1].nama)>0){

                Produk temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
    }

    cout<<"Data berhasil diurutkan berdasarkan nama\n";
}

void quickSort(Produk data[], int low, int high){

    if(low >= high)
        return;

    float pivot = data[high].harga;
    int i = low - 1;

    for(int j = low; j < high; j++){

        if(data[j].harga > pivot){
            i++;
            Produk temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    Produk temp = data[i+1];
    data[i+1] = data[high];
    data[high] = temp;

    int pi = i + 1;

    quickSort(data, low, pi - 1);
    quickSort(data, pi + 1, high);
}

void sequentialSearch(Produk data[], int n){

    char cari[50];

    cout<<"Masukkan nama produk: ";
    cin.ignore();
    cin.getline(cari,50);

    for(int i=0;i<n;i++){

        if(strcmp(data[i].nama,cari)==0){

            cout<<"Produk ditemukan\n";
            cout<<"Harga : "<<data[i].harga<<endl;
            cout<<"Kategori : "<<data[i].kategori<<endl;
            cout<<"Stok : "<<data[i].stok<<endl;
            return;
        }
    }

    cout<<"Produk tidak ditemukan\n";
}

void binarySearch(Produk data[], int n){

    bubbleSort(data,n);

    char cari[50];

    cout<<"Masukkan nama produk: ";
    cin.ignore();
    cin.getline(cari,50);

    int kiri=0;
    int kanan=n-1;

    while(kiri<=kanan){

        int mid=(kiri+kanan)/2;

        int hasil=strcmp(data[mid].nama,cari);

        if(hasil==0){

            cout<<"Produk ditemukan\n";
            cout<<"Harga : "<<data[mid].harga<<endl;
            cout<<"Kategori : "<<data[mid].kategori<<endl;
            cout<<"Stok : "<<data[mid].stok<<endl;
            return;
        }

        else if(hasil<0)
            kiri=mid+1;

        else
            kanan=mid-1;
    }

    cout<<"Produk tidak ditemukan\n";
}

int main(){

    Produk data[10];
    int n;
    int pilih;

    do{

    system("cls");

    cout << "====MENU====\n";
    cout << "1. Tambah Produk\n";
    cout << "2. Tampilkan Data Produk\n";
    cout << "3. Urutkan Produk\n";
    cout << "4. Cari Produk\n";
    cout << "5. Keluar\n";
    cout << "Masukkan pilihan : ";
    cin >> pilih;

    switch(pilih){

        case 1:
            tambahProduk(data,n);
            system("pause");
            system("cls");
            break;

        case 2:
            tampilProduk();
            system("pause");
            system("cls");
            break;

        case 3:{
            int metode;

            cout << "\n----- Metode Pengurutan -----\n";
            cout << "1. Berdasarkan Nama (Bubble Sort)\n";
            cout << "2. Berdasarkan Harga (Quick Sort)\n";
            cout << "Pilih metode : ";
            cin >> metode;

            if(metode == 1)
                bubbleSort(data,n);
            else if(metode == 2){
                quickSort(data,0,n-1);
                cout << "Data berhasil diurutkan berdasarkan harga\n";
            }

            system("pause");
            system("cls");
            break;
        }

        case 4:{
            int metode;

            cout << "\n----- Metode Pencarian -----\n";
            cout << "1. Sequential Search\n";
            cout << "2. Binary Search\n";
            cout << "Pilih metode : ";
            cin >> metode;

            if(metode == 1)
                sequentialSearch(data,n);
            else if(metode == 2)
                binarySearch(data,n);

            system("pause");
            system("cls");
            break;
        }

        case 5:
            cout << "\nProgram selesai.\n";
            break;

        default:
            cout << "\nPilihan tidak tersedia.\n";
            system("pause");
            system("cls");
    }

} while(pilih != 5);

}