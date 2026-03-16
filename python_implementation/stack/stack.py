class aStack:
    """Implementation of array based stack"""
    def __init__(self):
        self._data = []

    def size(self):
        return len(self._data)
    
    def isempty(self) -> bool:
        return len(self._data) == 0
    
    def pop(self):    
        if self.isempty():
            return None
        return self._data.pop()

    def push(self, value):
        self._data.append(value)
        
    def top(self):
        if self.isempty():
            print('The stack is empty')
            return
        return self._data[0]
