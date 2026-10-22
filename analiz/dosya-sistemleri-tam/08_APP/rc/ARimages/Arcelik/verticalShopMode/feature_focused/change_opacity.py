#!/usr/bin/python

from PIL import Image
import glob, os

def premultiply(im):
    pixels = im.load()
    for y in range(im.size[1]):
        for x in range(im.size[0]):
            r, g, b, a = pixels[x, y]
            if a != 255:
                r = r * a // 255
                g = g * a // 255
                b = b * a // 255
                pixels[x, y] = (r, g, b, a)

def unmultiply(im):
    pixels = im.load()
    for y in range(im.size[1]):
        for x in range(im.size[0]):
            r, g, b, a = pixels[x, y]
            if a != 255 and a != 0:
                r = 255 if r >= a else 255 * r // a
                g = 255 if g >= a else 255 * g // a
                b = 255 if b >= a else 255 * b // a
                pixels[x, y] = (r, g, b, a)

def changeopacity(img):
	# Opaque is 255, input between 0-255   %80 = 204
	
	img = img.convert("RGBA")
	datas = img.getdata()

	newData = []
	for item in datas:
	    newData.append((item[0], item[1], item[2], item[3]*80/100))
	
	img.putdata(newData)
	return img

size = (87,87)
size_focused = (105,105)
os.chdir("./")
for file in glob.glob("*.png"):
	im = Image.open(file)
	premultiply(im)
	im = im.resize(size_focused, Image.ANTIALIAS)  
	unmultiply(im)
	im.save("./"+ file, "PNG")
	premultiply(im)
	im = im.resize(size, Image.ANTIALIAS)  
	unmultiply(im)
	im=changeopacity(im)
	im.save("../feature/"+ file, "PNG")





