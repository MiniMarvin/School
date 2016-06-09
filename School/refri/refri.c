#include <8052.h>
#include <string.h>

#define bit __bit

#define add_25	P2_0
#define add_50	P2_1
#define add_100	P2_2
#define select	P2_3
#define abortit	P2_4

///Function prototypes
bit check(bit pt);
void config();
void selectRefri();
void returnMoney();
void Delay_ms(unsigned int mytime);

//global variables
unsigned int total = 0;
bit selectFlag;

void main() {
	config();
	//P2 = 0xFF;
	
	selectFlag = 0;

	while(1){

		//wait untill the user ask for getting a refrigerant.
		if(check(select)) selectFlag = 1;

		while(selectFlag == 1) {
			P2_7 = 0x00;
			//check the buttons from adding.
			if( check(add_25) ) total += 25;
			if( check(add_50) ) total += 50;
			if( check(add_100) ) total += 100;

			//check if it's going to abort the operation.
			if( check(abortit) ) {
				returnMoney();
				total = 0;
				P2_7 = 0x01;
			}
			
			//check if it has already enought money to choose a refrigerant.
			if(total >= 350){
				selectRefri();
			}
		}
	}
}

/**
 * @brief Check the state of a bit.
 * @details Analise if a port bit has been set and if it has returns 1, solve the bounce problem.
 * 
 * @param pt The bit wich we want to analyse.
 * @return The state of the bit/button.
 */
bit check(bit pt) {
	if(!pt) { 
		Delay_ms(1);
		if(!pt) return 1;
	}
	return 0;
}

/**
 * @brief Initial config of the system.
 * @details Configure the initial bits registers and operations mode in the system.
 */
void config() {
	
}

/**
 * @brief delay milliseconds
 * @details delay function to milliseconds
 * 
 * @param int the time wich will be delayed
 */
void Delay_ms(unsigned int mytime) {
	unsigned int i, j;
	for (i=0; i < mytime; i++)
	for (j=0; j < 1275; j++); //1ms delay
}

/**
 * @brief The Refrigerant select section.
 * @details The selection section in GLCD and in the system, waiting for the refri selection.
 */
void selectRefri() {

}

/**
 * @brief Return the money to the user.
 * @details Show in the graphic interface that it's going to return the money.
 */
void returnMoney() {
	P1 = 0b01010101;
}