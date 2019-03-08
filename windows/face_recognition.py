# -*- coding: utf-8 -*-
from __future__ import print_function
import click
import os
import re
import api as face_recognition
import multiprocessing
import itertools
import sys
import PIL.Image
import numpy as np
import cv2

def scan_known_people(known_people_folder):
	"""Scans the dataset containing images of known people."""
	known_names = []
	known_face_encodings = []

	for file in image_files_in_folder(known_people_folder):
		basename = os.path.splitext(os.path.basename(file))[0]
		img = face_recognition.load_image_file(file)
		encodings = face_recognition.face_encodings(img)

		if len(encodings) > 1:
			click.echo("WARNING: More than one face found in {}. Only considering the first face.".format(file))

		if len(encodings) == 0:
			click.echo("WARNING: No faces found in {}. Ignoring file.".format(file))
		else:
			known_names.append(basename)
			known_face_encodings.append(encodings[0])

	return known_names, known_face_encodings

def test_image(known_names, known_face_encodings):
	"""Compares the captured image to the images in the dataset."""
	cam = cv2.VideoCapture(0)
	ret, image_to_check = cam.read()

	cam.release()
	cv2.destroyAllWindows()

	unknown_image = image_to_check

	# Scale down image if it's giant so things run a little faster
	if max(unknown_image.shape) > 1600:
		pil_img = PIL.Image.fromarray(unknown_image)
		pil_img.thumbnail((1600, 1600), PIL.Image.LANCZOS)
		unknown_image = np.array(pil_img)

	unknown_encodings = face_recognition.face_encodings(unknown_image)

	for unknown_encoding in unknown_encodings:
		distances = face_recognition.face_distance(known_face_encodings, unknown_encoding)
		result = list(distances <= 0.5625) #0.5625 is tolerance

		if True in result:
			continue
		else:
			# No match
			sys.exit()

	if not unknown_encodings:
		# No faces were found in image
		sys.exit()	
	
def image_files_in_folder(folder):
	"""Return a list containing the path of the images in the folder."""
	return [os.path.join(folder, f) for f in os.listdir(folder) if re.match(r'.*\.(jpg|jpeg|png)', f, flags=re.I)]

def main():
	known_people_folder = "C:/dataset"
	known_names, known_face_encodings = scan_known_people(known_people_folder)
	test_image(known_names, known_face_encodings)

if __name__ == "__main__":
	main()
