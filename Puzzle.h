#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Puzzle
{
private:
    // declare question, a1, a2, a3, a4
    string question;
    string a1;
    string a2;
    string a3;
    string a4;

public:
    // constructors
    Puzzle();
    Puzzle(string q, string ans1, string ans2, string ans3, string ans4);

    // getters
    string getQuestion();
    string getA1();
    string getA2();
    string getA3();
    string getA4(); 

    // setters
    void setQuestion(string q);
    void setA1(string ans1);
    void setA2(string ans2);
    void setA3(string ans3);
    void setA4(string ans4); 
};


