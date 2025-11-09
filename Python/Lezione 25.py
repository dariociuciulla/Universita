def quicksort(a, sx, dx):
    i = sx
    j = dx
    pivot = a[(sx + dx) // 2]

    while i <= j:
        while a[i] < pivot:
            i += 1
        while a[j] > pivot:
            j -= 1
        if i <= j:
            if i < j:
                temp = a[i]
                a[i] = a[j]
                a[j] = temp
            i += 1
            j -= 1

    if sx < j:
        quicksort(a, sx, j)
    if i < dx:
        quicksort(a, i, dx)

#main
a = [22, 34, 78, 12, 0, 45, 90, 34]
i=0
j=7

quicksort(a, i, j)

for i in range (0, len(a)):
    print(a[i])