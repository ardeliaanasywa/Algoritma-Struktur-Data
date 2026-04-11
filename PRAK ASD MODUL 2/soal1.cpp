#include <iostream>
using namespace std;

#define MAX 5

struct Stack {
    int atas;
    int data[MAX];
} Tumpuk;

int kosong() {
    return (Tumpuk.atas == -1);
}

int penuh() {
    return (Tumpuk.atas == MAX - 1);
}

void input(int data) {
    if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << data << " Masuk Ke Stack\n";
    } else {
        cout << "Tumpukan Penuh\n";
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Terambil\n";
        Tumpuk.atas--;
    } else {
        cout << "Data Kosong\n";
    }
}

void tampil() {
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    } else {
        cout << "Tumpukan Kosong\n";
    }
}

int main() {
    Tumpuk.atas = -1;
    input(10);  
    input(20);  
    input(30);  
    
    cout << "\n--- Kondisi Stack Sekarang ---\n";
    tampil();   
    
    cout << "\n--- Mencoba Hapus ---\n";
    hapus();    
    
    cout << "\n--- Kondisi Stack Setelah Dihapus ---\n";
    tampil();  
    return 0;
}