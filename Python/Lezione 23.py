a = [41, 37, 10, 74, 98, 22, 83, 66]
n = 8

scambio = True

while (scambio):
    scambio = False
    for i in range(n - 1):
        if a[i] >= a[i + 1]:
            temp = a[i]
            a[i] = a[i + 1]
            a[i + 1] = temp
            scambio = True

print(a)
