# Ruby Installation Guide

*How to install Ruby on your machine*

### Installing RVM
First, before installing Ruby, you must install Ruby Version Manager (RVM). The simplest way to do this is to enter the following in the console:

`\curl -L https://get.rvm.io | bash -s stable`

Once this command has run, you must restart your terminal.

### Installing Ruby

Once you have installed RVM as above, you can now install the most recent version of Ruby. To do this, you must enter the command:

`rvm install ruby-2.4.2`

*Note: you must enter the most recent Ruby version, you can check the latest version <a href="https://www.ruby-lang.org/en/downloads/">here</a>.*

You may be asked to enter your password to complete the installation.

The final step is to ensure the RubyGems version is up to date. To do this type:

`gem update --system`

Now you have successfully installed and updated to the most recent version of Ruby!

Note: If you try install a old ruby version maybe you can get a ssl error. You can solve it with rvm install `ruby-x.x.x --disable-binaries`

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---

