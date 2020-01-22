from Node import Node

class LinkedList:
    def __init__(self, data):
        self._head = Node(data)  # Head Node
        self._count = 1
        self_tail = None

    def insert_as_head(self, data):
        new_node = Node(data)
        new_node.set_next(self._head)
        self._head = new_node
        self._count += 1

    def insert_after(self,node, data):
        new_node = Node(data)
        new_node.set_next(node.get_next())
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

    def remove_node(self,data):
        #Like Pointer and pre ptr
        pre_tmp_node = self.get_head_node()
        pre_tmp_data = self.get_head_node().get_data()
        tmp_node = self.get_head_node().get_next()
        tmp_data = tmp_node.get_data()
        
        while(True):
            if(pre_tmp_node == None): # TODO
                break
            if(tmp_data == data):
                pre_tmp_node.set_next(tmp_node.get_next())
            else:
                # Increment Node
                pre_tmp_node = pre_tmp_node.get_next()
                tmp_node = tmp_node.get_next()
                # Set Data
                tmp_data = tmp_node.get_data()
                pre_tmp_data = pre_tmp_data.get_data()

    def get_count():
        return self._count
