import tkinter as tk
from tkinter import ttk
import re
import os
import wikipedia
import time
import webbrowser
import json
import requests
import ctypes
import youtube_dl
import random
import urllib
import ssl
from bs4 import BeautifulSoup
from urllib.request import urlopen
import speech_recognition as sr
import requests
import pyttsx3
import sys
import threading
from datetime import datetime
import errno
import subprocess
import csv

#requests.packages.urllib3.disable_warnings()
#try:
#		_create_unverified_https_context=ssl._create_unverified_context
#except 'AttributeError':
#		pass
#else:
#		ssl._create_default_https_context=_create_unverified_https_context

#headers = {'''user-agent':'Chrome/53.0.2785.143'''}
#speak=wicl.Dispatch("SAPI.SpVoice")
home_dir = os.environ['HOME']
#reminder settings
reminder_mode = 0
reminder_dirloc = home_dir
reminder_filedir = reminder_dirloc+'.B.E.N.J.I.'
reminder_filename = reminder_filedir + '/reminders.txt'
reminder = str()
# Creating the graphical user interface

speak = pyttsx3.init()


def events(frame, put):
	"""Identifies the event to be performed."""
	identity_keywords = ["who are you", "who r u", "what is your name"]
	open_keywords = ["open "]
	launcher_keywords = ["launch "]
	search_keywords = ["search ",]
	wikipedia_keywords = ["wikipedia ", "wiki "]
	reminder_keywords = ["set a reminder"]
	youtube = ("play","stream","queue")
	download = ("download","download music")
	search_pc= ("find","lookfor")
	close_keywords=("close ","over ","stop ","exit ")
	
	global reminder_mode
	
	put = put.lower()
	link = put.split()

	if reminder_mode or any(word in put for word in reminder_keywords) :
		try :
			if reminder_mode == 0 :
				try :
					os.makedirs(reminder_filedir)
					os.chmod(reminder_dirloc, 0o777)
				except OSError as e :
					if e.errno != errno.EEXIST :
						raise
				speak.say("Reminder of what?")
				speak.runAndWait()
				reminder_mode = 1
			elif reminder_mode == 1 :
				subject = ' '.join(link)
				global reminder
				reminder = subject + '\t'
				speak.say("When to remind you?")
				speak.runAndWait()
				reminder_mode = 2
			elif reminder_mode == 2 :
				reminder_mode = 0
				date_as_string = ' '.join(link)
				date = datetime.strptime(date_as_string, '%d %b %Y %I %M %p')
				reminder = reminder + date_as_string
				file_hand = open(reminder_filename, 'a')
				file_hand.write(reminder)
				file_hand.write('\n')
				file_hand.close()
				speak.say("Reminder Added")
				speak.runAndWait()
		except :
			frame.displayText("Cannot set reminder")

	#Play song on  Youtube
	elif put.startswith(youtube):
		try:
			link = '+'.join(link[1:])

#                   print(link)
			say = link.replace('+', ' ')
			url = 'https://www.youtube.com/results?search_query='+link
#                 webbrowser.open('https://www.youtube.com'+link)
			fhand=urllib.request.urlopen(url).read()
			soup = BeautifulSoup(fhand, "html.parser")
			songs = soup.findAll('div', {'class': 'yt-lockup-video'})
			hit = songs[0].find('a')['href']
#                   print(hit)
			speak.say("playing "+say)
			speak.runAndWait()
			webbrowser.open('https://www.youtube.com'+hit)
		except:
			frame.displayText('Sorry Ethan. Looks like its not working!')
	elif put.startswith(download):
		link = '+'.join(link[1:])
  #                   print(link)
		say = link.replace('+', ' ')
		url = 'https://www.youtube.com/results?search_query='+link
	 #                 webbrowser.open('https://www.youtube.com'+link)
		fhand=urllib.request.urlopen(url).read()
		soup = BeautifulSoup(fhand, "html.parser")
		songs = soup.findAll('div', {'class': 'yt-lockup-video'})
		hit = songs[0].find('a')['href']
	 #                   print(hit)
		speak.say("downloading "+say)
		speak.runAndWait()
		ydl_opts = {
				 'format': 'bestaudio/best',
				 'postprocessors': [{
						   'key': 'FFmpegExtractAudio',
						   'preferredcodec': 'mp3',
						   'preferredquality': '192',
						   }],
						   'quiet': True,
						   'restrictfilenames': True,
						   'outtmpl': home_dir+'/Desktop/%(title)s.%(ext)s'
						   }
 
		ydl = youtube_dl.YoutubeDL(ydl_opts)
		ydl.download(['https://www.youtube.com'+hit])
		speak.say("download completed.Check your desktop for the song")
		speak.runAndWait()
		#application launcher
	elif any(word in put for word in launcher_keywords):
		database_path = './data.csv'
		database_file = open(database_path, 'r')
		database = csv.reader(database_file)
		app = ' '.join(link[1:])
		app_name = ""
		checker = 0
		for row in database:
			if app == row[0]:
				app_name = row[1]
				checker = 1
		database_file.close()
		if checker == 1:
			try:
				speak.say("Opening" + app_name)
				speak.runAndWait()
				subprocess.run(app_name, shell = True, check = True)
			except:
				frame.displayText('Care to try again?')
		else:
			speak.say("Application not found in database")
			speak.runAndWait()
		#BENJI Intro
	elif any(word in put for word in identity_keywords):
		try:
			speak.say("I am BENJI, a digital assistant declassified for civilian use. Previously I was used by the Impossible Missions Force")
			speak.runAndWait()
		except:
			frame.displayText('Error. Try reading the ReadMe to know about me!')
	#Open a webpage
	elif any(word in put for word in open_keywords):
		try:
			link = '+'.join(link[1:])
			speak.say("opening "+link)
			speak.runAndWait()
			webbrowser.open('http://www.'+ link)
		except:
			frame.displayText('Sorry Ethan,unable to access it. Cannot hack either-IMF protocol!')
	#Closing Benji
	elif put.startswith(close_keywords):
		os._exit(0)

	#Google search
	elif any(word in put for word in search_keywords):
		try:
			link='+'.join(link[1:])
			say=link.replace('+',' ')
			speak.say("searching google for "+say)
			speak.runAndWait()
			webbrowser.open('https://www.google.com/search?q='+link)
		except:
			print('Nope, this is not working.')
	#Google Images
	elif put.startswith("images of "):
		try:
			link='+'.join(link[2:])
			say=link.replace('+',' ')
			speak.say("searching images of " + say)
			speak.runAndWait()
			webbrowser.open('https://www.google.co.in/search?q=' + link + '&source=lnms&tbm=isch')
		except:
			print('Could not search for images!')
	#Gmail
	elif put.startswith("gmail"):
		try:
			speak.say("Opening Gmail!")
			speak.runAndWait()
			webbrowser.open('https://www.google.com/gmail')
		except:
			print("Could not open Gmail!")
	#Google Cloud Print
	elif put.startswith("google cloud print"):
		try:
			speak.say("Opening google cloud print!")
			speak.runAndWait()
			webbrowser.open('https://www.google.com/cloudprint')
		except:
			print("Could not open Google Cloud Print!")
	#Google Others
	elif put.startswith("google "):
		try:
			say = link[1]
			speak.say("Opening google " + say)
			speak.runAndWait()
			webbrowser.open('https://'+ say +'.google.com')
		except:
			print("Could not open Google " + say.capitalize() + "!")
	#Blogger
	elif put.startswith("blogger"):
		try:
			speak.say("Opening blogger!")
			speak.runAndWait()
			webbrowser.open('https://www.blogger.com')
		except:
			print("Could not open Blogger!")
	#Wikipedia
	elif any(word in put for word in wikipedia_keywords):
		try:
			link = '+'.join(link[1:])
			say = link.replace('+', ' ')
			wikisearch = wikipedia.page(say)
			speak.say("Opening wikipedia page for" + say)
			speak.runAndWait()
			webbrowser.open(wikisearch.url)
		except:
			frame.displayText('Wikipedia could not either find the article or your Third-world connection is unstable')
	#Lock the device
	elif put.startswith('secure'):
		try:
			speak.say("locking the device")
			speak.runAndWait()
			subprocess.run("xdg-screensaver lock",shell=True,check=True)
		except :
			frame.displayText('Cannot lock device')

	#Finding and Opening files in pc

	elif put.startswith(search_pc):
		process=subprocess.Popen("find $HOME -name "+link[1],shell=True,stdout=subprocess.PIPE)
		stdout=process.communicate()[0]
		found=stdout.decode()
		frame.displayText(found)
		try:
			subprocess.run("xdg-open "+found,shell=True,check=True)
		except:
			speak.say("Sorry,couldn't open")

	#News of various press agencies

	elif put.startswith('news '):
		try:
			say = '+'.join(link[1:])
			say = say.replace('+','-')
			if link[1] == "al" and link[2] == "jazeera":
				say += "-english"
			elif link[1] == "bbc":
				say += "-news"
			elif link[1] == "espn" and link[2] == "cric":
				say += "-info"
			url = ('https://newsapi.org/v1/articles?source=' + say + '&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(url)
			newsjson = newsresponce.json()
			speak.say('Our agents from ' + say + ' report this')
			speak.runAndWait()
			frame.displayText('  ====='+ say.upper() +'===== \n')
			i = 1
			for item in newsjson['articles']:
				frame.displayText(str(i) + '. ' + item['title'] + '\n')
				frame.displayText(item['description'] + '\n')
				i += 1
		except:
			print('Unable to retrieve data!')
			
	#Controlling wifi Adapter
	elif put.startswith('wifi '):
		word = link[1]
		if word=="enable":
			os.system("nmcli radio wifi on")
			speak.say("Enabling Wifi")
			speak.runAndWait()
		elif word=="disable":
			os.system("nmcli radio wifi off")
			speak.say("Disabling Wifi")
			speak.runAndWait()
			
	#print files
	elif put.startswith('print '):
		process=subprocess.Popen("find $HOME -name "+link[1],shell=True,stdout=subprocess.PIPE)
		stdout=process.communicate()[0]
		found=stdout.decode()
		try:
			subprocess.run("lpr "+found,shell=True,check=True)
		except:
			speak.say("Sorry,couldn't print")


class reminderThread(threading.Thread):
	"""A customized thread class for tracking reminders."""
	def __init__(self, frame):
		threading.Thread.__init__(self)
		self.event = threading.Event()
		self.reminder_given_flag = False
		self.frame = frame
		
	def run(self):
		"""Displays the upcoming reminders."""
		while not self.event.is_set() :
			upcoming_reminders = list()
			self.removePastReminders()
			try :
				#reading the reminders from reminders.txt
				file_hand = open(reminder_filename, 'r')
				reminder_list = file_hand.readlines()
				file_hand.close()
				for line in reminder_list :
					vals = line.split('\t')
					date_time = datetime.strptime(vals[1].replace('\n',''), '%d %b %Y %I %M %p')
					time_now = datetime.now()
					#getting diff between time now and the reminder
					time_diff = date_time - time_now
					time_diff_hour = time_diff.days * 24 + time_diff.seconds // 3600
					#if time diff less than 1 hour, add it to upcoming lists
					if time_diff_hour < 1 :
							upcoming_reminders.append(vals)
			except :
				pass
			if not self.reminder_given_flag and len(upcoming_reminders) > 0 :
				speak.say("You have " + str(len(upcoming_reminders))+" upcoming reminders")
				speak.runAndWait()
				for reminder in upcoming_reminders :
					#wx.CallAfter(self.frame.displayText, reminder[0]+'\t\t'+reminder[1])
					self.frame.displayText(reminder[0]+'\t\t'+reminder[1])
				self.reminder_given_flag = True
			time.sleep(1)

	def removePastReminders(self):
		"""Removes the past reminders."""
		try :
			file_hand = open(reminder_filename, 'r')
			reminder_list = file_hand.readlines()
			file_hand.close()
			new_list = list()
			for reminder in reminder_list :
				date_time = datetime.strptime(reminder.split('\t')[1].replace('\n',''), '%d %b %Y %I %M %p')
				time_diff = date_time - datetime.now()
				if time_diff.seconds >= 0 and time_diff.days >= 0 :
					new_list.append(reminder)
			file_hand = open(reminder_filename, 'w')
			for line in new_list :
				file_hand.write(line)
			file_hand.close()
		except FileNotFoundError :
			pass
		except :
			self.frame.displayText("Error occured")
i=0


class StdRedirector(object):
	"""A stdout class to redirect output to tkinter window."""
	def __init__(self, text_window):
		self.text_window = text_window

	def write(self, output):
		self.text_window.insert(tk.END, output)

class MyFrame(tk.Frame):
	"""Creates the graphical user interface."""
	def __init__(self,*args,**kwargs):
		"""Creates a new thread to track reminders."""
		global reminder_thread
		reminder_thread = reminderThread(self)
		tk.Frame.__init__(self,*args,**kwargs)

		self.textBox = tk.Text(root,
			height=1,width=30,
			font=("Times", 16),
			bg="#666", fg="#0f0",
			spacing1=6, spacing3=6,
			insertbackground="#0f0"
			)
		self.textBox.insert("1.0", "$>")
		self.textBox.grid(row=1,column=1, padx=10, pady=10)
		root.bind('<Return>', self.OnEnter)
		root.bind('<Destroy>', self.onClose)
		self.textBox.focus_set()
		speak.say('''Hi Agent! BENJI at your service''')
		speak.runAndWait()

		self.photo1 = tk.PhotoImage(file="mic_icon.png")

		self.btn = ttk.Button(root,command=self.OnClicked,
		image=self.photo1, style="C.TButton")
		self.btn.grid(row=1,column=2, padx=10, pady=20)
		reminder_thread.start()

	def OnEnter(self,event):
		"""Identifies the text and sends it for display to displayText."""
			put=self.textBox.get("1.2","end-1c")
			self.displayText(put)
			self.textBox.insert('1.2',put)
			self.textBox.delete('1.2',tk.END)
			events(self, put)
			if put=='':
				self.displayText('Reenter')

	def OnClicked(self):
		"""Recognizes the audio and sends it for display to displayText."""
		r = sr.Recognizer()
		with sr.Microphone() as source:
			speak.say('Hey I am Listening ')
			speak.runAndWait()
			audio = r.listen(source)
		try:
			put=r.recognize_google(audio)

			self.displayText(put)
			self.textBox.insert('1.2',put)
			self.textBox.delete('1.2',tk.END)
			events(self,put)
		except sr.UnknownValueError:
			self.displayText("Could not understand audio")
		except sr.RequestError as e:
			self.displayText("Could not request results; {0}".format(e))

	def onClose(self, event):
		"""Destroys the thread."""
			global reminder_thread
			reminder_thread.event.set()
			#root.destroy()

	def displayText(self, text):
		"""Displays the text in a output window."""
		try :
			if not self.output_window.winfo_viewable() :
				self.output_window.update()
				self.output_window.deiconify()
		except :
			self.createOutputWindow()
		print(text)

	def createOutputWindow(self):
		"""Creates a output window to display the text."""
		self.output_window = tk.Toplevel()
		output_text_window = tk.Text(self.output_window)
		self.stddirec = StdRedirector(output_text_window)
		sys.stdout = self.stddirec
		output_text_window.pack()

	#Trigger the GUI. Light the fuse!
if __name__=="__main__":
	root = tk.Tk()
	view = MyFrame(root)
	style = ttk.Style()
	style.configure('C.TButton',
		background='#555',
		highlightthickness='0'
	)
	style.map("C.TButton",
		background=[('pressed', '!disabled', '#333'), ('active', '#666')]
	)
	# root.geometry('{}x{}'.format(400, 100))
	# view.pack(side="top",fill="both",expand=False)
	root.iconphoto(True, tk.PhotoImage(file=os.path.join(sys.path[0],'benji_final.gif')))
	root.title('B.E.N.J.I.')
	root.configure(background="#444")
	root.resizable(0,0)
	root.mainloop()
