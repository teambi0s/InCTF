from Crypto.Util.number import *
from gmpy2 import *
from secret import FLAG
from time import time
from random import randint
from libnum import s2n

class Van3Helsing():
    def __init__(self):
        a = 10

    def VampireLog(self,page):
        with open(".logs/VampireDiaries_"+str(int(time()*1000))+".log",'wb') as riddle:
            riddle.write(str(page[0])+":"+str(page[1]))
        return page[2]

    def DiscreteRSA(self, size=512):
        p = getStrongPrime(size)
        q = getStrongPrime(size)
        r = getStrongPrime(size)
        n = p*q*r
        x = randint((q if q>r else r)*p,n)
        x_dash = x%p
        return [n,n-x_dash+x,p]

    def getVeryStrongPrime(self):
        p = self.VampireLog(self.DiscreteRSA())
        q = self.VampireLog(self.DiscreteRSA())
        r = self.VampireLog(self.DiscreteRSA())
        prime = 2*p*q*r+ pow(p,q-1,q)
        return next_prime(prime)

    def start(self,flag):
        P = self.getVeryStrongPrime()
        Q = self.getVeryStrongPrime()
        R = self.getVeryStrongPrime()
        N = P*Q*R
        E = 65537
        M = bytes_to_long(flag)
        C = pow(M,E,N)
        open("ci.pher.text","wb").write(str(C))
        open("mod.ul.us","wb").write(str(N))
        

class DrAculA():
    def __init__(self):
        purgatory = Van3Helsing()
    
    def VampireLog(self,page):
        with open(".logs/VampireDiaries_"+str(int(time()*1000))+".log",'wb') as riddle:
            riddle.write(str(page[0])+":"+str(page[1]))
        return page[2]
    
    def DiscreteDLP(self):
        p = getPrime(128)
        q = getPrime(128)
        n = p*q
        x = randint(q*p-q,n)
        x_dash = x%p
        return [n,n-x_dash+x,p]

    def start(self,flag):
        p = self.VampireLog(self.DiscreteDLP())
        g = randint(p/2,p)
        y = pow(g,s2n(flag),p)
        open("pub.lic","wb").write(str(g)+":"+str(y))
    
if __name__=="__main__":
    heaven = Van3Helsing().start(FLAG[:-6])
    hell = DrAculA().start(FLAG[-6:][::-1])

