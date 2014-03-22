def main():
    test=input()
    for j in range(test):
        out=0
        x=raw_input()
        x=x.split(' ')
        m=int(x[0])
        n=int(x[1])
        k=int(x[2])
        for i in range(m,n+1):
            bak=i
            string=''
            while 1:
                if bak%2==0:
                    string+='0'
                else:
                    string+='1'
                bak=bak/2
                if bak==0:
                    break
            string=string[::-1]
            a=0
            b=0
            for l in range(len(string)):
                if string[l]=='1':
                    if (l+1)%2==0:
                        b+=1
                    else:
                        a+=1
            if abs(a-b)==k:
                out+=1
        print out
        

main()

