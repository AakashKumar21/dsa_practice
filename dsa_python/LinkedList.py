from Node import Node

class LinkedList:
    def __init__(self, data):
        self._head = Node(data)  # Head Node
        self._n = self._head  # Current Node
        self._count = 1

    def insert_as_head(self, new_node):
        new_node.set_next(self._head)
        self._head = new_node
        self._count += 1

    def insert_after(self,node, new_node):
        new_node.set_next(node)
        node.set_next(new_node)

    def delete_head(self):
        if self._head is None:
            raise Exception("Empty Stack")

        # IF there is no next node, return 'None' Data
        if self._head.get_data() is None:
            return None
        else:
            popped_element = self._head.get_data()
            self._head = self._head.get_next()
            return popped_element

    def get_data(self):
        return self._head.get_data()

    def set_head_data(data):
        self._head.set_data(data)
        
    def get_head_node(self):
        return self._head
