from sys import argv

inp = "abcdefghijklmnopqrstuvwxyz,. "
ALPHALEN = len(inp)

inpPos = {}
for x in range(len(inp)):
  inpPos[inp[x]] = x
  
MODULUS = 2**31 - 1

def modularHashing(string):
  h = 0
  for x in range(len(string)):
    h = (h + (2**x) * inpPos.get(string[x].lower(), 0)) % MODULUS
  return h + 1

if __name__ == "__main__":
  if len(argv) != 2:
    print "There is no use of it if you are not inputting any file"
    
  else:
    string = open(argv[1]).read()
    print modularHashing(string)

