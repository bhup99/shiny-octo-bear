import math


print "Let us define two rectangles as ABCD and PQRS"
print "Enter coordinates of A,B,C,D one by one"
rec1=[]
sub=[]
sub.append(input("Enter x co-ordinate of A"))
sub.append(input("Enter y co-ordinate of A"))
rec1.append(sub)
sub=[]
sub.append(input("Enter x co-ordinate of B"))
sub.append(input("Enter y co-ordinate of B"))
rec1.append(sub)
sub=[]
sub.append(input("Enter x co-ordinate of C"))
sub.append(input("Enter y co-ordinate of C"))
rec1.append(sub)
sub=[]
sub.append(input("Enter x co-ordinate of D"))
sub.append(input("Enter y co-ordinate of D"))
rec1.append(sub)

print "Enter co-ordinates of P,Q,R,S sequentially"
rec2=[]
sub=[]
sub.append(input("Enter x co-ordinate of P"))
sub.append(input("Enter y co-ordinate of P"))
rec2.append(sub)
sub=[]
sub.append(input("Enter x co-ordinate of Q"))
sub.append(input("Enter y co-ordinate of Q"))
rec2.append(sub)
sub=[]
sub.append(input("Enter x co-ordinate of R"))
sub.append(input("Enter y co-ordinate of R"))
rec2.append(sub)
sub=[]
sub.append(input("Enter x co-ordinate of S"))
sub.append(input("Enter y co-ordinate of S"))
rec2.append(sub)

intersec=[]


for i in range(0,4):
    a1,b1,c1=rec1[i-1][1]-rec1[i][1],rec1[i][0]-rec1[i-1][0],rec1[i][1]*rec1[i-1][0]-rec1[i][0]*rec1[i-1][1]
    for j in range(0,4):
        a2,b2,c2=rec1[j-1][1]-rec1[j][1],rec1[j][0]-rec1[j-1][0],rec1[j][1]*rec1[j-1][0]-rec1[j][0]*rec1[j-1][1]
        if a1*b2!=a2*b1:
            x=(b1*c2-b2*c1)/(a1*b2-b1*a2)
            y=(a2*c1-a1*c2)/(a1*b2-b1*a2)
            dist1=math.sqrt((rec1[i-1][0]-x)**2+(rec1[i-1][1]-y)**2)
            dist2=math.sqrt((rec1[i][0]-x)**2+(rec1[i][1]-y)**2)
            dist3=math.sqrt((rec1[i][0]-rec1[i-1][0])**2+(rec1[i][1]-rec1[i-1][1])**2)
            if dist1+dist2==dist3:
                dist1=math.sqrt((rec2[i-1][0]-x)**2+(rec2[i-1][1]-y)**2)
                dist2=math.sqrt((rec2[i][0]-x)**2+(rec2[i][1]-y)**2)
                dist3=math.sqrt((rec2[i][0]-rec2[i-1][0])**2+(rec2[i][1]-rec2[i-1][1])**2)
                if dist1+dist2==dist3:
                    sub=[]
                    sub.append(x)
                    sub.append(y)
                    intersec.append(sub)
print intersec
