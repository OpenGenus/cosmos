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
requests.packages.urllib3.disable_warnings()
try:
		_create_unverified_https_context=ssl._create_unverified_context
except 'AttributeError':
		pass
else:
		ssl._create_default_https_context=_create_unverified_https_context

headers = {'''user-agent':'Chrome/53.0.2785.143'''}
#speak=wicl.Dispatch("SAPI.SpVoice")

# Creating the graphical user interface

speak = pyttsx3.init()

def events(put,link):
	identity_keywords = ["who are you", "who r u", "what is your name"]
	youtube_keywords = ["play ", "stream ", "queue "]
	launch_keywords = ["open ", "launch "]
	search_keywords = ["search ", "google "]
	wikipedia_keywords = ["wikipedia ", "wiki "]
	download_music=["download","download music"]
 #Play song on  Youtube
	if any(word in put for word in youtube_keywords):
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
			print('Sorry Ethan. Looks like its not working!')
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
         speak.Speak("downloading "+say)
         ydl_opts = {
                        'format': 'bestaudio/best',
                        'postprocessors': [{
                                            'key': 'FFmpegExtractAudio',
                                            'preferredcodec': 'mp3',
                                            'preferredquality': '192',
                                            }],
                                            'quiet': True,
                                            'restrictfilenames': True,
                                            'outtmpl': 'C:\\Users\\'+os.environ['USERNAME']+'\\Desktop\\%(title)s.%(ext)s'
                                            }

         ydl = youtube_dl.YoutubeDL(ydl_opts)
         ydl.download(['https://www.youtube.com'+hit])
         speak.speak("download completed.Check your desktop for the song")
         
	elif any(word in put for word in identity_keywords):
		try:
			speak.say("I am BENJI, a digital assistant declassified for civilian use. Previously I was used by the Impossible Missions Force")
			speak.runAndWait()
		except:
			print('Error. Try reading the ReadMe to know about me!')
	#Open a webpage
	elif any(word in put for word in launch_keywords):
		try:
			link = '+'.join(link[1:])
			speak.say("opening "+link)
			speak.runAndWait()
			webbrowser.open('http://www.'+ link)
		except:
			print('Sorry Ethan,unable to access it. Cannot hack either-IMF protocol!')
	#Google Images	
	elif put.startswith("images of "):
		try:
			link='+'.join(link[2:])
			say=link.replace('+',' ')
			speak.Speak("searching images of " + say)
			webbrowser.open('https://www.google.co.in/search?q=' + link + '&source=lnms&tbm=isch')
		except:
			print('Could search for images!')	
	#Gmail		
	elif put.startswith("gmail"):
		try:
			speak.Speak("Opening Gmail!")
			webbrowser.open('https://www.google.com/gmail')
		except:
			print("Could not open Gmail!")
	#Google News
	elif put.startswith("google news"):
		try:
			speak.Speak("Opening google news!")
			webbrowser.open('https://news.google.com')
		except:
			print("Could not open Google News!")	
	#Google Translate
	elif put.startswith("google translate"):
		try:
			speak.Speak("Opening google translate!")
			webbrowser.open('https://translate.google.com')
		except:
			print("Could not open Google Translate!")
	#Google Photos	
	elif put.startswith("google photos"):
		try:
			speak.Speak("Opening google photos!")
			webbrowser.open('https://photos.google.com')
		except:
			print("Could not open Google Photos!")
	#Google Drive
	elif put.startswith("google drive"):
		try:
			speak.Speak("Opening google drive!")
			webbrowser.open('https://drive.google.com')
		except:
			print("Could not open Google Drive!")			
	#Google Plus	
	elif put.startswith("google plus"):
		try:
			speak.Speak("Opening google plus!")
			webbrowser.open('https://plus.google.com')
		except:
			print("Could not open Google Plus!")
	#Google Forms
	elif put.startswith("google forms"):
		try:
			speak.Speak("Opening google forms!")
			webbrowser.open('https://docs.google.com/forms')
		except:
			print("Could not open Google Forms!")
	#Google Document
	elif put.startswith("google document"):
		try:
			speak.Speak("Opening google docs!")
			webbrowser.open('https://docs.google.com/document')
		except:
			print("Could not open Google Docs!")
	#Google Sheets
	elif put.startswith("google sheets"):
		try:
			speak.Speak("Opening google sheets!")
			webbrowser.open('https://docs.google.com/spreadsheets')
		except:
			print("Could not open Google Sheets!")
	#Google Slides
	elif put.startswith("google slides"):
		try:
			speak.Speak("Opening google slides!")
			webbrowser.open('https://docs.google.com/presentation')
		except:
			print("Could not open Google Slides!")
	#Google Groups
	elif put.startswith("google groups"):
		try:
			speak.Speak("Opening google groups!")
			webbrowser.open('https://groups.google.com')
		except:
			print("Could not open Google Groups!")
	#Google Earth
	elif put.startswith("google earth"):
		try:
			speak.Speak("Opening google earth!")
			webbrowser.open('https://www.google.com/earth')
		except:
			print("Could not open Google Earth!")
	#Google Cloud Print
	elif put.startswith("google cloud print"):
		try:
			speak.Speak("Opening google cloud print!")
			webbrowser.open('https://www.google.com/cloudprint')
		except:
			print("Could not open Google Cloud Print!")
	#Google Fonts
	elif put.startswith("google fonts"):
		try:
			speak.Speak("Opening google fonts!")
			webbrowser.open('https://fonts.google.com')
		except:
			print("Could not open Google Fonts!")
	#Blogger
	elif put.startswith("blogger"):
		try:
			speak.Speak("Opening blogger!")
			webbrowser.open('https://www.blogger.com')
		except:
			print("Could not open Blogger!")
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
			print('Wikipedia could not either find the article or your Third-world connection is unstable')
	#Lock the device
	elif put.startswith('secure '):
		try:
			speak.say("locking the device")
			speak.runAndWait()
			ctypes.windll.user32.LockWorkStation()
		except :
			print('Cannot lock device')

	#News of various press agencies
	elif put.startswith('al jazeera '):
		try:
			aljazeeraurl = ('https://newsapi.org/v1/articles?source=al-jazeera-english&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(aljazeeraurl)
			newsjson = newsresponce.json()
			speak.say('Our agents from Al-Jazeera report this')
			speak.runAndWait()
			print('  =====Al Jazeera===== \n')
			i = 1
			for item in newsjson['articles']:
				print(str(i) + '. ' + item['title'] + '\n')
				print(item['description'] + '\n')
				i += 1
		except:
			print('Qatari agents have refused to share this intel, Ethan')
	elif put.startswith('bbc '):
		try:
			bbcurl = ('https://newsapi.org/v1/articles?source=bbc-news&sortBy=top&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(bbcurl)
			newsjson = newsresponce.json()
			speak.say('Our agents from BBC report this')
			speak.runAndWait()
			print('  =====BBC===== \n')
			i = 1
			for item in newsjson['articles']:
				print(str(i) + '. ' + item['title'] + '\n')
				print(item['description'] + '\n')
				i += 1
		except:
			print('MI6 is going crazy! Not allowing this!')
	elif put.startswith('cricket '):
		try:
			cricketurl = ('https://newsapi.org/v1/articles?source=espn-cric-info&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(cricketurl)
			newsjson = newsresponce.json()
			speak.say('Our agents from ESPN Cricket report this')
			speak.runAndWait()
			print('  =====CRICKET NEWS===== \n')
			i = 1
			for item in newsjson['articles']:
				print(str(i) + '. ' + item['title'] + '\n')
				print(item['description'] + '\n')
				i += 1
		except:
			print('Connection not secure')
	elif put.startswith('hindus '):
		try:
			hindusurl = ('https://newsapi.org/v1/articles?source=the-hindu&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(hindusurl)
			newsjson = newsresponce.json()
			speak.say('Our agents from Hindu News report this')
			speak.runAndWait()
			print('  =====HINDU NEWS===== \n')
			i = 1
			for item in newsjson['articles']:
				print(str(i) + '. ' + item['title'] + '\n')
				print(item['description'] + '\n')
				i += 1
		except:
			print('R&A W is blocking our reports, Ethan. Sorry! ')


i=0
class MyFrame(tk.Frame):
	def __init__(self,*args,**kwargs):
		tk.Frame.__init__(self,*args,**kwargs)
		self.textBox = tk.Text(root,height=1,width=50)
		self.textBox.pack()
		root.bind('<Return>', self.OnEnter)
		self.textBox.focus_set()
		speak.say('''Hi Agent! BENJI at your service''')
		speak.runAndWait()
		self.btn = tk.Button(root, text="Click to Speak",command=self.OnClicked).pack()

	def OnEnter(self,event):
			put=self.textBox.get("1.0","end-1c")
			self.textBox.delete('1.0',tk.END)
			put=put.lower()
			put = put.strip()
			#put = re.sub(r'[?|$|.|!]', r'', put)
			link=put.split()
			events(put,link)

			if put=='':
			   print('Reenter')

	def OnClicked(self):
		r = sr.Recognizer()
		with sr.Microphone() as source:
			speak.say('Hey I am Listening ')
			speak.runAndWait()
			audio = r.listen(source)
		try:
			put=r.recognize_google(audio)
			print(put)
			self.textBox.insert('1.0',put)
			put=put.lower()
			put = put.strip()
			#put = re.sub(r'[?|$|.|!]', r'', put)
			link=put.split()
			events(put,link)
		except sr.UnknownValueError:
			print("Could not understand audio")
		except sr.RequestError as e:
			print("Could not request results; {0}".format(e))


	#Trigger the GUI. Light the fuse!
if __name__=="__main__":
	root = tk.Toplevel()
	view = MyFrame(root)
	root.geometry('{}x{}'.format(400, 100))
	view.pack(side="top",fill="both",expand=False)
	root.iconphoto(True, tk.PhotoImage(file=os.path.join(sys.path[0],'benji_final.gif')))
	root.title('B.E.N.J.I.')
	root.resizable(0,0)
	root.mainloop()