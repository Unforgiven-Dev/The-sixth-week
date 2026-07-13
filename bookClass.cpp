#include <iostream>
#include <string>
using namespace std;

// lop Book
class Book {
private:
    string title;
    string author;
    int year;

public:
    // Constructor
    Book(string title, string author, int year) {
        this->title = title;
        this->author = author;
        this->year = year;
    }

    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << "\n";
    }
};

int main() {
    // Tối ưu hóa đọc/ghi dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string title;
    string author;
    int year;

    // Đọc dữ liệu
    getline(cin, title);
    getline(cin, author);
    
    if (cin >> year) {
        Book a(title, author, year);
        a.display();
    }
    
    return 0;
}