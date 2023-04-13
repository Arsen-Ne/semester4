#include <iostream>

struct Employee {
    Employee();
    Employee(int, const char*, double);

    int             num;
    char            name[10];
    double          hours;
};
