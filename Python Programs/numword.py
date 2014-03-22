n=input()
p=[[None]*10]*10
t=[None]*10
p=[["","one","two","three","four","five","six","seven","eight","nine"],["ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]]
t=["","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "]
for i in range(2,10):
    p.append([])
for i in range(2,10):
    for j in range(10):
        p[i].append([])
for i in range(20,100):
   p[i/10][i%10]=t[i/10]+p[0][i%10]
if n==0:
    print "zero"
if n>999:
    x=n/1000;
    print p[x/10][x%10],"thousand",
    n=n%1000;
if n>99:
    print p[0][n/100],"hundred",
    n=n%100;
print p[n/10][n%10]



