from sklearn.cluster import KMeans
import sys
import re
from collections import defaultdict
import math
import os
import glob
import random
import time
import string
import pickle
import numpy as np
import csv
from sklearn.cluster import DBSCAN
from sklearn import metrics
from sklearn.datasets.samples_generator import make_blobs
from sklearn.preprocessing import StandardScaler
MIN_CLUSTER = 10
candidates = []
def read_file(dir):
    with open(dir) as f:
        read_f = csv.reader(f, delimiter=',')
        pre_status = 0
        for row in read_f:
            cur_status = int(row[1])
            if pre_status == 0 and cur_status == 1:
                candidates.append((float(row[3]), float(row[4])))
                break
            pre_status = cur_status

def read_files():
    d = './Data'
    foldername = [os.path.join(d, o) for o in os.listdir(d) if os.path.isdir(os.path.join(d, o))]
    for folder in foldername:
        direct = folder + "/*"
        list_file = glob.glob(direct)
        for direction in list_file:
            read_file(direction)

def TopLeft(lst):
    X_min = min([e[0] for e in lst])
    Y_min = min([e[1] for e in lst])
    return (X_min, Y_min)

def BottomRight(lst):
    X_max = max([e[0] for e in lst])
    Y_max = max([e[1] for e in lst])
    return (X_max, Y_max)

def RecBound(lst):
    return TopLeft(lst), BottomRight(lst)

def dist(a, b):
    return math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)

res_cluster = defaultdict(list)

def cost_function(centroids, res_cluster):
    res = 0
    total_points = 0
    for k, v in res_cluster.items():
        for e in v:
            # print (centroids[k], e)
            res += dist(centroids[k], e)
        total_points += len(v)
    return 1 / total_points * res


def KMean(k):
    kmeans = KMeans(n_clusters=k).fit(candidates)
    cnt = 0
    for label in kmeans.labels_:
        res_cluster[label].append(candidates[cnt])
        cnt += 1

    for label, lst in list(res_cluster.items()):
        if len(lst) < MIN_CLUSTER:
            del res_cluster[label]

    t = 0
    for label, lst in list(res_cluster.items()):
        t += len(lst)
        print (len(lst))
    print ('len =', len(res_cluster))
    print ('t =', t)

    return cost_function(kmeans.cluster_centers_, res_cluster)

def DBCluster(dist, min_samples):
    dist /= 1000
    db = DBSCAN(eps= float(dist / 6371.0088), min_samples=min_samples, algorithm='ball_tree', metric='haversine').fit(np.radians(candidates))
    cnt = 0
    for label in db.labels_:
        if label != -1:
            res_cluster[label].append(candidates[cnt])
        cnt += 1

    t = 0
    for label, lst in list(res_cluster.items()):
        t += len(lst)
        print (len(lst))
    print ('len =', len(res_cluster))
    print ('t =', t)

def Write(res_cluster):
    with open('./Cluster/cluster.txt', 'w') as f:
        for cluster_id,_ in res_cluster.items():
            # print (cluster_id)
            # t = TopLeft(res_cluster[cluster_id])
            # f.write(str(t[0]) + ' ' + str(t[1]) + '\n')
            # t = BottomRight(res_cluster[cluster_id])
            # f.write(str(t[0]) + ' ' + str(t[1]) + '\n')
            f.write(str(len(res_cluster[cluster_id])) + '\n')

            for e in res_cluster[cluster_id]:
                f.write(str(e[0]) + ', ' + str(e[1]) + '\n')

def main():
    read_files()
    d = [450]
    cost = 1E9
    tracked = defaultdict(list)
    for k in d:
        res_cluster.clear()
        # for loop in range(4):
        #     x = KMean(k)
        #     if x < cost:
        #         cost = x
        #         tracked = res_cluster
        # KMean(k)
        DBCluster(30, 10)
    Write(res_cluster)

main() 