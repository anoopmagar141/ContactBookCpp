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
