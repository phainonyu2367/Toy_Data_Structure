class SeqQueue:
    """Directed queue implementation based on array"""
    
    def __init__(self):
        self.max_size = 10
        self.data = [None] * self.max_size
        self.head = 0  # head idx, always points at the empty box
        self.tail = 0  # tail idx, always points at the last box
    
    def isempty(self) -> bool:
        return self.head % self.max_size == self.tail % self.max_size
    
    def _resize(self, size: int) -> None:
        """Private method to resize the internal array"""
        tmp = [None] * size
        length = self.tail - self.head
        
        # Copy data to new array, starting from index 1
        # (index 0 is reserved as the empty box for head)
        for i in range(1, length + 1):
            tmp[i] = self.data[(self.head + i) % self.max_size]
        
        self.max_size = size
        self.head = 0
        self.tail = length
        self.data = tmp
    
    def enQueue(self, val) -> None:
        # Check if queue is full (next tail position equals head)
        if (self.tail + 1) % self.max_size == self.head % self.max_size:
            self._resize(2 * self.max_size)
        
        self.tail += 1
        self.data[self.tail % self.max_size] = val
    
    def deQueue(self):
        if self.isempty():
            raise Exception("Error, empty queue, cannot deQueue")
        
        # Shrink if queue is less than 1/4 full
        if self.max_size > 10 and self.tail - self.head < self.max_size // 4:
            self._resize(self.max_size // 2)
        
        self.head += 1
        return self.data[self.head % self.max_size]
    
    def getHead(self):
        if self.isempty():
            raise Exception("Error, empty queue, cannot getHead")
        return self.data[(self.head + 1) % self.max_size]
    
    def printQueue(self) -> None:
        for i in range(1, self.tail - self.head + 1):
            print(self.data[(self.head + i) % self.max_size], end='')
        print()
    
    def __del__(self):
        # Python has automatic garbage collection
        # No need to manually free memory
        pass
