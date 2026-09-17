Fase2_Problem2

#include <iostream>
using namespace std;

// Mengubah huruf menjadi nilai alfabet
int nilaiHuruf(char huruf) {
    return huruf - 'A' + 1;
}

// Mengubah nilai alfabet menjadi huruf
char hurufDariNilai(int nilai) {
    return 'A' + nilai - 1;
}

int main() {
    char pesan[1000];
    char hasil[1000];

    int panjang;
    int i;
    int nilaiSekarang;
    int nilaiSebelumnya;
    int nilaiBaru;

    // Input pesan asli
    cin >> pesan;

    // Menghitung panjang pesan secara manual
    panjang = 0;

    while (pesan[panjang] != '\0') {
        panjang++;
    }

    i = 0;

    // Proses enkripsi
    while (i < panjang) {

        // Mengambil nilai huruf saat ini
        nilaiSekarang = nilaiHuruf(pesan[i]);

        // Jika huruf pertama
        if (i == 0) {
            nilaiBaru = nilaiSekarang;
        }
        // Jika bukan huruf pertama
        else {
            nilaiSebelumnya = nilaiHuruf(pesan[i - 1]);

            nilaiBaru = nilaiSekarang + nilaiSebelumnya;

            // Jika lebih dari 26, kembali ke awal alfabet
            if (nilaiBaru > 26) {
                nilaiBaru = nilaiBaru - 26;
            }
        }

        // Mengubah nilai kembali menjadi huruf
        hasil[i] = hurufDariNilai(nilaiBaru);

        i++;
    }

    // Menambahkan penanda akhir string
    hasil[panjang] = '\0';

    // Menampilkan hasil
    cout << hasil << endl;

    return 0;
}