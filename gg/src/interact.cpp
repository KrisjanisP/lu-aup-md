#include <iostream>
#include "MyListSolution.h"
#include "StlListSolution.hpp"
#define ListTesting MyListSolution
using namespace std;

int main()
{
    cout << "G17. Uzrakstit funkciju, kas atrod saraksta otro lielako elementu, ja tas eksiste un parvieto to uz saraksta beigam.\n";
    cout << "Ievadiet sarakstu, kuru norobežo nulle, piemēram, \"1 2 3 0\": ";

    ListTesting<int> list;
    int x;
    cin >> x;
    while (x != 0)
    {
        list.pushBack(x);
        cin >> x;
    }

    cout << "Saraksts pirms funkcijas izpildes: " << list.toString() << endl;
    try {
        list.moveSecondLargestToEnd();
    } catch(const std::runtime_error &e) {
        cout << e.what() << endl;
        return 0;
    }
    cout << "Saraksts pec funkcijas izpildes: " << list.toString() << endl;
}