#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    // CONSTRUCTOR
    Rectangle(int w, int h) {
        width = (w > 0) ? w : 0;
        height = (h > 0) ? h : 0;
    } 

    int getArea() {
        return (width * height);
    }
};

int main() {
    // Tối ưu hóa đọc/ghi dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int w, h;
    
    // Đọc dữ liệu đầu vào
    if (cin >> w >> h) {
        Rectangle a(w, h);
        
        // In ra diện tích
        cout << a.getArea() << "\n";
    }
    
    return 0;
}