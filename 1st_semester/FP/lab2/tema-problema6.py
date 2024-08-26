print('introduceti numarul n pentru care vom gasi cel mai mic numar m din sirul lui fibonacci mai mare decat n')
n=int(input())
print('Numarul gasit este: ')
if(n==1):
    print(2)
    exit()
else:#folosim a si b ca fiind numere fibonacci, pentru a-l afla pe al 3-lea, respectiv al urmatoru-lea
    a=1
    b=2
    while(b<=n):
        c=b
        b=a+b
        a=c
    print(b)
    