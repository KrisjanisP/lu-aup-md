/*
Krišjānis Petručeņa kp22084

=== F21 =======================================
Izveidot programmu valodā C++, kas apstrādā teksta failu secīgā režīmā.
Dati no faila jānolasa pa vienai rindiņai.
Nedrīkst dublēt visa faila saturu operatīvajā atmiņā.
Sīkākas prasības sk. Laboratorijas darbu noteikumos.

F21. Dots teksta fails, kurā atrodas sintaktiski pareizs C++ programmas teksts.
Saskaitīt , cik if operatoru un cik cikla operatoru (for, while) satur dotā programma.
Drīkst uzskatīt, ka programmas tekstā nav komentāru un
ka attiecīgie simboli neparādīsies teksta literāļos.
*/

#include <iostream>
#include <map>
#include <fstream>
#include <vector>

#ifndef FILENAME
#define FILENAME "test.cpp"
#endif

using namespace std;

vector<string> extract_words(string line);

int main() {
    ifstream file;
    file.open(FILENAME);
    if (!file.is_open()) {
        printf("Failu %s neizdevās atvērt.", FILENAME);
        return 1;
    }

    map<string, int> word_count;
    word_count["if"] = 0;
    word_count["for"] = 0;
    word_count["while"] = 0;

    string line;
    while (getline(file, line)) {
        for(string word: extract_words(line)) {
            if(word_count.count(word))
                word_count[word]++;
        }
    }

    for(auto [word, count]: word_count) {
        cout<<word<<" "<<count<<endl;
    }

    file.close();
}

vector<string> extract_words(string line) {
    vector<string> res;
    string current;
    for(int i=0;i<line.size();i++){
        bool letter = (line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z');
        bool digit = line[i]>='0'&&line[i]<='9';
        bool underscore = line[i]=='_';
        if((!letter)&&(!digit)&&(!underscore)) {
            if(current.size())
                res.push_back(current);
            current = "";
        } else {
            current += line[i];
        }
    }
    return res;
}