def merge(a, left, center, right):
    i = left
    j = center + 1
    k = 0
    b = [0]*(right - left + 1)

    while (i <= center) and (j <= right):
        if a[i] <= a[j]:
            b[k] = a[i]
            i = i + 1
        else:
            b[k] = a[j]
            j = j + 1
        k = k + 1

    while i <= center:
        b[k] = a[i]
        i = i + 1
        k = k + 1

    while j <= right:
        b[k] = a[j]
        j = j + 1
        k = k + 1

    for k in range (left, right+1):
        a[k] = b[k- left]


def mergesort(a, left, right):
    if left < right:
        center = (left + right) // 2
        mergesort(a, left, center)
        mergesort(a, center + 1, right)
        merge(a, left, center, right)


a = [41, 37, 10, 74, 98, 22, 83, 66]
n = 8
mergesort(a, 0, len(a) - 1)
print(a)
