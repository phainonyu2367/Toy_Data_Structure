from typing import Optional

class SLList:

    class _Node:
        """Enclosed implementation of Node"""
        def __init__(self, value, next=None):
            self.value = value
            self.next = next

    def __init__(self):
        self._head = SLList._Node(-1)
        self._tail = self._head
        self._size = 0

    class iterator:

        def __init__(self, ptr):
            self._cur = ptr

        def next(self):
            self.cur = self.cur.next

        def val(self):
            return self.cur.value

    def Head(self):
        return SLList.iterator(self._head)

    def Tail(self):
        return SLList.iterator(self._tail)

    def size(self):
        return self._size
    
    def addFirst(self, value) -> None:
        self._head.next = SLList._Node(value, self._head.next)
        if self._head.next.next == None:
            self._tail = self._head.next
        self._size += 1

    def addLast(self, value) -> None:
        self._tail.next = SLList._Node(value)
        self._tail = self._tail.next
        self._size += 1

    