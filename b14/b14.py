#! /usr/bin/python3

print("Autors: Krišjānis Petručeņa kp22084")
print("Uzdevums: B14 - noskaidrot, vai n! var izteikt kā trīs secīgu skaitļu reizinājumu")
print("Programma izveidota: 13.09.2022")
print()

# "high-level" loģika uzdevuma izpildei
def main():
    proceed = True
    while proceed == True:
        x = query_natural()
        f = factorial(x)
        print("Faktoriāļa n! vērtība: ", f)

        can_represent = False
        i = 1
        while i*(i+1)*(i+2) <= f:
            if i*(i+1)*(i+2) == f:
                can_represent = True
                break
            i += 1
        
        if can_represent:
            print(fgcolors.GREEN+f"Faktoriāli VAR izteikt kā {i}, {i+1}, {i+2} reizinājumu."+fgcolors.NORMAL)
        else:
            print(fgcolors.RED+"Faktoriāli NEVAR izteikt ka trīs secīgu skaitļu reizinājumu."+fgcolors.NORMAL)
            
        proceed = query_to_proceed()

# Tālāk seko definīcijas izmantotajām funkcijām

class fgcolors:
    RED = "\033[1;31m"
    GREEN = "\033[1;32m"
    NORMAL = "\033[0m"

def query_natural() -> int:
    """Vaicā un atgriež vienu naturālu skaitli (n)."""
    x = -1 # a ir <= 0, kamēr tas nav korekti ievadīts
    while x <= 0:
        x_str = input("Lūdzu, ievadiet naturālu skaitli (n): ").strip()
        if x_str.isnumeric():
            x = int(x_str)
        if x<=0: # ja pareizi ievadīts, tad būs > 0
            print(fgcolors.RED+"Kļūda! Ievadītais skaitlis nav naturāls."+fgcolors.NORMAL)
    return x

def factorial(n:int) -> int:
    """Atgriež n!"""
    res = 1
    for i in range(1,n+1):
        res *= i
    return res

def query_to_proceed() -> bool:
    """Vaicā lietotājam, vai viņš vēlas turpināt."""
    q_res = input("Vai turpināt (1), vai beigt (0)? ")
    if q_res != "0" and q_res != "1":
        print(fgcolors.RED+"Kļūda. Tika gaidīta atbilde, kas ir 0 vai 1."+fgcolors.NORMAL)
        return query_to_proceed()
    return q_res=="1"

if __name__ == "__main__":
    main()