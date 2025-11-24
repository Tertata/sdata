#include <iostream>
using namespace std;

class NilaiMahasiswa {
private:
	string* nama;
    int jumlah;
    float* nilai; // pointer untuk array dinamis

public:
    void inputNilai() {
        cout << "Masukkan jumlah mahasiswa: ";
        cin >> jumlah;

        // Alokasi memori dinamis untuk array nilai
        
		nama= new string[jumlah];
		nilai= new float [jumlah];
	
		cout<<"Input Data Mahasiswa";
		for(int i=0; i<jumlah; i++){
			cout<<"Mahasiswa ke- "<<i+1<<endl;
			cout<<"Nama : ";
			cin>>nama[i];
			cout<<"Nilai : ";
			cin>>nilai[i];
		}
	
		
  	cout<<"==== Daftar Nilai Mahasiswa ===="<<endl;;
  	for(int i=0; i<jumlah; i++){
  		cout<<i+1 << " . "<< nama[i]<<" Nilai: "<<nilai[i]<<endl;
	  }
			cout<<endl;
			cout<<"==== Statistik Nilai===="<<endl;
		float total =0;
		for(int i=0; i<jumlah; i++){
			total += nilai[i];
			
		}
		
		float rata2 = total /jumlah;
		
			float tertinggi= nilai[0];
			float terendah= nilai[0];
			string namatertinggi = nama[0];
			string namaterendah = nama[0];
			
			for(int i = 1; i<jumlah; i ++){
				if (nilai[i] > tertinggi){
					tertinggi = nilai[i];
					namatertinggi = nama[i];
				}
				if(nilai[i] < terendah){
					terendah = nilai[i];
					namaterendah = nama[i];	
				}
			}
			cout<<"Rata- rata nilai "<<rata2;
			cout<<"\nNilai Tertinggi "<<namatertinggi;
			cout<<"\nNilai Terendah "<< namaterendah;
						
        // Hapus memori dinamis setelah digunakan
        delete[] nama;
		delete[] nilai;
    }
};

int main() {
    NilaiMahasiswa data;
    data.inputNilai();
    return 0;
}

