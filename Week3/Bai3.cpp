#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string a;
    if (s[8] == 'A') {
        a = s.substr(0, 8);
        if (s[0] == '1' && s[1] == '2') {
            a = "00" + s.substr(2, 6);
        }
    }
    else {
        int d = stoi(s.substr(0, 2)) + 12;
        a = to_string(d) + s.substr(2, 6);
        if (s[0] == '1' && s[1] == '2') {
            a = s.substr(0, 8);
        }
    }
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
