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
        self._list.insert_after(self._tail_node,node)
        # self._tail_node.set_next(node)
        # self._tail_node = node

    def delete_from_front(self): # Constant Time
        return self._list.delete_head()

    def delete_from_rear(self):
        if(not self._list.get_data):
            raise Exception("Empty Queue")
        # Like Pointer and pre ptr
        ## Head Node i.e Front
        pre_tmp_node = self._list.get_head_node() 
        pre_tmp_data = pre_tmp_node.get_data() 
        ## Next to Head
        tmp_node = pre_tmp_node.get_next() 
        tmp_data = tmp_node.get_data()
        
        while(True):
            if(tmp_node.get_next() == None):
                rear_data = tmp_node.get_data()
                pre_tmp_node.set_next(None)
                self._tail_node = pre_tmp_node
            else:
                # Increment Node
                pre_tmp_node = pre_tmp_node.get_next()
                tmp_node = tmp_node.get_next()
                # Set Data
                tmp_data = tmp_node.get_data()
                pre_tmp_data = pre_tmp_node.get_data()

    def get_rear(self):
        return self._tail_node.get_data()

    def get_front(self):
        return self._list.get_data()
    
    def traverse(self):
        x = self._list.get_head_node()
        while(x != None):
            print(x.get_data())
            x.set_next(x.get_next())