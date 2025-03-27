#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Contact {
private:
    string name, phone, email;

public:
    Contact(string n, string p, string e) : name(n), phone(p), email(e) {}
    string getName() const { return name; }
    void display() const {
        cout << "Name: " << name << " | Phone: " << phone << " | Email: " << email << endl;
    }
};

class ContactBook {
private:
    vector<Contact> contacts;

public:
    void addContact() {
        string name, phone, email;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Email: ";
        getline(cin, email);
        contacts.emplace_back(name, phone, email);
        cout << "Contact added successfully!\n";
    }

 
};

int main() {
    ContactBook book;
    int choice;
    while (true) {
        cout << "\nContact Book Menu:\n";
        cout << "1. Add Contact\n2. View Contacts\n3. Search Contact\n4. Delete Contact\n5. Exit\nChoose an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                book.addContact();
                break;
            case 2:
                book.viewContacts();
                break;
            case 3:
                book.searchContact();
                break;
            case 4:
                book.deleteContact();
                break;
            case 5:
                cout << "Exiting Contact Book...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
