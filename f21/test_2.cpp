#include <iostream>
using namespace std;

int main()
{
    while(123){
        for(int i=0;false;i++){
            if(true){
                return 1;
            }
        }
        break;
    }
    return 0;
}