#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Lop Book
class Book {
private:
    string title;
    string author;
    int year;

public:
    // Constructor khởi tạo
    Book(string title, string author, int year) {
        this->title = title;
        this->author = author;
        this->year = year;
    }

    string displayInfo() const {
        return "Title: " + title + ", Author: " + author + ", Year: " + to_string(year);
    }

    bool isOldBook() const {
        return year < 2000;
    }
};

// Lop Thu vien
class Library {
private:
    vector<Book> list;

public:
    // Dùng emplace_back
    void addBook(string title, string author, int year) {
        list.emplace_back(title, author, year);
    }

    void displayAll() const {
        for(size_t i = 0; i < list.size(); i++) {
            // In thông tin sách
            cout << list[i].displayInfo() << "\n";
            
            // In phân loại cũ/mới (Nhớ phải có dấu () để gọi hàm)
            if(list[i].isOldBook()) {
                cout << "Old book\n";
            } else {
                cout << "New book\n";
            }
            
            if (i < list.size() - 1) {
                cout << "\n";
            }
        }
    }
};

int main() {
    // Toi uu hoa doc/ghi du lieu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    // Doc du lieu 
    if (cin >> n) {
        Library a;
        
        // Vòng lặp 1: Dùng để NHẬP dữ liệu
        for(int i = 0; i < n; i++) {
            string title;
            string author;
            int year;

            cin.ignore(); 
            getline(cin, title);
            getline(cin, author);
            cin >> year;

            a.addBook(title, author, year);
        }

        a.displayAll();
    }
    
    return 0;
}