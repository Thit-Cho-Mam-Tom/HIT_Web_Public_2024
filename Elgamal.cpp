#include <bits/stdc++.h>
using namespace std;

// Hàm mũ modulo (a^b mod m)
long long power(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

// Tính nghịch đảo modular (dùng Fermat vì p là số nguyên tố)
long long modInverse(long long a, long long p) {
    return power(a, p - 2, p);
}

// Kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

// Tìm phần tử sinh g
int findGenerator(int p) {
    for (int g = 2; g < p; ++g) {
        bool ok = true;
        set<int> powers;
        for (int i = 1; i < p - 1; ++i)
            powers.insert(power(g, i, p));
        if ((int)powers.size() == p - 2)
            return g;
    }
    return -1;
}

int main() {
    srand(time(0));

    // Sinh số nguyên tố p
    int p;
    do {
        p = rand() % 100 + 150; // p từ 150 đến 249
    } while (!isPrime(p));

    int g = findGenerator(p);
    int x = rand() % (p - 2) + 1;  // Khóa riêng
    int y = power(g, x, p);        // Khóa công khai

    cout << "Public key: (p = " << p << ", g = " << g << ", y = " << y << ")\n";
    cout << "Private key: x = " << x << "\n";

    // Nhập chuỗi cần mã hóa
    string message;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, message);

    // Mã hóa từng ký tự
    vector<pair<int, int>> encrypted;
    for (char ch : message) {
        int m = (int)ch;
        if (m >= p) {
            cout << "Ky tu '" << ch << "' co ma ASCII lon hon p => Tăng p len.\n";
            return 1;
        }
        int k = rand() % (p - 2) + 1;
        int c1 = power(g, k, p);
        int c2 = (m * power(y, k, p)) % p;
        encrypted.push_back({c1, c2});
    }

    // In bản mã
    cout << "Ban ma:\n";
    for (size_t i = 0; i < encrypted.size(); ++i) {
        cout << "(" << encrypted[i].first << ", " << encrypted[i].second << ") ";
    }
    cout << endl;

    // Giải mã
    string decrypted = "";
    for (size_t i = 0; i < encrypted.size(); ++i) {
        int c1 = encrypted[i].first;
        int c2 = encrypted[i].second;
        int s = power(c1, x, p);
        int s_inv = modInverse(s, p);
        int m = (c2 * s_inv) % p;
        decrypted += (char)m;
    }

    cout << "Giai ma: " << decrypted << endl;

    return 0;
}
