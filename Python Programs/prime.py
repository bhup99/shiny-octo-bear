prime=[]
prime.append(2)
fp=open('prime','w')
for i in range(3,10**8):
    signal=1
    for j in prime:
        if i%j==0:
            signal=0
            break
    if signal:
        prime.append(i)
        fp.write('%d \n' %i)
print prime
