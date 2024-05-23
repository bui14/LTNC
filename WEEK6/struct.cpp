#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    add code for struct here.
*/
struct Student{
    int age,standard;
    string first_name,last_name;
    
    friend istream& operator>> (istream& nhap, Student& x){
        nhap >>x.age >> x.first_name >> x.last_name >> x.standard;
        return nhap;
    }
    friend ostream& operator<< (ostream& xuat, Student& x){
        xuat << x.age <<x.first_name << x.last_name << x.standard;
        return xuat;
    }
    
};

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}
