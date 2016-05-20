#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define HALF_PI (1.570796326794897)
unsigned char d = 100;


void buffon();
unsigned char getRight(double l,double rad, double position);
double mod(double x);

int main(void)
{
    
    buffon();
    
    #ifdef __MINGW32
        system("pause");
    #endif
    
    return 0;
}

void buffon()
{
    long i = 0;
    double Prob = 0;
    long rights = 0;
    int l = 50;
    long itNum = 10000000;
    double PiValue = 0;
    double mediaPi = 0.0;
    
    srand(time(NULL));
    while(i <= itNum){
        
        if(i%1000 == 0){
            printf("pi = %f (%lu) | acertos: %lu \n", PiValue, i, rights);
        }
        
        rights += getRight(l, rand(), rand()%d);
        
        PiValue = (double) (((double)i)/((double)rights))*(((double)2*l)/((double)d));//(1/Prob)*(2*l/d);
        if(PiValue == PiValue)mediaPi += PiValue;
        i++;
    }
    
    mediaPi /= (double)itNum;
    
    printf("\n\nPi Value is: %g\n", mediaPi);
    
}

unsigned char getRight(double l,double rad, double position)
{
    double a = 0;
    double b = 0;
    double c = 0;
    unsigned char got = 0;
    
    //convert to a value between 0 and pi/2
    //rad = (double) 4*HALF_PI*rad/RAND_MAX;
    
    a = sin(rad/100)*l;
    b = ((double)position) + a;
    //c = position - a;
    
    if(b > d || b < 0) got = 1;
    
    return got;
}

double mod(double x)
{
    if(x < 0) return -x;
    return x;
}
