#include <iostream>
#include <cmath> 
using namespace std;

class Fraction {
private:
    int tuSo;
    int mauSo;

public:
    // Constructor
    Fraction(int t = 0, int m = 1) {
        if(m != 0) {
            if(m < 0) {
                tuSo = -t;
                mauSo = -m;
            }
            else {
                tuSo = t;
                mauSo = m;
            }
            rutGon();
        }
    }
    
    // Hàm tính ước chung lớn nhất
    int GCD(int a, int b) const {
        a = abs(a);
        b = abs(b);
        return (b == 0) ? a : GCD(b, a % b);
    }

    void rutGon() {
        if(tuSo == 0) {
            mauSo = 1;
            return;
        }

        int u = GCD(tuSo, mauSo);
        tuSo = tuSo / u;
        mauSo = mauSo / u;
    }

    // Hàm cộng 
    Fraction add(const Fraction& a) const {
        return Fraction(tuSo * a.mauSo + a.tuSo * mauSo, mauSo * a.mauSo);
    }

    // Hàm hiển thị kết quả 
    void display() const {
        if (mauSo == 1) {
            cout << tuSo << "\n";
        } else {
            cout << tuSo << "/" << mauSo << "\n";
        }
    }
};

int main() {
    // Tối ưu hóa đọc/ghi dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;

    // Đọc 4 số nguyên 
    if (cin >> a >> b >> c >> d) {
        Fraction f1(a, b);
        Fraction f2(c, d);

        // Tính tổng và in ra
        Fraction sum = f1.add(f2);
        sum.display();
    }

    return 0;
}