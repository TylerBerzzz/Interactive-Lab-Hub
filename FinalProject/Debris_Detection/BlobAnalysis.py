# -*- coding: utf-8 -*-
"""
Created on Sun Nov 20 20:46:56 2022

@author: tyler
"""

#https://learnopencv.com/blob-detection-using-opencv-python-c/

import cv2
import numpy as np

# Setup SimpleBlobDetector parameters.
params = cv2.SimpleBlobDetector_Params()
 
# Change thresholds
params.minThreshold = 10;
params.maxThreshold = 200;
 
# Filter by Area.
params.filterByArea = True
params.minArea = 10
 
# Filter by Circularity
params.filterByCircularity = True
params.minCircularity = 0.1
 
# Filter by Convexity
params.filterByConvexity = False
params.minConvexity = 0.87
 
# Filter by Inertia
params.filterByInertia = False
params.minInertiaRatio = 0.01
 
# Create a detector with the parameters
ver = (cv2.__version__).split('.')
if int(ver[0]) < 3 :
  detector = cv2.SimpleBlobDetector(params)
else : 
  detector = cv2.SimpleBlobDetector_create(params)
  
# Read in the image in grayscale
img = cv2.imread('Debris_photo2.jpg')

#detector = cv2.SimpleBlobDetector_create()

# Detect the blobs in the image
keypoints = detector.detect(img)
print(len(keypoints))

# Draw detected keypoints as red circles
imgKeyPoints = cv2.drawKeypoints(img, keypoints, np.array([]), (0,0,255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

# Naming a window
cv2.namedWindow("Resized_Window", cv2.WINDOW_NORMAL)
  
# Using resizeWindow()
cv2.resizeWindow("Resized_Window", 300, 700)
  
# Displaying the image
cv2.imshow("Resized_Window", imgKeyPoints)

# Display found keypoints
cv2.imshow("Keypoints", imgKeyPoints)
cv2.waitKey(0)

cv2.destroyAllWindows()