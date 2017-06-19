# coding: utf-8
import wx,os,wikipedia,wolframalpha,time,webbrowser,winshell,json
import requests,ctypes,random,ssl
from bs4 import BeautifulSoup
import win32com.client as wicl
from urllib.request import urlopen
import speech_recognition as sr
import requests
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
class MyFrame(wx.Frame):
        def __init__(self):
            wx.Frame.__init__(self,None,pos=wx.DefaultPosition, size=wx.Size(400,100),style=wx.MINIMIZE_BOX| wx.SYSTEM_MENU | wx.CAPTION | wx.CLOSE_BOX | wx.CLIP_CHILDREN, title="BENJI")
            panel=wx.Panel(self)
            ico= wx.Icon('benji1.ico',wx.BITMAP_TYPE_ICO)
            self.SetIcon(ico)
            my_sizer=wx.BoxSizer(wx.VERTICAL)
            lbl=wx.StaticText(panel,label="Welcome to IMF,Ethan.See the world on a monitor, in a closet")
            my_sizer.Add(lbl,0,wx.ALL,6)
            self.txt=wx.TextCtrl(panel,style=wx.TE_PROCESS_ENTER,size=(400,40))
            self.txt.SetFocus()
            self.txt.Bind(wx.EVT_TEXT_ENTER,self.OnEnter)
            my_sizer.Add(self.txt,0,wx.ALL,6)
            panel.SetSizer(my_sizer)
            self.Show()
            speak.Speak('''Hi Ethan! Going on a mission?''')
     
        def OnEnter(self,event):
            put=self.txt.GetValue()
            put=put.lower()
            link=put.split()
            if put=='':
                m=sr.Recognizer()
                with sr.Microphone() as srm:
                    audio=m.listen(srm)
                try:
                    put=m.recognize_google(audio)
                    put=put.lower()
                    link=put.split()
                    self.txt.SetValue(put)
                except sr.UnknownValueError:
                    print("BENJI could not understand audio")
                except sr.RequestError as RE:
                    print("could not request results from IMF archives;{0}".format(RE))
                except:
                    print("Unknown error occurred!")
         #Play song on  Youtube
            if put.startswith('play '):
                try:
                    link = '+'.join(link[1:])
                    say = link.replace('+', ' ')
                    url = 'https://www.youtube.com/results?search_query='+link
                    source_code = requests.get(url, headers=headers, timeout=15)
                    plaincode = source_code.text
                    soup = BeautifulSoup(plaincode, "html.parser")
                    songs = soup.findAll('div', {'class': 'yt-lockup-video'})
                    song = songs[0].contents[0].contents[0].contents[0]
                    hit = song['href']
                    speak.Speak("playing "+say)
                    webbrowser.open('https://www.youtube.com'+hit)
                except:
                    print('Sorry Ethan. Looks like its not working!')
         #Open a webpage
            elif put.startswith('open '):
                try:
                    speak.Speak("opening "+link[1])
                    webbrowser.open('http://www.'+link[1]+'.com')
                except:
                    print('Sorry Ethan,unable to access it. Cannot hack either-IMF protocol!')
        #Google search
            elif put.startswith('search '):
                try:
                    link='+'.join(link[1:])
                    say=link.replace('+',' ')
                    speak.Speak("searching google for "+say)
                    webbrowser.open('https://www.google.com/search?q='+link)
                except:
                    print('Nope, this is not working.')
        #Wikipedia
            elif put.startswith('wiki '):
                try:
                    put=put.split()
                    put=''.join(put[2:])
                    print(wikipedia.summary(put))
                    speak.Speak('searched Wikipedia for'+put)
                except:
                    print('Net is an issue!')
    
    #News of various press agencies
            elif put.startswith('aljazeera '):
                try:
                    jsonObj=urlopen('''  https://newsapi.org/v1/articles?source=al-jazeera-english&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3''')
                    data=json.load(jsonObj)
                    i+=1
                    speak.Speak('''Our agents from Al-Jazeera report this''')
                    print('''  =====Al Jazeera====='''+'\n')
                    for item in data['articles']:
                        print(str(i)+'. '+item['title']+'\n')
                        print(item['description']+'\n')
                        i+=1
                except:
                    print('Qatari agents have refused to share this intel, Ethan')
            elif put.startswith('bbc '):
                try:
                    jsonObj=urlopen('''https://newsapi.org/v1/articles?source=bbc-news&sortBy=top&apiKey=571863193daf421082a8666fe4b666f3''')
                    data=json.load(jsonObj)
                    i+=1
                    speak.Speak('''Our agents from BBC report this''')
                    print('''  =====BBC====='''+'\n')
                    for item in data['articles']:
                        print(str(i)+'. '+item['title']+'\n')
                        print(item['description']+'\n')
                        i+=1
                except:
                    print('MI6 is going crazy! Not allowing this!')
            elif put.startswith('cricket '):
                try:
                    jsonObj=urlopen(''' https://newsapi.org/v1/articles?source=espn-cric-info&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3''')
                    data=json.load(jsonObj)
                    i+=1
                    speak.Speak('''Cricket news are''')
                    print('''  =====ESPN====='''+'\n')
                    for item in data['articles']:
                        print(str(i)+'. '+item['title']+'\n')
                        print(item['description']+'\n')
                        i+=1
                except:
                    print('Connection not secure')
            elif put.startswith('news '):
                try:
                    jsonObj=urlopen('''https://newsapi.org/v1/articles?source=the-hindu&sortBy=latest&apiKey=571863193daf421082a8666fe4b666f3''')
                    data=json.load(jsonObj)
                    i+=1
                    speak.Speak('''Some news from The Hindu''')
                    print('''  =====The Hindu====='''+'\n')
                    for item in data['articles']:
                        print(str(i)+'. '+item['title']+'\n')
                        print(item['description']+'\n')
                        i+=1
                except:
                    print('R&A W is blocking our reports, Ethan. Sorry! ')

    #Trigger the GUI. Light the fuse!
if __name__=="__main__":
    app = wx.App(True)
    frame= MyFrame()
    app.MainLoop()




