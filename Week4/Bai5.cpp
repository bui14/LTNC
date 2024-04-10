#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n], b[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n + 1; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n + 1; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (b[i] == a[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << b[i] << " ";
        }
    }

    return 0;
}