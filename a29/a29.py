#! /usr/bin/python3

print("Autors: Krišjānis Petručeņa kp22084")
print("Uzdevums: A29 - izvadīt divu naturālu skaitļu kopīgos dalītājus")
print("Programma izveidota: 13.09.2022")
print()

# "high-level" loģika uzdevuma izpildei
def main():
    proceed = True
    while proceed == True:
        a, b = query_two_naturals()
        result = get_common_divisors(a,b)
        output_result(result)
        proceed = query_to_proceed()

# Tālāk seko definīcijas izmantotajām funkcijām

class fgcolors:
    RED = "\033[1;31m"
    GREEN = "\033[1;32m"
    NORMAL = "\033[0m"

def query_two_naturals() -> tuple[int,int]:
    """Vaicā un atgriež divus naturālus skaitļus."""
    a = -1 # a ir <= 0, kamēr tas nav korekti ievadīts
    while a <= 0:
        a_str = input("Lūdzu, ievadiet pirmo skaitli: ").strip()
        if a_str.isnumeric():
            a = int(a_str)
        if a<=0: # ja pareizi ievadīts, tad būs > 0
            print(fgcolors.RED+"Kļūda! Ievadītais skaitlis nav naturāls."+fgcolors.NORMAL)
    b = -1 # b ir <= 0, kamēr tas nav korekti ievadīts
    while b <= 0:
        b_str = input("Lūdzu, ievadiet otro skaitli: ").strip()
        if b_str.isnumeric():
            b = int(b_str)
        if b<=0: # ja pareizi ievadīts, tad būs > 0
            print(fgcolors.RED+"Kļūda! Ievadītais skaitlis nav naturāls."+fgcolors.NORMAL)
    return a, b

def get_divs(x: int) -> list:
    """Atgriež skaitļa naturālos dalītājus."""
    res = []
    i = 1
    while i*i<=x:
        if x%i==0:
            res.append(i)
            if((x//i)!=i):
                res.append(x//i)
        i += 1
    return res

def get_common_divisors(a: int, b: int):
    """Atgriež skaitļu kopīgos dalītājus."""
    res = []
    if b < a: # neliela veiktspējas, kas atkarīga no a dal. skaita, optimizācija
        a,b=b,a
    a_divs = get_divs(a)
    for d in a_divs:
        if b%d==0:
            res.append(d)
    res.sort()
    return res

def output_result(result: list):
    # fgcolors.GREEN iestata zaļu tekstu
    print(fgcolors.GREEN,"Kopīgie dalītāji: ",end="")
    print(" ".join(["-"+str(x) for x in result[::-1]]),end=" ")
    print(" ".join([str(x) for x in result]),end=" ")
    print(fgcolors.NORMAL) # atiestatam krāsu uz ierasto

def query_to_proceed() -> bool:
    """Vaicā lietotājam, vai viņš vēlas turpināt."""
    q_res = input("Vai turpināt (1), vai beigt (0)?\n")
    if q_res != "0" and q_res != "1":
        print(fgcolors.RED+"Kļūda. Tika gaidīta atbilde, kas ir 0 vai 1."+fgcolors.NORMAL)
        return query_to_proceed()
    return q_res=="1"

main()
