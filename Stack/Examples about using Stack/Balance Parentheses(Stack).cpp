#include <iostream>
#include<string>
#include<stack>
using namespace std;

//Balanced parentheses Using Stack

//Implementation this Problems: any Expression

bool arepair(char open , char close) {
    
    if (open == '{' && close == '}')
        return true;
    else if (open == '(' && close == ')')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else    return false;
}

//this fun to push parentheses in Stack
bool Balanced(string ex) {
   
    stack<char> s;
    for (int i = 0; i < ex.size(); i++) {

        if (ex[i] == '{' || ex[i] == '(' || ex[i] == '[')
            s.push(ex[i]);

        else if (ex[i] == '}' || ex[i] == ')' || ex[i] == ']') {
            if (s.empty() || !arepair(s.top(), ex[i]))
                return false;
            else
                s.pop();
        }
   }
    return s.empty() ? true:false;

}

int main()
{
    string x;
    cin >> x;

    (Balanced(x)) ? cout << " Yes Balanced" << endl : cout << "not Balanced" << endl;


    return 0;
}
