#include <stdio.h>
#include <math.h>

float gravityAcceleration( float distance){
    float earthmass  = 5.976*pow(10,24); //kg
    float G = 6.674*pow(10, -11);
    float grav = G*((earthmass)/(distance*distance)); // m/s^2
    return(grav);
}

int main(){
    //crear archivo
    FILE *fpt;
    fpt = fopen("Infocambio.csv", "w+");
    fprintf(fpt,"Seconds, instMass, instFuel, Acceleration, Velocity, Height, Gravitational Acceleration\n");


    //variables
    int mass = 100000; //kg

    float fuel = 100; //kg
    int trusts = 1000000; //N
    float fuelrate = 1.5; //kg per sec
    float instMass = mass+fuel;
    float earthRadius = 6371000;
    float acceleration; // m / s^{2}
    float velocity = 0; // m / s
    float distance = 0; // m
    float gravAcc;
    float gravForce;


    int time = 2000;   
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
       


        if(fuel != 0){
          
            if (i == 0){
                velocity = 0;
                distance = 0;
            }
            else {
                distance = distance + velocity + acceleration/2;
                velocity = velocity + acceleration;
            }
            acceleration = trusts/instMass;
        
        //gravity
        gravAcc = gravityAcceleration((distance+earthRadius));
        gravForce = gravAcc*instMass;
        }

        else{
        distance = distance+velocity+acceleration/2;
        velocity = velocity+acceleration;
        
        acceleration = -gravAcc;
        gravAcc = gravityAcceleration(distance+earthRadius);
        }
        fprintf(fpt,"%f, %f, %f, %f, %f, %f, %f \n", i, instMass, fuel, acceleration, velocity, distance, gravAcc);
    }

    fclose(fpt);
    return 0;
}