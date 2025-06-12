#include <bits/stdc++.h>
using namespace std;


string encryptCaesar(string text, int key) {
    string result = "";
    for (char c : text) {
        if (c >= 32 && c <= 126) {
            result += (c - 32 + key) % 95 + 32;
        } else {
            result += c;
        }
    }
    return result;
}


string decryptCaesar(string text, int key) {
    string result = "";
    for (char c : text) {
        if (c >= 32 && c <= 126) {
            result += (c - 32 - key + 95) % 95 + 32;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string input;
    int key;

    cout << "Nhap khoa (so nguyen): ";
    cin >> key;
    cin.ignore(); 

    cout << "Nhap chuoi: ";
    getline(cin, input);

    string encrypted = encryptCaesar(input, key);
    string decrypted = decryptCaesar(encrypted, key);

    cout << "Chuoi da ma hoa: " << encrypted << endl;
    cout << "Chuoi da giai ma: " << decrypted << endl;

    return 0;
}
