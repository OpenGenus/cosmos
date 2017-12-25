# B.E.N.J.I.

<h1 align="center">
  <img width="400" src="https://raw.githubusercontent.com/the-ethan-hunt/B.E.N.J.I./master/benji_final.ico">
  <br>
  <br>
</h1>

### The "***launch***" command

The "***launch*** _ApplicationName_" command works on the basis of the "data.csv" file.
The present content of the file is:

>text,gedit
>office,libreoffice
>calc,gnome-calculator
>chrome,google-chrome
>google chrome,google-chrome
>firefox,firefox
>mozilla firefox,firefox
>calendar,gnome-calendar
>terminal,gnome-terminal

The first word of every line is the _ApplicationName_ in the "***launch*** _ApplicationName_" command and the second word is the name of the application installed on your system.

For example:

* If you say _launch chrome_, Google Chrome will be launched.
* If you say _launch text_, Gedit (which is the default text editor on Ubuntu) will be launched. 

So right now, you can launch Gedit, Libre Office, Calculator, Google Chrome, Mozilla Firefox, Calendar and terminal.

In case you want to change the associated command, or if your system has different application installed, you can change the file as per your need.
(For instance, KDE based Kubuntu uses tilix as the command line application)

> To know the name of the application installed on your system, open up terminal and type "***dpkg --list***" and press enter.

To edit the commands, just open "_data.csv_" file in this folder using any text editor or any spreadsheet application like "_LibreOffice Calc_" and edit the file. Say my system uses "_tilix_" as the terminal and I want to add "_Visual Studio Code_" for the command "***coding***" then I will do the following:

1. Open up "_data.csv_" using "Gedit".
2. Change name of the application for the command ***terminal*** from _gnome-terminal_ to _tilix_.
3. Open up terminal or tilix and type "***dpkg --list***" to find out the name by which my system identifies "_Visual Studio Code_". On doing so, I find that my system identifies it by the name "_code_". So I will add a new line in _data.csv_ as follows:

>coding,code

After all the above changes, save the file.
So new content of "_data.csv_" will be as below:

>text,gedit
>office,libreoffice
>calc,gnome-calculator
>chrome,google-chrome
>google chrome,google-chrome
>firefox,firefox
>mozilla firefox,firefox
>calendar,gnome-calendar
>terminal,tilix
>coding,code
