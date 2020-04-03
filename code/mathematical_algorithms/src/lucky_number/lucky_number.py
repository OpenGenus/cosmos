# -*- coding: utf-8 -*-
class Solution:
    def __init__(self):
        self.n = 0
        self.list = []
        self.jump = 2
        self.pointer = 1

    def lazynum(self):
        self.n = int(
            input("Enter the number to be checked for : ")
        )  # Take input number

        for i in range((self.n)):
            self.list.append(
                i + 1
            )  # create the list of all numbers up till n that will be processed later

        while len(self.list) >= self.jump:  # loop end condn
            toBeRemoved = (
                []
            )  # create a list for the numbers to be removed in a single pass
            for i in range(len(self.list)):  # ensure how long the loop operates
                if (
                    self.pointer <= len(self.list) - 1
                ):  # ensure that the pointer doesn't go out of range
                    toBeRemoved.append(
                        self.list[self.pointer]
                    )  # append the number at that index into the list
                    self.pointer = self.pointer + self.jump  # update pointer
            self.list = list(
                set(self.list).symmetric_difference(set(toBeRemoved))
            )  # update list
            self.jump = self.jump + 1
            self.pointer = self.jump - 1

        if self.n in self.list:
            return 1, self.n
        return 0, self.n


o = Solution()
value = o.lazynum()
if value[0] == 1:
    print(value[1], " is a lucky no.")
else:
    print(value[1], "is not a lucky no.")

        
        
        
