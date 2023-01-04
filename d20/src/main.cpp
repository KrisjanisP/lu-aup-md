#include "program.hpp"
#include <iostream>

using namespace std;

int main(){
    Datums datums(1,1,1970); // diena, mēnesis, datums
    datums.Drukāt();

    datums.Aprēķināt(); // ceturtdiena

    datums.Mainīt(18,10,2022);
    datums.Aprēķināt(); // otrdiena

    datums.Mainīt(4,1,2023);
    datums.Aprēķināt(); // trešdiena
}