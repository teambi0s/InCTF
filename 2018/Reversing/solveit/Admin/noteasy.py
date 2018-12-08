from z3 import *
s=Solver()
a=[BitVec('a%d' %i,8) for i in range(8)]
for i in range(8):
    s.add(Or(And(a[i]>=48,a[i]<=57),And(a[i]>=65,a[i]<=122)))
s.add(a[1]+a[2]+a[4]+a[5]-4*48==14)
s.add(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]==647)
s.add(a[0]^a[1]^a[2]^a[3]^a[4]^a[5]^a[6]^a[7]==59)
s.add(a[0]^a[1]^a[2]^a[3]==54)
s.add(a[4]^a[5]^a[6]^a[7]==13)
s.add(a[1]^a[3]^a[5]^a[7]==34)
s.add(a[0]*a[1]*a[2]*a[3]*a[4]*a[5]*a[6]*a[7]==1018068377040000)
s.add(a[0]*a[0]==12100)
s.add(a[4]*a[4]==2601)

while(s.check()==sat):
    m=s.model()
    w=''
    for i in range(8):
        w+=chr(m[a[i]].as_long())
    print w
    s.add(Or(a[0] != s.model()[a[0]],
             a[1] != s.model()[a[1]],
             a[2] != s.model()[a[2]],
             a[3] != s.model()[a[3]],
             a[4] != s.model()[a[4]],
             a[5] != s.model()[a[5]],
             a[6] != s.model()[a[6]],
             a[7] != s.model()[a[7]]
))

