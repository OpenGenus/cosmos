# Introduction

This file is intended to give you a brief introduction on the working of B.E.N.J.I. and everything you need to know about it, 
including the steps you can take to set up your environment, solve an issue/bug and to follow the code of conduct. The 
project stands due to the support of the maintainers and valuable contributors. Read till the end and enter the amazing world 
of open-source.

# About B.E.N.J.I.

* It is a digital assistant built to give you functionality beyond your imagination. It supports both text and voice, with an 
easy to use GUI.

NOTE: This project is in its development phase.

# Setting up your environment

* B.E.N.J.I. uses python3.x. pip comes preinstalled with this version of python. B.E.N.J.I. uses multiple libraries. It 
becomes necessary to keep a track of these libraries. These libraries should be included in the "requirements.txt", which 
holds every 3<sup>rd</sup> party libraries. Apart from these libraries, sometimes it becomes necessary to install 
dependencies that are not available as a part of "pip". We need to install such dependencies using "normal installation".

NOTE: <b>"pip"</b> stands for "pip install packages".

* The first thing to be performed is to install the dependencies from the <b>requirements.txt</b>.
1) Go to the directory where the file exists.
2) Use the following command to install the dependencies
<i>pip install -r requirements.txt</i>
Generalized command: <b>pip install module_name</b>

NOTE: A dependency is a module that helps in extending functionality of the program. The module may be a part of 
"Python Standard Library" or a "3<sup>rd</sup> party library".

* The module is imported using the following command:
<b>import module_name</b>

* After using the module for extending functionality, it is must to edit the "requirements.txt" file so that others don't 
have to keep searching for the <b>new</b> 3<sup>rd</sup> party library.

* "activities.md" file should contain description of the added feature.

NOTE: If you see error "module not found", it is because you haven't installed the "3<sup>rd</sup> party library". If you 
see error "module not defined", it is because you have not imported that module.

# Solving an/a issue/bug

* If you find bug or any performance issues, then the developer can "open an issue" on GitHub.

NOTE: A discussion with the maintainer is requested.

* Important and repetitive issues will be answered in the FAQs.

* Topics related to the issue can be found on "Stack Overflow".

* Individual/collaborative efforts are welcomed.

# Take a note of

* Proper documentation should be done.
* Optimized code should be used.
* Feature intended to be added should not break earlier code.
* Respect every other individual.
* Any major changes to the project should be thoroughly discussed with the maintainers.
