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

    void viewContacts() const {
        if (contacts.empty()) {
            cout << "No contacts found.\n";
            return;
        }
        cout << "\nContact List:\n";
        for (const auto &contact : contacts) {
            contact.display();
        }
    }

    void searchContact() const {
        string name;
        cout << "Enter name to search: ";
        cin.ignore();
        getline(cin, name);
        bool found = false;
        for (const auto &contact : contacts) {
            if (contact.getName() == name) {
                contact.display();
                found = true;
            }
        }
        if (!found) {
            cout << "Contact not found.\n";
        }
    }

    void deleteContact() {
        string name;
        cout << "Enter name to delete: ";
        cin.ignore();
        getline(cin, name);
        auto it = remove_if(contacts.begin(), contacts.end(), [&](const Contact &c) {
            return c.getName() == name;
        });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            cout << "Contact deleted successfully!\n";
        } else {
            cout << "Contact not found.\n";
        }
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
