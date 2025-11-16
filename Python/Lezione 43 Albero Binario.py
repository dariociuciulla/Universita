class Nodo:
    def __init__(self, valore, sinistra = None, destra = None):
        self.valore = valore
        self.sinistra = sinistra
        self.destra = destra

class AlberoBinario:
    def __init__(self, radice = None):
        self.radice = radice

    def stampa_albero(self, nodo = None, prefix = ""):
        if not nodo:
            return
        print(prefix + str(nodo.valore))
        prefix += "| "
        self.stampa_albero(nodo.sinistra, prefix)
        self.stampa_albero(nodo.destra, prefix)

    def dfs_preorder(self, radice):
        stack = []
        stack.append(radice)
        while stack:
            nodo = stack.pop()
            print(nodo.valore)
            if nodo.destra:
                stack.append(nodo.destra)
            if nodo.sinistra:
                stack.append(nodo.sinistra)

    def dfs_postorder(self, radice):
        if radice is None:
            return

        stack = [radice]
        result = []
        while stack:
            nodo = stack.pop()
            result.append(nodo.valore)

            if nodo.sinistra is not None:
                stack.append(nodo.sinistra)
            if nodo.destra is not None:
                stack.append(nodo.destra)
        return result[::-1]

    def dfs_inorder(self, radice):
        if radice is None:
            return

        stack = []
        result = []
        current = radice
        while current is not None or stack:
            while current is not None:
                stack.append(current)
                current = current.sinistra

            current = stack.pop()
            result.append(current.valore)
            current = current.destra

        return result

#main
radice = Nodo(1)
radice.sinistra = Nodo(2)
radice.destra = Nodo(3)
radice.sinistra.sinistra = Nodo(4)
radice.sinistra.destra = Nodo(5)
radice.sinistra.sinistra.sinistra = Nodo(6)
radice.sinistra.sinistra.destra = Nodo(7)
albero = AlberoBinario(radice)
print("Stampa albero: \n")
albero.stampa_albero(radice)
print("\n")
print("Vista in preOrder: \n")
albero.dfs_preorder(radice)
print("\n")
print("Stampa postorder: \n")
print(albero.dfs_postorder(radice))
print("\n")
print("Stampa Inorder: \n")
print(albero.dfs_inorder(radice))
print("\n")