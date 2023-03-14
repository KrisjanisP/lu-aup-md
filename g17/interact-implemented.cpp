#include <iostream>
#include "implement-list.h"

using namespace std;

int main() {
    cout<<"G17. Uzrakstit funkciju, kas atrod saraksta otro lielako elementu, ja tas eksiste un parvieto to uz saraksta beigam.\n";
    cout<<"Ievadiet sarakstu, kuru norobežo nulle, piemēram, \"1 2 3 0\": ";
    List<int> list;
    int x;
    cin>>x;
    while(x!=0){
        list.pushBack(x);
        cin>>x;
    }
    cout<<"Saraksts pirms funkcijas izpildes: "<<list.toString()<<endl;
    list.moveSecondLargestToEnd();
    cout<<"Saraksts pec funkcijas izpildes: "<<list.toString()<<endl;
}
