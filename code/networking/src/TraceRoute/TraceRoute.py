# Original source at https://github.com/AliasgarSabunwala/NetTracer 

# The Code -

# importing CSV file which will record the data we got from the TraceRoute
import csv 
    
# Column names 
Col= ['S.No', 'RTT-1', 'RTT-2', 'RTT-3','IP-Address'] 
    
# data rows of csv file 
rows = [ ['Nikhil', 'COE', '2', '9.0'], 
         ['Sanchit', 'COE', '2', '9.1'], 
         ['Aditya', 'IT', '2', '9.3'], 
         ['Sagar', 'SE', '1', '9.5'], 
         ['Prateek', 'MCE', '3', '7.8'], 
         ['Sahil', 'EP', '2', '9.1']] 
    
# name of csv file 
filename = "tracert_records.csv"
    
# writing to csv file 
with open(filename, 'w') as csvfile: 
    # creating a csv writer object 
    csvwriter = csv.writer(csvfile) 
        
    # writing the fields 
    csvwriter.writerow(Col) 
        
    # writing the data rows 
    csvwriter.writerows(rows)

import subprocess

#specify your cmd command, here tracert www.example.com

# here tracert is for windows, but it can be changed as and when needed
# like for Windows - cmdCommand = "tracert www.vitbhopal.ac.in" 
cmdCommand = "tracert www.vitbhopal.ac.in"   

process = subprocess.Popen(cmdCommand.split(), stdout=subprocess.PIPE)
output, error = process.communicate()

strR=output.decode()

# Converting string To List
def stringToList(string):
    listRes = list(string.split(" "))
    return listRes

print(stringToList(strR))
