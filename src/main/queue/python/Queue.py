class Queue:

    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = [None] * capacity
        self.head = -1
        self.tail = -1
        self.size = 0

    def is_empty(self):
        return self.head == - 1 and self.tail == -1

    def is_full(self):
        return (self.tail + 1) % self.capacity == self.head

    def add_last(self, element):
        #TODO

    def add_first(self, element):
        #TODO

    def add(self, element, index):
        #TODO

    def remove_first(self):
        #TODO

    def remove_last(self):
        #TODO

    def remove(self, index):
        #TODO

    def get_first(self):
        #TODO

    def get_last(self):
        #TODO

    def get(self, index):
        #TODO

    def index_of(self, element):
        #TODO

    def last_index_of(self, element):
        #TODO
