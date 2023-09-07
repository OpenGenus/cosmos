import sys
from os import system


class checkip:

    # Initilaize IP
    def __init__(self, ip):
        ip = ip.strip().split(".")
        ip = [int(n) for n in ip]
        # set input ip to correct form of IP
        ip_correct = str(ip).strip("[]").replace(",", ".").replace(" ", "")
        self.ip_correct = ip_correct
        self.ip = ip
        self.flag = 1

    # Check if number of octed are correct or not
    def check_octed(self):
        if len(self.ip) != 4:
            print("worng number of octed")
            self.flag = 0
            return

    # Check if each octed number are in rang 0 to 255
    def check_digit(self):
        for i in range(4):
            if not (0 <= self.ip[i] <= 255):
                print(self.ip[i], " is not in range ")
                print("IP", self.ip_correct, " is NOT valid")
                self.flag = 0
                return
        # If correct print confiramtion
        if self.flag == 1:
            print("IP", self.ip_correct, " is valid")

    # Check if current system is connected to IP or not
    def check_connection(self):
        if self.flag == 1:
            exit_code = system("ping -c1 -s1 -W1 " + self.ip_correct)
            if exit_code != 0:
                print("IP ", self.ip_correct, " is not up")
            else:
                print("IP ", self.ip_correct, " is up")


ip = input()
ipn = checkip(ip)
ipn.check_octed()
ipn.check_digit()
ipn.check_connection()
