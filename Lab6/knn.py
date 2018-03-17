import csv
import random
import math
import operator 

def readData(filename, ratio, trainingSet=[] , testSet=[]):
    with open(filename, 'rb') as file:
        lines = csv.reader(file)
        #convert to lists
        dataset = list(lines)
        for x in range(len(dataset)-1):
            for y in range(4):
                dataset[x][y] = float(dataset[x][y])
            #split the data into two sets 
            if random.random() < ratio:
                trainingSet.append(dataset[x])
            else:
                testSet.append(dataset[x])

def calDistance(point1, point2, length):
    distance = 0
    for x in range(length):
        #euclidean distances
        distance += pow((point1[x] - point2[x]), 2)
    result = math.sqrt(distance)
    return result
 
def KNN(trainingSet, testSet, k):
    distances = []
    length = len(testSet)-1
    for x in range(len(trainingSet)):
        dist = calDistance(testSet, trainingSet[x], length)
        distances.append((trainingSet[x], dist))
    distances.sort(key=operator.itemgetter(1))
    neighbors = []
    for x in range(k):
        neighbors.append(distances[x][0])
    return neighbors
 
def getResponse(neighbors):
    classVotes = {}
    for x in range(len(neighbors)):
        response = neighbors[x][-1]
        if response in classVotes:
            classVotes[response] += 1
        else:
            classVotes[response] = 1
    sortedVotes = sorted(classVotes.iteritems(), key=operator.itemgetter(1), reverse=True)
    return sortedVotes[0][0]
 
def getAccuracy(testSet, predictions):
    correct = 0
    for x in range(len(testSet)):
        if testSet[x][-1] == predictions[x]:
            correct += 1

    print 'error nums: ' + str(len(testSet) - correct)
    return (correct/float(len(testSet))) * 100.0
    
def main():
    # prepare data
    trainingSet=[]
    testSet=[]
    ratio = 0.8
    counter = 0
    readData('iris.data', ratio, trainingSet, testSet)
    print ('Train set: ' + repr(len(trainingSet)) )
    print ('Test set: ' + repr(len(testSet)) )
    # generate predictions
    predictions=[]
    k = 3

    for x in range(len(testSet)):
        neighbors = KNN(trainingSet, testSet[x], k)
        result = getResponse(neighbors)
        predictions.append(result)
    
    print 'errors number: ' + str(counter)
    
    accuracy = getAccuracy(testSet, predictions)
    print('Accuracy: ' + repr(accuracy) + '%')
    
main()