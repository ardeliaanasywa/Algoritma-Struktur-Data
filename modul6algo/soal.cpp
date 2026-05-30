#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int random(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

void SequentialSearch()
{
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save = -1;
    
    randomize();
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++)
    {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");
    
    for (int i = 0; i < 100; i++)
    {
        if (data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }
    
    printf("\nAngka yang dicari adalah: %d\n", cari);
    if (flag == 1)
    {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d\n", save);
    }
    else
    {
        printf("Data tidak ada!\n");
    }
}

void BinarySearch()
{
    clrscr();
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;
    
    cout << "Masukan jumlah data? ";
    cin >> n;
    
    int *angka = new int[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    
    cout << "-----------------------------------------------------\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }
    cout << "\n-----------------------------------------------------\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;
    
    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if (key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }
    
    if (ketemu == true)
    {
        cout << "Angka ditemukan!\n";
    }
    else
    {
        cout << "Angka tidak ditemukan!\n";
    }
    
    delete[] angka;
}

void JelaskanPerbedaan()
{
    clrscr();
    cout << "=======================================================================\n";
    cout << "        PERBEDAAN SEQUENTIAL SEARCHING DAN BINARY SEARCHING\n";
    cout << "=======================================================================\n\n";
    cout << "1. Metode / Cara Kerja:\n";
    cout << "   - Sequential Searching:\n";
    cout << "     Mencari data dengan membandingkan elemen yang dicari dengan setiap\n";
    cout << "     elemen array satu per satu dari awal hingga akhir.\n";
    cout << "   - Binary Searching:\n";
    cout << "     Mencari data dengan membagi array menjadi dua bagian terus-menerus.\n";
    cout << "     Mengecek elemen tengah, lalu menentukan area pencarian berikutnya.\n\n";
    
    cout << "2. Syarat Data:\n";
    cout << "   - Sequential Searching: Data tidak perlu diurutkan terlebih dahulu (acak).\n";
    cout << "   - Binary Searching: Data WAJIB diurutkan terlebih dahulu.\n\n";
    
    cout << "3. Kompleksitas Waktu:\n";
    cout << "   - Sequential Searching: Best Case O(1), Worst Case O(n)\n";
    cout << "   - Binary Searching: Best Case O(1), Worst Case O(log n)\n\n";
    
    cout << "4. Kelebihan & Kekurangan:\n";
    cout << "   - Sequential Searching:\n";
    cout << "       Kelebihan: Sangat mudah diimplementasikan; data tidak perlu diurutkan;\n";
    cout << "                  efisien untuk jumlah data yang sedikit.\n";
    cout << "       Kekurangan: Lambat untuk data berjumlah besar (karena harus mengecek satu per satu).\n";
    cout << "   - Binary Searching:\n";
    cout << "       Kelebihan: Sangat cepat dan efisien untuk pencarian pada data berjumlah besar.\n";
    cout << "       Kekurangan: Data harus dalam keadaan terurut terlebih dahulu; proses pengurutan\n";
    cout << "                  data (sorting) memerlukan waktu dan memori tambahan.\n";
    cout << "=======================================================================\n";
}

int main()
{
    int pilihan;
    do
    {
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilihan;
        
        switch (pilihan)
        {
            case 1:
                SequentialSearch();
                cout << "\nTekan Enter untuk kembali ke menu...";
                cin.ignore();
                cin.get();
                clrscr();
                break;
            case 2:
                BinarySearch();
                cout << "\nTekan Enter untuk kembali ke menu...";
                cin.ignore();
                cin.get();
                clrscr();
                break;
            case 3:
                JelaskanPerbedaan();
                cout << "\nTekan Enter untuk kembali ke menu...";
                cin.ignore();
                cin.get();
                clrscr();
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid! Silakan masukkan pilihan 1-4.\n";
                cout << "\nTekan Enter untuk mencoba lagi...";
                cin.ignore();
                cin.get();
                clrscr();
                break;
        }
    } while (pilihan != 4);
    
    return 0;
}