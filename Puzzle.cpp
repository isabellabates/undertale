#include "Puzzle.h"
using namespace std;

// default constructor
Puzzle::Puzzle()
{
    question = "";
    a1 = "";
    a2 = "";
    a3 = "";
    a4 = "";
}

// parameterized constructor
Puzzle::Puzzle(string q, string ans1, string ans2, string ans3, string ans4)
{
    question = q;
    a1 = ans1;
    a2 = ans2;
    a3 = ans3;
    a4 = ans4;
}

// function to get question
string Puzzle::getQuestion()
{
    return question;
}

// function to get a1
string Puzzle::getA1()
{
    return a1;
}

// function to get a2
string Puzzle::getA2()
{
    return a2;
}

// function to get a3
string Puzzle::getA3()
{
    return a3;
}

// function to get a4
string Puzzle::getA4()
{
    return a4;
}

// function to set question
void Puzzle::setQuestion(string q)
{
    question = q;
}

// function to set a1
void Puzzle::setA1(string ans1)
{
    a1 = ans1;
}

// function to set a2
void Puzzle::setA2(string ans2)
{
    a2 = ans2;
}

// function to set a3
void Puzzle::setA3(string ans3)
{
    a3 = ans3;
}

// function to set a4
void Puzzle::setA4(string ans4) 
{
    a4 = ans4;
}