#Funzione Heapify
def heapify(a, sx, dx):
    temp = a[sx]
    i = sx
    j = 2*i

    while j <= dx:
        if j < dx and a[j + 1] > a[j]:
            j += 1
        if temp < a[i]:
            a[i] = a[j]
            i = j
            j = 2 * i
        else:
            j = dx + 1

    if i != sx:
        a[i] = temp


def heapsort(a, n):
    #Fase 1: Trasformare l'array in un heap
    for sx in  range(n // 2, 0, -1):
        heapify(a, sx, n)

    #Fase 2: Ordinare l'array
    for dx in range(n, 1, -1):
        tmp = a[1]
        a[1] = a[dx]
        a[dx] = tmp
        heapify(a, 1, dx - 1)

a = [0, 42, 38, 11, 75, 99, 23, 84, 67]
n = 8
heapsort(a, n)
print(a)