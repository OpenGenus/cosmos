## Python Installation Guide for Linux

Most Linux Distros come pre-installed with python2, sometimes even python3. 

check by

```
python2 --version
```

if its not installed, install by

```
sudo dnf install python2
```

this also works

```
sudo apt-get install python2 
sudo apt-get install python3
sudo apt-get install python ...<tab> to see your options
```


# Cosmos Guides
> Your personal library of every algorithm and data structure code that you will ever encounter


---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---

#### Python Installation Guide
By default, most Linux distribution come pre-installed with Python package. To check the version of python available in your distro, open up your terminal and type 'python' to see which version of python 2 is installed on your system. While you type 'python 3' to see which version of python 3 in available in your system.

<p>If python is not installed in your system, you will visit the python download page:
<a href='https://www.python.org/downloads/source/'>Python Download Page.</a> </p>
After visiting the page, you will download the version of your choice (preferably Python 3), then change your terminal directory to where you downloaded the python package, unzip the tar file and change to the appropriate directory. You can run './configure', 'make' and then 'make install' for Debian.

<h6> OR </h6>
You can use any of the package manager available in to your linux distro like yum, apt-get etc to install python via terminal.

For Ubuntu user
Type the following command to install python version 2.x (2.7 is the latest but support to it ends by 2020):
$ sudo apt-get install python2.7.5
Type the following command to install python version 3.x (3.6 is the latest):
$ sudo apt-get install python3.1

For Red Hat/RHEL/CentOS Linux user
Type the following command:
$ sudo yum install python
OR
# yum install python


