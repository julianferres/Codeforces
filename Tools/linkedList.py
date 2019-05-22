class Node:

    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

    def __str__(self):
        return str(self.data)

class LinkedList:

    def __init__(self):
        self.head = None
        self.len = 0

    def __len__(self):
        return self.len

    def __str__(self):
        it = self.head
        output = []
        while(it is not None):
            output.append(it.data)
            it = it.next
        return " ".join(output)

    def append(self, data):
        newNode = Node(data)
        act = self.head
        if(self.head is None):
            self.head = newNode
        else:
            while(act.next is not None):
                act = act.next
            act.next = newNode

        self.len+=1



l = LinkedList()
l.append("Hola,")
l.append("como")
l.append("andas?")
print(str(l))
