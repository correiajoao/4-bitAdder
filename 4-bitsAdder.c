/* Universidade Federal de Alagoas - Campus A.C. Simões
*  Developer: João Lucas Marques Correia
*  Description: Four bits adder
*  Repository: https://github.com/correiajoao/4-bitAdder.git
*/

#include <stdio.h>

//Logic gate and
int and(int bitOne, int bitTwo){
	return bitOne & bitTwo;
}
//Logic gate or
int or(int bitOne, int bitTwo){
	return bitOne | bitTwo;
		
}
	
//Logic gate exclusive or 
int xor(int bitOne, int bitTwo){
	return bitOne ^ bitTwo;
}	


int main(int argc, char *argv[ ]){
	
	int firstNumber[3];
	int secondNumber[3];

	// Transforming the parameters string in binary vectors
	// This conversion - Char to int - is based in the ASCII table	
	firstNumber[0] = argv[1][0]-48;   
	firstNumber[1] = argv[1][1]-48;
	firstNumber[2] = argv[1][2]-48;
	firstNumber[3] = argv[1][3]-48;
 
	secondNumber[0] = argv[2][0]-48;
	secondNumber[1] = argv[2][1]-48;
	secondNumber[2] = argv[2][2]-48;
	secondNumber[3] = argv[2][3]-48;
	
	/*  The sum is of the type
	*
	*    firstNumber[0]   firstNumber[1]   firstNumber[2]   firstNumber[3]
	*  + secondNumber[0]  secondNumber[1]  secondNumber[2]  secondNumber[3]
	*   -------------------------------------------------------------------
	*    res[0]           res[1] 	       res[2]           res[3]
	*/
	
	int carryIn = 0;	
	int carryOut = 0;

	int res[3];

	// This part simulates what is described in the electric scheme
	
	res[3] = xor(carryIn, xor(firstNumber[3],secondNumber[3]));
	carryOut = or(and(firstNumber[3],secondNumber[3]),and(carryIn,xor(firstNumber[3],secondNumber[3])));
	carryIn = carryOut;
 	
	res[2] = xor(carryIn, xor(firstNumber[2],secondNumber[2]));
	carryOut = or(and(firstNumber[2],secondNumber[2]),and(carryIn,xor(firstNumber[2],secondNumber[2])));
	carryIn = carryOut; 
	
	res[1] = xor(carryIn, xor(firstNumber[1],secondNumber[1]));
	carryOut = or(and(firstNumber[1],secondNumber[1]),and(carryIn,xor(firstNumber[1],secondNumber[1])));
	carryIn = carryOut; 
	
	res[0] = xor(carryIn, xor(firstNumber[0],secondNumber[0]));
	carryOut = or(and(firstNumber[0],secondNumber[0]),and(carryIn,xor(firstNumber[0],secondNumber[0])));
	carryIn = carryOut; 
	
	if(carryIn == 1){
		printf("%d %d %d %d %d\n", carryIn, res[0],res[1],res[2],res[3]);
	}else{
		printf("%d %d %d %d\n", res[0],res[1],res[2],res[3]);
			
	}		

	return 0;
}
