inp=[]
while 1:
    try:
        n=input()
    except:
        break
    inp.append(n)

for i in range(len(inp)):
    if inp[i]==42:
        break
    print inp[i]
    
