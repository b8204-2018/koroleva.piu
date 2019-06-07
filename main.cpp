#include <iostream>
#include "solve_lib.h"


int main(int argc, char *argv[]) {

    std::vector<TypeDependence *> collector;

    collector.push_back(new TypeDependence(quadraticEq, 2, 5, new QadraticEqSolver));
    collector.push_back(new TypeDependence(plus, 1, 2, new TwoVariableAddSolver));
    collector.push_back(new TypeDependence(minus, 1, 2, new TwoVariableAddSolver));
    collector.push_back(new TypeDependence(mul, 1, 2, new TwoVariableMulSolver));
    collector.push_back(new TypeDependence(del, 1, 2, new TwoVariableDelSolver));

    if (argc == 3) {
        try {
            (new Writer)->write(argv[2], *((new PracticSolver((new Reader)->read(argv[1], &collector)))->Solve()));
        }
        catch (char const *s) {
            std::cout << s;
        }
    } else {
        std::cout << "Неверное количество аргументов программы";
    }
    return 0;
}