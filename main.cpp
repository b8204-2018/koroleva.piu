#include <iostream>
#include <fstream>
#include <cmath>

class AbstractSolver;

enum exTypes {
    quadraticEq = 1, plus = 2, minus = 3, mul = 4, del = 5
};

class Exercise {
    int type;
    std::string exercise;
public:
    Exercise(int type, std::string ex) {
        this->type = type;
        this->exercise = ex;
    }

    int getType() {
        return type;
    }

    std::string getEx() {
        return exercise;
    }
};


class Solution {
    int count;
    float *roots;
public:
    Solution(int t, float *roots) {
        if (t == quadraticEq) {
            count = 2;
        } else if (t == plus || t == minus || t == mul || t == del) {
            count = 1;
        }
        this->roots = roots;
    }

    int getCout() {
        return count;
    }

    float getRoot(int i) {
        return roots[i];
    }

    friend class AbstractSoler;
};

class Reader {
public:
    Exercise *read(std::string input) {
        std::fstream f(input);
        if (f.is_open()) {
            int t;
            std::string s;
            f >> t;
            f >> s;
            f.close();
            return new Exercise(t, s);
        } else {
            return nullptr;
        }
    }

};

class Writer {
public:
    void write(std::string output, Solution s) {
        std::fstream f(output);
        if (f.is_open()) {
            f << "Решения примера:" << std::endl;
            for (int i = 0; i < s.getCout(); i++) {
                f << "x" << i + 1 << " = " << s.getRoot(i) << "; ";
            }
            f.close();
        }
    }
};

class Parser {
    char Num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int isNum(char ch) {
        for (int i = 0; i < 10; i++) {
            if (ch == Num[i]) {
                return i;
            }
        }
        return -1;
    }

public:
    int *Parse(Exercise e) {
        int *vars;
        int t = e.getType();
        if (t == quadraticEq) {
            vars = new int[5];
        } else if (t == plus || t == minus || t == mul || t == del) {
            vars = new int[2];
        }
        int count = 0, i = 0;
        std::string s = e.getEx();
        while (i < s.size()) {
            if (isNum(s[i]) == -1) {
                i++;
            } else {
                int temp = 0;
                int j = i;
                for (j; isNum(s[j]) != -1; j++) {
                    temp = temp * 10 + isNum(s[j]);
                }
                if (i > 0) {
                    if (s[i - 1] == '-') {
                        temp = -temp;
                    }
                }
                vars[count] = temp;
                count++;
                i = j;
            }
        }
        return vars;
    }
};

class AbstractSolver {


public:
    virtual float *Solve(int *vars) = 0;
};


class TwoVariableMulSolver : public AbstractSolver {
public:
    float *Solve(int *vars) override {
        float *roots = new float[1];
        roots[0] = vars[0] * vars[1];
        return roots;
    }
};

class TwoVariableDelSolver : public AbstractSolver {
public:
    float *Solve(int *vars) override {
        float *roots = new float[1];
        roots[0] = (float) vars[0] / (float) vars[1];
        return roots;
    }
};

class TwoVariableAddSolver : public AbstractSolver {
public:
    float *Solve(int *vars) override {
        float *roots = new float[1];
        roots[0] = vars[0] + vars[1];
        return roots;
    }
};

class QadraticEqSolver : public AbstractSolver {
public:
    float *Solve(int *vars) override {
        float *roots = new float[2];
        float d = (vars[2] * vars[2]) - (4 * vars[0] * (vars[3] - vars[4]));
        roots[0] = ( - vars[2] + sqrt(d)) / (2 * vars[0]);
        roots[1] = ( - vars[2] - sqrt(d)) / (2 * vars[0]);
        return roots;
    }
};


class PracticSolver {

    AbstractSolver *asolver = nullptr;

    void setSolver(int t) {
        switch (t) {
            case quadraticEq:
                asolver = new QadraticEqSolver;
                break;
            case plus:
                asolver = new TwoVariableAddSolver;
                break;
            case minus:
                asolver = new TwoVariableAddSolver;
                break;
            case mul:
                asolver = new TwoVariableMulSolver;
                break;
            case del:
                asolver = new TwoVariableDelSolver;
                break;
            default:
                asolver = nullptr;
        }
    }

    int *vars;

    Exercise *ex;

public:
    PracticSolver(Exercise *e) {
        setSolver(e->getType());
        vars = (new Parser)->Parse(*e);
        ex = e;
    }

    Solution *Solve() {
        return (new Solution(ex->getType(), asolver->Solve(vars)));
    }

};

int main(int argc, char *argv[]) {
    if (argc == 3) {
        (new Writer)->write(argv[2], *((new PracticSolver((new Reader)->read(argv[1])))->Solve()));
    } else {
        std::cout << "Неверное количество аргументов программы";
    }
    return 0;
}