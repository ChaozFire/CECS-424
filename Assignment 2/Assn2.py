import sys
import re

file = sys.argv[1]
lines = [line.rstrip('\n') for line in open(file)]
pattern = re.compile("^[$][*]*([0]|([1-9][\\d]{2}|[1-9][\\d]|[1-9])([,][\\d]{3})*)([.][\\d]{2})?$")

for line in lines:
    if(pattern.match(line)):
        print "Matched: " + line
    else:
        print "Not Matched: " + line
