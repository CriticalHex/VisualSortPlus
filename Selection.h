#pragma once
#include"Sort.h"

class Selection :
    public Sort
{
public:
    int smallest_index = 0;
    int smallest = INFINITY;
    void step();
    void increment();
    void run(sf::RenderWindow& screen, int speed);
    void swap();
    using Sort::Sort;

private:

};

