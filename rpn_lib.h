//
// Created by polina on 14.06.19.
//

#ifndef RPN_RPNLIB_H
#define RPN_RPNLIB_H

#include <fstream>

using namespace std;

class Reader {
    string filename;

    ifstream *f;

    Reader(ifstream &f, string &filename);

public:
    static Reader *create(string filename);


    string readLine();

    ~Reader();

};

class Writer {
    string filename;

    ofstream *f;

    Writer(ofstream &f, string &filename);

public:
    static Writer *create(string filename);

    void write(string s);

    ~Writer();

};

class OperationPriority {
    int priority;
    char operation;
public:
    OperationPriority(char op, int p);

    int getPriority();

    int getOperation();
};

class Parser {

    string getRPN(string infnot);

    string getInfNot(string rpn);

};

class Calculator {

public:
    float calculate();

};

class MemoryItem {
    string rpn;
    string infnot;
public:
    string getRPN() {
        return rpn;
    }

    string getInfNotation() {
        return infnot;
    }
};

#endif //RPN_RPNLIB_H
