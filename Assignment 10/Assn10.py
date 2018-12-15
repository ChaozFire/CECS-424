import sys
import re
import struct
import numpy as np

def floatToBits(f):
    val = struct.pack('>f', f)
    bits = struct.unpack('>l', val)[0]
    return bits

def bitsToFloat(b):
    val = struct.pack('>l', b)
    f = struct.unpack('>f', val)[0]
    return f

def convertFloat(number):
    number_i = floatToBits(number)
    sign = (number_i & 0x80000000) >> 31
    exponent = (number_i & 0x7f8000000L) >> 23
    matissa = (number_i & 0x007fffff)
    return int(sign),int(exponent),int(matissa)

def nextFloat(number):
    number_i = floatToBits(number)
    number_i += 1
    num = bitsToFloat(number_i)
    return num

def countBetween(lower, upper):
    number_lower = floatToBits(lower)
    number_upper = floatToBits(upper)
    return number_upper - number_lower

def main():
    print "i. Floating Point Number Converter"
    pi = np.float32(3.14159265358979)
    print round(pi, 5), "->", convertFloat(pi)

    print "ii. Floating Point Number Enumerator"
    fp = np.float32(0.0)
    i = 0
    while fp < 1.4E-44:
        i+=1
        fp = nextFloat(fp)
        print "{}th number: ".format(i),'{:0.5e}'.format(fp)

    print "iii. Floating Point Number Counting"
    posFPs = countBetween(np.float32(0.0),np.finfo(np.float32).max)
    zeroOneFPs = countBetween(np.float32(0.0),np.float32(1.0))
    print "Number of positive floating point numbers:", posFPs
    print "Number of floating point numbers between 0 and 1:", zeroOneFPs
    print "Proportion (# of 0~1) / (# of positive): {}%".format(round((np.float32(zeroOneFPs)/np.float32(posFPs))*100,4))

main()
