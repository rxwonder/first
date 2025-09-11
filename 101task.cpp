#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Bank {
private:
    int balance;
    string owner_name;
    int owner_ID;

    static vector<int> all_ids;
    static vector<Bank*> all_accounts;

public:
    Bank(int b, int id, const string& name) : balance(b), owner_ID(id), owner_name(name) {
        all_ids.push_back(id);
        all_accounts.push_back(this);
    }

    int getID() const { return owner_ID; }
    string getName() const { return owner_name; }

    void show_all() const {
        cout << "Name: " << owner_name << ", ID: " << owner_ID << ", Balance: " << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << amount << " added to " << owner_name << "'s account.\n";
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Not enough money in " << owner_name << "'s account.\n";
            return false;
        }
        balance -= amount;
        cout << amount << " withdrawn from " << owner_name << "'s account.\n";
        return true;
    }

    void transfer(int target_id, double amount) {
        Bank* target = check_id(target_id);
        if (!target) {
            cout << "Account with ID " << target_id << " not found!\n";
            return;
        }
        if (withdraw(amount)) {
            target->deposit(amount);
            cout << "Transfer successful to from main: " << amount << " from " << owner_name 
                 << " to " << target->owner_name << "\n";
        }
    }

    static Bank* check_id(int id) {
        for (size_t i = 0; i < all_ids.size(); i++) {
            if (all_ids[i] == id)
                return all_accounts[i];
        }
        return nullptr;
    }

    static void show_all_accounts() {
        cout << "\nAll accounts:\n";
        for (auto acc : all_accounts)
            acc->show_all();
        cout << endl;
    }
};

// Статические поля класса
vector<int> Bank::all_ids;
vector<Bank*> Bank::all_accounts;

int generate_random_id() {
    return rand() % 9000 + 1000; // ID от 1000 до 9999
}

int main() {
    srand(time(0)); // для rand()

    // Создаём начальные аккаунты
    Bank objA(5000, 1234, "Jack");
    Bank objB(2300, 1233, "Michael");

    int choice;
    for (;;) {
        cout << "\nChoose operation:\n"
             << "1. Add money\n"
             << "2. Withdraw money\n"
             << "3. Transfer money\n"
             << "4. Show all accounts\n"
             << "5. Create new account\n"
             << "0. Exit\n";
        cin >> choice;

        if (choice == 0) break;

        int id, target_id;
        double amount;
        string name;

        switch (choice) {
            case 1: { // Add money
                cout << "Enter your account ID: ";
                cin >> id;
                cout << "Enter amount: ";
                cin >> amount;
                if (Bank* acc = Bank::check_id(id))
                    acc->deposit(amount);
                else
                    cout << "Account not found!\n";
                break;
            }

            case 2: { // Withdraw money
                cout << "Enter your account ID: ";
                cin >> id;
                cout << "Enter amount: ";
                cin >> amount;
                if (Bank* acc = Bank::check_id(id))
                    acc->withdraw(amount);
                else
                    cout << "Account not found!\n";
                break;
            }

            case 3: { // Transfer money
                cout << "Enter your account ID: ";
                cin >> id;
                cout << "Enter target account ID: ";
                cin >> target_id;
                cout << "Enter amount: ";
                cin >> amount;
                if (Bank* acc = Bank::check_id(id))
                    acc->transfer(target_id, amount);
                else
                    cout << "Your account not found!\n";
                break;
            }

            case 4: // Show all accounts
                Bank::show_all_accounts();
                break;

            case 5: { // Create new account
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter initial balance: ";
                cin >> amount;
                int new_id = generate_random_id();
                Bank* new_acc = new Bank(amount, new_id, name);
                cout << "Account created! ID: " << new_id << "\n";
                break;
            }

            default:
                cout << "Wrong choice!\n";
        }
    }

    cout << "Program finished.\n";
    return 0;
}

