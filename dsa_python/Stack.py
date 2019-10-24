from LinkedList import LinkedList
from Node import Node

class Stack:
    def __init__(self, data=None):
        self._list = LinkedList(data)
        self._top = 0 if data is None else 1

    def push(self, element):
        self._top += 1
        node = Node(element)
        self._list.insert_as_head(node)

    def pop(self):
        if self._top == 0:
            raise Exception("Empty Stack")
        self._top -= 1
        return self._list.delete_head()

    def get_data(self):
        return self._list.get_data()

    def get_top(self):
        return self._top

