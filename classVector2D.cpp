#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Lop Vector
class Vector2D {
private: 
    double a;
    double b;

public:
    // Constructor dùng Initializer List 
    Vector2D() : a(0), b(0) {}
    Vector2D(double x, double y) : a(x), b(y) {}
    
    double getX() const {
        return a;
    }
    double getY() const {
        return b;
    }

    // Do dai vector
    double length() const {
        return sqrt(a*a + b*b);
    }

    // Tinh vector tong
    Vector2D add(const Vector2D& other) const {
        return Vector2D(a + other.a, b + other.b);
    }

    // Tinh vector hieu
    Vector2D subtract(const Vector2D& other) const {
        return Vector2D(a - other.a, b - other.b);
    }

    // Tinh tich vo huong cua hai vector
    double dotProduct(const Vector2D& other) const {
        return a * other.a + b * other.b;
    }

    // Hien thi
    void display() const {
        cout << a << " " << b << "\n";
    }
};

int main() {
    // Tối ưu hóa đọc/ghi dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double x1, y1, x2, y2;
    
    // Đọc đầu vào 4 tọa độ
    if (cin >> x1 >> y1 >> x2 >> y2) {
        Vector2D A(x1, y1);
        Vector2D B(x2, y2);

        cout << fixed << setprecision(2);
        cout << A.length() << "\n";
        cout << B.length() << "\n";
        
        cout << defaultfloat; 
        
        // In vector tổng
        Vector2D sum = A.add(B);
        sum.display();
        
        // In vector hiệu
        Vector2D diff = A.subtract(B);
        diff.display();
        
        // In tích vô hướng
        cout << A.dotProduct(B) << "\n";
    }
    
    return 0;
}