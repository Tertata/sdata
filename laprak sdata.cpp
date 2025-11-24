#include <iostream>
using namespace std;

class NilaiMahasiswa {
	private:
		int jumlah;
		float* nilai; // pointer untuk array dinamis
		
		public:
			void inputNilai(){
				cot << "Masukan jumlah Mahasiswa: "
				cin >> jumlah;
			};

        // Alokasi memori dinamis untuk array nilai
        nilai = new float[jumlah];

        cout << "\nMasukkan nilai mahasiswa:\n";
        for (int i = 0; i < jumlah; i++) {
            cout << "Nilai ke-" << i + 1 << ": ";
            cin >> nilai[i];
        }

        cout << "\nDaftar nilai mahasiswa:\n";
        for (int i = 0; i < jumlah; i++) {
            cout << "Mahasiswa ke-" << i + 1 << " = " << nilai[i] << endl;
        }

        float total = 0;
        for (int i = 0; i < jumlah; i++) {
            total += nilai[i];
        }

        cout << "\nRata-rata nilai: " << total / jumlah << endl;

        // Hapus memori dinamis setelah digunakan
        delete[] nilai;
    }

int main() {
    NilaiMahasiswa data;
    data.inputNilai();
    return 0;
}


