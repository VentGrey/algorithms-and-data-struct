import cv2

img = cv2.imread('chrono.png')
print(img[0][0])
print(img.shape)
for row in img:
    for pixel in row:
        print(pixel, end=' ')

cv2.imshow('Image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
