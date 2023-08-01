import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("Infocambio.csv")

dfFuel = df[df[' instFuel'] != 0]
dfNotFuel = df[(df[' instFuel'] == 0) & (df[' Height'] > 0)]



minAcce = min(dfFuel[" Acceleration"])
maxAcce = max(dfFuel[" Acceleration"])
maxVel = max(dfFuel[" Velocity"])
maxP = max(dfFuel[" Height"])
maxSecond = max(dfFuel["Seconds"])

figA, axA = plt.subplots()

# Plot the data on the Axes object
axA.plot(df['Seconds'], df[' Acceleration'])

axA.set_xlim(0, max(df["Seconds"]))
axA.set_ylim(min(df[' Acceleration']), max(df[' Acceleration']))

axA.set_xlabel('Seconds')
axA.set_ylabel('Acceleration')

axA.set_title('Acceleration over Time General')

plt.savefig('Acceleration over time General.png')
plt.show()

#General acceleration
figAG, axAG = plt.subplots()

axAG.plot(df['Seconds'], df[' Acceleration'])

axAG.set_xlim(0, maxSecond)
axAG.set_ylim(minAcce-0.01, maxAcce+0.01)

axAG.set_xlabel('Seconds')
axAG.set_ylabel('Acceleration')

axA.set_title('Acceleration over Time while fuel supported')

plt.savefig('Acceleration over time.png')
plt.show()




#Velocity vs time

figV, axV = plt.subplots()


axV.plot(df['Seconds'], df[' Velocity'])

axV.set_xlim(0, maxSecond)
axV.set_ylim(0, maxVel+5)

axV.set_xlabel('Seconds')
axV.set_ylabel('Velocity')

axV.set_title('Velocity over Time while fuel supported')

plt.savefig('Velocity over time with fuel.png')
plt.show()

figVNotFuel, axVNotFuel = plt.subplots()


axVNotFuel.plot(df['Seconds'], df[' Velocity'])

axVNotFuel.set_xlim(min(dfNotFuel["Seconds"]), max(dfNotFuel["Seconds"]))
axVNotFuel.set_ylim(min(dfNotFuel[" Velocity"])-100, max(dfNotFuel[" Velocity"])+100)

axVNotFuel.set_xlabel('Seconds')
axVNotFuel.set_ylabel('Velocity')

axVNotFuel.set_title('Velocity over Time without fuel')

plt.savefig('Velocity over time without fuel.png')
plt.show()


#Position vs Time
figP, axP = plt.subplots()


axP.plot(df['Seconds'], df[' Height'])

axP.set_xlim(0, maxSecond)
axP.set_ylim(0, maxP+10)

axP.set_xlabel('Seconds')
axP.set_ylabel('Height')

axP.set_title('Height over Time while fuel supported')

plt.savefig('Height over time with fuel.png')
plt.show()

figPnotFuel , axPnotFuel = plt.subplots()

axPnotFuel.plot(df['Seconds'], df[' Height'])

axPnotFuel.set_xlim(min(dfNotFuel["Seconds"]), max(dfNotFuel["Seconds"]))
axPnotFuel.set_ylim(0, max(dfNotFuel[" Height"])+100)

axPnotFuel.set_xlabel('Seconds')
axPnotFuel.set_ylabel('Height')

axPnotFuel.set_title('Height over Time without fuel')

plt.savefig('Height over time without fuel.png')

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










