from turtle import color
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.animation as animation

data = []

path="/home/fabio/Universita/MetodiComputazionali/Esame/SecondaStesura/Output/Earth/"


all_x_0= np.loadtxt(path + "e_object3.dat", dtype=float, usecols=1)
all_y_0= np.loadtxt(path + "e_object3.dat", dtype=float, usecols=2)
all_z_0= np.loadtxt(path + "e_object3.dat", dtype=float, usecols=3)


all_x_1= np.loadtxt(path + "e_object4.dat", dtype=float, usecols=1)
all_y_1= np.loadtxt(path + "e_object4.dat", dtype=float, usecols=2)
all_z_1= np.loadtxt(path + "e_object4.dat", dtype=float, usecols=3)

all_x_2= np.loadtxt(path + "e_object11.dat", dtype=float, usecols=1)
all_y_2= np.loadtxt(path + "e_object11.dat", dtype=float, usecols=2)
all_z_2= np.loadtxt(path + "e_object11.dat", dtype=float, usecols=3)

path2="/home/fabio/Universita/MetodiComputazionali/Esame/SecondaStesura/Dati_veri_nasa/"


r_all_x_0= np.loadtxt(path2 + "sonda.txt", dtype=float, usecols=1)
r_all_y_0= np.loadtxt(path2 + "sonda.txt", dtype=float, usecols=2)
r_all_z_0= np.loadtxt(path2 + "sonda.txt", dtype=float, usecols=3)


r_all_x_1= np.loadtxt(path2 + "luna.txt", dtype=float, usecols=1)
r_all_y_1= np.loadtxt(path2 + "luna.txt", dtype=float, usecols=2)
r_all_z_1= np.loadtxt(path2 + "luna.txt", dtype=float, usecols=3)
#all_x_2= np.loadtxt('/home/fabio/Universita/MetodiComputazionali/Laboratorio/Lab4/prova.txt', usecols=0)
#all_y_2= np.loadtxt('/home/fabio/Universita/MetodiComputazionali/Laboratorio/Lab4/prova.txt', usecols=1)
#all_z_2= np.loadtxt('/home/fabio/Universita/MetodiComputazionali/Laboratorio/Lab4/prova.txt', usecols=2)











fig = plt.figure()
ax = plt.axes(projection='3d')
#plt.grid(True)
#plt.axis('off')

# Creating the Animation object
#ani = animation.FuncAnimation(plt.gcf(), animate, n_points, interval=5)
#ani.save('changes_collision.gif', writer='imagemagick', fps=60)    
i=3500
while True:
    ax.plot(all_x_0[:i], all_y_0[:i], all_z_0[:i], color= "green", alpha=0.2)
    ax.plot(all_x_1[:i], all_y_1[:i], all_z_1[:i], color="red", alpha=0.2)
    ax.plot(all_x_2[:i], all_y_2[:i], all_z_2[:i], color="blue", alpha=0.2)
    #ax.plot(r_all_x_0[:i], r_all_y_0[:i], r_all_z_0[:i], color="green", alpha=0.2)
    #ax.plot(r_all_x_1[:i], r_all_y_1[:i], r_all_z_1[:i], color="black", alpha=0.2)
#   ax.plot(all_x_3[:i], all_y_3[:i], all_z_3[:i], color="green", alpha=0.2)

    ax.plot(all_x_0[i], all_y_0[i], all_z_0[i], color= "green", marker='o', markersize=5)
    ax.plot(all_x_1[i], all_y_1[i], all_z_1[i], color="red",  marker='o', markersize=4)
    ax.plot(all_x_2[i], all_y_2[i], all_z_2[i], color="blue", marker='o', markersize=1)
    #ax.plot(r_all_x_1[i], r_all_y_1[i], r_all_z_1[i], color="black", marker='o', markersize=4)
    #ax.plot(r_all_x_0[i], r_all_y_0[i], r_all_z_0[i], color="green", marker='o', markersize=1 )
#   ax.plot(all_x_3[i], all_y_3[i], all_z_3[i], color="green", marker='o', markersize=1)

    i=i+1
    
    plt.title("Giorno " + str(i))
    plt.pause(0.01)
    if(i==4050):
         break
    ax.clear()