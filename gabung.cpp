#include <iostream>
#include <iomanip>
using namespace std;

struct Proses {
    string nama;
    int waktu_eksekusi;
    int waktu_tunggu;
    int waktu_selesai;
};

void tampilkanTabel(Proses p[], int n, string judul) {
    cout << "\n=== " << judul << " ===\n";
    cout << left << setw(10) << "Proses"
         << setw(15) << "Waktu Eksekusi"
         << setw(15) << "Waktu Tunggu"
         << setw(15) << "Waktu Selesai" << endl;
    cout << string(55, '-') << endl;

    double totalTunggu = 0, totalSelesai = 0;
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << p[i].nama
             << setw(15) << p[i].waktu_eksekusi
             << setw(15) << p[i].waktu_tunggu
             << setw(15) << p[i].waktu_selesai << endl;
        totalTunggu += p[i].waktu_tunggu;
        totalSelesai += p[i].waktu_selesai;
    }

    cout << "\nRata-rata waktu tunggu   : " << totalTunggu / n;
    cout << "\nRata-rata waktu selesai  : " << totalSelesai / n << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    Proses p[n], sjf[n];

    for (int i = 0; i < n; i++) {
        cout << "Nama proses ke-" << i + 1 << " : ";
        cin >> p[i].nama;
        cout << "Waktu eksekusi " << p[i].nama << " : ";
        cin >> p[i].waktu_eksekusi;
        sjf[i] = p[i]; // salin untuk versi SJF
    }

    // ================= FCFS =================
    p[0].waktu_tunggu = 0;
    for (int i = 1; i < n; i++)
        p[i].waktu_tunggu = p[i - 1].waktu_tunggu + p[i - 1].waktu_eksekusi;

    for (int i = 0; i < n; i++)
        p[i].waktu_selesai = p[i].waktu_eksekusi + p[i].waktu_tunggu;

    tampilkanTabel(p, n, "Penjadwalan FCFS (First Come First Serve)");

    // ================= SJF =================
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sjf[i].waktu_eksekusi > sjf[j].waktu_eksekusi)
                swap(sjf[i], sjf[j]);
        }
    }

    sjf[0].waktu_tunggu = 0;
    for (int i = 1; i < n; i++)
        sjf[i].waktu_tunggu = sjf[i - 1].waktu_tunggu + sjf[i - 1].waktu_eksekusi;

    for (int i = 0; i < n; i++)
        sjf[i].waktu_selesai = sjf[i].waktu_eksekusi + sjf[i].waktu_tunggu;

    tampilkanTabel(sjf, n, "Penjadwalan SJF (Shortest Job First)");

    cout << "\nTerima kasih! Program selesai dijalankan dengan sukses.\n";

    return 0;
}




