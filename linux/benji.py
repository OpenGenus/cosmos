# coding: utf-8
import wx
import re
import os
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
	youtube_keywords = ["play", "stream", "queue"]
	launch_keywords = ["open", "launch"]
	search_keywords = ["search", "google"]
	wikipedia_keywords = ["wikipedia", "wiki"]
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
		#Who are you?
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
	elif put.startswith('aljazeera '):
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
class MyFrame(wx.Frame):
		def __init__(self):
			wx.Frame.__init__(self,None,pos=wx.DefaultPosition,size=wx.Size(400,200), title="BENJI")
			panel=wx.Panel(self)
			ico= wx.Icon('benji_final.ico',wx.BITMAP_TYPE_ICO)
			self.SetIcon(ico)
			my_sizer=wx.BoxSizer(wx.VERTICAL)
			lbl=wx.StaticText(panel,label="Hello Agent! How can I help you")
			my_sizer.Add(lbl,0,wx.ALL,6)
			
			
			self.txt=wx.TextCtrl(panel,style=wx.TE_PROCESS_ENTER,size=(400,40))
			self.txt.Bind(wx.EVT_TEXT_ENTER,self.OnEnter)
			my_sizer.Add(self.txt,0,wx.ALL,6)
			
			self.btn = wx.Button(panel,6,"click to Speak")
			my_sizer.Add(self.btn,0,wx.ALIGN_CENTER,6)
			self.btn.Bind(wx.EVT_BUTTON,self.OnClicked) 
			panel.SetSizer(my_sizer)
			
			speak.say('''Hi Agent! BENJI at your service''')
			speak.runAndWait()
			self.Show()

		def OnEnter(self,event):
			put=self.txt.GetValue()
			self.txt.SetValue("")
			put=put.lower()
			put = put.strip()
			put = re.sub(r'[?|$|.|!]', r'', put)
			link=put.split()
			events(put,link)
			
			if put=='':
			   print('Reenter')
		 
		 #Play song on  Youtube

		def OnClicked(self,event):
#            time.sleep(4)
			r = sr.Recognizer()                                                                                   
			with sr.Microphone() as source:                                                                                                                                                        
				speak.say('Hey I am Listening ')
				speak.runAndWait()
				audio = r.listen(source)   
			try:
				put=r.recognize_google(audio)
				self.txt.SetValue(put)
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
    app = wx.App(True)
    frame= MyFrame()
    app.MainLoop()
