import tkinter as tk
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

requests.packages.urllib3.disable_warnings()
try:
		_create_unverified_https_context=ssl._create_unverified_context
except 'AttributeError':
		pass
else:
		ssl._create_default_https_context=_create_unverified_https_context

headers = {'''user-agent':'Chrome/53.0.2785.143'''}
#speak=wicl.Dispatch("SAPI.SpVoice")

#reminder settings
reminder_mode = 0
reminder_dirloc = '/home/arib/'
reminder_filedir = reminder_dirloc+'.B.E.N.J.I.'
reminder_filename = reminder_filedir + '/reminders.txt'
reminder = str()
# Creating the graphical user interface

speak = pyttsx3.init()

def events(frame, put,link):
	identity_keywords = ["who are you", "who r u", "what is your name"]
	youtube_keywords = ["play ", "stream ", "queue "]
	launch_keywords = ["open ", "launch "]
	search_keywords = ["search ", "google "]
	wikipedia_keywords = ["wikipedia ", "wiki "]
	download_music=["download","download music"]
  download_music = ["download","download music"]
	reminder_keywords = ["set a reminder"]
	
	global reminder_mode
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
				# global reminder
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
	elif any(word in put for word in youtube_keywords):
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
	elif any (word in put for word in download_music):
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
                                            'outtmpl': os.environ['HOME']+'/Desktop/%(title)s.%(ext)s'
                                            }

         ydl = youtube_dl.YoutubeDL(ydl_opts)
         ydl.download(['https://www.youtube.com'+hit])
         speak.say("download completed.Check your desktop for the song")
         speak.runAndWait()
	elif any(word in put for word in identity_keywords):
		try:
			speak.say("I am BENJI, a digital assistant declassified for civilian use. Previously I was used by the Impossible Missions Force")
			speak.runAndWait()
		except:
			frame.displayText('Error. Try reading the ReadMe to know about me!')
	#Open a webpage
	elif any(word in put for word in launch_keywords):
		try:
			link = '+'.join(link[1:])
			speak.say("opening "+link)
			speak.runAndWait()
			webbrowser.open('http://www.'+ link)
		except:
			frame.displayText('Sorry Ethan,unable to access it. Cannot hack either-IMF protocol!')
	#Google Images	
	elif put.startswith("images of "):
		try:
			link='+'.join(link[2:])
			say=link.replace('+',' ')
			speak.Speak("searching images of " + say)
			webbrowser.open('https://www.google.co.in/search?q=' + link + '&source=lnms&tbm=isch')
		except:
			frame.displayText('Could search for images!')	
	#Gmail		
	elif put.startswith("gmail"):
		try:
			speak.Speak("Opening Gmail!")
			webbrowser.open('https://www.google.com/gmail')
		except:
			frame.displayText("Could not open Gmail!")
	#Google News
	elif put.startswith("google news"):
		try:
			speak.Speak("Opening google news!")
			webbrowser.open('https://news.google.com')
		except:
			frame.displayText("Could not open Google News!")	
	#Google Translate
	elif put.startswith("google translate"):
		try:
			speak.Speak("Opening google translate!")
			webbrowser.open('https://translate.google.com')
		except:
			frame.displayText("Could not open Google Translate!")
	#Google Photos	
	elif put.startswith("google photos"):
		try:
			speak.Speak("Opening google photos!")
			webbrowser.open('https://photos.google.com')
		except:
			frame.displayText("Could not open Google Photos!")
	#Google Drive
	elif put.startswith("google drive"):
		try:
			speak.Speak("Opening google drive!")
			webbrowser.open('https://drive.google.com')
		except:
			frame.displayText("Could not open Google Drive!")			
	#Google Plus	
	elif put.startswith("google plus"):
		try:
			speak.Speak("Opening google plus!")
			webbrowser.open('https://plus.google.com')
		except:
			frame.displayText("Could not open Google Plus!")
	#Google Forms
	elif put.startswith("google forms"):
		try:
			speak.Speak("Opening google forms!")
			webbrowser.open('https://docs.google.com/forms')
		except:
			frame.displayText("Could not open Google Forms!")
	#Google Document
	elif put.startswith("google document"):
		try:
			speak.Speak("Opening google docs!")
			webbrowser.open('https://docs.google.com/document')
		except:
			frame.displayText("Could not open Google Docs!")
	#Google Sheets
	elif put.startswith("google sheets"):
		try:
			speak.Speak("Opening google sheets!")
			webbrowser.open('https://docs.google.com/spreadsheets')
		except:
			frame.displayText("Could not open Google Sheets!")
	#Google Slides
	elif put.startswith("google slides"):
		try:
			speak.Speak("Opening google slides!")
			webbrowser.open('https://docs.google.com/presentation')
		except:
			frame.displayText("Could not open Google Slides!")
	#Google Groups
	elif put.startswith("google groups"):
		try:
			speak.Speak("Opening google groups!")
			webbrowser.open('https://groups.google.com')
		except:
			frame.displayText("Could not open Google Groups!")
	#Google Earth
	elif put.startswith("google earth"):
		try:
			speak.Speak("Opening google earth!")
			webbrowser.open('https://www.google.com/earth')
		except:
			frame.displayText("Could not open Google Earth!")
	#Google Cloud frame.displayText
	elif put.startswith("google cloud print"):
		try:
			speak.Speak("Opening google cloud print!")
			webbrowser.open('https://www.google.com/cloudprint')
		except:
			frame.displayText("Could not open Google Cloud Print!")
	#Google Fonts
	elif put.startswith("google fonts"):
		try:
			speak.Speak("Opening google fonts!")
			webbrowser.open('https://fonts.google.com')
		except:
			frame.displayText("Could not open Google Fonts!")
	#Blogger
	elif put.startswith("blogger"):
		try:
			speak.Speak("Opening blogger!")
			webbrowser.open('https://www.blogger.com')
		except:
			frame.displayText("Could not open Blogger!")
	#Google search
	elif any(word in put for word in search_keywords):
		try:
			link='+'.join(link[1:])
			say=link.replace('+',' ')
			speak.say("searching google for "+say)
			speak.runAndWait()
			webbrowser.open('https://www.google.com/search?q='+link)
		except:
			frame.displayText('Nope, this is not working.')
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
	elif put.startswith('secure '):
		try:
			speak.say("locking the device")
			speak.runAndWait()
			ctypes.windll.user32.LockWorkStation()
		except :
			frame.displayText('Cannot lock device')

	#News of various press agencies
	elif put.startswith('al jazeera '):
		try:
			aljazeeraurl = ('https://newsapi.org/v1/articles?source=al-jazeera-english&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(aljazeeraurl)
			newsjson = newsresponce.json()
			speak.say('Our agents from Al-Jazeera report this')
			speak.runAndWait()
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
			speak.say('Our agents from BBC report this')
			speak.runAndWait()
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
			speak.say('Our agents from ESPN Cricket report this')
			speak.runAndWait()
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
			speak.say('Our agents from Hindu News report this')
			speak.runAndWait()
			frame.displayText('  =====HINDU NEWS===== \n')
			i = 1
			for item in newsjson['articles']:
				frame.displayText(str(i) + '. ' + item['title'] + '\n')
				frame.displayText(item['description'] + '\n')
				i += 1
		except:
			frame.displayText('R&A W is blocking our reports, Ethan. Sorry! ')

	# Finding files in pc
	elif put1.startswith('lookfor '):
			try:
				link1=put1.split()
				name=link1[1]
				rex=regex.compile(name)
				filepath=link1[2]
				for root,dirs,files in os.walk(os.path.normpath(filepath)):
					for f in files:
						result = rex.search(f)
						if result:
							print (os.path.join(root, f))
				
			except:
				print("Error")


#A customized thread class for tracking reminders
class reminderThread(threading.Thread):
	
	def __init__(self, frame):
		threading.Thread.__init__(self)
		self.event = threading.Event()
		self.reminder_given_flag = False
		self.frame = frame
		
	def run(self):
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

#A stdout class to redirect output to tkinter window
class StdRedirector(object):
	
	def __init__(self, text_window):
		self.text_window = text_window
		
	def write(self, output):
		self.text_window.insert(tk.END, output)
		
class MyFrame(tk.Frame):
	def __init__(self,*args,**kwargs):
		#new Thread to track reminders
		global reminder_thread
		reminder_thread = reminderThread(self)
		tk.Frame.__init__(self,*args,**kwargs)
		self.textBox = tk.Text(root,height=1,width=50)
		self.textBox.pack()
		root.bind('<Return>', self.OnEnter)
		root.bind('<Destroy>', self.onClose)
		self.textBox.focus_set()
		speak.say('''Hi Agent! BENJI at your service''')
		speak.runAndWait()
		self.btn = tk.Button(root, text="Click to Speak",command=self.OnClicked).pack()
		
		'''
		self.output_window = tk.Toplevel()
		output_text_window = tk.Text(self.output_window)
		self.stddirec = StdRedirector(output_text_window)
		sys.stdout = self.stddirec
		output_text_window.pack()
		self.output_window.withdraw()
		'''
		
		reminder_thread.start()
		
	def OnEnter(self,event):
			put=self.textBox.get("1.0","end-1c")
			self.textBox.delete('1.0',tk.END)
			put=put.lower()
			put = put.strip()
			#put = re.sub(r'[?|$|.|!]', r'', put)
			link=put.split()
			events(self, put,link)
			if put=='':
			   self.displayText('Reenter')

	def OnClicked(self):
		r = sr.Recognizer()
		with sr.Microphone() as source:
			speak.say('Hey I am Listening ')
			speak.runAndWait()
			audio = r.listen(source)
		try:
			put=r.recognize_google(audio)
			self.displayText(put)
			self.textBox.insert('1.0',put)
			put=put.lower()
			put = put.strip()
			#put = re.sub(r'[?|$|.|!]', r'', put)
			link=put.split()
			events(put,link)
		except sr.UnknownValueError:
			self.displayText("Could not understand audio")
		except sr.RequestError as e:
			self.displayText("Could not request results; {0}".format(e))
	
	def onClose(self, event):
			global reminder_thread
			reminder_thread.event.set()
			#root.destroy()
		
	def displayText(self, text):
		try :
			if not self.output_window.winfo_viewable() :
				self.output_window.update()
				self.output_window.deiconify()
		except :
			self.createOutputWindow()
		print(text)	

	def createOutputWindow(self):
		self.output_window = tk.Toplevel()
		output_text_window = tk.Text(self.output_window)
		self.stddirec = StdRedirector(output_text_window)
		sys.stdout = self.stddirec
		output_text_window.pack()
		
	#Trigger the GUI. Light the fuse!
if __name__=="__main__":
	root = tk.Tk()
	view = MyFrame(root)
	root.geometry('{}x{}'.format(400, 100))
	view.pack(side="top",fill="both",expand=False)
	root.iconphoto(True, tk.PhotoImage(file=os.path.join(sys.path[0],'benji_final.gif')))
	root.title('B.E.N.J.I.')
	root.resizable(0,0)
	root.mainloop()
