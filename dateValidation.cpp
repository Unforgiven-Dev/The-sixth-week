#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year; 

public:
    // Constructor: Chỉ làm đúng nhiệm vụ gán dữ liệu ban đầu
    Date(int d, int m, int y) {
        day = d; 
        month = m;
        year = y;
    }

    // Kiểm tra năm nhuận
    bool leapYear(int y) {
        return (y % 4 == 0) && (y % 100 != 0 || y % 400 == 0);
    }

    // Tính số ngày trong tháng
    int daysInMonth(int m, int y) {
        if (m == 2) return (leapYear(y)) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

    // Phương thức kiểm tra tính hợp lệ (Class Invariant)
    bool isValid() {
        // Đã sửa lại thành || (HOẶC)
        if (year < 1 || year > 9999) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > daysInMonth(month, year)) return false;
        
        // Vượt qua hết các bài test trên nghĩa là ngày tháng hợp lệ
        return true; 
    }
};

int main() {
    // Tối ưu hóa đọc/ghi dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    

    int d, m, y;
    
    // Đọc dữ liệu đầu vào
    if (cin >> d >> m >> y) {
        // Khởi tạo đối tượng
        Date myDate(d, m, y);
        
        // Gọi phương thức kiểm tra và in kết quả đúng chuẩn viết hoa
        if (myDate.isValid()) {
            cout << "Valid\n";
        } else {
            cout << "Invalid\n";
        }
    }

    return 0;
}