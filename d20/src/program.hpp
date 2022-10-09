#ifndef DATUMS_H
#define DATUMS_H

class Datums
{
private:
    int gads;
    int mēnesis;
    int diena;
public:
    Datums(int diena, int mēnesis, int gads);
    ~Datums();
    void Drukāt();
    void Mainīt(int diena, int mēnesis, int gads);
};

#endif