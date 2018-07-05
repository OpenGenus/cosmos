import os
import cv2
import numpy as np
from PIL import Image

def getImagesWithID(path):
	recognizer = cv2.face.LBPHFaceRecognizer_create()

	imagePaths = [os.path.join(path,f) for f in os.listdir(path)]
	faces = []
	IDs = []
	for imagePath in imagePaths:
		faceImg = Image.open(imagePath).convert('L')
		faceNp = np.array(faceImg, 'uint8')
		ID = int(os.path.split(imagePath)[-1].split('_')[0])
		faces.append(faceNp)
		IDs.append(ID)
		cv2.imshow("Training", faceNp)
		cv2.waitKey(10)
	
	Ids = np.array(IDs)
	recognizer.train(faces, Ids)
	recognizer.save('C:/recognizer/trainingData.yml')
	cv2.destroyAllWindows()
