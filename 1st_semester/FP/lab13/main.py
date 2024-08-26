# 2) Se dă un întreg pozitiv, găsiți toate descompunerile în sumă de numere prime
def solutionFoundPrime(number,list:list):
    print(list)
def isPrime(number):
    if number<2:
        return False
    if number==2:
        return True
    if number%2==0:
        return False
    for i in range(3,number//2+1,2):
        if number%i==0:
            return False
    return True
primenumbers=[]
def generatePrimeNumbers(number):
    for i in range(2, number+1):
        if isPrime(i):
            primenumbers.append(i)
def backtrackingprime(number,list:list):
    if number<1:
        return
    if len(primenumbers)==0:
        generatePrimeNumbers(number)
    if number==sum(list):
        solutionFoundPrime(number,list)
        return
    for prime in primenumbers:
        if len(list):
            if prime<list[-1]:
                return
        if sum(list)+prime<=number:
            list.append(prime)
            print(list)
            backtrackingprime(number,list)
            list.pop()

number=7
backtrackingprime(number,[])
