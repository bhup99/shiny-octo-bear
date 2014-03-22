dic={}

def cal(n):
    if n<5:
        return n
    if dic.has_key(n):
        return dic[n]

    x=cal(n/2)
    y=cal(n/3)
    z=cal(n/4)

    dic[n] = max(n, x+y+z)
    return dic[n]

while 1:
    try:
        n = input()
    except:
        break
    print cal(n)
