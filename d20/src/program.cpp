#include <stdio.h>

class Datums
{
private:
    int gads;
    int mēnesis;
    int diena;
public:
    Datums(int diena, int mēnesis, int gads):
        diena(diena),
        mēnesis(mēnesis),
        gads(gads)
    {}
    ~Datums()
    {
        printf("Datums %d/%d/%d tika likvidēts.\n",diena,mēnesis,gads);
    }
    void Drukāt()
    {
        printf("%d/%d/%d",diena,mēnesis,gads);    
    }
    void Mainīt(int diena, int mēnesis, int gads)
    {
        this->diena = diena;
        this->diena = mēnesis;
        this->gads = gads;
    }
};