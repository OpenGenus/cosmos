# coding: utf-8
import tkinter as tk
from tkinter import ttk
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
import sys
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
speak = pyttsx3.init()

def events(frame,put):
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
            speak.say("Note added successfully!")
            speak.runAndWait()
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
            speak.say("playing "+say)
            speak.runAndWait()
            webbrowser.open('https://www.youtube.com'+hit)
        except:
            print('Sorry Ethan. Looks like its not working!')
    #Download music
    elif any (word in put for word in download_music):
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
                                            'outtmpl': 'C:\\Users\\'+os.environ['USERNAME']+'\\Desktop\\%(title)s.%(ext)s'
                                            }

            ydl = youtube_dl.YoutubeDL(ydl_opts)
            ydl.download(['https://www.youtube.com'+hit])
            speak.say("download completed Check your desktop for the song")
            speak.runAndWait()
        except:
            print("Unable to download requested music!")    
    #Location     
    elif any(word in put for word in location_keywords):
        try:
            link='+'.join(link[1:])
            say=link.replace('+',' ')
            speak.say("locating "+ say)
            speak.runAndWait()
            webbrowser.open('https://www.google.nl/maps/place/'+link)
        except:
            print('The place seems to be sequestered.')
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
	#Google Images	
    elif put.startswith("images of "):
        try:
            link='+'.join(link[2:])
            say=link.replace('+',' ')
            speak.say("searching images of " + say)
            speak.runAndWait()
            webbrowser.open('https://www.google.co.in/search?q=' + link + '&source=lnms&tbm=isch')
        except:
            print('Could search for images!')	
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
            print('Wikipedia could not either find the article or your Third-world connection is unstable')
	#Podcast
    elif put.startswith("podcast"):
        try:
            speak.say("Opening podcast!")
            speak.runAndWait()
            webbrowser.open('https://castbox.fm/home')
        except:
            print("Could not open podcast!")
    #Lock the device 
    elif put.startswith('secure ') or put.startswith('lock '):
        try:
            speak.say("locking the device")
            speak.runAndWait()
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
            speak.say('Our agents from ' + say + ' report this')
            speak.runAndWait()
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
            if link[2].isdigit() and link[4].isdigit():
                if link[2] == "zero":
                    link[2] = "0"
                if link[4] == "zero":
                    link[4] = "0"    
                hours = int(link[2])
                minutes = int(link[4])
                time_seconds = 60 * minutes 
                time_seconds = time_seconds + hours * 3600	
                subprocess.call("shutdown /s /t {0}".format(str(time_seconds)), shell = True)
                speak.say("Shutdown initialized!")
                speak.runAndWait()
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
            speak.say("Shutdown cancelled!")
            speak.runAndWait()
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
            speak.say("Created" + filename)
            speak.runAndWait()
        except:
            print("Unable to create a file.")
    #Calculator
    elif put.startswith('calculator'):
        try:
            subprocess.call('calc',shell=True)
        except:
            print("Unable to open calculator!")        	

    elif put.startswith('exit') or put.startswith('quit'):
        sys.exit()

#A stdout class to redirect output to tkinter window
class StdRedirector(object):

    def __init__(self, text_window):
        self.text_window = text_window

    def write(self, output):
        self.text_window.insert(tk.END, output)
# Creating the graphical user interface
class MyFrame(tk.Frame):
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
        #root.bind('<Destroy>', self.onClose)
        self.textBox.focus_set()
        speak.say('''Hi Agent! BENJI at your service''')
        speak.runAndWait()

        self.photo1 = tk.PhotoImage(file="mic_icon.png")

        self.btn = ttk.Button(root,command=self.OnClicked,
        image=self.photo1, style="C.TButton")
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
            put=self.textBox.get("1.2","end-1c")
            self.displayText(put)
            self.textBox.insert('1.2',put)
            self.textBox.delete('1.2',tk.END)
            events(self, put)
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
            self.textBox.insert('1.2',put)
            self.textBox.delete('1.2',tk.END)
            events(self,put)
        except sr.UnknownValueError:
            self.displayText("Could not understand audio")
        except sr.RequestError as e:
            self.displayText("Could not request results; {0}".format(e))

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
