//
// Created by polina on 07.06.19.
//

#include <cmath>
#include <fstream>
#include "solve_lib.h"

TypeDependence::TypeDependence(unsigned int t, unsigned int r, unsigned int v, AbstractSolver *s) {
    exType = t;
    rootsCount = r;
    varsCount = v;
    solver = s;
}

unsigned int TypeDependence::getType() {
    return exType;
}

unsigned int TypeDependence::getRootsCount() {
    return rootsCount;
}

unsigned int TypeDependence::getVarsCout() {
    return varsCount;
}

AbstractSolver *TypeDependence::getSolver() {
    return solver;
}


Exercise::Exercise(TypeDependence *type, std::string *ex) {
    this->type = type;
    this->exercise = *ex;
}

TypeDependence Exercise::getType() {
    return *type;
}

std::string Exercise::getEx() {
    return exercise;
}


Solution::Solution(TypeDependence t, float *roots) {
    this->count = t.getRootsCount();
    this->roots = roots;
}

int Solution::getCout() {
    return count;
}

float Solution::getRoot(int i) {
    return roots[i];
}


Exercise *Reader::read(std::string input, std::vector<TypeDependence *> *collection) {
    std::fstream f(input);
    if (f.is_open()) {
        int t;
        std::string s;
        f >> t;
        f >> s;
        f.close();
        for (int i = 0; i < collection->size(); i++) {
            if (collection->at(i)->getType() == t) {
                return new Exercise(collection->at(i), &s);
            }
        }
        throw "There isn't right type of exercise in the collection";
    }
}

void Writer::write(std::string output, Solution s) {
    std::fstream f(output);
    if (f.is_open()) {
        f << "Решения примера:" << std::endl;
        for (int i = 0; i < s.getCout(); i++) {
            f << "x" << i + 1 << " = " << s.getRoot(i) << "; ";
        }
        f.close();
    }
}


int Parser::isNum(char ch) {
    if (ch >= 48 && ch <= 57) {
        return -(48 - ch);
    }
    return -1;
}

int *Parser::Parse(Exercise e) {
    int *vars = new int[e.getType().getVarsCout()];
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


float *TwoVariableMulSolver::Solve(unsigned int rootsCount, int *vars) {
    float *roots = new float[rootsCount];
    roots[0] = vars[0] * vars[1];
    return roots;
}


float *TwoVariableDelSolver::Solve(unsigned int rootsCount, int *vars) {
    float *roots = new float[rootsCount];
    roots[0] = (float) vars[0] / (float) vars[1];
    return roots;
}


float *TwoVariableAddSolver::Solve(unsigned int rootsCount, int *vars) {
    float *roots = new float[rootsCount];
    roots[0] = vars[0] + vars[1];
    return roots;
}


float *QadraticEqSolver::Solve(unsigned int rootsCount, int *vars) {
    float *roots = new float[rootsCount];
    float d = (vars[2] * vars[2]) - (4 * vars[0] * (vars[3] - vars[4]));
    roots[0] = (-vars[2] + sqrt(d)) / (2 * vars[0]);
    roots[1] = (-vars[2] - sqrt(d)) / (2 * vars[0]);
    return roots;
}


void PracticSolver::setSolver(TypeDependence t) {
    asolver = t.getSolver();
}


PracticSolver::PracticSolver(Exercise *e) {
    setSolver(e->getType());
    vars = (new Parser)->Parse(*e);
    ex = e;
}

Solution *PracticSolver::Solve() {
    return (new Solution(ex->getType(), asolver->Solve(ex->getType().getRootsCount(), vars)));
}


