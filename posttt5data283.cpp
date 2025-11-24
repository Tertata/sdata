#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

// ===== Tambah Depan =====
void tambahDepan(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
    cout << "Data " << value << " ditambah di depan.\n";
}

// ===== Tambah Belakang =====
void tambahBelakang(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
    cout << "Data " << value << " ditambah di belakang.\n";
}

// ===== Tambah Tengah (setelah nilai tertentu) =====
void tambahTengah(int value, int afterValue) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Node* current = head;
    do {
        if (current->data == afterValue) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            if (current == tail)
                tail = newNode;
            cout << "Data " << value << " ditambah setelah " << afterValue << ".\n";
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "Data " << afterValue << " tidak ditemukan!\n";
}

// ===== Hapus Depan =====
void hapusDepan() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
    } else {
        Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
    cout << "Node depan berhasil dihapus.\n";
}

// ===== Hapus Belakang =====
void hapusBelakang() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = NULL;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }
    cout << "Node belakang berhasil dihapus.\n";
}

// ===== Tampil dari Depan =====
void tampilDepan() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    cout << "Tampil dari depan: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(kembali ke head)\n";
}

// ===== MENU UTAMA =====
void menu() {
    int pilihan, nilai, after;
    do {
        cout << "\n===== CIRCULAR DOUBLY LINKED LIST MENU =====\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Hapus Depan\n";
        cout << "5. Hapus Belakang\n";
        cout << "6. Tampil dari Depan\n";
        cout << "7. Keluar\n";
        cout << "Pilih 	Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahDepan(nilai);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahBelakang(nilai);
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai setelahnya: ";
                cin >> after;
                tambahTengah(nilai, after);
                break;
            case 4:
                hapusDepan();
                break;
            case 5:
                hapusBelakang();
                break;
           
            case 6:
                tampilDepan();
                break;
            case 7:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 7);
}

// ===== MAIN =====
int main() {
    menu();
    return 0;
}

