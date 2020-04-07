# ------------------
#   Part of cosmos from OpenGenus Foundations
# ------------------
import sys

"""
    Class FCFS accepts dictionary for __processes
"""


class FCFS:
    def __init__(self, processes):
        # initializing private method
        self.__processes = processes  # colling processes
        self.__wtList = self.__wtl()  # self.__wtl() returns a list of waiting_time
        self.__taList = self.__tal()  # self.__tal() returns a list of turn_arround_time
        pass

    # Print() prints details about the processes
    def Print(self):
        l = 0  # local variable used to print elements in list
        print(
            "FORMAT : process_name -> arrival_time -> burst_time -> waiting_time -> turn_arround_time\n"
        )
        for process in self.__processes:
            print(
                process,
                self.__processes[process][0],
                self.__processes[process][1],
                self.__wtList[l],
                self.__taList[l],
                sep=" -> ",
            )
            l += 1  # incrementing the list
            pass
        pass

    # Print_Chat() prints the gantt chart for the FCFS
    def Print_Chat(self):
        for (
            process
        ) in (
            self.__processes
        ):  # creating line | separates the process and = indicates the burst_time
            print("=" * self.__processes[process][1], "|", end="", sep="")
            pass
        print()
        temp = 0
        # printing the waiting_time
        for process in self.__processes:
            temp += self.__processes[process][1]
            print(" " * self.__processes[process][1], temp, end="", sep="")
            pass
        print("\n")
        pass

    # Method that returns the average waiting_time upto 3 decimal places
    def get_avg_wt(self):
        return round(sum(self.__wtList) / len(self.__wtList), 3)

    # Method that returns the average turn_arround_time upto 3 decimal places
    def get_avg_ta(self):
        return round(sum(self.__taList) / len(self.__taList), 3)

    # Private method to build a list of waiting_time
    def __wtl(self):
        temp = []
        for x in self.__processes:
            if len(temp) == 0:
                temp.append(0)
                pass
            else:
                temp.append(temp[-1] + self.__processes[x][1])
                pass
            pass
        return temp

    # Private method to build a list of turn_arround_time
    def __tal(self):
        temp = []
        for x in self.__processes:
            if len(temp) == 0:
                temp.append(self.__processes[x][1])
                pass
            else:
                temp.append(temp[-1] + self.__processes[x][1])
                pass
            pass
        return temp

    pass


# processes with key as process and value as list having 0th index = arrival time and 1st index = burst time
process = {"P01": [0, 4], "P02": [1, 5], "P03": [2, 8], "P04": [3, 3]}
fcfs = FCFS(process)
print("<--=[printing process]=-->")
fcfs.Print()
print("\n<--=[printing gantt chart]=-->")
fcfs.Print_Chat()
print("average waiting time : ", fcfs.get_avg_wt())
print("average turn arround time : ", fcfs.get_avg_ta())
