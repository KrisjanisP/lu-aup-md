#include <iostream>
#include <list>
#include <sstream>

using namespace std;

template <typename T>
struct List : public std::list<T>
{
    std::string toString()
    {
        std::ostringstream oss;
        for (auto it = this->begin(); it != this->end(); ++it)
            oss << *it << ' ';
        return oss.str();
    }
    void moveSecondLargestToEnd()
    {
        if (this->size() < 2)
            return;

        typename list<T>::iterator largest_it = this->end();
        typename list<T>::iterator second_largest_it = this->end();
        ++second_largest_it;

        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (largest_it==this->end() || *it >= *largest_it)
            {
                second_largest_it = largest_it;
                largest_it = it;
            }
            else if (second_largest_it==this->end() || *it > *second_largest_it)
            {
                second_largest_it = it;
            }
        }

        if(second_largest_it!=this->end())
            this->splice(this->end(), *this, second_largest_it);
    }
};

int main()
{
    cout << "G17. Uzrakstit funkciju, kas atrod saraksta otro lielako elementu, ja tas eksiste un parvieto to uz saraksta beigam.\n";
    cout << "Ievadiet sarakstu, kuru norobežo nulle, piemēram, \"1 2 3 0\": ";
    List<int> list;
    int x;
    cin >> x;
    while (x != 0)
    {
        list.push_back(x);
        cin >> x;
    }
    cout << "Saraksts pirms funkcijas izpildes: " << list.toString() << endl;
    list.moveSecondLargestToEnd();
    cout << "Saraksts pec funkcijas izpildes: " << list.toString() << endl;
}
