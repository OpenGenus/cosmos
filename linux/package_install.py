import subprocess
import sys

def toString(byte):
    return byte.decode("utf-8").strip()

def run(args) :
    process = subprocess.Popen(args, stderr=subprocess.PIPE, stdout=subprocess.PIPE)
    return process.communicate()


def runrealtime(args) :
    process = subprocess.Popen(args, stderr=subprocess.PIPE, stdout=subprocess.PIPE)
    while process.poll() is None :
        output = process.stdout.readline().decode("utf-8").strip()
        print(output)
    
    return process.communicate()   

#
#checking for python version 3
#
output, error = run(["python3", "--version"])

if len(error) != 0 :
    #python 3 is not installed
    print("install python 3")
    sys.exit(1)
    
#
#checking if pip installed
#
print("checking if pip installed...")
output, error = run(["pip3", "--version"])

if len(error) != 0 :
    #pip not installed
    print("pip not installed")
else :
    #pip is installed. proceed further.
    print("pip is installed")
   
#
#Upgrade setuptools and wheel
#
print("upgrading setuptools and wheel...")
output, error = runrealtime(["python3", "-m", "pip", "install", "--upgrade", "pip", "setuptools", "wheel"])
if len(error) != 0 :
    print(toString(error))
    sys.exit(1)
    
#
# install packages from requirement.txt
#
print("installing required packages...")
output, error = runrealtime(["pip3", "install", "-r", "requirements-linux.txt"])
if len(error) != 0 :
    print(toString(error))
    sys.exit(1)


