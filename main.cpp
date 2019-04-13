#include <iostream>
#include <fstream>
#include <string>

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

    void write(int solution) {
        ofstream f(output);
        f << solution;
        f.close();
    }
};

class AbstractSolver {
public:
    virtual void FormatString(string s) = 0;

    virtual int Solve() = 0;
};

class EquationSolver : AbstractSolver {
    int a, b, c, d, e;
public:
    virtual int Solve() = 0;

    void FormatString(string s) final {
        string temp;
        int i;
        for (i = 0; s[i] != '*'; i++) {
            temp += s[i];
        }
        a = atoi(temp.c_str());
        i++;
        temp = "";
        for (i; s[i] != '-'; i++) {
            temp += s[i];
        }
        b = atoi(temp.c_str());
        i++;
        temp = "";
        for (i; s[i] != 'x'; i++) {
            temp += s[i];
        }
        c = atoi(temp.c_str());
        i++;
        i++;
        temp = "";
        for (i; s[i] != '='; i++) {
            temp += s[i];
        }
        d = atoi(temp.c_str());
        i++;
        temp = "";
        for (i; i < s.length(); i++) {
            temp += s[i];
        }
        e = atoi(temp.c_str());
    }

    int getA() { return a; }

    int getB() { return b; }

    int getC() { return c; }

    int getD() { return d; }

    int getE() { return e; }
};

class TwoVariablesSolver : AbstractSolver {
    int a, b;
public:
    virtual int Solve() = 0;

    void FormatString(string s) final {
        string temp;
        int i;
        for (i = 0; i < s.length()
                    && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/';
             i++) {
            temp += s[i];
        }
        i++;
        a = atoi(temp.c_str());
        temp = "";
        for (i; i < s.length(); i++) {
            temp += s[i];
        }
        b = atoi(temp.c_str());
    }

    int getA() { return a; }

    int getB() { return b; }
};

class Solver1 : public EquationSolver {
public:
    int Solve() final {
        return (getE() - getD() - getA() * getB()) / -getC();
    };
};

class Solver2 : public TwoVariablesSolver {
public:
    int Solve() final {
        return getA() + getB();
    };
};

class Solver3 : public TwoVariablesSolver {
public:
    int Solve() final {
        return getA() - getB();
    };
};

class Solver4 : public TwoVariablesSolver {
public:
    int Solve() final {
        return getA() * getB();
    };
};

class Solver5 : public TwoVariablesSolver {
public:
    int Solve() final {
        return getA() / getB();
    };
};


class SolveThis {
    AbstractSolver *s;

public:
    SolveThis(int format) {
        switch (format) {
            case 1:
                s = (AbstractSolver *) new Solver1;
                break;
            case 2:
                s = (AbstractSolver *) new Solver2;
                break;
            case 3:
                s = (AbstractSolver *) new Solver3;
                break;
            case 4:
                s = (AbstractSolver *) new Solver4;
                break;
            case 5:
                s = (AbstractSolver *) new Solver5;
                break;
        }
    }

    int Solve(string str) {
        s->FormatString(str);
        return (s->Solve());
    }
};

int main(int argc, char *argv[]) {
    if (argc == 3) {
        Reader r(argv[1]);
        r.Read();
        SolveThis MySolver(r.getType());
        int solution = MySolver.Solve(r.getString());
        Writer w(argv[2]);
        w.write(solution);
    } else {
        cout << "Неверное количество аргументов программы";
    }
    return 0;
}