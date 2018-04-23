from serial import Serial
import numpy as np

serPort = Serial("COM10", baudrate=19200, timeout=None)
print(serPort)

lu = []

while True:
    data = serPort.readline()
    data = data.strip()
    if data == b'-1':
        serPort.close()
        print("Fin")
        break 
    if data is not "": 
        data = list(map(float,data.split()))
        print(data) 
        if len(data) > 1:
            lu.append(data)

lu = np.array(lu) 
X  = lu[:,0] 
Y  = lu[:,1]

from time import strftime
uniqFileName = "TensionData_"+strftime("%Y-%m-%d_%H-%M-%S")+".txt"
fOut = open(uniqFileName, "w");
LF = "\r\n"
fOut.write("#Temps [ms]\tTension [V]"+LF)
for x, y in zip(X,Y):
    fOut.write("{:f}\t{:f}{:s}".format(x, y, LF))
fOut.close()

import matplotlib.pyplot as plt
plt.figure()
plt.grid(True)
plt.xlabel("Temps [s]")
plt.ylabel("Tension [V]")
plt.ylim(-0.1,5.1)
plt.plot(X/1000, Y, "o-b")
plt.show()
