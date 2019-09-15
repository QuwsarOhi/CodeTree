import numpy as np
import matplotlib.pyplot as plt

def circle_points(r, n):
    circles = []
    for r, n in zip(r, n):
        t = np.linspace(0, 2*np.pi, n)
        x = r * np.cos(t)
        y = r * np.sin(t)
        circles.append(np.c_[x, y])
    return circles


n = [100000]
r = [10.5]
circles = np.array(circle_points(r, n))

#fig, ax = plt.subplots()
#for circle in circles[-1:]:
#    ax.scatter(circle[:, 0], circle[:, 1])
#ax.set_aspect('equal')
#plt.show()

#print(circles.shape)

points = [(0, 0)]
for circle in circles[-1:]:
    for x, y in zip(circle[:, 0], circle[:, 1]):
        points.append((x, y))

print(2)

for i in range(2):
    print(len(points)-1)
    for x, y in points:
        print(x, y)

    points[0] = (1, 2)