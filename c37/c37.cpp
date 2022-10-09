#include <iostream>
#include "libfort.hpp"

using namespace std;

string hex_format(int x) {
    string res = "  ";

    int a = x/16, b = x%16;

    if(a){
        if(a>=10) res[0]=a-10+'A';
        else res[0]=a+'0';
    }

    if(b>=10) res[1]=b-10+'A';
    else res[1]=b+'0';

    return res;
}

int main() {
    fort::char_table table;

    table.set_border_style(FT_DOUBLE2_STYLE);

    for(int i=1;i<=0xf;i++)
    {
        for(int j=1;j<=0xf;j++)
        {
            table<<hex_format(i*j);
        }
        table<<fort::endr;
    }

    std::cout<<table.to_string()<<endl;
}