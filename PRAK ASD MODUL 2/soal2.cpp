#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();
void RESET(); 
int PIL, F, R;
char PILIHAN[10], HURUF;
char Q[n];

void Inisialisasi() {
    F = -1;
    R = -1;
}

void RESET() {
    F = -1;
    R = -1;
    cout << "Antrean Dikosongkan!" << endl;
}

void INSERT() {

    if (R == n - 1) {
        cout << "Antrean Penuh!" << endl;
    } else {
        cout << "Masukkan Huruf: "; cin >> HURUF;
        if (F == -1) F = 0; 
        R++;
        Q[R] = HURUF;
    }
}

void DELETE() {
    if (F == -1) {
        cout << "Antrean Kosong!" << endl;
    } else {
        cout << "Huruf " << Q[F] << " Terambil" << endl;
        F++;
        if (F > R) {
            RESET(); 
        }
    }
}

void CETAKLAYAR() {
    if (F == -1) {
        cout << "Antrean Kosong" << endl;
    } else {
        for (int i = F; i <= R; i++) {
            cout << "Antrean ke-" << i << " = " << Q[i] << endl;
        }
    }
}

int main() {
    Inisialisasi();
    do {
        cout << "QUEUE" << endl;
        cout << "===============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);

        switch (PIL) {
            case 1: INSERT(); break;
            case 2: DELETE(); break;
            case 3: CETAKLAYAR(); break;
            default: cout << "TERIMA KASIH" << endl; break;
        }
        cout << "press any key to continue" << endl;
        getch();
        system("cls");
    } while (PIL < 4);
}