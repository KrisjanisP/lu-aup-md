/*
Izveidot programmu valodā C++.  Ja programma darbojas ar failu, nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
Ar faila komponenti tiek saprasts fiksēta garuma ieraksts. Sīkākās prasības sk. Laboratorijas darbu noteikumos.

H6. Dots teksta fails. Atrast tekstā 5 viesbiežāk sastopamos blakus esošu (latīņu alfabēta) burtu pārus (nešķirojot reģistru).
Izdrukāt burtu pārus pēc to sastapšanas reižu skaita dilstošā secībā, pievienojot arī sastapšanas biežumu (piemēram, he 289, th 288, an 187, in 147, nd 137).
Informācijas glabāšanai pirms izdrukas failā izmantot vārdnīcu STL map un/vai STL list.

Krišjānis Petručeņa kp22084
*/

#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    // parse command line argiuments
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // open input file
    ifstream input_file(argv[1], ios::binary);
    if (!input_file) {
        cout << "Could not open input file '" << argv[1] << "'!" << endl;
        return 1;
    }
    input_file.unsetf(ios::skipws);

    // create map for storing pairs of characters
    map<pair<char,char>, int> pairs;
    
    // read file letter by letter
    char current = '\0';
    char previous = '\0';
    while (input_file.get(current)) {
        // convert characters to lowercase
        current = tolower(current);
        previous = tolower(previous);

        if(previous == '\0') {
            previous = current;
            continue;
        }

        // check if characters are letters
        if (isalpha(previous) && isalpha(current)) {
            pairs[{previous, current}]++;
        }

        previous = current;
    }

    multimap<int, pair<char,char>, greater<int>> sorted_pairs;
    for (auto pair : pairs) {
        sorted_pairs.insert({pair.second, pair.first});
    }

    for (auto pair : sorted_pairs) {
        cout << pair.second.first << pair.second.second << " " << pair.first << endl;
    }

    if(sorted_pairs.size() < 1) {
        cout<<"File doesn't have letter pairs"<<endl;
    }

}