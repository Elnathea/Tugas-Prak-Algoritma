#include <iostream>
using namespace std;

void tampilNama(string nama[], int n){
    for(int i=0;i<n;i++){
        cout << nama[i] << endl;
    }
}

	
void bubbleSort(string nama[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(nama[j] > nama[j+1]){
                string temp = nama[j];
                nama[j] = nama[j+1];
                nama[j+1] = temp;
            }
        }
    }
}

void quickSort(string nama[], int awal, int ahkir){
    int i = awal, j = ahkir;
    string pivot = nama[(awal+ahkir)/2];

    while(i <= j){
        while(nama[i] > pivot) i++;
        while(nama[j] < pivot) j--;

        if(i <= j){
            string temp = nama[i];
            nama[i] = nama[j];
            nama[j] = temp;
            i++;
            j--;
        }
    }

    if(awal < j)
        quickSort(nama, awal, j);
    if(i < ahkir)
        quickSort(nama, i, ahkir);
}

int main(){

    int n;

    cout << "Jumlah mahasiswa: ";
    cin >> n;
    cin.ignore();

    string nama[n];
    string namaQuick[n];

    cout << "\nMasukkan nama mahasiswa:\n";
    for(int i=0;i<n;i++){
        cout << "Nama ke-" << i+1 << " : ";
        getline(cin, nama[i]);
        namaQuick[i] = nama[i];
    }
    
    cout << "\nDaftar Nama Sebelum Sorting:\n";
    tampilNama(nama, n);

    bubbleSort(nama, n);

    cout << "\nHasil Bubble Sort (Ascending):\n";
    tampilNama(nama, n);

    quickSort(namaQuick, 0, n-1);

    cout << "\nHasil Quick Sort (Descending):\n";
    tampilNama(namaQuick, n);

}
