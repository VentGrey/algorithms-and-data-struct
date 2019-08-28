import cv2
import numpy as np
from scipy import ndimage
from math import copysign, log10

img = cv2.imread('frog.jpg')
"""
# grey = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
# cv2.imwrite('Pika_grey.png', grey)
# _, img_bin = cv2.threshold(grey, 128, 255, cv2.THRESH_BINARY)

# Redimensionar una imágen
# scale_percent = 50
# width = int(img.shape[1] * scale_percent / 100)
# height = int(img.shape[0] * scale_percent / 100)
# dim = (width, height)
# resized = cv2.resize(img, dim, interpolation = cv2.INTER_AREA)

# size = img.shape
# M = np.float32([
#    [1, 0, 100],
#    [0, 1, 50]
# ])

# dst = cv2.warpAffine(img, M, (size[0], size[1]))

# rows, cols, _ = img.shape
# M = cv2.getRotationMatrix2D((cols / 2, rows / 2), 45, 1)
# dst = cv2.warpAffine(img, M, (cols, rows))

# dst = ndimage.rotate(img, 45, reshape = True)

scale = 1
delta = 0
ddepth = cv2.CV_16S
img = cv2.imread('frog.jpg', cv2.IMREAD_GRAYSCALE)

grad_x = cv2.Sobel(img, ddepth, 1, 0, ksize = 3, scale = scale, delta = delta, borderType = cv2.BORDER_DEFAULT)
grad_y = cv2.Sobel(img, ddepth, 0, 1, ksize = 3, scale = scale, delta = delta, borderType = cv2.BORDER_DEFAULT)

abs_grad_x = cv2.convertScaleAbs(grad_x)
abs_grad_y = cv2.convertScaleAbs(grad_y)

grad = cv2.addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0)
"""
img = cv2.imread('frog.jpg', cv2.IMREAD_GRAYSCALE)
_, im = cv2.threshold(img, 128, 255, cv2.THRESH_BINARY)
moments = cv2.moments(im)
huMoments = cv2.HuMoments(moments)

for i in range(0, 7):
    huMoments[i] = -1 * copysign(1.0, huMoments[i]) * log10(abs(huMoments[i]))

print(huMoments)


cv2.imshow('Image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
