#include <stdio.h>
#include "../include/Hello.hpp"

int main()
{
    Hello* h = new Hello();
    delete h;
    return 0;
}