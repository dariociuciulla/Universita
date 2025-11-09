"""
#Ordine crescente
#insertion Sort
#Dichiaro l'array
a = [41, 37, 10, 74, 98, 22, 83, 66]
#Dichiaro la variabile n che è il massimo elemento del mio array
n = 8

#inizializzo il ciclo for per girarmi tutto l'array
for i in range(1, n):
    value = a[i]
    j = i - 1

    while j >= 0 and a[j] > value:
        a[j + 1] = a[j]
        j = j - 1

    a[j + 1] = value

print(a)
"""
#Ordine decrescente
#insertion Sort

#Dichiaro l'array
a = [41, 37, 10, 74, 98, 22, 83, 66]
#Dichiaro la variabile n che è il massimo elemento del mio array
n = 8

#inizializzo il ciclo for per girarmi tutto l'array
for i in range(1, n):
    value = a[i]
    j = i - 1

    while j >= 0 and a[j] < value:
        a[j + 1] = a[j]
        j = j - 1

    a[j + 1] = value

print(a)