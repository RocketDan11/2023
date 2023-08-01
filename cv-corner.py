import numpy as np
import cv2 as cv

img = cv.imread('assets/check.png')
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

# Shi-Tomasi corner detector
corners = cv.goodFeaturesToTrack(gray, 100, 0.01, 10)
corners = np.intp(corners)

for corner in corners:
    #flattens corner
    x, y = corner.ravel()   # [[x, y]] -> [x,y]  
    cv.circle(img, (x, y), 5, (255, 0, 0), -1)

for i in range(len(corners) - 1):
    for j in range(i + 1, len(corners)):
        corners1 = tuple(corners[i][0])
        corners2 = tuple(corners[j][0])
        color = tuple(map(lambda x: int(x), np.random.randint(0, 255, size=3)))
        cv.line(img, corners1, corners2, color, 1)

cv.imshow('frame', img)
cv.waitKey(0)
cv.destroyAllWindows()