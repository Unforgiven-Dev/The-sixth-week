#include <iostream>
#include <iomanip>
using namespace std;

// Lop Account
class bankAccount {
    private:
        double balance;
    
    public:
        // Contructor
        bankAccount() {
            balance = 0.0;
        }

        bankAccount(double b) {
            balance = b;
        }

        // Gui tien
        void deposit(double amount) {
            if (amount > 0) {
                balance = balance + amount;
            }
        }

        // Rut tien
        void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance = balance - amount;
            }
        }

        // So du
        double getBalance() {
        return balance;
        }
};

int main() {
    // Toi uu hoa doc/ghi du lieu
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Khai bao kieu du lieu
    bankAccount myAccount;
    int n;
    
    // Doc du lieu
    if(cin >> n) {
        for (int i = 0; i < n; i++) {
            char operation;
            double amount;

            cin >> operation >> amount;
            if (operation == 'D') {
                myAccount.deposit(amount);
            }
            else {
                myAccount.withdraw(amount);
            }
        }

        cout << fixed << setprecision(2) << myAccount.getBalance() << "\n";
    }
    return 0;
}