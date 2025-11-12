#nodo


class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

#pila
class stack:
    def __init__(self):
        self.head = Node("head")
        self.size = 0

    def __str__(self):
        cur = self.head.next
        out = ""
        while cur:
            out += str(cur.value) + "->"
            cur = cur.next
        return out[: - 2]

    def getSize(self):
        return self.size

    def isEmpty(self):
        return self.size == 0

    def peek(self):
        if self.isEmpty():
            raise Exception("Stack is empty")
        return self.head.next.value

    def push(self, value):
        node = Node(value)
        node.next = self.head.next
        self.head.next = node
        self.size += 1

    def pop(self):
        if self.isEmpty():
            raise Exception("Stack is empty")
        remove = self.head.next
        self.head.next = self.head.next.next
        self.size -= 1
        return remove.value

#Main
A = stack()
A.push(100)
A.push(20)
A.push(10)
A.push(5)
print(A)
print('Il Peek è:', A.peek())
print('Esecuzione dei Pop')
print('Rimosso il: ',A.pop())
print('Il Peek è:', A.peek())
print('Rimosso il: ',A.pop())
print('Il Peek è:', A.peek())
print('Rimosso il: ',A.pop())
print('questo è ciò che rimane della pila:', A)
print('Il Peek è:', A.peek())

