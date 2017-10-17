# ------------------
#   Part of cosmos from OpenGenus Foundations
# ------------------
import sys

"""
    Class FCFS accepts dictionary for processes
"""
class FCFS():
    def __init__(self, processes):
        self.processes = processes   # creating a variable for processes
        # initializing some private variables
        self.process = [x for x in self.processes]   # getting all process names
        self.__burst = [self.processes[x] for x in self.processes]  # getting bursttime of each
        # building list to get average waiting time
        self.__wtList = self.__buildWT()  # self.__buildWT() is a private method that is used to build a waiting time list
        # building list to get average turn arround time
        self.__taList = self.__buildTA() # self.__buildWT() is a private method that is used to build a turn arround time list
        pass


    def get_avg_wt(self):
        return round(sum(self.__wtList) / len(self.__wtList), 3) # getting average of waiting time upto 3 decimal places

    def get_avg_ta(self):
        return round(sum(self.__taList) / len(self.__wtList), 3) # getting average of waiting time upto 3 decimal places

    def print_process(self):
        print("FORMAT : process -> burst_time -> awaiting_time -> turn_arround_time",end="\n\n")
        for x in self.processes:
            print(x, self.processes[x], self.__wtList[x-1], self.__taList[x-1], sep=" -> ")
        pass

    def __buildWT(self):
        temp = [0]
        for x in (0, len(self.__burst) - 2):
            temp.append(temp[-1] + self.__burst[x])
            pass
        return temp

    def __buildTA(self):
        temp = [self.__burst[0]]
        for x in (1,len(self.__burst) - 1):
            temp.append(temp[-1] + self.__burst[x])
            pass
        return temp
    pass

# processes with key as process and value as burst time
process = {1:10, 2:5, 3:8}
fcfs = FCFS(process)
fcfs.print_process()
print("average waiting time : ", fcfs.get_avg_wt())
print("average turn arround time : ", fcfs.get_avg_ta())
