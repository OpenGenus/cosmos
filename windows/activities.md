# B.E.N.J.I.

<h1 align="center">
  <img width="400" src="https://raw.githubusercontent.com/the-ethan-hunt/B.E.N.J.I./master/benji_final.ico">
  <br>
  <br>
</h1>

> _***A digital assistant for your device with the capability of listening and following your orders.***_


List of the things that B.E.N.J.I. can do:

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
* Search for a file on your Device
* Play Youtube videos
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

Keep reading to see how to do all the above mentioned jobs with B.E.N.J.I.

You can either click on the 'Mic' button and speak the commands in your microphone, or type the commands in the 'Command Box' and hit 'Enter'.

>Please note that you need to be connected to the internet and a working microphone for the Voice Recognition Engine to work properly.
You can always type in your commands in the Command Box and hit 'Enter' and B.E.N.J.I. will obey your orders.

The commands for the various functions are as follows:

* "***Who are you/Identify Youself/What is your name***" for B.E.N.J.I. to introduce itself.
* "***note*** _NoteContent_" to add a note. The note is saved on your desktop.
* "***recorder*** _VideoName_ _AudioName_" to initiate screen recorder. If only "***recorder***" is used, it will use "UScreenCapture" and "Microphone (Realtek High Definition Audio)" as default video and audio. You can choose them, by using "ffmpeg -list_devices true -f dshow -i dummy" in command prompt. If only "***recorder*** _VideoName_" is used, then the audio will be chosen as per the default one. NOTE: Press 'q' in the command prompt when you are done with the recording. This holds true for every other recording feature.
* "***audio recorder*** _AudioName_" records audio. Use "***audio recorder***", this will use default audio "Microphone (Realtek High Definition Audio)".
* "***video recorder*** _VideoName_" records video(without audio). Use "***video recorder***", this will use default "UScreenCapture".
* "***merge*** _VideoFileName_ _AudioFileName_ _OutputFileName_". This will merge video and audio file. OutputFileName is the resultant file.
* "***convert*** _InputFormat_ _InputFile_ _OutputFormat_ _OutputFile_". This will convert the input file to the output file.
NOTE: All the recorded files will be saved on the desktop. Make sure that the file names should not be same. "input.avi" and "input.mp3" have no conflicts. But "input.avi" and "input.avi" will result into conflicts. 
* "***lookfor/find*** _Filename_ _PathWhereYouWantToSearch_" to look for a file at a specified location and open it.
* "***play/stream/queue*** _Song/VideoName_" to play any song or video on Youtube.
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


>In cases where the commands are separated by '/', use any one of the mentioned commands
>For example, use either ***What is your name*** or ***Identify Yourself*** or ***Who are you***. Don't type all of them at once.

_***Hope you enjoy using B.E.N.J.I.***_

_More features coming soon._
