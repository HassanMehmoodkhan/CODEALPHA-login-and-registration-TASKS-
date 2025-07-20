#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;

    cout << "Register\nEnter username: ";
    cin.ignore(); // Clear input buffer
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    // Check for duplicate
    ifstream checkFile("users.txt");
    string u, p;
    while (checkFile >> u >> p) {
        if (u == username) {
            cout << "Username already exists. Try a different one.\n";
            return;
        }
    }
    checkFile.close();

    ofstream outFile("users.txt", ios::app);
    outFile << username << " " << password << endl;
    outFile.close();

    cout << "Registration successful.\n";
}

void loginUser() {
    string username, password;

    cout << "Login\nEnter username: ";
    cin.ignore(); // Clear input buffer
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    ifstream inFile("users.txt");
    string u, p;
    bool found = false;

    while (inFile >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    inFile.close();

    if (found)
        cout << "Login successful. Welcome, " << username << "!\n";
    else
        cout << "Login failed. Invalid credentials.\n";
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
        registerUser();
    else if (choice == 2)
        loginUser();
    else
        cout << "Invalid choice.\n";

    return 0;
}
