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
    // parse command line arguments
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // open input file
    ifstream input_file(argv[1]);
    if (!input_file) {
        cout << "Could not open input file '" << argv[1] << "'!" << endl;
        return 1;
    }

    // create map for storing pairs of characters
    map<pair<char,char>, int> pairs;
    
    // read file line by line
    string line;
    while (getline(input_file, line)) {
        // iterate over characters in line
        for (int i = 0; i < line.length() - 1; i++) {
            // get current and next character
            char current = line[i];
            char next = line[i + 1];

            // convert characters to lowercase
            current = tolower(current);
            next = tolower(next);

            // check if characters are letters
            if (!isalpha(current) || !isalpha(next)) 
                continue;
            
            pairs[{current, next}]++;
        }
    }

    map<int, pair<char,char>> sorted_pairs;
    for (auto pair : pairs) {
        sorted_pairs[pair.second] = pair.first;
    }

    for (auto pair : sorted_pairs) {
        cout << pair.second.first << pair.second.second << " " << pair.first << endl;
    }

}