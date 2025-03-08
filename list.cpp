#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;
void explainlist(){
    list <int> ls;

    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(5);
}