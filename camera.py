import cv2
from joblib import load
face_cascade=cv2.CascadeClassifier("haarcascade_frontalface_default.xml")
model=load('modell.joblib')
d={1:'MASK',0:'No Mask'}
font=cv2.FONT_HERSHEY_COMPLEX
class VideoCamera(object):
    def __init__(self):
        self.video=cv2.VideoCapture(0)
        
    def __del__(self):
        self.video.release()
    
    def get_frame(self):
        ret,frame=self.video.read()
        frame=cv2.flip(frame,1)
        gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
        faces=face_cascade.detectMultiScale(gray,scaleFactor=1.2,minNeighbors=5,minSize=(30,30))
        a,b=0,0
        for(x,y,w,h) in faces:
            cv2.rectangle(frame,(x,y),(x+w,y+h),(250,0,0),4)
            face=frame[y:y+h,x:x+w,:]
            face=cv2.resize(face,(100,100))
            face=face.reshape(1,-1)
            pred=model.predict(face)[0]
            n=int(pred)
            m=d[n]
            if n==0: 
                cv2.putText(frame,m,(x,y),font,1,(0,0,240),2)
                a+=1
            if n==1: 
                cv2.putText(frame,m,(x,y),font,1,(0,255,0),2)
                b+=1
        cv2.rectangle(frame,(0,0),(200,60),(255,255,255),-1)
        cv2.putText(frame,"no of face detected: " +str(len(faces)),(0,25),font,0.5,(255,0,0),1)
        cv2.putText(frame," Wearing MASK : " +str(b),(0,40),font,0.5,(0,255,0),1)
        cv2.putText(frame,"Not Wearing MASK: " +str(a),(0,55),font,0.5,(0,0,255),1)
        #res = cv2.resize(frame,None,fx=1.6, fy=1.5, interpolation = cv2.INTER_CUBIC)
        ret,jpeg=cv2.imencode('.jpg',frame)
        return jpeg.tobytes()