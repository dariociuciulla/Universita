class node ():
    def __init__ (self, value):
        self.value = value
        self.next = None

class myList():
    def __init__ (self):
        self.head = None

    def showList(self):
        curr = self.head
        while (curr != None):
            print(curr.value, end = ' -> ' )
            curr = curr.next
        print('None\n')

    def headInsert(self, newValue):
        newNode = node(newValue)

        if(self.head == None):
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode

    def tailInsert(self, newValue):
        if(self.head == None):
            self.headInsert(newValue)
        else:
            curr = self.head
            while(curr.next != None):
                curr = curr.next

            newNode = node(newValue)
            curr.next = newNode

    def findElem(self, toFind):
        curr = self.head
        while(curr != None):
            if (curr.value == toFind):
                return True
            curr = curr.next
        return False

    def headRemove(self):
        if(self.head != None):
            headNode = self.head
            self.head = self.head.next
            headNode.next = None
            return headNode
        return None

    def tailRemove(self):
        if(self.head == None or self.head.next == None):
            return self.headRemove()
        else:
            curr = self.head
            prev = None
            while(curr.next != None):
                prev = curr
                curr = curr.next
            prev.next = curr.next
            return curr

    def posiotionInsert(self, newValue, index):
        if(index == 0 or self.head == None):
            self.headInsert(newValue)
        else:
            i = 0
            curr = self.head
            prev = None
            newNode = node(newValue)
            while(i < index and curr != None):
                i += 1
                prev = curr
                curr = curr.next

            if(curr == None):
                prev.next = newNode
            else:
                newNode.next = curr
                prev.next = newNode

#main
newList = myList()
newList.tailInsert(2)
newList.tailInsert(8)
newList.tailInsert(4)
newList.showList()
if (newList.findElem(2) == True):
    print('Elemento 2 Trovato')
else:
    print('Elemento 2 non trovato')
newList.posiotionInsert(6,3)
newList.showList()
if (newList.findElem(6) == True):
    print('Elemento 6 Trovato')
else:
    print('Elemento 6 non trovato')