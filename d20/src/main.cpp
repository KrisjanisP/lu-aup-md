#include "program.hpp"
#include <iostream>

using namespace std;

int main(){
    Datums datums(1,1,1970); // diena, mēnesis, datums

    datums.Drukāt();

    printf("Nedēļas diena: %d.\n", datums.Aprēķināt());
}
