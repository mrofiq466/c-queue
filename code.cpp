#include<iostream>
#include<cstdlib>
#define MAX 5
using namespace std;

struct queue {
    int data[MAX];
    int awal, akhir;
} antrean;

void init() {
    antrean.awal = -1;
    antrean.akhir = -1;
}

bool full() {
    return antrean.akhir == MAX - 1;
}

bool empty() {
    return antrean.awal == -1;
}

void inQueue() {
    int elemen;
    cout << "Data yang akan dimasukkan: ";
    cin >> elemen;
    if (empty()) {
        antrean.awal = 0;
        antrean.akhir = 0;
        antrean.data[antrean.awal] = elemen;
    } else {
        if (!full()) {
            antrean.akhir++;
            antrean.data[antrean.akhir] = elemen;
            cout << "Data berhasil ditambahkan\n";
        } else {
            cout << "Queue penuh\n";
        }
    }
    getchar();
}

void deQueue() {
    if (!empty()) {
        cout << "\nMengambil data \"" << antrean.data[antrean.awal] << "\"..." << endl;
        for (int i = antrean.awal; i < antrean.akhir; i++) {
            antrean.data[i] = antrean.data[i + 1];
        }
        antrean.akhir--;
        if (antrean.akhir < antrean.awal) { // Queue menjadi kosong
            antrean.awal = -1;
            antrean.akhir = -1;
        }
    } else {
        cout << "Antrean kosong\n";
    }
    getchar();
}

void tampilData() {
    if (!empty()) {
        for (int i = antrean.awal; i <= antrean.akhir; i++) {
            cout << antrean.data[i] << "[" << i << "] | ";
        }
        cout << "\n";
    } else {
        cout << "Antrean kosong\n";
    }
}

void clear() {
    antrean.awal = -1;
    antrean.akhir = -1;
}

int main() {
    int pilihan;
    init();
    cout << "Demo Queue dengan Linear Array" << endl;
    do {
        cout << "\nMenu Utama\n";
        cout << "===\n";
        cout << "[1] Init \n[2] InQueue \n[3] DeQueue \n[4] Print \n[5] Clear \n[0] Keluar\n";
        cout << "=============\n";
        cout << "\nMasukkan pilihan: ";
        cin >> pilihan;
        cout << "===============\n";
        switch (pilihan) {
            case 1:
                init();
                break;
            case 2:
                inQueue();
                break;
            case 3:
                deQueue();
                break;
            case 4:
                tampilData();
                break;
            case 5:
                clear();
                break;
        }
    } while (pilihan != 0);
    return 0;
}
