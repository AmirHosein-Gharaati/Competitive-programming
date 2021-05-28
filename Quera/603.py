def fac(n):
    summ = 1
    for i in range(1,n+1):
        summ *= i
    return summ

def entekhab(all,number):
    return (fac(all) / (fac(number)*fac(all-number)))



number = int(input())
counts = 0

for five_counts in range(7):
    for two_counts in range(16):
        for one_counts in range(31):
            summ = five_counts + two_counts +one_counts
            if five_counts*5 + two_counts*2 + one_counts*1 == number:
                counts +=  entekhab(summ,five_counts) * entekhab(summ-five_counts,two_counts)


print(int(counts))
