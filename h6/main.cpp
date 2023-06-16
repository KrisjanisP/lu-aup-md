/*
Izveidot programmu valodā C++.  Ja programma darbojas ar failu,
nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
Ar faila komponenti tiek saprasts fiksēta garuma ieraksts.
Sīkākās prasības sk. Laboratorijas darbu noteikumos.

H6. Dots teksta fails. Atrast tekstā 5 viesbiežāk sastopamos
blakus esošu (latīņu alfabēta) burtu pārus (nešķirojot reģistru).
Izdrukāt burtu pārus pēc to sastapšanas reižu skaita dilstošā secībā,
pievienojot arī sastapšanas biežumu
(piemēram, he 289, th 288, an 187, in 147, nd 137).
Informācijas glabāšanai pirms izdrukas failā izmantot
vārdnīcu STL map un/vai STL list.

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

    // atveram failu
    ifstream input_file(argv[1]);
    if (!input_file) {
        cout << "Could not open input file '" << argv[1] << "'!" << endl;
        return 1;
    }

    // izveidojam map struktūru, lai glabātu blakusesošo burtu pāru skaitus
    map<pair<char,char>, int> pairs;
    
    // ielasam failu pa rindiņai
    string line;
    while (getline(input_file, line)) {
        // pārlasam visus simbolus šajā rindā
        for (int i = 0; i < line.length() - 1; i++) {
            // apskatam tagadējo un nākamo simbolu
            char current = line[i];
            char next = line[i + 1];

            // pārvēršam abus burtus uz apakšējo reģistru
            current = tolower(current);
            next = tolower(next);

            // ja šis vai nākamais simbols nav burts, izlaižam
            if (!isalpha(current) || !isalpha(next)) 
                continue;
            
            // palielinam skaitu
            pairs[{current, next}]++;
        }
    }

    // izveidojam struktūru multimap, kas attiecīgajam skaitam glabā pāri
    // es to izmantoju kā alternatīvu rezultātu kārtošanai. nezinu kāpēc
    multimap<int, pair<char,char>, greater<int>> sorted_pairs;
    for (auto pair : pairs) {
        sorted_pairs.insert({pair.second, pair.first});
    }

    // izvadam pārus ar to attiecīgo skaitiem
    for (auto pair : sorted_pairs) {
        cout << pair.second.first << pair.second.second << " " << pair.first << endl;
    }

    // izvadam, ka failā nav burtu pāru
    if(sorted_pairs.size() < 1) {
        cout<<"File doesn't have letter pairs"<<endl;
    }

}