import numpy as np
import matplotlib.pyplot as plt

#leyendo los datos y asignandoles variables para poder ser graficadas
datos=np.loadtxt("RadialVelocities.dat")
#print (datos)

radio=datos[:,0]
velocidad=datos[:,1]

#Definiendo las constantes
bb=0.2497
bd=5.16
ad=0.3105
ah=64.3
G=1

#Con los valores obtenidos en el codigo de C mostrados en la consola
Mb = 0.594944
Md = 0.928650
Mh = 0.424934 


#calculando la nueva velocidad con los tres parametros Mb, Md y Mh
#se crea un array solo de ceros que sera llenado con los valores encontrados y la formula del enunciado

velocidad_2 = np.zeros(len(radio))
for i in range (0, len(radio)):
    velocidad_2[i]= ((((Mb)**(1/2))*radio[i])/(((radio[i])**2+bb**2)**(3/4)))+((((Md)**(1/2))*radio[i])/(((radio[i])**2 + (bd + ad)**2)**(3/4)))+(((Mh)**(1/2))/((((radio[i])**2) + ah**2)**(1/4)))




#graficando ambos grupos de datos y generando la grafica

plt.plot(radio, velocidad, color='black', label="Curva datos")
plt.plot(radio, velocidad_2, color='cyan', label="Curva modelo")

plt.xlabel("Radio (kpc)")
plt.ylabel("Velocidad (km/s)")
plt.legend()
plt.savefig("Results_hw5.pdf")










