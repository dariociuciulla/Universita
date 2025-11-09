#Selection Sort
# Decrescente
"""
a=[41, 37, 10, 74, 98, 22, 83, 66]
n=8

for i in range(n-1,-1,-1):
    max=i
    for j in range(i-1,-1,-1):
        if a[j]<a[max]:
            max=j
    if max!=i:
        temp=a[i]
        a[i]=a[max]
        a[max]=temp

print(a)
"""
#Crescente
a=[41, 37, 10, 74, 98, 22, 83, 66]
n=8

for i in range(0,n,+1):
    min=i
    for j in range(i+1,n,+1):
        if a[j]<a[min]:
            min=j
    if min!=i:
        temp=a[i]
        a[i]=a[min]
        a[min]=temp

print(a)

