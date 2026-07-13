#include <iostream>
#include <iomanip>
using namespace std;

// Lop Circle
class Circle {
    private:
    double radius;

    static constexpr double PI = 3.14159;

    public:

    // Constructor
    Circle(double r) {
        radius = (r < 0) ? 0 : r;
    }

    void setRadius(double r) {
        radius = (r > 0) ? r : 0;
    }

    double dienTich() const {
        return PI * radius * radius;
    }

    double chuVi() const {
        return PI * radius * 2;
    }

    void display() const {
        cout << fixed << setprecision(2) << dienTich() << " " << chuVi() << "\n";
    }
};

int main() {
    // Toi uu hos doc/ghi du lieu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    // Doc du lieu
    if (cin >> n) {
        Circle a(n);
        a.display();
    }
    return 0;
}