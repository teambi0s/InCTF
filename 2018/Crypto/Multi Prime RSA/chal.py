from Crypto.Util.number import *
from flag import *

def nextPrime(prim):
    if isPrime(prim):
        return prim
    else:
        return nextPrime(prim+1)

p = getPrime(256)
q = nextPrime(13*p)
r = nextPrime(p*q)
s = nextPrime(q*r)
n = p*q*r*s

phin = (p-1)*(q-1)*(r-1)*(s-1)
e = 65537
assert GCD(e,phin) == 1
m = bytes_to_long(flag)
c = pow(m,e,n)
print long_to_bytes(c).encode("hex")
print n
