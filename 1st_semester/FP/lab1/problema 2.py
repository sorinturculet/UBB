n=int(input('introduceti numarul pentru a verifica daca este prim'))
prim='Numarul este prim'
notprim='Numarul nu este prim'
if(n<2):
    print(notprim)
elif(n==2):
    print(prim)
elif(n%2==0):
    print(notprim)

else:
    for i in range(3,n//2,2):
        if(n%i==0):
            print(notprim)
            exit()
    print(prim)
