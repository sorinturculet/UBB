n = int(input('Introduceti numarul de numere a caror suma trebuie calculata.'))
s=0
for i in range(n):
    print("Introduceti al "+str(i+1)+"-lea numar")
    numar=int(input())
    s+=numar
print(s)