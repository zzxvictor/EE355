import sys
import numpy as np
import matplotlib.pyplot as plt


def main():
	#create two lists
	X = []
	y = []
	#import data
	data = open("trainingset.txt")
	Z = data.read().splitlines()
	for line in Z:
		X.append(line.split('	')[0])
		y.append(line.split('	')[1])
	data.close()
	X = [float(item) for item in X]
	y = [float(item) for item in y]
	print(X)
	print(y)
	regression = np.polyfit(X, y, 1)
	print (regression)
	plt.plot(X,y)

if __name__ == '__main__':
    sys.exit(main())