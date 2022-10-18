#include "program.hpp"
#include <iostream>

using namespace std;

int main(){
    Datums datums(18,10,2022); // diena, mēnesis, datums

    datums.Drukāt();

    printf("Nedēļas diena: %d.\n", datums.Aprēķināt());
}