#include <stdio.h>
#include "program.hpp"

Datums::Datums(int diena, int mēnesis, int gads):
    diena(diena),
    mēnesis(mēnesis),
    gads(gads)
{}

Datums::~Datums()
{
    printf("Datums %d/%d/%d tika likvidēts.\n",diena,mēnesis,gads);
}

void Datums::Drukāt()
{
    printf("%d/%d/%d\n",diena,mēnesis,gads);    
}

void Datums::Mainīt(int diena, int mēnesis, int gads)
{
    this->diena = diena;
    this->diena = mēnesis;
    this->gads = gads;
}

bool ir_garais(int year){
    if(year%4) return false;
    if(year%100) return false;
    if(year%400) return false;
    return true;
}

int Datums::Aprēķināt()
{
    // normal year, leap year
    int mēneši[12][2]={
        {31,31}, // 1.
        {28,29}, // 2.
        {31,31}, // 3.
        {30,30}, // 4.
        {31,31}, // 5.
        {30,30}, // 6.
        {31,31}, // 7.
        {31,31}, // 8.
        {30,30}, // 9.
        {31,31}, // 10.
        {30,30}, // 11.
        {31,31}, // 12.
    };

    int d=1,m=1,y=1,r=0;
    while(y<gads||m<mēnesis||d<diena)
    {
        int garais = 0;
        if(ir_garais(y)) garais=1;
        d++;
        if(d>mēneši[m][garais])
            d=1,m++;
        if(m>12)
            m=1,y++;
        r++;
    }
    return (r%7)+1;
}