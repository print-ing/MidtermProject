#include "Reaction.h"

Reaction::Reaction() {
    positive = 0;
    negative = 0;
    total = 0;
}

void Reaction::PlusPositive() {
    this->positive++;
    this->total++;
}

void Reaction::PlusNegative() {
    this->negative++;
    this->total++;
}

double Reaction::getPositive() const
{
    if (total == 0)
    {
        return 0;
    }
    double percent = (positive / (double)total) * 100;
    return percent;
}

double Reaction::getNegative() const
{
    if (total == 0)
    {
        return 0;
    }
    double percent = (negative / (double)total) * 100;
    return percent;
}

void Reaction::TestReacion()
{
    Reaction test_reaction;
    test_reaction.PlusPositive();
    test_reaction.PlusPositive();
    test_reaction.PlusNegative();
    cout << "현재 Reaciton의 긍정적인 반응 " << test_reaction.getPositive() << endl;
    cout << "현재 Reaciton의 부정적인 반응 " << test_reaction.getNegative() << endl;
}

