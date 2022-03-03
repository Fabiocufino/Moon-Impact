from turtle import color
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.animation as animation

data = []

path="/home/fabio/Universita/MetodiComputazionali/Esame/PrimaStesura/Dati_veri_nasa/"


all_x_0= np.loadtxt(path + "sonda.txt", dtype=float, usecols=1)
all_y_0= np.loadtxt(path + "sonda.txt", dtype=float, usecols=2)
all_z_0= np.loadtxt(path + "sonda.txt", dtype=float, usecols=3)


all_x_1= np.loadtxt(path + "luna.txt", dtype=float, usecols=1)
all_y_1= np.loadtxt(path + "luna.txt", dtype=float, usecols=2)
all_z_1= np.loadtxt(path + "luna.txt", dtype=float, usecols=3)



fig = plt.figure()
ax = plt.axes(projection='3d')

i=1
while True:
    ax.plot(all_x_0[:i], all_y_0[:i], all_z_0[:i], color= "green", alpha=0.2)
    ax.plot(all_x_1[:i], all_y_1[:i], all_z_1[:i], color="red", alpha=0.2)
#    ax.plot(all_x_2[:i], all_y_2[:i], all_z_2[:i], color="blue", alpha=0.2)
#   ax.plot(all_x_3[:i], all_y_3[:i], all_z_3[:i], color="green", alpha=0.2)

    ax.plot(all_x_0[i], all_y_0[i], all_z_0[i], color= "green", marker='o', markersize=5)
    ax.plot(all_x_1[i], all_y_1[i], all_z_1[i], color="red",  marker='o', markersize=4)
#    ax.plot(all_x_2[i], all_y_2[i], all_z_2[i], color="blue", marker='o', markersize=1)
#   ax.plot(all_x_3[i], all_y_3[i], all_z_3[i], color="green", marker='o', markersize=1)

    i=i+1
    
    #fig.patch.set_facecolor('black')
    plt.pause(0.1)
    ax.clear()