import csv
from datetime import datetime
from datetime import date
from datetime import time
from datetime import timedelta
import time
import os

TIMEINTERVAL = timedelta(minutes = 10)
w, h = 2, 40341

for tt in range(20151019,20151027):
    listGPS = []
    for t in range(37,338):
        i_file = os.getcwd() + "/" +(str)(tt) + "/" + (str)(t) + '.csv'
        if os.path.isfile(i_file):
            with open(i_file) as inputf:
                reader = csv.reader(inputf)
                for row in reader:
                    listGPS.append(row)
    sTime = datetime(tt/10000,(tt/100)%100,tt%100,0,0,0)
    c = 0
    for timethres in range(0,144):
        res = [[0 for x in range(w)] for y in range(h)]
        eTime = sTime + TIMEINTERVAL
        print timethres
        print sTime
        print eTime
        print "----"
        for i in range(0,len(listGPS)):
            t_date = datetime(int(listGPS[i][2][:4]),int(listGPS[i][2][5:7]),int(listGPS[i][2][8:10]),int(listGPS[i][2][11:13]),int(listGPS[i][2][14:16]),int(listGPS[i][2][17:19]))
            if (t_date > sTime and t_date < eTime):
                if (listGPS[i][1] == "0" and not listGPS[i-1][5] == listGPS[i][5]):
                    res[int(listGPS[i][5])][0] += 1
                if (listGPS[i-1][1] == "0" and listGPS[i][1] == "1"):
                    res[int(listGPS[i][5])][1] += 1
        outfile = os.getcwd() + "/" + (str)(tt) + "/count/" + (str)(sTime.time()).replace(":","") + '.csv' 
        with open(outfile, 'wb') as outputf:
            writer = csv.writer(outputf)
            for line in res:
                writer.writerow(line)
        sTime = eTime