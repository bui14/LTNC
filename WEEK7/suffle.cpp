#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateStrings(const vector<char>& charset, int length, string current, vector<string>& results) {
    if (length == 0) {
        results.push_back(current);
        return;
    }

    for (size_t i = 0; i < charset.size(); ++i) {
        generateStrings(charset, length - 1, current + charset[i], results);
    }
}

int main() {
    vector<char> charset;
    charset.push_back('a');
    charset.push_back('b');
    charset.push_back('c');
    charset.push_back('d');

    vector<string> results;

    int length = 3;
    generateStrings(charset, length, "", results);
    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i] << "\n";
    }

    return 0;
}
