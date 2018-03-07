//Basic includes
#include <iostream>
#include <stack>

//Use std, cause I don't wanna type a lot
using namespace std;

//Enum that contains all supported instructions for the interpreters
enum INSTRUCTIONS {
    LOAD = 0, //Pop the next item off the stack and onto the register stack
    ADD = 1, //Add the top two elements of the register stack
    MULTIPLY = 2, //Multiply the top two elements of the register stack
    PRINT = 3 //Print the top element of the register stack
};

//Declare main
// My first programming language
int main() {
    //Init the main stack
    stack<int> s;
    //Init the register stack
    stack<int> reg;

    //Push our program onto the stack
    // It does this: (1+2)*(3+4)
    s.push(PRINT);
    s.push(MULTIPLY);
    s.push(ADD);
    s.push(4);
    s.push(LOAD);
    s.push(3);
    s.push(LOAD);
    s.push(ADD);
    s.push(1);
    s.push(LOAD);
    s.push(2);
    s.push(LOAD);

    //Run the interpreter until the stack is empty
    while (!s.empty()) {
        //Pop the top instruction from the stack
        int instruction = s.top();
        s.pop();
        int a, b;

        //Implement instructions
        switch (instruction) {
            case LOAD:
                reg.push(s.top());
                s.pop();
                break;
            case ADD:
                a = reg.top();
                reg.pop();
                b = reg.top();
                reg.pop();
                reg.push(a + b);
                break;
            case MULTIPLY:
                a = reg.top();
                reg.pop();
                b = reg.top();
                reg.pop();
                reg.push(a * b);
                break;
            case PRINT:
                cout << "PRINT: " << reg.top();
                reg.pop();
                break;
            default:
                cout << "ERR: Unknown Instruction: " << instruction << endl;
                break;
        }
    }

    //Ret 0
    return 0;
}