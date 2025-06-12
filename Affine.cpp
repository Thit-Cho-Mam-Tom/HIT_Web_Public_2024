#include <bits/stdc++.h>
using namespace std;

// Tìm nghịch đảo modulo m của a
int nghichDao(int a, int m) {
    a %= m;
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) 
            return i;
    }
    return -1; // Không tồn tại nghịch đảo
}

// Kiểm tra a nguyên tố cùng nhau với m
bool check(int a, int m) {
    return __gcd(a, m) == 1;
}

string mahoa(string s, int a, int b) {
    string l = "";
    for (auto c : s) {
        if (isupper(c)) {
            l += ((c - 'A') * a + b) % 26 + 'A';
        } else if (islower(c)) {
            l += ((c - 'a') * a + b) % 26 + 'a';
        } else if (isdigit(c)) {
            l += ((c - '0') * a + b) % 10 + '0';
        } else {
            l += c;
        }
    }
    return l;
}

string giaima(string s, int a, int b) {
    string l = "";

    int inv26 = nghichDao(a, 26);
    int inv10 = nghichDao(a, 10);

    if (inv26 == -1 || inv10 == -1) {
        return "Khong the giai ma vi khong phai nghich dao modulo";
    }

    for (auto c : s) {
        if (isupper(c)) {
            int val = (inv26 * ((c - 'A' - b + 26) % 26)) % 26;
            l += val + 'A';
        } else if (islower(c)) {
            int val = (inv26 * ((c - 'a' - b + 26) % 26)) % 26;
            l += val + 'a';
        } else if (isdigit(c)) {
            int val = (inv10 * ((c - '0' - b + 10) % 10)) % 10;
            l += val + '0';
        } else {
            l += c;
        }
    }
    return l;
}

int main() {
    string s;
    int a, b;

    cout << "Nhap chuoi: ";
    getline(cin, s);

    cout << "Nhap khoa a (nguyen to cung nhau voi 26 va 10): ";
    cin >> a;

    if (!check(a, 26) || !check(a, 10)) {
        cout << "a phai la so nguyen to cung nhau voi ca 26 va 10.\n";
        return 0;
    }

    cout << "Nhap khoa b: ";
    cin >> b;

    string encoded = mahoa(s, a, b);
    cout << "Chuoi sau khi ma hoa: " << encoded << endl;

    string decoded = giaima(encoded, a, b);
    cout << "Chuoi sau khi giai ma: " << decoded << endl;

    return 0;
}
