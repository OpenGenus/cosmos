
# Image Encryption Decryption

# imported necessary library
import tkinter
from tkinter import *
import tkinter as tk
import tkinter.messagebox as mbox
from tkinter import ttk
from tkinter import filedialog
from PIL import ImageTk, Image
import cv2
import os
import numpy as np
from cv2 import *
import random

#created main window
window = Tk()
window.geometry("1000x700")
window.title("Image Encryption Decryption")

# defined variable
global count, emig
# global bright, con
# global frp, tname  # list of paths
frp = []
tname = []
con = 1
bright = 0
panelB = None
panelA = None

# function defined to get the path of the image selected
def getpath(path):
    a = path.split(r'/')
    # print(a)
    fname = a[-1]
    l = len(fname)
    location = path[:-l]
    return location

# function defined to get the folder name from which image is selected
def getfoldername(path):
    a = path.split(r'/')
    # print(a)
    name = a[-1]
    return name

# function defined to get the file name of image is selected
def getfilename(path):
    a = path.split(r'/')
    fname = a[-1]
    a = fname.split('.')
    a = a[0]
    return a

# function defined to open the image file
def openfilename():
    filename = filedialog.askopenfilename(title='"pen')
    return filename

# function defined to open the selected image
def open_img():
    global x, panelA, panelB
    global count, eimg, location, filename
    count = 0
    x = openfilename()
    img = Image.open(x)
    eimg = img
    img = ImageTk.PhotoImage(img)
    temp = x
    location = getpath(temp)
    filename = getfilename(temp)
    # print(x)
    if panelA is None or panelB is None:
        panelA = Label(image=img)
        panelA.image = img
        panelA.pack(side="left", padx=10, pady=10)
        panelB = Label(image=img)
        panelB.image = img
        panelB.pack(side="right", padx=10, pady=10)
    else:
        panelA.configure(image=img)
        panelB.configure(image=img)
        panelA.image = img
        panelB.image = img

# function defined for make the sketch of image selected
def en_fun():
    global x, image_encrypted, key
    # print(x)
    image_input = imread(x, IMREAD_GRAYSCALE)# 'C:/Users/aakas/Documents/flower.jpg'
    (x1, y) = image_input.shape
    image_input = image_input.astype(float) / 255.0
    # print(image_input)

    mu, sigma = 0, 0.1  # mean and standard deviation
    key = np.random.normal(mu, sigma, (x1, y)) + np.finfo(float).eps
    # print(key)
    image_encrypted = image_input / key
    imwrite('image_encrypted.jpg', image_encrypted * 255)

    imge = Image.open('image_encrypted.jpg')
    imge = ImageTk.PhotoImage(imge)
    panelB.configure(image=imge)
    panelB.image = imge
    mbox.showinfo("Encrypt Status", "Image Encryted successfully.")

# function defined to make the image sharp
def de_fun():
    global image_encrypted, key
    image_output = image_encrypted * key
    image_output *= 255.0
    imwrite('image_output.jpg', image_output)

    imgd = Image.open('image_output.jpg')
    imgd = ImageTk.PhotoImage(imgd)
    panelB.configure(image=imgd)
    panelB.image = imgd
    mbox.showinfo("Decrypt Status", "Image decrypted successfully.")


# function defined to reset the edited image to original one
def reset():
    # print(x)
    image = cv2.imread(x)[:, :, ::-1]
    global count, eimg
    count = 6
    global o6
    o6 = image
    image = Image.fromarray(o6)
    eimg = image
    image = ImageTk.PhotoImage(image)
    panelB.configure(image=image)
    panelB.image = image
    mbox.showinfo("Success", "Image reset to original format!")

# function defined to same the edited image
def save_img():
    global location, filename, eimg
    print(filename)
    # eimg.save(location + filename + r"_edit.png")
    filename = filedialog.asksaveasfile(mode='w', defaultextension=".jpg")
    if not filename:
        return
    eimg.save(filename)
    mbox.showinfo("Success", "Encrypted Image Saved Successfully!")



# top label
start1 = tk.Label(text = "Image Encryption\nDecryption", font=("Arial", 40), fg="magenta") # same way bg
start1.place(x = 350, y = 10)

# original image label
start1 = tk.Label(text = "Original\nImage", font=("Arial", 40), fg="magenta") # same way bg
start1.place(x = 100, y = 270)

# edited image label
start1 = tk.Label(text = "Encrypted\nDecrypted\nImage", font=("Arial", 40), fg="magenta") # same way bg
start1.place(x = 700, y = 230)

# choose button created
chooseb = Button(window, text="Choose",command=open_img,font=("Arial", 20), bg = "orange", fg = "blue", borderwidth=3, relief="raised")
chooseb.place(x =30 , y =20 )

# save button created
saveb = Button(window, text="Save",command=save_img,font=("Arial", 20), bg = "orange", fg = "blue", borderwidth=3, relief="raised")
saveb.place(x =170 , y =20 )

# Encrypt button created
enb = Button(window, text="Encrypt",command=en_fun,font=("Arial", 20), bg = "light green", fg = "blue", borderwidth=3, relief="raised")
enb.place(x =150 , y =620 )

# decrypt button created
deb = Button(window, text="Decrypt",command=de_fun,font=("Arial", 20), bg = "orange", fg = "blue", borderwidth=3, relief="raised")
deb.place(x =450 , y =620 )

# reset button created
resetb = Button(window, text="Reset",command=reset,font=("Arial", 20), bg = "yellow", fg = "blue", borderwidth=3, relief="raised")
resetb.place(x =800 , y =620 )

# function created for exiting
def exit_win():
    if mbox.askokcancel("Exit", "Do you want to exit?"):
        window.destroy()

# exit button created
exitb = Button(window, text="EXIT",command=exit_win,font=("Arial", 20), bg = "red", fg = "blue", borderwidth=3, relief="raised")
exitb.place(x =880 , y =20 )


window.protocol("WM_DELETE_WINDOW", exit_win)
window.mainloop()