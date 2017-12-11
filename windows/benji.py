# coding: utf-8
import wx
import re
import os
import wikipedia
import time 
import webbrowser 
#import winshell
import json
import requests
import ctypes 
import random
import urllib
import ssl
from bs4 import BeautifulSoup
import win32com.client as wicl
from urllib.request import urlopen
import speech_recognition as sr
import requests
from pptx import Presentation
from xlsxwriter import Workbook
import subprocess

requests.packages.urllib3.disable_warnings()
try:
		_create_unverified_https_context=ssl._create_unverified_context
except 'AttributeError':
		pass
else:
		ssl._create_default_https_context=_create_unverified_https_context
		
headers = {'''user-agent':'Chrome/53.0.2785.143'''}
speak=wicl.Dispatch("SAPI.SpVoice")
# Creating the graphical user interface
i=0

def events(put):
	identity_keywords = ["who are you", "who r u", "what is your name"]
	youtube_keywords = ["play", "stream", "queue"]
	launch_keywords = ["open ", "launch "]
	search_keywords = ["search ", "google "]
	wikipedia_keywords = ["wikipedia ", "wiki "]
	location_keywords = ["locate","spot"]
	check_keywords = ["what","when","was","how","has","had","should","would","can","could","cool","good"] #could or cool or good
	
	link = put.split()

	#Add note
	if put.startswith("note") or put.startswith("not") or put.startswith("node"):
		try:
			check = link[1]
			username = os.getlogin()
			filename = "Notes.txt"
			f1 = open(r'''C:\Users\{0}\Desktop\{1}'''.format(username,filename),'a')
			link = '+'.join(link[1:])
			text = link.replace('+',' ')
			text = text[0].capitalize() + text[1:]
			if check in check_keywords:
				text += "?"
			else:
				text += "."	
			f1.write(text)
			f1.write("\n")
			f1.close()
			speak.Speak("Note added successfully!")
		except:
			print("Could not add the specified note!")	

	put = put.lower()
	put = put.strip()
	link = put.split()

	#Play song on youtube
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
			speak.Speak("playing "+say)
			webbrowser.open('https://www.youtube.com'+hit)
		except:
			print('Sorry Ethan. Looks like its not working!')
	#Location finder
	elif any(word in put for word in location_keywords):
		try:
			link='+'.join(link[1:])
			say=link.replace('+',' ')
			speak.Speak("locating "+ say)
			webbrowser.open('https://www.google.nl/maps/place/'+link)
		except:
			speak.Speak('The place seems to be sequestered.')
			print('The place seems to be sequestered.')
	#Who are you?
	elif any(word in put for word in identity_keywords):
		try: 
			speak.Speak("I am BENJI, a digital assistant declassified for civilian use. Previously I was used by the Impossible Missions Force")
		except:
			print('Error. Try reading the ReadMe to know about me!')
	#Open a webpage
	elif any(word in put for word in launch_keywords):
		try:
			link = '+'.join(link[1:])
			speak.Speak("opening "+link)
			webbrowser.open('http://www.'+ link)
		except:
			print('Sorry Ethan,unable to access it. Cannot hack either-IMF protocol!')
	#Google images	
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
			speak.Speak("searching google for "+say)
			webbrowser.open('https://www.google.com/search?q='+link)
		except:
			print('Nope, this is not working.')
	#Wikipedia
	elif any(word in put for word in wikipedia_keywords):
		try:
			link = '+'.join(link[1:])
			say = link.replace('+', ' ')
			wikisearch = wikipedia.page(say)
			speak.Speak("Opening wikipedia page for" + say)
			webbrowser.open(wikisearch.url)
		except:
			print('Wikipedia could not either find the article or your Third-world connection is unstable')
	#Lock the device 
	elif put.startswith('secure '):
		try:
			speak.Speak("locking the device")
			ctypes.windll.user32.LockWorkStation()
		except :
			print('Cannot lock device')  

	#News of various press agencies
	elif put.startswith('al jazeera '):
		try:
			aljazeeraurl = ('https://newsapi.org/v1/articles?source=al-jazeera-english&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3')
			newsresponce = requests.get(aljazeeraurl)
			newsjson = newsresponce.json()
			speak.Speak('Our agents from Al-Jazeera report this')
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
			speak.Speak('Our agents from BBC report this')
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
			speak.Speak('Our agents from ESPN Cricket report this')
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
			speak.Speak('Our agents from Hindu News report this')
			print('  =====HINDU NEWS===== \n')
			i = 1
			for item in newsjson['articles']:
				print(str(i) + '. ' + item['title'] + '\n')
				print(item['description'] + '\n')
				i += 1
		except:
			print('R&A W is blocking our reports, Ethan. Sorry! ')
	#shutdown after specific time
	elif put.startswith('shutdown after '):
		try:
			if not link[2].isdigit():
				hours = int('0')
			else:	 
				hours = int(link[2])
			minutes = int(link[4])
			time_seconds = 60 * minutes 
			time_seconds = time_seconds + hours * 3600	
			subprocess.call("shutdown /s /t {0}".format(str(time_seconds)), shell = True)
			speak.Speak("Shutdown initialized!")
		except:
			print("Please shutdown manually!")		
	#shutdown now
	elif put.startswith("shutdown now"):
		try:
			subprocess.call("shutdown /s /t 0", shell = True)
		except:
			print("Please shutdown manually!")			
	#abort shutdown
	elif put.startswith("cancel shutdown"):
		try:
			subprocess.call("shutdown /a", shell = True)
			speak.Speak("Shutdown cancelled!")
		except:
			print("Unable do cancel shutdown!")	
	#restart
	elif put.startswith("restart now"):
		try:
			subprocess.call("shutdown /r /t 0", shell = True)
		except:
			print("Unable do restart device!")		
	#create file
	elif put.startswith('create '):
		try:
			username = os.getlogin()
			filename = '+'.join(link[1:-2])
			filename = filename.replace('+','_').capitalize()
			if link[-2] == "text":
				filename += ".txt"
				f1 = open(r'''C:\Users\{0}\Desktop\{1}'''.format(username,filename),'a')
				f1.close()
			elif link[-2] == "word" or link[-2] == "world":
				filename += ".docx"
				f1 = open(r'''C:\Users\{0}\Desktop\{1}'''.format(username,filename),'a')
				f1.close() 
			elif link[-2] == "powerpoint" or link[-2] =="presentation":
				filename += ".pptx"
				prs = Presentation()
				title_slide_layout = prs.slide_layouts[0]
				slide = prs.slides.add_slide(title_slide_layout)
				os.chdir(r'''C:\Users\{0}\Desktop'''.format(username))	
				prs.save(filename)
			elif link[-2] == "excel" or link[-2] == "Excel":
				filename += ".xlsx"
				wb = Workbook(filename)
				ws = wb.add_worksheet()
				os.chdir(r'''C:\Users\{0}\Desktop'''.format(username))
				wb.close()
			elif link[-2] == "visio" or link[-2] == "vizio":
				filename += ".vsdx"
				f1 = open(r'''C:\Users\{0}\Desktop\{1}'''.format(username,filename),'a')
				f1.close()
			elif link[-2] == "rich" or link[-2] == "reach":
				filename += ".rtf"
				f1 = open(r'''C:\Users\{0}\Desktop\{1}'''.format(username,filename),'a')
				f1.close()	
				speak.Speak("Created" + filename)
		except:
			print("Unable to create a file.")	

class MyFrame(wx.Frame):
		def __init__(self):
			wx.Frame.__init__(self,None,pos=wx.DefaultPosition, size=wx.Size(400,200),style=wx.MINIMIZE_BOX| wx.SYSTEM_MENU | wx.CAPTION | wx.CLOSE_BOX | wx.CLIP_CHILDREN, title="BENJI")
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
			
			speak.Speak('''Hi Agent! BENJI at your service''')
			self.Show()
			self.Centre() 
			self.Fit() 
	 
		def OnEnter(self,event):
			put=self.txt.GetValue()
			self.txt.SetValue("")
			#put=put.lower()
			#put = put.strip()
			#put = re.sub(r'[?|$|.|!]', r'', put)
			#link=put.split()
			events(put)
			
			if put=='':
			   print('Reenter')
		 
		def OnClicked(self,event):
#            time.sleep(4)
			r = sr.Recognizer()                                                                                   
			with sr.Microphone() as source:                                                                                                                                                        
				speak.Speak('Hey I am Listening ')
				audio = r.listen(source)   
			try:
				put=r.recognize_google(audio)
				self.txt.SetValue(put)
				#put=put.lower()
				#put = put.strip()
				#put = re.sub(r'[?|$|.|!]', r'', put)
				#link=put.split()
				events(put)
				
			except sr.UnknownValueError:
				print("Could not understand audio")
			except sr.RequestError as e:
				print("Could not request results; {0}".format(e))

#    #Trigger the GUI. Light the fuse!
if __name__=="__main__":
	app = wx.App(True)
	frame= MyFrame()
	app.MainLoop()
