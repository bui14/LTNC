#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student{
    private:
    int score[5];
    public:
    void input(){
        for (int i=0;i<5;i++) cin >> diem[i];
    }
    int totalscore(){
        int sum=0;
        for(int i=0;i<5;i++) sum+=score[i];
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    Student *s = new Student[n];
    for(int i = 0; i < n; i++){
        s[i].input();
    }
    int kristen_score = s[0].totalscore();
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].totalscore();
        if(total > kristen_score){
            count++;
        }
    }
    cout << count;
    
    return 0;
}
