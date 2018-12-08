#The third function gives us an idea about the other two functions. The sum of return values of the two functions should be 16. So we write a script to find the possible outputs.
import string
l=string.digits
b='Xsl\x7f}p'
for i in l:
    c=''
    for j in b:
        c+=chr(ord(j)^int(i))
    m=sum(bytearray(c))%10
    if(m==int(i)):
	print "string = "+c
	print "code = "+ str((16-m)*306783371)

#Two outputs out of which the second one is the only possible input as the first code is not an integer and it will not be accepted. 



