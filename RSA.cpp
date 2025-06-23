#include <bits/stdc++.h> 
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}


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

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

int main() {
    srand(time(0));

    int p, q;
    do { p = rand() % 100 + 200; } while (!isPrime(p));
    do { q = rand() % 100 + 200; } while (!isPrime(q) || q == p);

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e;
    do { e = rand() % (phi - 2) + 2; } while (__gcd(e, phi) != 1);

    int d = modInverse(e, phi);

    cout << "Public key: (n = " << n << ", e = " << e << ")\n";
    cout << "Private key: (n = " << n << ", d = " << d << ")\n";

    // cin.ignore(); // Sửa ở đây

    string message;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, message);

    for (char ch : message) {
        if ((int)ch >= n) {
            cout << "Ky tu '" << ch << "' co ma ASCII lon hon n => RSA khong hoat dong. Tang n len.\n";
            return 1;
        }
    }

    vector<int> encrypted;
    for (char ch : message) {
        int m = (int)ch;
        int c = power(m, e, n);
        encrypted.push_back(c);
    }

    cout << "Ban ma: ";
    for (int c : encrypted)
        cout << c << " ";
    cout << endl;

    string decrypted = "";
    for (int c : encrypted) {
        int m = power(c, d, n);
        decrypted += (char)m;
    }

    cout << "Giai ma: " << decrypted << endl;

    return 0;
}
