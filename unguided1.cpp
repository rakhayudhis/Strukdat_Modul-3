#include <iostream>
using namespace std;

struct Node
{
    string nama;
    int usia;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAwal(string nama, int usia)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    void insertAkhir(string nama, int usia)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertSetelah(string nama, int usia, string namaSebelum)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;

        Node *temp = head;
        while (temp != nullptr && temp->nama != namaSebelum)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node dengan nama " << namaSebelum << " tidak ditemukan." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void hapus(string nama)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }

        if (head->nama == nama)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *prev = head;
        Node *temp = head->next;
        while (temp != nullptr && temp->nama != nama)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node dengan nama " << nama << " tidak ditemukan." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void ubah(string nama, string namaBaru, int usiaBaru)
    {
        Node *temp = head;
        while (temp != nullptr && temp->nama != nama)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node dengan nama " << nama << " tidak ditemukan." << endl;
            return;
        }

        temp->nama = namaBaru;
        temp->usia = usiaBaru;
    }

    void tampilkan()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->nama << " " << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList myList;

    myList.insertAwal("Rakha Yudhistira", 19);
    myList.insertAwal("John", 19);
    myList.insertAwal("Jane", 20);
    myList.insertAwal("Michael", 18);
    myList.insertAwal("Yusuke", 19);
    myList.insertAwal("Akechi", 20);
    myList.insertAwal("Hoshino", 18);
    myList.insertAwal("Karin", 18);

    cout << "Data setelah langkah (a):" << endl;
    myList.tampilkan();
    cout << endl;

    myList.hapus("Akechi");
    myList.insertSetelah("Futaba", 18, "John");
    myList.insertAwal("Igor", 20);
    myList.ubah("Michael", "Reyn", 18);
    cout << "Data setelah dilakukan semua operasi:" << endl;
    myList.tampilkan();

    return 0;
}