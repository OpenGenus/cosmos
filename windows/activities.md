# B.E.N.J.I.

<h1 align="center">
  <img width="400" src="https://raw.githubusercontent.com/the-ethan-hunt/B.E.N.J.I./master/benji_final.ico">
  <br>
  <br>
</h1>

> _***A digital assistant for your device with the capability of listening and following your orders.***_


List of the things that B.E.N.J.I. can do:

* Authenticate user by using facial recognition with the help of webcam
* Add and save notes
* Screen Recorder(Audio+Video)
* Audio Recorder
* Video Recorder
* Merge(Audio+Video)
* Change formats of video
  * With audio:
    * avi - mp4, mkv, webm, mp3, m4a
    * webm - mp4, mkv, avi, mp3, m4a
    * mp4 - avi, mkv, webm, mp3, m4a
  * Without audio:
    * avi - mp4, mkv, webm
    * webm - mp4, mkv, avi
    * mp4 - avi, mkv, webm
* Images to video    
* Search for a file on your Device
* Add event in your Google Calendar
* Play Youtube videos
* Download video
* Download music
* Search for any place on the Google Maps
* Open any website that you ask it to, in your default browser
* Search for Images on Google Images
* Open Gmail to check your mails
* Open any of the following apps from the Google Suite in your default browser:
  * Google News
  * Google Translate
  * Google Photos
  * Google Drive
  * Google Plus
  * Google Forms
  * Google Documents
  * Google Sheets
  * Google Slides
  * Google Groups
  * Google Earth
  * Google Cloud Print
  * Google Fonts
* Open up Blogger
* Search for anything on Google from the application itself
* Search from Wikipedia
* Lock your device securely
* Look up latest news/cricket scores from:
  * Al Jazeera
  * BBC
  * Bloomberg
  * Business Insider
  * CNN
  * ESPN Cricket
  * Financial Times
  * Mirror
  * Talksport
  * TechRadar
  * TechCrunch
  * The Hindu
  * The Huffington Post
  * The New York Times
  * The Times of India
  * The Wall Street Journal
  * The Washington Post
  * The Telegraph
  * The Verge
  * Time
* Shut Down your device instantly or set a timer
* Restart your device
* Create a file(txt, docx, pptx,xlsx, vsdx and rtf supported)
* Podcast
* Calculator
* Twitter(get top 10 tweets, get list of people you are following)
* Say "Spanish", and then give the commands in Spanish
* Say "French", and then give the commands in French

Keep reading to see how to do all the above mentioned jobs with B.E.N.J.I.

You can either click on the 'Mic' button and speak the commands in your microphone, or type the commands in the 'Command Box' and hit 'Enter'.

>Please note that you need to be connected to the internet and a working microphone for the Voice Recognition Engine to work properly.
You can always type in your commands in the Command Box and hit 'Enter' and B.E.N.J.I. will obey your orders.

The commands for the various functions are as follows:

* "***Who are you/Identify Youself/What is your name***" for B.E.N.J.I. to introduce itself.
* Face detection feature will automatically fetch image for first time user. From next time, it will predict the authenticity of user. If user is authenticated, then B.E.N.J.I. will start running. If user wants to add another user, he/she can use "***face*** username". By default, username is "admin". So, make sure, while adding a new user, use "username" other than "admin". B.E.N.J.I. will fetch a single image of the user and store it in "dataset" folder in "C" drive. 
NOTE: Make sure that system is able to fetch a good image of yours(be in a good lighting conditions). You can also directly add image to "dataset" folder in "C" drive.
* "***note*** _NoteContent_" to add a note. The note is saved on your desktop.
* "***recorder*** _VideoName_ _AudioName_" to initiate screen recorder. If only "***recorder***" is used, it will use "UScreenCapture" and "Microphone (Realtek High Definition Audio)" as default video and audio. You can choose them, by using "ffmpeg -list_devices true -f dshow -i dummy" in command prompt. If only "***recorder*** _VideoName_" is used, then the audio will be chosen as per the default one. NOTE: Press 'q' in the command prompt when you are done with the recording. This holds true for every other recording feature.
* "***audio recorder*** _AudioName_" records audio. Use "***audio recorder***", this will use default audio "Microphone (Realtek High Definition Audio)".
* "***video recorder*** _VideoName_" records video(without audio). Use "***video recorder***", this will use default "UScreenCapture".
* "***merge*** _VideoFileName_ _AudioFileName_ _OutputFileName_". This will merge video and audio file. OutputFileName is the resultant file.
* "***convert*** _InputFormat_ _InputFile_ _OutputFormat_ _OutputFile_". This will convert the input file to the output file. To create a file without audio, use "convert na _InputFormat_ _InputFile_ _OutputFormat_ _OutputFile_".Here "na" stands for "no audio".
NOTE: All the recorded files will be saved on the desktop. Make sure that the file names should not be same. "input.avi" and "input.mp3" have no conflicts. But "input.avi" and "input.avi" will result into conflicts.
* "***images to video*** _time_". Here time is the display time of each image. For this feature to run, you should create a folder "Images" on desktop. Add the images to the folder and rename them as "img001.jpg", "img002.jpg" and so on. After running the command, you will get the video in the same folder in ".avi" format.
* "***lookfor/find*** _Filename_ _PathWhereYouWantToSearch_" to look for a file at a specified location and open it. Also you can open files from C drive, D drive, Desktop, Documents, Downloads by saying- find/lookfor in <C or D drive/Documents/Desktop?downloads>. C and D drive can be opened by saying- lookfor/find C/D drive(Version: Microsoft Windows [Version 10.0.16299.431]).
* "***draw graph for*** _formula_ ***from*** _Upper-limit_ ***to*** _Lower-limit_" to plot graph for formula like(x^n+ax^m+b ...) for example,
  _draw graph for x**2+4*x+6 from -100 to 100_.
* "***add event in google calendar*** to add event on your google calendar, type(or say) in the following format: "add event <event_name> <start date in format yyyy-mm-dd> to <end date in format yyyy-mm-dd>" and it will save the event on your google calendar.
* "***play/stream/queue*** _Song/VideoName_" to play any song or video on Youtube.
* "***download video*** _SongName_" to download video.
* "***download music*** _SongName_" to download a song.
* "***locate/spot*** _PlaceName_" to look for a place on Google Maps.
* "***open/launch*** _Website_" to open any website.
* "***images of*** _ImageToBeSearched_" to look up images on Google Images.
* "***gmail/google news/google translate/google photos/google drive/google plus/google forms/google document/google sheets/google slides/google groups/google earth/google cloud print/google fonts/blogger*** _open_" to open the respective in your default browser.
* "***search*** _ItemToBeSearched_" to google anything.
* "***wikipedia/wiki*** _ItemToBeSearched_" to search anything on Wikipedia.
* "***secure/lock device***" to lock your device.
* "***news al jazeera/bbc/espn cric/the hindus*** to lookup latest news from the respective networks.
* "***shutdown after*** _hours_ _minutes_" to initiate a Shut Down Timer.
* "***cancel shutdown***" in case you want the Shut Down Timer to stop.
* "***shutdown now***" to instantly shut down your device.
* "***restart now***" to restart your device.
* "***create*** _filename_ _filetype_ document" to create a file where filetype maybe "text", "word", "powerpoint", "presentation", "excel", "visio" or "rich".
* "***podcast***". This will redirect you to "CastBox" which is a good source of podcasts.
* "***calculator***". This will open Calculator.
* "***exit/over/close/stop*** to exit BENJI.
* "***get tweets***" Get latest 10 tweets from timeline. For this an app is to be registered at https://apps.twitter.com/ (if confused, have a look at https://spring.io/guides/gs/register-twitter-app/). A new file named "twitterCredentials.py" is to be made in the windows folder. Save the consumer key, consumer secret, access token, access token secret with the names consumer_key, consumer_secret, access_token, access_secret repectively in the "twitterCredentials.py". Speak/type "get tweets" and top 10 tweets will be shown, also when and by whom it was created.
* Get latest 10 tweets done by the user. Speak/type "get my tweets" and top 10 tweets done by the user(you) will be shown with the time when it was tweeted
* You can get a list of everyone you follow from twitter by saying "get list of people I follow on twitter"
* "***Commands in Spanish***" You just need to speak/type "Spanish" and then give your command(in Spanish language). For example, speak/type "Spanish abierto facebook.com" opens facebook homepage, "Spanish buscar India" does a google search for India.
* "***Commands in French***" You just need to speak/type "French" and then give your command(in French language). For example, speak/type "French ouvert facebook.com" opens facebook homepage, "French trouver C drive" opens C drive.
>In cases where the commands are separated by '/', use any one of the mentioned commands
>For example, use either ***What is your name*** or ***Identify Yourself*** or ***Who are you***. Don't type all of them at once.

_***Hope you enjoy using B.E.N.J.I.***_

_More features coming soon._
