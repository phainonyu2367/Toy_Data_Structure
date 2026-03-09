class SLList:
    """Implementation of SLList(Single Linked List)"""
    class Node:   
        def __init__(self, item, next):
            self.item = item
            self.next = next

    def __init__(self, item=None):
        self.head = self.Node(0, None)
        self.size = 0
        if not item is None:
            self.head.next = self.Node(item, None)
            self.size += 1

    def addFirst(self, item):
        """Add item to the start of the SLList"""
        self.head.next = self.Node(item, self.head.next)
        self.size += 1

    def addLast(self, item):
        """Add item to the end of the SLList"""
        cur = self.head
        while (cur.next != None):
            cur = cur.next
        cur.next = self.Node(item, None)
        self.size += 1

    def get(self, idx: int):
        """Get the ith item of the Linked List"""
        assert idx < self.size, ValueError("Index out of bound when getting item")
        cur = self.head.next
        for _ in range(idx):
            cur = cur.next
        return cur
    
    def set(self, idx: int, item):
        """Set the ith item of the list"""
        assert idx < self.size, ValueError("Index out of bound when setting item")
        cur = self.head.next
        for _ in range(idx):
            cur = cur.next
        cur.item = item

    def find(self, item) -> int:
        """Find the position of the item"""
        idx = -1
        cur = self.head.next
        while cur != None:
            idx += 1
            if cur.item == item:
                return idx
            cur = cur.next
        return -1

    def insert(self, idx, item):
        """Insert item at index i"""
        assert idx < self.size, ValueError("Index out of bound when inserting item")
        cur = self.head
        for _ in range(idx):
            cur = cur.next
        cur.next = self.Node(item, cur.next)
        self.size += 1
        

    def delete(self, idx: int):
        """Delete the ith node of the list"""
        assert idx < self.size, ValueError("Index out of bound when deleting item")
        cur = self.head
        for _ in range(idx):
            cur = cur.next
        cur.next = cur.next.next
        self.size -= 1

    def myMap(self, func, *args):
        cur = self.head
        for _ in range(self.size):
            cur = cur.next
            cur.item = func(cur.item, *args)
        
    def size(self):
        return self.size