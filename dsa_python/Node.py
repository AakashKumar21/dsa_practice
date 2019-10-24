class Node:
    def __init__(self, data=None, Next=None):
        self._data = data
        self._next = Next

    # Getters
    def get_data(self):
        return self._data

    def get_next(self):
        return self._next

    # Setters
    def set_data(self, data):
        self._data = data

    def set_next(self, Next):
        self._next = Next

    def is_tail(self):
        return self._next is None
