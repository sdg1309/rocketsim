#include <stdio.h>
#include <math.h>

float gravityAcceleration( float distance){
    float earthmass  = 5.976*pow(10,24); //kg
    float G = 6.674*pow(10, -11);
    float grav = G*((earthmass)/(distance*distance)); // m/s^2
    return(grav);
}

float drag(float density , float vel, float dragCoe, float area){
    
    return (0.5)*density*pow(vel, 2)*dragCoe*area;
}

float weight (float mass, float grav){
    return mass * grav;
}

float density (float pressure, float temperatureC){
    return pressure/(0.2869*(temperatureC+ 273.15));
}
float pressureTroposphere(float temperatureC){
    return 101.29*pow(((temperatureC+273.15)/288.08), 5.256);
}
float temperatureTroposphere(float height){
    return 15.04 -0.00649*height;
}
float pressureLowStratosphere(float height){
    return 22.65 * exp(1.73 - 0.000157 * height);
}

float temperatureStratosphere(float height){
    return -131.21 + 0.00299 * height;
}

float pressureStratosphere(float height){
    return 2.488 * pow(((temperatureStratosphere(height) + 273.1)/ 216.6), -11.388);
}
//https://www.grc.nasa.gov/www/k-12/rocket/atmosmet.html
int main(){
    //crear archivo
    FILE *fpt;
    FILE *fpt2;
    fpt = fopen("Infocambio_cinematico.csv", "w+");
    fpt2 = fopen("Infocambio_dinamico.csv", "w+");
    fprintf(fpt,"Seconds, instMass, instFuel, Acceleration, Velocity, Height, Gravitational Acceleration\n");
    fprintf(fpt2,"Seconds, instWeight, Thrust, Air Resistance, density\n");

    //variables
    float thrusts = 100000; //N
    float mass = 5000; //kg

    float fuel = 100; //kg
    float fuelrate = 1.5; //kg per sec

    float instMass = mass+fuel ;
    float earthRadius = 6371000;
    float acceleration; // m / s^{2}
    float velocity = 0; // m / s
    float distance = 0; // m
    float gravAcc;
    float gravForce;
    float airDensity;
    float dragCoe = 0.47;
    float crosSectionalArea = 9*3.14159;
    float Drag  = 0;

    int time = 10000;   
    for(float i=0; i <= time; i += 1){
        // weigh change

        if (i != 0){
            instMass = mass-fuel;
            fuel = fuel-fuelrate;
            
            if(fuel < 1){
                fuel = 0;
                fuelrate = 0;
            
            }
            instMass = mass+fuel;
        }
        if (distance <= 11000){
            airDensity = density(pressureTroposphere(temperatureTroposphere(distance)), temperatureTroposphere(distance));
        } 
        if (distance > 11000 && distance <= 25000){
            airDensity = density(pressureLowStratosphere(distance), -56.46);
        }
        if (distance > 25000){
            airDensity = density(pressureStratosphere(distance), temperatureStratosphere(distance));
        }
        if(fuel != 0){
          
            if (i == 0){
                velocity = 0;
                distance = 0;
            }
            else {
                distance = distance + velocity + acceleration/2;
                velocity = velocity + acceleration;
            }
            Drag = drag(airDensity, velocity, dragCoe, crosSectionalArea);
            acceleration = (thrusts-weight(instMass, gravityAcceleration(distance+earthRadius))-Drag)/instMass;
            
        // Motion without Fuel
        } else {
            thrusts = 0;
            distance = distance+velocity+acceleration/2;
            velocity = velocity+acceleration;
            Drag = drag(airDensity, velocity, dragCoe, crosSectionalArea);
            acceleration = (-weight(mass, gravityAcceleration(distance+earthRadius)))/mass;

            if (velocity <= 0){
                acceleration = (-weight(mass, gravityAcceleration(distance+earthRadius))+Drag)/mass;
            }
            
        }
        if (distance < 0){
            
        } else {
            fprintf(fpt,"%f, %f, %f, %f, %f, %f, %f \n", i, instMass, fuel, acceleration, velocity, distance, gravityAcceleration(distance+earthRadius));
            fprintf(fpt2, "%f, %f, %f, %f, %f \n", i, weight(instMass, gravityAcceleration(distance+earthRadius)), thrusts, Drag, airDensity );

        }
    }

    fclose(fpt);
    fclose(fpt2);
    return 0;
}