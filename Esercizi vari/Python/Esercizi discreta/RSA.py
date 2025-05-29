# Programma che genera chiavi RSA usando numeri primi a 5 cifre

import sympy as sp
from random import randint 

def generatePrime(): # numero primo tra 10.000 e 99.999 usando il Teorema di Wilson
    return next(num for num in iter(lambda: randint(10000, 99999), None) if (sp.factorial(num - 1) + 1) % num == 0)

def generate2Primes():
    p = generatePrime()
    q = generatePrime()
    
    while p == q:
        q = generatePrime()
    
    return p, q

def MCD(x, y): 
    return x if y == 0 else MCD(y, x % y)

def generateE(phi): 
    return next(e for e in iter(lambda: randint(1, phi - 1), None) if MCD(e, phi) == 1)

def generateKeys():
    p, q = generate2Primes()
    n = p * q
    phi = (p - 1) * (q - 1)
    e = generateE(phi) 
    d = sp.mod_inverse(e, phi)
    return (n, e), (n, d)

publicKey, privateKey = generateKeys()
    

print("Public key: ", publicKey)
print("Private key: ", privateKey)