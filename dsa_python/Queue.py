from Node import Node
from LinkedList import LinkedList


class Queue:
    def __init__(self, data=None):
        self._list = LinkedList(data)  # LinkedList
        self._tail_node = self._list.get_head_node() # Node

    def insert_at_front(self, data):
        pass

    def insert_at_rear(self, data):
        node = Node(data)
        self._tail_node.set_next(node)
        self._tail_node = node

    def delete_from_front(self):
        return self._list.delete_head()

    def delete_from_rear(self, data):
        tmp = self._tail_node.get_data()
        self._tail_node = self._tail_node.get_next()
        return tmp

    def get_rear(self):
        return self._tail_node.get_data()

    def get_front(self):
        return self._list.get_data()