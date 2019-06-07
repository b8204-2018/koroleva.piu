//
// Created by polina on 07.06.19.
//

#ifndef MATHFINAL_SOLVE_LIB_H
#define MATHFINAL_SOLVE_LIB_H

#include <string>
#include <vector>


class AbstractSolver {
public:
    virtual float *Solve(unsigned int rootsCount, int *vars) = 0;
};


enum exTypes {
    quadraticEq = 1, plus = 2, minus = 3, mul = 4, del = 5
};

class TypeDependence {
    unsigned int exType;
    unsigned int rootsCount;
    unsigned int varsCount;
    AbstractSolver *solver;

public:
    TypeDependence(unsigned int t, unsigned int r, unsigned int v, AbstractSolver *s);

    unsigned int getType();

    unsigned int getRootsCount();

    unsigned int getVarsCout();

    AbstractSolver *getSolver();
};

class Exercise {
    TypeDependence *type = nullptr;
    std::string exercise;
public:
    Exercise(TypeDependence *type, std::string *ex);

    TypeDependence getType();

    std::string getEx();
};


class Solution {
    int count;
    float *roots;
public:
    Solution(TypeDependence t, float *roots);

    int getCout();

    float getRoot(int i);

};

class Reader {
public:
    Exercise *read(std::string input, std::vector<TypeDependence *> *collection);
};

class Writer {
public:
    void write(std::string output, Solution s);
};

class Parser {

    int isNum(char ch);

public:
    int *Parse(Exercise e);
};


class TwoVariableMulSolver : public AbstractSolver {
public:
    float *Solve(unsigned int rootsCount, int *vars) override;
};

class TwoVariableDelSolver : public AbstractSolver {
public:
    float *Solve(unsigned int rootsCount, int *vars) override;
};

class TwoVariableAddSolver : public AbstractSolver {
public:
    float *Solve(unsigned int rootsCount, int *vars) override;
};

class QadraticEqSolver : public AbstractSolver {
public:
    float *Solve(unsigned int rootsCount, int *vars) override;
};


class PracticSolver {

    AbstractSolver *asolver = nullptr;

    void setSolver(TypeDependence t);

    int *vars;

    Exercise *ex;

public:
    PracticSolver(Exercise *e);

    Solution *Solve();
};


#endif //MATHFINAL_SOLVE_LIB_H
