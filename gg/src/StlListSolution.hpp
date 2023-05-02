#include <iostream>
#include <list>
#include <sstream>

using namespace std;

template <typename T>
struct StlListSolution : public std::list<T>
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
            if (largest_it == this->end() || *it >= *largest_it)
            {
                second_largest_it = largest_it;
                largest_it = it;
            }
            else if (second_largest_it == this->end() || *it > *second_largest_it)
            {
                second_largest_it = it;
            }
        }

        if (second_largest_it != this->end())
            this->splice(this->end(), *this, second_largest_it);
    }
};