#include <iostream>
#include <string>
#include <set>
#include <fstream>

#define MAX_VARS 30
#define SOLVERS_COUNT 5

using namespace std;

class Reader {
    int type;
    string ex;
    string input;
public:
    Reader(string input) {
        this->input = input;
    }

    void Read() {
        ifstream f(input);
        f >> type;
        f >> ex;
        f.close();
    }

    int getType() {
        return type;
    }

    string getString() {
        return ex;
    }
};

class Writer {
    string output;
public:
    Writer(string output) {
        this->output = output;
    }

    void write(float solution) {
        ofstream f(output);
        f << solution;
        f.close();
    }
};

class AbstractSolver{
public:
    virtual float Solve (int* var) = 0;
};

class Sol1: public AbstractSolver{
    float Solve (int* var) override{
        return  (float) (var[5] - var [4] - var[1]*var[2]) / - var[3];
    }
};

class Sol2: public AbstractSolver{
public:
    float Solve (int* var) override{
        return var[1] + var[2];
    }
};


class Sol3: public AbstractSolver{
public:
    float Solve (int* var) override{
        return var[1] - var [2];
    }
};

class Sol4: public AbstractSolver{
public:
    float Solve (int* var) override{
        return var[1] * var [2];
    }
};

class Sol5: public AbstractSolver{
public:
    float Solve (int* var) override{
        return (float) var[1] / var [2];
    }
};

class PracticSolver{
    AbstractSolver *SolversArr [SOLVERS_COUNT];
    int count = 0;
public:
    void addSolver(AbstractSolver *s){
        SolversArr[count] = s;
        count++;
    }

    int solveByType(int type, int *var){
        SolversArr[type - 1]->Solve(var);
    }
};

class Parser{

    char Num [10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    bool isNum(char ch){
        for (int i = 0; i < 10; i++){
            if (ch == Num[i]){
                return true;
            }
        }
        return false;
    }

public:
    int* Parse (string s){
        int *var = new int [MAX_VARS];
        var[0] = 0;
        string temp;
        for (int i = 0; i <= s.length(); i++){
            if (!isNum(s[i])){
                var[0]++;
                var[var[0]] = atoi (temp.c_str());
                temp = "";
            } else {
                temp += s[i];
            }
        }
        return var;
    }
};

int main(int argc, char *argv[]) {
    if (argc == 3){
        Reader r(argv[1]);
        r.Read();
        
        Parser p;
        int *var = p.Parse(r.getString());
        float solution;

        PracticSolver PS;
        PS.addSolver(new Sol1);
        PS.addSolver(new Sol2);
        PS.addSolver(new Sol3);
        PS.addSolver(new Sol4);
        PS.addSolver(new Sol5);

        solution = PS.solveByType(r.getType(), var);

        Writer w(argv[2]);
        w.write(solution);
    } else{
        cout << "Неверное количество аргументов программы";
    }
    return 0;
}