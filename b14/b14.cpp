/*
Autors: Krišjānis Petručeņa kp22084
Uzdevums: B14 - noskaidrot, vai n! var izteikt kā trīs secīgu skaitļu reizinājumu
Programma izveidota: 13.09.2022
*/

#include <iostream>
#include <sstream>

using namespace std;
using ull = unsigned long long;

void print_success(string scc_msg)
{
    cout<<"\033[1;32m"<<scc_msg<<"\033[0m"<<endl;
}

void print_error(string err_msg)
{
    cout<<"\033[1;31m"<<err_msg<<"\033[0m"<<endl;
}

/**
 * @brief Atgriež true, ja simbolu virkne ir naturāls skaitlis.
 */
bool is_natural(string number)
{
    bool has_non_zero = false; // naturals skaitlis satur ciparu, kas nav nulle
    for (char c : number)
    {
        if (c!='0') has_non_zero = true;
        if (c < '0' || c > '9')
            return false;
    }
    return has_non_zero&&true;
}

/// Atgriež TRUE, ja lietotājs vēlas turpināt, un FALSE, ja nevēlas.
bool query_to_proceed()
{
    cout<<"Vai turpināt (1), vai beigt (0)?"<<endl;
    string response;
    cin>>response;
    if(response!="1"&&response!="0")
    {
        print_error("Kļūda! Tika sagaidīta atbilde, kas ir 0 vai 1.");
        return query_to_proceed();
    }
    return response=="1";
}

/**
 * @brief Vaicā lietotājam ievadīt naturālu skaitli.
 * @return ievadītais naturālais skaitlis.
 */
int query_natural()
{
    cout << "Lūdzu, ievadiet naturālu skaitli (n)!"<<endl;
    
    string x_str;
    cin>>x_str;

    if (!is_natural(x_str))
    {
        print_error("Kļūda! Ievadītais skaitlis nav naturāls.");
        return query_natural();
    }

    try
    {
        int x = stoi(x_str);
        return x;
    }
    catch(out_of_range& oor)
    {
        print_error("Kļūda! Ievadītais skaitlis ir pārāk liels.");
        return query_natural();
    }
}

/**
 * @brief Atgriež n!
 */
int factorial(int n)
{
    int res = 1;
    for(int i=2;i<=n;i++)
        res *= i;
    return res;
}

int main() {
    cout<<"Autors: Krišjānis Petručeņa kp22084"<<endl;
    cout<<"Uzdevums: B14 - noskaidrot, vai n! var izteikt kā trīs secīgu skaitļu reizinājumu"<<endl;
    cout<<"Programma izveidota: 13.09.2022"<<endl;
    cout<<endl;


    bool turpināt = true;
    do
    {
        int x = query_natural();

        ull f = factorial(x);
        bool var_izteikt = false; // true, ja var izteikt, false, ja nevar
        int sākums = 0; // secīgo skaitļu reizinājuma sākums
        for(int i=1;(i)*(i+1)*(i+2)<=f;i++)
            if((i)*(i+1)*(i+2)==f)
                sākums = i,
                var_izteikt = true;

        if(var_izteikt) {
            // pārvēršam trīs secīgos skaitļus uz string
            stringstream ss;
            ss<<sākums<<", ";
            ss<<sākums+1<<", ";
            ss<<sākums+2<<" ";

            print_success("Faktoriāli VAR izteikt kā "+ss.str()+"reizinājumu.");
        }else {
            print_error("Faktoriāli NEVAR izteikt ka trīs secīgu skaitļu reizinājumu.");
        }

        turpināt = query_to_proceed();
 
    } while (turpināt);
}