import random 
import math


#read file
def loadDataset(filename,X,y):
	data = open(filename)
	Z = data.read().splitlines()
	#for line in Z:
	#	X.append(line.split('	')[0])
	#	y.append(line.split('	')[1])
	data.close()
	#X = [float(item) for item in X]
	#y = [float(item) for item in y]
	print (Z)

#main file 
def main():
	trainingSet = []
	testSet = []
	loadDataset('trainingset.txt',trainingSet,testSet)
	#print (trainingSet)
	#print (testSet)

main()