import cv2 as cv
from matplotlib import pyplot as plt

img1 = cv.imread(
    r'C:\Users\jaypr\Desktop\Code\Python Codes\mapComparision\assets\lobbycart.jpg', 0)
img2 = cv.imread(
    r'C:\Users\jaypr\Desktop\Code\Python Codes\mapComparision\assets\lobbyslam.jpg', 0)


up_width = 600
up_height = 400
up_points = (up_width, up_height)

img1 = cv.resize(img1, up_points, interpolation=cv.INTER_LINEAR)
img2 = cv.resize(img2, up_points, interpolation=cv.INTER_LINEAR)

edges1 = cv.Canny(img1, 100, 200)
edges2 = cv.Canny(img2, 100, 500)


# Row 1
plt.subplot(2, 2, 1), plt.imshow(img1, cmap='gray')
plt.title('Hostel (HectorSLAM)'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 2, 2), plt.imshow(edges1, cmap='gray')
plt.title('Hostel (HectorSLAM)'), plt.xticks([]), plt.yticks([])

# Row 2
plt.subplot(2, 2, 3), plt.imshow(img2, cmap='gray')
plt.title('Hostel (Cartographer)'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 2, 4), plt.imshow(edges2, cmap='gray')
plt.title('Hostel (Cartographer)'), plt.xticks([]), plt.yticks([])


plt.show()
