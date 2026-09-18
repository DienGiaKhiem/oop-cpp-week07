#include <iostream>
#include <string>
using namespace std;
 
const int MAX_BOOK = 100;
 
struct Book {
    int id;
    string title;
    string author;
    double price;
 
    void inputInfo() {
        cout << "Nhap ma sach: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap ten sach: ";
        getline(cin, title);
        cout << "Nhap tac gia: ";
        getline(cin, author);
        cout << "Nhap gia sach: ";
        cin >> price;
    }
 
    void outputInfo() {
        cout << "Ma sach: " << id
             << " - Ten sach: " << title
             << " - Tac gia: " << author
             << " - Gia: " << price << endl;
    }
};
 
struct Library {
    int idLibrary;
    string nameLibrary;
    int numBooks;
    Book books[MAX_BOOK];
 
    Library() : idLibrary(0), numBooks(0) {}
 
    void inputLibrary() {
        cout << "Nhap ma thu vien: ";
        cin >> idLibrary;
        cin.ignore();
        cout << "Nhap ten thu vien: ";
        getline(cin, nameLibrary);
        cout << "Nhap so luong sach: ";
        cin >> numBooks;
 
        for (int i = 0; i < numBooks; i++) {
            cout << "-- Sach thu " << (i + 1) << " --" << endl;
            books[i].inputInfo();
        }
    }
 
    void outputLibrary() {
        cout << "Thu vien: " << nameLibrary << " (Ma thu vien: " << idLibrary << ")" << endl;
        cout << "Danh sach sach:" << endl;
        for (int i = 0; i < numBooks; i++) {
            books[i].outputInfo();
        }
    }
 
    void addBook(Book b) {
        if (numBooks < MAX_BOOK) {
            books[numBooks] = b;
            numBooks++;
        } else {
            cout << "Thu vien da day, khong the them sach!" << endl;
        }
    }
 
    Book* getBookInfo(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) {
                return &books[i];
            }
        }
        return nullptr;
    }
 
    Book* getBooks() {
        return books;
    }
 
    bool removeBook(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) {
                for (int j = i; j < numBooks - 1; j++) {
                    books[j] = books[j + 1];
                }
                numBooks--;
                return true;
            }
        }
        return false;
    }
};
 
int main() {
    Library library;
    library.inputLibrary();
    library.outputLibrary();
 
    Book newBook;
    cout << "Them 1 quyen sach moi vao thu vien:" << endl;
    newBook.inputInfo();
    library.addBook(newBook);
 
    library.outputLibrary();
 
    int idTim;
    cout << "Nhap ma sach can tim: ";
    cin >> idTim;
    Book* found = library.getBookInfo(idTim);
    if (found != nullptr) {
        cout << "Tim thay: ";
        found->outputInfo();
    } else {
        cout << "Khong tim thay sach co ma " << idTim << endl;
    }
 
    return 0;
}