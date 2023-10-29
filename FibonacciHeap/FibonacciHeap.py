import math


def floor_log(x):
    return math.frexp(x)[1] - 1


class FibonacciTree:
    def __init__(self, value) -> None:
        self.value = value
        self.child = []
        self.order = 0

    def add_at_end(self, t):
        self.child.append(t)
        self.order = self.order + 1


class FibonacciHeap:
    def __init__(self) -> None:
        self.trees = []
        self.least = None
        self.count = 0

    def insert_node(self, value):
        new_tree = FibonacciTree(value)
        self.trees.append(new_tree)
        if self.least is None or value < self.least.value:
            self.least = new_tree
        self.count = self.count + 1

    def get_min(self):
        if self.least is None:
            return None
        return self.least.value

    def extract_min(self):
        smallest = self.least
        if smallest is not None:
            for child in smallest.child:
                self.trees.append(child)
            self.trees.remove(smallest)
            if self.trees == []:
                self.least = None
            else:
                self.least = self.trees[0]
                self.consolidate()
            self.count = self.count - 1
            return smallest.value
        return None

    def consolidate(self):
        aux = (floor_log(self.count) + 1) * [None]

        while self.trees:
            tree_1 = self.trees[0]
            order = tree_1.order
            self.trees.remove(tree_1)
            while aux[order] is not None:
                tree_2 = aux[order]
                if tree_1.value > tree_2.value:
                    tree_1, tree_2 = tree_2, tree_1
                tree_1.add_at_end(tree_2)
                aux[order] = None
                order = order + 1
            aux[order] = tree_1

        self.least = None
        for k in aux:
            if k is not None:
                self.trees.append(k)
                if self.least is None or k.value < self.least.value:
                    self.least = k


fibonacci_heap = FibonacciHeap()

fibonacci_heap.insert_node(7)
fibonacci_heap.insert_node(3)
fibonacci_heap.insert_node(17)
fibonacci_heap.insert_node(24)

print("the minimum value of the fibonacci heap: {}".format(fibonacci_heap.get_min()))

print("the minimum value removed: {}".format(fibonacci_heap.extract_min()))
