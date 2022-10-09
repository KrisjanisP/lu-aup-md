#include "program.hpp"
#include <iostream>

using namespace std;

int main(){
    Datums datums(9,10,2022);

    datums.Drukāt();

    printf("Nedēļas diena: %d.\n", datums.Aprēķināt());
}