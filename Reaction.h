#pragma once
#include <iostream>
using namespace std;

class Reaction
{
private:
    int positive;
    int negative;
    int total;
public:
    Reaction();
    void PlusPositive();
    void PlusNegative();
    double getPositive() const;
    double getNegative() const;

    void TestReacion();
};