#include <iostream>
using namespace std;

static int memberCount = 0;
int fine = 0; 

class Library {
private:
    string name;
    string publisher;
    int bookID;
    int year;
    string type;
    bool available = true;

public:
    Library() {
        memberCount++;
    }

    void calculateFine() {
        int choice;
        cout << "Is it on time? (Press 1 for Yes, Any Other Digit for No): ";
        cin >> choice;

        if (choice == 1) {
            fine = 0; // No fine if on time
        } else {
            int daysLate;
            cout << "How many days late: ";
            cin >> daysLate;
            fine = 10 * daysLate; // 10 rs fine per day
        }
    }

    void getData() {
        cout << "Enter Book Name: ";
        cin >> name;
        cout << "Enter Publisher Name: ";
        cin >> publisher;
        cout << "Enter Book Reference ID: ";
        cin >> bookID;
        cout << "Enter Publish Year: ";
        cin >> year;
        cout << "Enter The Type (Book, Magazine, Newspaper): ";
        cin >> type;
    }

    void display() {
        cout << "-----------------\n";
        cout << "Name: " << name << "\n"
             << "Publisher Name: " << publisher << "\n"
             << "Reference ID: " << bookID << "\n"
             << "Publish Year: " << year << "\n"
             << "Type: " << type << "\n"
             << "Available: " << (available ? "Yes" : "No") << "\n";
    }

    void allot() {
        int id;
        cout << "Enter Book ID to allot: ";
        cin >> id;
        if (id == bookID && available) {
            cout << "Book Successfully Allotted to Member: " << memberCount << "\n";
            available = false;
        } else if (!available) {
            cout << "Book Not Available Yet\n";
        } else {
            cout << "Invalid Book ID\n";
        }
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;
        if (id == bookID && !available) {
            calculateFine(); // Calculate fine when returning
            cout << "Book Returned by Member: " << memberCount << "\n";
            available = true;
            cout << "Fine: " << fine << "\n";
        } else if (available) {
            cout << "Not Found in allocated books\n";
        } else {
            cout << "Invalid Reference ID\n";
        }
    }
};

int main() {
    Library m1;
    m1.getData();
    m1.display();
    m1.allot();
    m1.allot(); // Attempting to allot again to demonstrate book availability
    m1.display();
    m1.returnBook();
    m1.display();
    return 0;
}
