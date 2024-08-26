def palindrom(a):
    palindromn=int(0)
    while a:
        palindromn=palindromn*10+a%10
        a//=10
    return palindromn

n=input('Introduceti numarul pentru a calcula palindromul sau')
n=int(n)
palindromN=palindrom(n)
print("Palindromul numarului "+str(n)+" este "+str(palindromN))

# 4,9