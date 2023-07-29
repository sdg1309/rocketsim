#include <stdio.h>
#include <math.h>

float gravity(float mass, float distance){
    float earthmass  = 5.976*pow(10,24); //kg
    float G = 6.674*pow(10, -11);
    float grav = G*((earthmass*mass)/(pow(distance,2)));
    return(grav);
}

int main(){
    //crear archivo
    FILE *fpt;
    fpt = fopen("Infocambio.csv", "w+");
    fprintf(fpt,"seconds, weight change, fuel change, acceleration, velocity, hight, gravity change\n");


    //variables
    int weight = 1000; //kg
    float fuel = 100; //kg
    int trusts = 150; //N
    float fuelrate = 1.5; //kg per sec
    int high;
    float trueweight = weight-fuel;

    int time = 240;
    for(int i=0; i != time; i++){
        // weigh change
        fuel = fuel-fuelrate;
        float chweight = trueweight+fuel;
        if(fuel <= 1){
            fuel = 0;
            fuelrate = 0;
        }

        // gravity change
        float acceleration;
        float velocity = 0;
        float distance = 0;
        float gravch;

        if(fuel != 0){
        acceleration = trusts/chweight;
        velocity = velocity + acceleration;
        distance = distance + velocity;
        //gravity
        gravch = gravity(chweight, distance)/chweight;
        }

        else{
        acceleration = gravch;
        velocity = velocity+acceleration;
        distance = distance+velocity;
        gravch = gravity(chweight, distance)/chweight;
        }
        fprintf(fpt,"%i, %f, %f, %f, %f, %f, %f \n", i, chweight, fuel, acceleration, velocity, distance, gravch);
    }

    fclose(fpt);
}