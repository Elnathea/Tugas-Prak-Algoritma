#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah elemen array : ";
    cin >> n;

    int angka[n];     
    int *ptr = angka;

    cout << "Masukkan " << n << " angka : ";
    for (int i = 0; i < n; i++) {
        cin >> *(ptr + i);
    }

    int max = *ptr;
    int min = *ptr;
    int sum = *ptr;

    for (int i = 1; i < n; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }

        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
        
        sum += *(ptr + i);
    }
    
    float avg = (float)sum / n;
	
    cout << "Nilai Maximum = " << max << endl;
    cout << "Nilai Minimum = " << min << endl;
    cout << "Rata - Rata = " << avg << endl;
    
    return 0;
}
