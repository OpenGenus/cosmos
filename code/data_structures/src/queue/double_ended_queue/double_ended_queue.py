""" python programme for showing dequeue data sturcture in python """


""" class for queue type data structure having following methods"""


class Queue:
    def __init__(self):
        self.array = []  # ''' initialise empty array '''

    def front_enqueue(self, data):  # 	''' adding element from front '''
        self.array.insert(0, data)

    def front_dequeue(self):  #   ''' deleting element from front '''
        k = self.array[0]
        del self.array[0]

    def rear_dequeue(self):  # 	''' deleting element from rear '''
        k = self.array.pop()
        print(k)

    def rear_enqueue(self, data):  #  ''' adding element from rear '''
        self.array.append(data)

    def traverse(self):  # 	''' priting all array '''
        print(self.array)


queue = Queue()  # 	''' initialise Queue instance '''
queue.front_enqueue(5)
queue.front_enqueue(4)
queue.front_enqueue(3)
queue.front_enqueue(2)

queue.traverse()

queue.front_dequeue()

queue.traverse()

queue.rear_enqueue(5)
queue.rear_enqueue(4)
queue.rear_enqueue(3)
queue.rear_enqueue(2)

queue.traverse()

queue.rear_dequeue()
queue.rear_dequeue()

queue.traverse()
