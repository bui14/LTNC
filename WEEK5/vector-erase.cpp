#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int pos,start,end;
    cin >> pos;
    arr.erase(arr.begin() + pos - 1,arr.begin()+pos);
    cin >> start >> end;
    arr.erase(arr.begin() + start - 1, arr.begin() + end - 1); 
    cout << arr.size() << endl;
    for (int i = 0; i < arr.size(); ++i)  cout << arr[i] << " ";
    cout << endl;
    return 0;
}
