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

def backtrackingprime_iterative(number:int):
    stack = [(0, [])]
    generatePrimeNumbers(number)
    while stack:
        current_sum,current_primes = stack.pop()
        for prime in primenumbers:
            if not current_primes or prime>=current_primes[-1]:
                new_sum=current_sum+prime
                if new_sum==number:
                    solutionFoundPrime(number,current_primes+[prime])
                elif new_sum<number:
                    stack.append((new_sum,current_primes+[prime]))
            print(current_sum,current_primes,stack)


number=7
backtrackingprime_iterative(number)

