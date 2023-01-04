#include <stdio.h>
#include <iostream>
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
    this->mēnesis = mēnesis;
    this->gads = gads;
}

bool irGarais(int gads){
    return (gads % 4 == 0 && gads % 100 != 0) || gads % 400 == 0;
}

int dienasMēnesī(int mēnesis, int gads)
{
    // dienu skaits katrā mēnesī īsajā gadā
    int mēneši[12]={
        31, /* 1. */ 28, /* 2. */
        31, /* 3. */ 30, /* 4. */
        31, /* 5. */ 30, /* 6. */
        31, /* 7. */ 31, /* 8. */
        30, /* 9. */ 31, /* 10 */
        30, /* 11 */ 31  /* 12 */
    };
    
    // garā gada februārī ir 29 dienas
    if(irGarais(gads)) mēneši[1]=29;

    return mēneši[mēnesis-1];
}

std::string nedēļasDienasNosaukums(int diena) {
    switch (diena) {
        case 1: return "pirmdiena";
        case 2: return "otrdiena";
        case 3: return "trešdiena";
        case 4: return "ceturtdiena";
        case 5: return "piektdiena";
        case 6: return "sestdiena";
        case 7: return "svētdiena";
    }
    return "?";
}

// rēķina pēc Gregora kalendāra
void Datums::Aprēķināt()
{
    // ejam pa vienai dienai uz priekšu sākot
    // no 1582. gada 15. oktobra mūsu ērā, kas bija piektdiena,
    // un, uzturot nedēļas dienu,
    // ja nepieciešams, nomainu mēnesi, gadu
    // līdz nonāku prasītajā datumā
    int d=15,m=10,y=1582,r=5; // day, month, year, weekday
    while(y<gads||m<mēnesis||d<diena)
    {
        d++, r++;
        int dm = dienasMēnesī(m,y);
        if(d>dm) d=1,m++;
        if(m>12) m=1,y++;
    }

    int res = ((r-1)%7)+1;
    printf("Nedēļas diena: %s.\n", nedēļasDienasNosaukums(res).c_str());
}