import cv2 as cv
from matplotlib import pyplot as plt
img1 = cv.imread(
    r'C:\Users\jaypr\Desktop\Code\Python Codes\mapComparision\assets\hostelGmapping.png', 0)
img2 = cv.imread(
    r'C:\Users\jaypr\Desktop\Code\Python Codes\mapComparision\assets\hostelHectorslam.png', 0)
img3 = cv.imread(
    r'C:\Users\jaypr\Desktop\Code\Python Codes\mapComparision\assets\lobbyGmapping.png', 0)
img4 = cv.imread(
    r'C:\Users\jaypr\Desktop\Code\Python Codes\mapComparision\assets\lobbyHectorslam.png', 0)

up_width = 600
up_height = 400
up_points = (up_width, up_height)

img1 = cv.resize(img1, up_points, interpolation=cv.INTER_LINEAR)
img2 = cv.resize(img2, up_points, interpolation=cv.INTER_LINEAR)
img3 = cv.resize(img3, up_points, interpolation=cv.INTER_LINEAR)
img4 = cv.resize(img4, up_points, interpolation=cv.INTER_LINEAR)

edges1 = cv.Canny(img1, 100, 200)
edges2 = cv.Canny(img2, 100, 200)
edges3 = cv.Canny(img3, 100, 200)
edges4 = cv.Canny(img4, 100, 200)


# Row 1
plt.subplot(2, 4, 1), plt.imshow(img1, cmap='gray')
plt.title('Hostel (Gmapping)'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 4, 2), plt.imshow(edges1, cmap='gray')
plt.title('Hostel (Gmapping)'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 4, 3), plt.imshow(img2, cmap='gray')
plt.title('Hostel (HectorSLAM)'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 4, 4), plt.imshow(edges2, cmap='gray')
plt.title('Hostel (HectorSLAM)'), plt.xticks([]), plt.yticks([])

# Row 2
plt.subplot(2, 4, 5), plt.imshow(img3, cmap='gray')
plt.title('Lobby (Gmapping)'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 4, 6), plt.imshow(edges3, cmap='gray')
plt.title('Lobby (Gmapping)'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 4, 7), plt.imshow(img4, cmap='gray')
plt.title('Lobby (HectorSLAM)'), plt.xticks([]), plt.yticks([])

plt.subplot(2, 4, 8), plt.imshow(edges4, cmap='gray')
plt.title('Lobby (HectorSLAM)'), plt.xticks([]), plt.yticks([])


plt.show()
