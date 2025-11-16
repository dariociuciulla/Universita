class Nodo:
    def __init__(self, valore, sinistra = None, destra = None):
        self.valore = valore
        self.sinistra = sinistra
        self.destra = destra

class AlberoBinario:
    def __init__(self, radice=None):
        self.radice = radice

    def is_bst(self, nodo, lower_bound=-float("inf"), upper_bound=float("inf")):
        if nodo is None:
            return True
        if nodo.valore <= lower_bound or nodo.valore >= upper_bound:
            return False
        return (self.is_bst(nodo.sinistra, lower_bound, nodo.valore) and
                self.is_bst(nodo.destra, nodo.valore, upper_bound))

    def stampa_albero(self, nodo=None, prefix=""):
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

    def insert_bst(self, radice, valore):
        if radice is None:
            radice = Nodo(valore)
        else:
            if valore < radice.valore:
                if radice.sinistra is None:
                    radice.sinistra = Nodo(valore)
                else:
                    self.insert_bst(radice.sinistra, valore)
            else:
                if radice.destra is None:
                    radice.destra = Nodo(valore)
                else:
                    self.insert_bst(radice.destra, valore)

    def delete_node_bst(self, radice, valore):
        if not radice:
            return None
        if valore < radice.valore:
            radice.sinistra = self.delete_node_bst(radice.sinistra, valore)
        elif valore > radice.valore:
            radice.destra = self.delete_node_bst(radice.destra, valore)
        else:
            if not radice.destra:
                return radice.sinistra
            if not radice.sinistra:
                return radice.destra

            min_larger_node = radice.destra
            while min_larger_node.sinistra:
                min_larger_node = min_larger_node.sinistra
            radice.valore = min_larger_node.valore
            radice.destra = self.delete_node_bst(radice.destra, min_larger_node.valore)

        return radice

# main
radice = Nodo(10)
radice.sinistra = Nodo(5)
radice.destra = Nodo(15)
albero = AlberoBinario(radice)
albero.insert_bst(radice, 22)
albero.insert_bst(radice, 3)
albero.insert_bst(radice, 4)
albero.stampa_albero(radice)
print("Eliminazione elemento 5 \n")
albero.delete_node_bst(radice,5)
albero.stampa_albero(radice)
print(albero.is_bst(albero.radice))
