#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    private:
    int age,standard;
    string firstname,lastname;
    public:
    void set_age(int tuoi){
        age= tuoi;
    }
    void set_first_name(string ho){
        firstname=ho;
    }
    void set_last_name(string ten){
        lastname=ten;    
    }
    void set_standard(int tieuchuan) {
        standard=tieuchuan;
    }
    int get_age(){
        return age;
    }
    string get_last_name(){
        return lastname;
    }
    string get_first_name(){
        return firstname;
    }
    int get_standard(){
        return standard;
    }
    string to_strings(){
        string ages = to_string(age), standards = to_string(standard);
        string newstring= ages+","+firstname+","+lastname+","+standards;
        return newstring;
    }
    
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_strings();
    
    return 0;
}
