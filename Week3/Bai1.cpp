#include <iostream>
#include <string>
using namespace std;

int main() {
    // Complete the program
    string a, b; cin >> a >> b;
    int n1 = a.length();
    int n2 = b.length();
    cout << n1 << " " << n2 << endl;
    cout << a + b << endl;
    swap(a[0], b[0]);
    cout << a << " " << b << endl;
    return 0;
}