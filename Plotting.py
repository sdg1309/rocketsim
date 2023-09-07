import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("Infocambio_cinematico.csv")

dfFuel = df[df[' instFuel'] != 0]
dfNotFuel = df[(df[' instFuel'] == 0) & (df[' Height'] > 0)]

### Variables while fuel supported

#Acceleration
figA, axA = plt.subplots()


axA.plot(dfFuel['Seconds'], dfFuel[' Acceleration'])

axA.set_xlim(0, max(dfFuel["Seconds"]))
axA.set_ylim(min(dfFuel[' Acceleration']), max(dfFuel[' Acceleration']))

axA.set_xlabel('Seconds')
axA.set_ylabel('Acceleration')

axA.set_title('Acceleration over Time while fuel supported')

plt.savefig('Acceleration over time while fuel supported.png')

# Velocity
figV, axV = plt.subplots()


axV.plot(dfFuel['Seconds'], dfFuel[' Velocity'])

axV.set_xlim(0, max(dfFuel['Seconds'],))
axV.set_ylim(0, max(dfFuel[' Velocity'])+5)

axV.set_xlabel('Seconds')
axV.set_ylabel('Velocity')

axV.set_title('Velocity over Time while fuel supported')

plt.savefig('Velocity over time with fuel.png')

#Position
figP, axP = plt.subplots()

axP.plot(dfFuel['Seconds'], dfFuel[' Height'])

axP.set_xlim(0, max(dfFuel['Seconds']))
axP.set_ylim(0, max(dfFuel[' Height'])+10)

axP.set_xlabel('Seconds')
axP.set_ylabel('Height')

axP.set_title('Height over Time while fuel supported')

plt.savefig('Height over time with fuel.png')

### Variables without fuel

#Velocity

figVNotFuel, axVNotFuel = plt.subplots()


axVNotFuel.plot(df['Seconds'], df[' Velocity'])

axVNotFuel.set_xlim(min(dfNotFuel["Seconds"]), max(dfNotFuel["Seconds"]))
axVNotFuel.set_ylim(min(dfNotFuel[" Velocity"])-100, max(dfNotFuel[" Velocity"])+100)

axVNotFuel.set_xlabel('Seconds')
axVNotFuel.set_ylabel('Velocity')

axVNotFuel.set_title('Velocity over Time without fuel')

plt.savefig('Velocity over time without fuel.png')

#Position

figPnotFuel , axPnotFuel = plt.subplots()

axPnotFuel.plot(df['Seconds'], df[' Height'])

axPnotFuel.set_xlim(min(dfNotFuel["Seconds"]), max(dfNotFuel["Seconds"]))
axPnotFuel.set_ylim(0, max(dfNotFuel[" Height"])+100)

axPnotFuel.set_xlabel('Seconds')
axPnotFuel.set_ylabel('Height')

axPnotFuel.set_title('Height over Time without fuel')

plt.savefig('Height over time without fuel.png')


#General acceleration
figAG, axAG = plt.subplots()

axAG.plot(df['Seconds'], df[' Acceleration'])

axAG.set_xlim(0, max(df['Seconds']))
axAG.set_ylim(min(df[" Acceleration"])-1, max(df[" Acceleration"])+1)

axAG.set_xlabel('Seconds')
axAG.set_ylabel('Acceleration')

axAG.set_title('Acceleration over Time General')

plt.savefig('Acceleration over time General.png')
plt.show()

#General height over time
figPmix , axPmix = plt.subplots()

axPmix.plot(df['Seconds'], df[' Height'])

axPmix.set_xlim(min(df["Seconds"]), max(df["Seconds"]))
axPmix.set_ylim(0, max(df[" Height"])+100)

axPmix.set_xlabel('Seconds')
axPmix.set_ylabel('Height')

axPmix.set_title('Height over Time General')

plt.savefig('Height over time General.png')
plt.show()










