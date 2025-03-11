class Deque:

    def __init__(self, capacity):
        self.dq = [None] * capacity
        self.cap = capacity
        self.size = 0
        self.head = 0
    
    def append_left(self, value):
        if self.is_full():
            return
        else:
            self.head = (self.head - 1 + self.cap) % self.cap
            self.dq[self.head] = value
            self.size += 1
    
    def append_right(self, value):
        if self.is_full():
            return
        else:
            tail = (self.head + self.size) % self.cap
            self.dq[tail] = value
            self.size += 1
    
    def pop_left(self):
        if self.dq.is_empty():
            return None
        else:
            aux = self.dq[self.tail]
            self.tail = (self.tail + 1) % self.cap
            self.size -= 1
            return aux
    
    def pop_right(self):
        if self.dq.is_empty():
            return
        else:
            tail = (self.head + self.size - 1) % self.cap
            self.size -= 1
            return self.dq[tail]
    
    def peek_left(self):
        return self.dq[self.head]
    
    def peek_right(self):
        tail = (self.head + self.size - 1) % self.cap
        return self.dq[tail]
    
    def is_full(self):
        if self.size == self.cap:
            return True
        return False
    
    def is_empty(self):
        if self.size == 0:
            return True
        return False
