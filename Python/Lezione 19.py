def ricerca_lineare(a, valore):
    for i in range(len(a)):
        if a[i] == valore:
            return i
    return -1
def ricerca_binaria_non_ricorsiva(a, valore):
    sx = 0
    dx = len(a) - 1

    while sx <= dx:
        mx = (sx + dx) // 2
        if a[mx] == valore:
            return mx
        elif a[mx] < valore:
            sx = mx + 1
        else:
            dx = mx - 1
    return mx if sx <= dx and valore == a[mx] else -1
def check_ordinato(a):
    for i in range(len(a)-1):
        if a[i]>a[i+1]:
            return False
    return True

#main

a=[11,12,13,14,15,16,17,18,19,20,21]
valore = 22

if check_ordinato(a):
    print("Array Ordinato")
else:
    print("Array Non Ordinato")

if check_ordinato(a):
    print(ricerca_binaria_non_ricorsiva(a, valore))
else:
    print(ricerca_lineare(a,valore))

