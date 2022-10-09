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