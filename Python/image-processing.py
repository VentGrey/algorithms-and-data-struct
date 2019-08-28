import cv2
import numpy as np

img = cv2.imread('frog.jpg')
# grey = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
# cv2.imwrite('Pika_grey.png', grey)
# _, img_bin = cv2.threshold(grey, 128, 255, cv2.THRESH_BINARY)

# Redimensionar una imágen
# scale_percent = 50
# width = int(img.shape[1] * scale_percent / 100)
# height = int(img.shape[0] * scale_percent / 100)
# dim = (width, height)
# resized = cv2.resize(img, dim, interpolation = cv2.INTER_AREA)

size = img.shape
M = np.float32([
    [1, 0, 100],
    [0, 1, 50]
])

dst = cv2.warpAffine(img, M, (size[0], size[1]))

cv2.imshow('Image', dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
