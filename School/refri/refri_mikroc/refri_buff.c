sbit add_25		at	P1_0_bit;
sbit add_50		at	P1_1_bit;
sbit add_100	at	P1_3_bit;
sbit select 	at	P3_6_bit;
sbit abortit	at	P3_7_bit;

sbit tipo1 		at 	P3_1_bit;

///Function prototypes
unsigned short check(unsigned short pt);
void configit();
void selectRefri();
void returnMoney();


//global variables
unsigned float total = 0.0;
unsigned short selectFlag = 0;
unsigned short i;


//GLCD things-------------------------------------------------------------//
// Glcd module connections
char GLCD_DataPort at P0;

sbit GLCD_CS1 at P2_0_bit;
sbit GLCD_CS2 at P2_1_bit;
sbit GLCD_RS  at P2_2_bit;
sbit GLCD_RW  at P2_3_bit;
sbit GLCD_EN  at P2_4_bit;
sbit GLCD_RST at P2_5_bit;


const code unsigned char Const_Text1[] = "Preco Refri: R$3.50";
const code unsigned char Const_Text2[] = "Selecione o Refri";
const code unsigned char Const_Text3[] = "Atual: ";
char* vartxt;
// End Glcd module connections--------------------------------------------//

char* codetxt_to_ramtxt(const char* ctxt);
void atualizaP();

void main() {
	configit();
	//P2 = 0xFF;

	selectFlag = 0;

	while(1){

		//wait untill the user ask for getting a refrigerant.
		if( check(select) ) selectFlag = 1;

		while(selectFlag == 1) {
			//P2 &= 0b01111111;
			tipo1 = 0;
			//check the buttons from adding.
			if( check(add_25) ){
				total = total + 0.25;
				//atualizaP();
				while( check(add_25) );
			}
			if( check(add_50) ){
				total =  total + 0.50;
				//atualizaP();
				while( check(add_50) );
			}
			if( check(add_100) ){
				total = total + 1.00;
				//atualizaP();
				while( check(add_100) );
			}


                        FloatToStr(total, vartxt);
                        Glcd_Write_Text(vartxt, 56,1,1);


			//check if it's going to abort the operation.
			if( check(abortit) ) {
				returnMoney();
				//total = 0;
				tipo1 = 1;
				//P2 &= 0x01111111;
			}

			//check if it has already enought money to choose a refrigerant.
			if(total >= 3.50){
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

unsigned short check(unsigned short pt) {
         //P1 = 0xFF;
	if(!pt) {
		Delay_ms(1);
		if(!pt) return 1;
	}
	return 0;
}

 /*
void atualizaP() {
                                      // Initialize GLCD
	//Glcd_Fill(0x00);                          // Clear GLCD
	//Glcd_Set_Font(font5x7, 5, 7, 32);
  	//Glcd_Write_Text(codetxt_to_ramtxt(Const_Text1), 1,0,1);
  	//atualizaP();
  	//Delay_ms(2);

  	/*for (i = 14; i < 54; i += 10)
  	{
	  	Glcd_Circle(80,i, 3, 1);
	        Glcd_Circle(90,i, 3, 1);
		Glcd_Circle(100, i, 3, 1);
	  	Glcd_Circle(110, i, 3, 1);
  	}
	Glcd_Write_Text(codetxt_to_ramtxt(Const_Text3), 1,1,1);
	FloatToStr(total, vartxt);
	Glcd_Write_Text(vartxt, 56,1,1);
}     */

/**
 * @brief Initial config of the system.
 * @details Configure the initial bits registers and operations mode in the system.
 */


void configit() {
	Glcd_Init();                              // Initialize GLCD
	Glcd_Fill(0x00);                          // Clear GLCD
	Glcd_Set_Font(font5x7, 5, 7, 32);
  	Glcd_Write_Text(codetxt_to_ramtxt(Const_Text1), 1,0,1);
  	atualizaP();

  	/*for (i = 14; i < 54; i += 10)
  	{
	  	Glcd_Circle(80,i, 3, 1);
	        Glcd_Circle(90,i, 3, 1);
		Glcd_Circle(100, i, 3, 1);
	  	Glcd_Circle(110, i, 3, 1);
  	}  */


}

/**
 * @brief delay milliseconds
 * @details delay function to milliseconds
 *
 * @param int the time wich will be delayed
 */
 /*
void Delay_ms(unsigned int mytime) {
	unsigned int i, j;
	for (i=0; i < mytime; i++)
	for (j=0; j < 1275; j++); //1ms delay
}
*/
/**
 * @brief The Refrigerant select section.
 * @details The selection section in GLCD and in the system, waiting for the refri selection.
 */
void selectRefri() {
	P1 = 0b00001111;
}

/**
 * @brief Return the money to the user.
 * @details Show in the graphic interface that it's going to return the money.
 */
void returnMoney() {
	P1 = 0b00000011;
}


//Display glcd functions------------------------------------------------------//


char* codetxt_to_ramtxt(const char* ctxt){
  static char txt[20];
  char i;
  for(i =0; txt[i] = ctxt[i]; i++);

  return txt;
}

/**
 * @brief Write text in the center of the GLCD.
 * @details Write the text in the center of the line with a limit of 9 characters.
 * @param txt The text that will be plotted.
 * @param linha The line where you're going to write the text.
 * @param charNum the number of characters in the text.
 * @param cor The color of the text.
 */
void writeGLCDTextCenter(unsigned char* txt, unsigned short linha, unsigned short charNum, unsigned short cor) {
	charNum/2*7
	Glcd_Write_Text(txt, 32-charNum/2*7,linha,cor);
}

//......other declarations and functions
