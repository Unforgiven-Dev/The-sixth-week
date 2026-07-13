#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private: 
    int hours, minutes, seconds;
    
public:
    // Constructor
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
        chuanHoa();
    }

    Time addTime(const Time& other);
    Time subtractTime(const Time& other);
    void display();
    void chuanHoa();
};

// --- ĐỊNH NGHĨA CÁC HÀM BÊN NGOÀI CLASS ---

Time Time::addTime(const Time& other) {
    return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
}

Time Time::subtractTime(const Time& other) {
    // Dùng phương pháp tổng giây để trừ cho an toàn và dễ dàng
    int t1 = hours * 3600 + minutes * 60 + seconds;
    int t2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
    
    int diff = t1 - t2;
    
    return Time(0, 0, diff);
}

void Time::chuanHoa() {
    int sum = hours * 3600 + minutes * 60 + seconds;
    if (sum < 0) sum = 0;              // Đảm bảo không cho thời gian âm

    hours  = (sum / 3600) % 24;        // gói trong 1 ngày (0..23)
    minutes = (sum % 3600) / 60;
    seconds = sum % 60;
}

void Time::display() {
     cout << setfill('0')
         << setw(2) << hours  << ":"
         << setw(2) << minutes << ":"
         << setw(2) << seconds << "\n";
}

// --- HÀM MAIN ---
int main() {
    // Tối ưu hóa đọc/ghi dữ liệu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d, e, f;

    // Đọc dữ liệu
    if (cin >> a >> b >> c >> d >> e >> f) {
        Time init(a, b, c);
        Time other(d, e, f);

        Time sumTime = init.addTime(other);
        sumTime.display();
        
        Time diffTime = init.subtractTime(other);
        diffTime.display();
    }   
    return 0;
}