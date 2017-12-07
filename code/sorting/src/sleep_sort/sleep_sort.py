# Part of Cosmos by OpenGenus Foundation
import threading
import time

_lk = threading.Lock()


class sleep_sort_thread(threading.Thread):
    def __init__(self, val):
        self.val = val
        threading.Thread.__init__(self)

    def run(self):
        global _lk
        # Thread is made to sleep in proportion to value
        time.sleep(self.val * 0.1)
        # Acquire lock
        _lk.acquire()
        print(self.val, end=" ")
        # Release lock
        _lk.release()


def sleep_sort(list):
    ts = []

    # Intialize a thread corresponding to each element in list
    for i in list:
        t = sleep_sort_thread(i)
        ts.append(t)

    # Start all Threads
    for i in ts:
        i.start()

    # Wait for all threads to terminate
    for i in ts:
        i.join()


x = [2, 4, 3, 1, 6, 8, 4]
x = sleep_sort(x)
