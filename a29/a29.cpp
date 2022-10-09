/*
Autors: Krišjānis Petručeņa kp22084
Uzdevums: A29 - izvadīt divu naturālu skaitļu kopīgos dalītājus
Programma izveidota: 13.09.2022
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void print_error(string err_msg)
{
    cout<<"\033[1;31m"<<err_msg<<"\033[0m"<<endl;
}

void print_success(string scc_msg)
{
    cout<<"\033[1;32m"<<scc_msg<<"\033[0m"<<endl;
}

/**
 * @brief Atgriež true, ja number satur tikai ciparus.
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

/**
 * @brief Vaicā lietotājam ievadīt divus naturālus skaitļus līdz (2^64)-1.
 * @return pair<ull,ull> - ievadītie naturālie skaitļi.
 */
pair<ull,ull> query_two_naturals()
{
    cout << "Lūdzu, ievadiet divus naturālus skaitļus!"<<endl;
    
    string a_str, b_str;
    cin >> a_str >> b_str;

    if (!is_natural(a_str) || !is_natural(b_str))
    {
        print_error("Kļūda! Ievadītais skaitlis nav naturāls.");
        return query_two_naturals();
    }

    try
    {
        ull a = stoull(a_str), b = stoull(b_str);
        return {a,b};
    }
    catch(out_of_range& oor)
    {
        print_error("Kļūda! Ievadītais skaitlis ir pārāk liels.");
        return query_two_naturals();
    }
}

/**
 * @brief Atgriež skaitļa naturālos dalītājus.
 * @param x naturāls skaitlis līdz (2^64)-1.
 */
vector<ull> get_divisors(ull x)
{
    vector<ull> divs; 
    for(ull i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            divs.push_back(i);
            if((x/i)!=i)
                divs.push_back(x/i);
        }
    }
    return divs;
}

/**
 * @brief Atgriež kopīgos naturālos dalītājus augošā secībā.
 * @param a pirmais skaitlis līdz (2^64)-1.
 * @param b otrais skaitlis līdz (2^64)-1.
 */
vector<ull> get_common_divisors(ull a, ull b)
{

    if(b<a) swap(a,b); // neliela veiktspējas optimizācija

    vector<ull> a_divs = get_divisors(a);

    vector<ull> a_and_b_divs;
    for(ull x: a_divs)
        if(b%x==0)
            a_and_b_divs.push_back(x);

    sort(a_and_b_divs.begin(),a_and_b_divs.end());

    return a_and_b_divs;
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

int main()
{

    cout<<"Autors: Krišjānis Petručeņa kp22084"<<endl;
    cout<<"Uzdevums: A29 - izvadīt divu naturālu skaitļu kopīgos dalītājus"<<endl;
    cout<<"Programma izveidota: 13.09.2022"<<endl;
    cout<<endl;
    
    bool proceed = true;
    do
    {
        // nepieciešams C++17 priekš structured binding
        auto [a,b] = query_two_naturals();

        vector<ull> result = get_common_divisors(a,b);

        vector<ull> rev_result = result; 
        reverse(rev_result.begin(),rev_result.end());// lai iegūtu negatīvos skaitļus augoši, apgriežam otrādāk pozitīvos

        string result_str = "Kopīgie dalītāji: ";
        // es neesmu pārliecināts par to, vai jāizvada negatīvie dalītāji
        for(ull x: rev_result)
            result_str += "-"+to_string(x)+" "; // - tiek likts kā simbols, jo x ir unsigned 
        for(ull x: result)
            result_str += to_string(x)+" ";

        print_success(result_str);

        proceed = query_to_proceed();
 
    } while (proceed);
}