    #include <iostream>
    #include <fstream>
    #include <cmath>
    using namespace std;

    class Account {
    protected:
        int accNo;
        string name;
        double balance;
    public:
        Account() : accNo(0), balance(0) {}
        virtual void createAccount() = 0;
        void deposit(double amt) { balance += amt; }
        virtual bool withdraw(double amt) {
            if (amt > balance) return false;
            balance -= amt;
            return true;
        }
        void display() {
            cout << "\nAccount No: " << accNo
                << "\nName: " << name
                << "\nBalance: " << balance << "\n";
        }
        int getAccNo() { return accNo; }
        virtual char type() = 0;
        void saveToFile() {
            ofstream f("acc.txt", ios::app);
            f << accNo << " " << name << " " << balance << " " << type() << "\n";
            f.close();
        }
    };

    // ---------- Savings Account ----------
    class Savings : public Account {
    public:
        void createAccount() override {
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Initial Deposit: "; cin >> balance;
            accNo = rand() % 9000 + 1000;
            cout << "\nSavings Account Created! Account No: " << accNo << "\n";
            saveToFile();
        }
        char type() override { return 'S'; }
    };

    // ---------- Current Account ----------
    class Current : public Account {
    public:
        void createAccount() override {
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Initial Deposit: "; cin >> balance;
            accNo = rand() % 9000 + 1000;
            cout << "\nCurrent Account Created! Account No: " << accNo << "\n";
            saveToFile();
        }
        char type() override { return 'C'; }
    };

    // ---------- Fixed Deposit Account ----------
    class FixedDeposit : public Account {
        int years;
        double rate;
    public:
        void createAccount() override {
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Deposit Amount: "; cin >> balance;
            cout << "Enter Years: "; cin >> years;
            cout << "Enter Interest Rate (%): "; cin >> rate;
            accNo = rand() % 9000 + 1000;

            double maturity = balance * pow((1 + rate / 100), years);
            balance = maturity;

            cout << "\nFixed Deposit Created! Account No: " << accNo << "\n";
            cout << "Maturity Amount after " << years << " years: " << maturity << "\n";
            saveToFile();
        }
        bool withdraw(double) override {
            cout << "Withdrawals not allowed for Fixed Deposit!\n";
            return false;
        }
        char type() override { return 'F'; }
    };

    // ---------- MAIN FUNCTION ----------
    int main() {
        Account* acc = nullptr;
        int choice;

        while (true) {
            cout << "\n===== BANK MENU =====";
            cout << "\n1. Create Account (Savings / Current)";
            cout << "\n2. Create Fixed Deposit Account";
            cout << "\n3. Deposit";
            cout << "\n4. Withdraw";
            cout << "\n5. Exit";
            cout << "\nEnter your choice: ";
            cin >> choice;

            if (choice == 1) {
                int t;
                cout << "Select Account Type:\n1. Savings\n2. Current\nEnter: ";
                cin >> t;

                delete acc;
                if (t == 1) acc = new Savings();
                else if (t == 2) acc = new Current();
                else { cout << "Invalid Account Type!\n"; continue; }

                acc->createAccount();
            } 
            else if (choice == 2) {
                delete acc;
                acc = new FixedDeposit();
                acc->createAccount();
            } 
            else if (choice == 3) {
                if (!acc) { cout << "Create an account first!\n"; continue; }
                double amt;
                cout << "Enter amount to deposit: ";
                cin >> amt;
                acc->deposit(amt);
                cout << "Amount Deposited Successfully!\n";
                acc->display();
            } 
            else if (choice == 4) {
                if (!acc) { cout << "Create an account first!\n"; continue; }
                double amt;
                cout << "Enter amount to withdraw: ";
                cin >> amt;
                if (acc->withdraw(amt))
                    cout << "Withdrawal Successful!\n";
                else
                    cout << "Withdrawal Failed (Insufficient Balance or FD Account)!\n";
                acc->display();
            } 
            else if (choice == 5) {
                cout << "\nThank you for using the Banking System!\n";
                break;
            } 
            else {
                cout << "Invalid choice! Please try again.\n";
            }
        }

        delete acc;
        return 0;
    }
