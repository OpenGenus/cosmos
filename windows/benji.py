# coding: utf-8
import wx
import regex
import os
import wikipedia
import time 
import webbrowser
import youtube_dl 
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
    youtube_keywords = ["play ", "stream ", "queue "]
    launch_keywords = ["open ", "launch "]
    search_keywords = ["search "]
    wikipedia_keywords = ["wikipedia ", "wiki "]
    location_keywords = ["locate","spot"]
    check_keywords = ["what","when","was","how","has","had","should","would","can","could","cool","good"] #could or cool or good
    download_music=["download ","download music "]
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
    #Look for
    elif put.startswith('look for '):
        try:
            link1=put.split()
            name=link1[2]
            rex=regex.compile(name)
            filepath=link1[3]
            for root,dirs,files in os.walk(os.path.normpath(filepath)):
                for f in files:
                    result = rex.search(f)
                    if result:
                        print (os.path.join(root, f))
        except:
            print("Error")

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
    #Download music
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
         speak.speak("download completed Check your desktop for the song")
    #Location     
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
    #Google search
    elif any(word in put for word in search_keywords):
        try:
            link='+'.join(link[1:])
            say=link.replace('+',' ')
            speak.Speak("searching google for "+say)
            webbrowser.open('https://www.google.com/search?q='+link)
        except:
            print('Nope, this is not working.')        
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
    #Google Cloud Print
    elif put.startswith("google cloud print"):
        try:
            speak.Speak("Opening google cloud print!")
            webbrowser.open('https://www.google.com/cloudprint')
        except:
            print("Could not open Google Cloud Print!")        
    #Google Others
    elif put.startswith("google "):
        try:
            say = link[1]
            speak.Speak("Opening google " + say)
            webbrowser.open('https://'+ say +'.google.com')
        except:
            print("Could not open Google " + say.capitalize() + "!")        
	#Blogger
    elif put.startswith("blogger"):
        try:
            speak.Speak("Opening blogger!")
            webbrowser.open('https://www.blogger.com')
        except:
            print("Could not open Blogger!")
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
	#Podcast
    elif put.startswith("podcast"):
        try:
            speak.Speak("Opening podcast!")
            webbrowser.open('https://castbox.fm/home')
        except:
            print("Could not open podcast!")
    #Lock the device 
    elif put.startswith('secure '):
        try:
            speak.Speak("locking the device")
            ctypes.windll.user32.LockWorkStation()
        except :
            print('Cannot lock device')  
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
            speak.Speak('Our agents from ' + say + ' report this')
            print('  ====='+ say.upper() +'===== \n')
            i = 1
            for item in newsjson['articles']:
                print(str(i) + '. ' + item['title'] + '\n')
                print(item['description'] + '\n')
                i += 1
        except:
            print('Unable to retrieve data!')
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
    #Calculator
    elif put.startswith('calculator'):
        try:
            subprocess.call('calc',shell=True)
        except:
            print("Unable to open calculator!")        	

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

