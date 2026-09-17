Fase2_Problem1

#include <iostream>
using namespace std;

// Mencari posisi astronaut yang akan dieliminasi
int cariPosisiEliminasi(int posisi, int K, int jumlah) {
    return (posisi + K - 1) % jumlah;
}

// Mengubah nilai K berdasarkan astronaut yang dieliminasi
int ubahK(int K, int tereliminasi) {
    if (tereliminasi % 2 == 0) {
        K = K + 2;
    } else {
        K = K - 1;
    }

    if (K < 2) {
        K = 2;
    }

    return K;
}

// Menghapus astronaut dari array
void hapusAstronaut(int astronaut[], int &jumlah, int posisi) {
    for (int i = posisi; i < jumlah - 1; i++) {
        astronaut[i] = astronaut[i + 1];
    }

    jumlah = jumlah - 1;
}

int main() {
    int N, K;
    int astronaut[1000];
    int posisi;
    int jumlah;
    int tereliminasi;

    // Input
    cin >> N;
    cin >> K;

    // Mengisi nomor astronaut dari 1 sampai N
    for (int i = 0; i < N; i++) {
        astronaut[i] = i + 1;
    }

    jumlah = N;
    posisi = 0;

    // Proses eliminasi
    while (jumlah > 1) {

        posisi = cariPosisiEliminasi(posisi, K, jumlah);

        tereliminasi = astronaut[posisi];

        cout << tereliminasi << " ";

        hapusAstronaut(astronaut, jumlah, posisi);

        // Mengubah nilai K
        K = ubahK(K, tereliminasi);

        // Jika posisi sudah melewati astronaut terakhir,
        // kembali ke posisi pertama
        if (posisi >= jumlah) {
            posisi = 0;
        }
    }

    // Menampilkan astronaut terakhir
    cout << endl;
    cout << astronaut[0] << endl;

    return 0;
}