import tkinter as tk
from tkinter import ttk
from PIL import ImageTk
from PIL import Image 
from tkinter import PhotoImage
import os
from os.path import join
import subprocess
import re
import wikipedia
import time
import webbrowser
import json
import requests
import ctypes
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
from os import system

requests.packages.urllib3.disable_warnings()
try:
		_create_unverified_https_context=ssl._create_unverified_context
except 'AttributeError':
		pass
else:
		ssl._create_default_https_context=_create_unverified_https_context

headers = {'''user-agent':'Chrome/53.0.2785.143'''}


#speak = pyttsx3.init()


def events(frame, put,link):
	"""Identifies the event to be performed."""
	identity_keywords = ["who are you", "who r u", "what is your name"]
	youtube_keywords = ["play ", "stream ", "queue " , "youtube"]
	launch_keywords = ["open "]
	search_keywords = ["search ", "google "]
	wikipedia_keywords = ["wikipedia ", "wiki "]
	reminder_keywords = ["set a reminder" , "reminder"]
	calculator_keywords=["calculator","calc"]
	location_keywords = ["locate","spot"]
	translate_keywords = ["translate"]
	launcher_keywords = ["launch"]
	create_keywords = ["create" , "make"]
	note_keywords = ["note" , "node" , "not"]
	
	# Translate
	if any ( word in put for word in translate_keywords):
		try:
			lan = link[-1]
			link ='+'.join(link[1:-2])
			lang = "en"
			say=link.replace('+',' ') 
			print(say)
			if ( lan == "spanish" ):
				lang = "es" 
			elif ( lan == "french" ):
				lang = "fr"
			elif ( lan == "italian" ):
				lang = "it"
			elif ( lan == "hindi" ):
				lang = "hi" 
			elif ( lan == "dutch" ):
				lang = "nl" 
			elif (lan == "german" ):
				lang = "ge" 
			elif (lan == "polish" ):
				lang = "pl" 
			elif (lan == "portuguese" ):
				lang = "pt" 
			elif (lan == "chinese" ):
				lang = "zh-CN"
			elif (lan == "bengali" ):
				lang = "bn" 
			elif (lan == "arabic" ):
				lang = "ar"
			elif (lan == "japanese" ):
				lang = "ja" 
			system("say translating "+say)
			print('https://translate.google.com/#en/'+lang+'/'+link)
			webbrowser.open('https://translate.google.com/#en/'+lang+'/'+link)
		except:
			system('say Sorry , I coudnt translate.')
			print('Sorry , I coudnt translate.')
	
	#create a file
	elif any(word in put for word in create_keywords):
		try:
			fn = link[1]
			ft = link[2]
			if ft == "text":
				fn = fn + ".txt"
			elif ft == "powerpoint":
				fn = fn + ".pptx"
			elif ft == "excel":
				fn = fn + ".xlsx"
			elif ft == "pdf" :
				fn = fn + ".pdf"
			os.system("touch "+fn)
			system("say creating file")
		except:
			frame.displayText('Sorry , cannot create file')
	#create a note
	elif any(word in put for word in note_keywords):
		try:
			link='+'.join(link[1:])
			say=link.replace('+',' ')
			os.system("echo "+say+" >text.txt")
			system("creating note")
		except:
			frame.displayText('Sorry , cannot create note')
    #application launcher
	elif any(word in put for word in launcher_keywords):
		try:
			link = '+'.join(link[1:])
			system("say opening "+link)
			file = "/Applications/" + link +".app"
			subprocess.call(["open",file])
		except:
			frame.displayText('Sorry , cannot open '+link)

	#reminder
	elif any(word in put for word in reminder_keywords):
		try:
			system("say Opening Reminders")
			file = "/Applications/Reminders.app"
			subprocess.call(["open",file])
		except:
			frame.displayText('Sorry , cannot open reminders')
			system('say Sorry , cannot open reminders')
   
	#shut down the device
	elif put.startswith('secure'):
		try:
			system("say locking the device")
			os.system("sudo shutdown -h now")
			#subprocess.call(['osascript', '-e','tell app "System Events" to shut down'])
		except :
			frame.displayText('Cannot shut down the device')
	
	#Calculator
	elif any(word in put for word in calculator_keywords):
		try:
			system("say Opening Calaculator")
			file = "/Applications/Calculator.app"
			subprocess.call(["open",file])
		except:
			frame.displayText('Care to try again?')



	#Open a webpage
	elif any(word in put for word in launch_keywords):
		try:
			link = '+'.join(link[1:])
			system("say opening "+link)
			
			webbrowser.open('http://www.'+ link)
		except:
			frame.displayText('Sorry Ethan,unable to access it. Cannot hack either-IMF protocol!')

	
	#Google search
	elif any(word in put for word in search_keywords):
		try:
			link='+'.join(link[1:])
			say=link.replace('+',' ')
			system("say searching google for "+say)
			
			webbrowser.open('https://www.google.com/search?q='+link)
		except:
			frame.displayText('Nope, this is not working.')
	#Location     
	elif any(word in put for word in location_keywords):
		try:
			link='+'.join(link[1:])
			say=link.replace('+',' ')
			system("say locating "+ say)
			
			webbrowser.open('https://www.google.nl/maps/place/'+link)
		except:
			print('The place seems to be sequestered.')

	#Play song on Youtube
	elif any(word in put for word in youtube_keywords):
		try:
			link='+'.join(link[1:])
			say=link.replace('+',' ')
			system("say playing "+say)
			add = 'https://www.youtube.com/results?search_query=' + link
			#webbrowser.open('https://www.youtube.com/results?search_query='+link)
			system("say playing "+say)
			
			fhand=urllib.request.urlopen(add).read()
			soup = BeautifulSoup(fhand, "html.parser")
			songs = soup.findAll('div', {'class': 'yt-lockup-video'})
			hit = songs[0].find('a')['href']
#                   print(hit)
			
			
			webbrowser.open('https://www.youtube.com'+hit)
		
		except:
			frame.displayText('Sorry Ethan , looks like the link is not working')

	elif any(word in put for word in calculator_keywords):
		try:
			system("say Opening Calaculator")
			file = "/Applications/Calculator.app"
			subprocess.call(["open",file])
			 
			
		except:
			frame.displayText('Care to try again?')

	#BENJI
	elif any(word in put for word in identity_keywords):
		try:
			system("say I am BENJI, a digital assistant declassified for civilian use. Previously I was used by the Impossible Missions Force")
			
		except:
			frame.displayText('Error. Try reading the ReadMe to know about me!')
	#Google Images
	elif put.startswith("images of "):
		try:
			link='+'.join(link[2:])
			say=link.replace('+',' ')
			system("say searching images of " + say)
			webbrowser.open('https://www.google.co.in/search?q=' + link + '&source=lnms&tbm=isch')
		except:
			frame.displayText('Could search for images!')

	#Gmail
	elif put.startswith("gmail"):
		try:
			system("say Opening Gmail!")
			webbrowser.open('https://www.google.com/gmail')
		except:
			frame.displayText("Could not open Gmail!")
	#Google News
	elif put.startswith("google news"):
		try:
			system("say Opening google news!")
			webbrowser.open('https://news.google.com')
		except:
			frame.displayText("Could not open Google News!")
	#Google Translate
	elif put.startswith("google translate"):
		try:
			system("say Opening google translate!")
			webbrowser.open('https://translate.google.com')
		except:
			frame.displayText("Could not open Google Translate!")
	#Google Photos
	elif put.startswith("google photos"):
		try:
			system("say Opening google photos!")
			webbrowser.open('https://photos.google.com')
		except:
			frame.displayText("Could not open Google Photos!")
	#Google Drive
	elif put.startswith("google drive"):
		try:
			system("say Opening google drive!")
			webbrowser.open('https://drive.google.com')
		except:
			frame.displayText("Could not open Google Drive!")
	#Google Plus
	elif put.startswith("google plus"):
		try:
			system("say Opening google plus!")
			webbrowser.open('https://plus.google.com')
		except:
			frame.displayText("Could not open Google Plus!")
	#Google Forms
	elif put.startswith("google forms"):
		try:
			system("say Opening google forms!")
			webbrowser.open('https://docs.google.com/forms')
		except:
			frame.displayText("Could not open Google Forms!")
	#Google Document
	elif put.startswith("google document"):
		try:
			system("say Opening google docs!")
			webbrowser.open('https://docs.google.com/document')
		except:
			frame.displayText("Could not open Google Docs!")
	#Google Sheets
	elif put.startswith("google sheets"):
		try:
			system("say Opening google sheets!")
			webbrowser.open('https://docs.google.com/spreadsheets')
		except:
			frame.displayText("Could not open Google Sheets!")
	#Google Slides
	elif put.startswith("google slides"):
		try:
			system("say Opening google slides!")
			webbrowser.open('https://docs.google.com/presentation')
		except:
			frame.displayText("Could not open Google Slides!")
	#Google Groups
	elif put.startswith("google groups"):
		try:
			system("say Opening google groups!")
			webbrowser.open('https://groups.google.com')
		except:
			frame.displayText("Could not open Google Groups!")
	#Google Earth
	elif put.startswith("google earth"):
		try:
			system("say Opening google earth!")
			webbrowser.open('https://www.google.com/earth')
		except:
			frame.displayText("Could not open Google Earth!")
	#Google Cloud frame.displayText
	elif put.startswith("google cloud print"):
		try:
			system("say Opening google cloud print!")
			webbrowser.open('https://www.google.com/cloudprint')
		except:
			frame.displayText("Could not open Google Cloud Print!")
	#Google Fonts
	elif put.startswith("google fonts"):
		try:
			system("say Opening google fonts!")
			webbrowser.open('https://fonts.google.com')
		except:
			frame.displayText("Could not open Google Fonts!")

	#Blogger
	elif put.startswith("blogger"):
		try:
			system("say Opening blogger!")
			webbrowser.open('https://www.blogger.com')
		except:
			frame.displayText("Could not open Blogger!")
	
	#Wikipedia
	elif any(word in put for word in wikipedia_keywords):
		try:
			link = '+'.join(link[1:])
			say = link.replace('+', ' ')
			wikisearch = wikipedia.page(say)
			system("say Opening wikipedia page for" + say)
			
			webbrowser.open(wikisearch.url)
		except:
			frame.displayText('Wikipedia could not either find the article or your Third-world connection is unstable')

	#News of various press agencies
	elif put.startswith('al jazeera '):
		try:
			aljazeeraurl = ('https://newsapi.org/v1/articles?source=al-jazeera-english&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(aljazeeraurl)
			newsjson = newsresponce.json()
			system('say Our agents from Al-Jazeera report this')
			
			frame.displayText('  =====Al Jazeera===== \n')
			i = 1
			for item in newsjson['articles']:
				frame.displayText(str(i) + '. ' + item['title'] + '\n')
				frame.displayText(item['description'] + '\n')
				i += 1
		except:
			frame.displayText('Qatari agents have refused to share this intel, Ethan')
	elif put.startswith('bbc '):
		try:
			bbcurl = ('https://newsapi.org/v1/articles?source=bbc-news&sortBy=top&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(bbcurl)
			newsjson = newsresponce.json()
			system('say Our agents from BBC report this')
			
			frame.displayText('  =====BBC===== \n')
			i = 1
			for item in newsjson['articles']:
				frame.displayText(str(i) + '. ' + item['title'] + '\n')
				frame.displayText(item['description'] + '\n')
				i += 1
		except:
			frame.displayText('MI6 is going crazy! Not allowing this!')
	elif put.startswith('cricket '):
		try:
			cricketurl = ('https://newsapi.org/v1/articles?source=espn-cric-info&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(cricketurl)
			newsjson = newsresponce.json()
			system('say Our agents from ESPN Cricket report this')
			
			frame.displayText('  =====CRICKET NEWS===== \n')
			i = 1
			for item in newsjson['articles']:
				frame.displayText(str(i) + '. ' + item['title'] + '\n')
				frame.displayText(item['description'] + '\n')
				i += 1
		except:
			frame.displayText('Connection not secure')
	elif put.startswith('hindus '):
		try:
			hindusurl = ('https://newsapi.org/v1/articles?source=the-hindu&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(hindusurl)
			newsjson = newsresponce.json()
			system('say Our agents from Hindu News report this')
			frame.displayText('  =====HINDU===== \n')
			i = 1
			for item in newsjson['articles']:
				frame.displayText(str(i) + '. ' + item['title'] + '\n')
				frame.displayText(item['description'] + '\n')
				i += 1
		except:
			frame.displayText('error occured')



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
		#root.bind('<Destroy>', self.OnClose)
		self.textBox.focus_set()
		system("say Hi Agent! BENJI at your service")
		
		image = Image.open("mic_icon.png")
		self.photo1 = ImageTk.PhotoImage(image)

		self.btn = ttk.Button(root,command=self.OnClicked,image=self.photo1,style="C.TButton")
		self.btn.grid(row=1,column=2, padx=10, pady=20)
		
		'''
		self.output_window = tk.Toplevel()
		output_text_window = tk.Text(self.output_window)
		self.stddirec = StdRedirector(output_text_window)
		sys.stdout = self.stddirec
		output_text_window.pack()
		self.output_window.withdraw()
		'''

		

	def OnEnter(self,event):
		"""Identifies the text and sends it for display to displayText."""
			put=self.textBox.get("1.2","end-1c")
			print(put)
			self.textBox.delete('1.2',tk.END)
			put=put.lower()
			put = put.strip()
			#put = re.sub(r'[?|$|.|!]', r'', put)
			link=put.split()
			events(self, put,link)
			if put=='':
			   self.displayText('Reenter')

	def OnClicked(self):
		"""Recognizes the audio and sends it for display to displayText."""
		r = sr.Recognizer()
		with sr.Microphone() as source:
			system('say Hey I am Listening ')
			
			audio = r.listen(source)
		try:
			put=r.recognize_google(audio)

			self.displayText(put)
			self.textBox.insert('1.2',put)
			put=put.lower()
			put = put.strip()
			#put = re.sub(r'[?|$|.|!]', r'', put)
			link=put.split()
			events(self,put,link)
		except sr.UnknownValueError:
			self.displayText("Could not understand audio")
		except sr.RequestError as e:
			self.displayText("Could not request results; {0}".format(e))

	

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
	
	root.title('B.E.N.J.I.')
	root.configure(background="#444")
	root.resizable(0,0)
	root.mainloop()

