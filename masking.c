#include <stdio.h>


//clears bit at position i.
 unsigned int clearBit(unsigned int r1, unsigned int i){
     r1 = r1 & ~(1 << i); // clear bit at i;
     return r1;
 }

//sets bit at position i to be 1.
 unsigned int setBit(unsigned int r1, unsigned int i){
      r1 = r1 | (1 << i); // set bit at i;
      return r1;
  }

//initializes array[] starting at value 'first', 'nelem' elemts long.
 int init (int first, int array[], int nelem){
     int i ;
     array[0] = first ;
     for(i = 1; i < nelem; i++){
         array[i] = array[i-1] * 3 ;
     }
     return nelem;
 }


int main(){

    //TEST
    unsigned int R0,R1;
    R0 = 0xFFFF;
    R1 = 0x0000;
    R0 = clearBit(R0,2);
    R1 = setBit(R1,0);
    R1 = setBit(R1,1);
    R1 = setBit(R1,2);
    R1 = setBit(R1,3);

    printf( "%X\n" , R0);
    printf( "%X\n" , R1);
    return 0;
}