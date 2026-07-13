#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

class Student {
private:
    string name;
    vector<int> scores; 

public:
    // 1. CONSTRUCTOR: Khởi tạo đối tượng với tên sinh viên
    Student(string n) {
        name = n;
    }

    // 2. SETTER: Đưa dữ liệu điểm vào (Có kiểm soát giới hạn 0 - 100)
    void addScore(int score) {
        if (score >= 0 && score <= 100) {
            scores.push_back(score);
        }
    }

    // 3. GETTER: Lấy tên sinh viên ra ngoài
    string getName() {
        return name;
    }

    // 4. PHƯƠNG THỨC XỬ LÝ: Không cần truyền tham số vì nó dùng trực tiếp dữ liệu nội bộ
    double calculateGPA() {
        if (scores.empty()) {
            return 0.0;
        }
        
        double sum = 0;
        // Duyệt qua tất cả các điểm trong vector của CHÍNH ĐỐI TƯỢNG NÀY (this->scores)
        for (int s : scores) {
            sum += s;
        }
        
        return sum / scores.size();
    }
};

int main() {
    // Tối ưu hóa đọc/ghi dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    
    // Đọc tên sinh viên đầu tiên
    if (cin >> name) {
        // Tạo đối tượng student, Constructor sẽ lập tức chạy để gán tên
        Student student(name);
        
        int score;
        // Vòng lặp while này sẽ đọc liên tục các số nguyên cho đến khi hết dữ liệu (EOF)
        while (cin >> score) {
            student.addScore(score);
        }

        // In kết quả: Dùng fixed và setprecision(2) để làm tròn chuẩn 2 chữ số thập phân
        cout << student.getName() << " " << fixed << setprecision(2) << student.calculateGPA() << "\n";
    }

    return 0;
}