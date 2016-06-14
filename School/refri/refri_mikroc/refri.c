sbit add_25		at	P1_0_bit;
sbit add_50		at	P1_1_bit;
sbit add_100	at	P1_2_bit;
sbit select 	at	P3_6_bit;
sbit abortit	at	P3_7_bit;
sbit next		at 	P1_4_bit;
sbit back		at 	P1_4_bit;

sbit tipo1 		at 	P3_1_bit;

#include "background.c"

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

const code unsigned char Const_Text4[] = "Trabalho apresentado por:";
const code unsigned char Const_Text5[] = "Caio Gomes";
const code unsigned char Const_Text6[] = "Michael Barney";
const code unsigned char Const_Text7[] = "Otacilio Neto";

const code unsigned char nomeRefri_0[] = "Coca: ";
const code unsigned char nomeRefri_1[] = "Pespsi";
const code unsigned char nomeRefri_2[] = "Fanta";
const code unsigned char nomeRefri_3[] = "Sprite";
char* vartxt;

//extern unsigned char const background_bmp[1024];
//extern unsigned char const caio_bmp[1024];
//extern unsigned char const otacilio_bmp[1024];
//extern unsigned char const michael_bmp[1024];
// End Glcd module connections--------------------------------------------//

char* codetxt_to_ramtxt(const char* ctxt);
void atualizaP();
void creditos();
unsigned short refris[4] = {20, 20, 20, 20};
unsigned short rselect = 0;
unsigned int buff = 0;

void main() {
	Glcd_Init();                              // Initialize GLCD
	configit();
	//P2 = 0xFF;

	selectFlag = 1;

	while(1){

		//check the refrigerant selection buttons
		if( check(next) ) {
			if( rselect++ >= 4) rselect = 0;
			atualizaP();
			while( check(next) );
		}

		if( check(back) ) {
			if( rselect-- >= 4) rselect = 3;
			atualizaP();
			while( check(next) );
		}

		//check the buttons from adding.
		if( check(add_25) ) {
			total = total + 0.25;
			buff += 25;
			atualizaP();
			while( check(add_25) );
		}

		if( check(add_50) ) {
			total =  total + 0.50;
			buff += 50;
			atualizaP();
			while( check(add_50) );
		}
		if( check(add_100) ) {
			total = total + 1.00;
			buff += 100;
			atualizaP();
			while( check(add_100) );
		}

		//check if it's going to abort the operation.
		if( check(abortit) ) {
			returnMoney()
		}

		//check if it has already enought money to choose a refrigerant.
		if(total >= 3.50 && check(select)){
			if(total >= 10.0){
				creditos();
				while( !check(abortit) );
			}
			selectRefri();
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

 
 /**
  * @brief [brief description]
  * @details [long description]
  */
void atualizaP() {
	
	unsigned short i = 0;
	
	FloatToStr(total, vartxt);
	Glcd_Write_Text(vartxt, 56,1,1);
	
	for(i = 0; i< 4; i++){
		FloatToStr( refris[i], vartxt );
		Glcd_Write_Text(vartxt, 56,i+2,1);
	}
	
	
	
}     

/**
 * @brief Initial config of the system.
 * @details Configure the initial bits registers and operations mode in the system.
 */
void configit() {
	
	unsigned short i = 0;
	
	//Glcd_Init();                              // Initialize GLCD
	Glcd_Fill(0x00);                          // Clear GLCD
	Glcd_Set_Font(font5x7, 5, 7, 32);
	
  	Glcd_Write_Text(codetxt_to_ramtxt(Const_Text1), 1,0,1);
  	Glcd_Write_Text(codetxt_to_ramtxt(Const_Text3), 1,1,1);
  	
	Glcd_Write_Text(codetxt_to_ramtxt( nomeRefri_0 ), 1,2,1);
	Glcd_Write_Text(codetxt_to_ramtxt( nomeRefri_1 ), 1,3,1);
	Glcd_Write_Text(codetxt_to_ramtxt( nomeRefri_2 ), 1,4,1);
	Glcd_Write_Text(codetxt_to_ramtxt( nomeRefri_3 ), 1,5,1);
  	
  	
  	atualizaP();

}

/**
 * @brief The Refrigerant select section.
 * @details The selection section in GLCD and in the system, waiting for the refri selection.
 */
void selectRefri() {
	total -= 3.5;
	if(refris[rselect] != 0) refris[rselect]--;
	else nonRefri();
}

void nonRefri(){

}

/**
 * @brief Return the money to the user.
 * @details Show in the graphic interface that it's going to return the money.
 */
void returnMoney() {
	total -= buff/100.0;
}


//Display glcd functions------------------------------------------------------//

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param ctxt [description]
 * @return [description]
 */
char* codetxt_to_ramtxt(const char* ctxt){
  static char txt[20];
  char i;
  for(i =0; txt[i] = ctxt[i]; i++);

  return txt;
}

/**
 * @brief Write text in the center of the GLCD.
 * @details Write the text in the center of the line with a limit of 21 characters.
 * @param txt The text that will be plotted.
 * @param linha The line where you're going to write the text.
 * @param charNum the number of characters in the text.
 * @param cor The color of the text.
 */
void writeGLCDTextCenter(unsigned char* txt, unsigned short linha, unsigned short cor) {
	unsigned short charNum = 0;
	while(txt[charNum++]);
	Glcd_Write_Text(txt, 58 - charNum*5/2, linha, cor);
}

//......other declarations and functions


/**
 * @brief Convert a float value to a string
 * @details Convert a float value to a string with a determined precision after the 
 * 
 * @param myData [description]
 * @param char [description]
 * 
 * @return [description]
 */
unsigned char* floatToChar(float myData, unsigned char precisionRight){

    float aux = myData;
	unsigned int auxInt = 0;
	unsigned char b = (int) myData;
	unsigned char precisionLeft = 1;
	static unsigned char charater[18];
    unsigned char c = 0;


	//determina quantos caracteres existem antes da vírgula
	while(b /= 10){
		precisionLeft++;
	}

	b = 0;

	//coloca no array os números antes da vírgula
	while(b < precisionLeft){
		c = precisionLeft - 1 - b;
		aux = myData;
		//retrocede o número de casas decimais necessário
		//ex: 10.75(antes do loop) 1.075 após o loop
		while(c){
			aux /= 10;
            c--;
		}
		//retira o último dígito do número inteiro
		//ex: 107.5 (antes do loop) 7 após o loop
		auxInt = (int) aux;
		auxInt %= 10;
		charater[b] = auxInt + '0';
		b++;
	}


	//caso o usuário deseje ver valores após a vírgula
	if(precisionRight){
		//coloca uma vírgula no array
		charater[b] = '.';

		//coloca no array os valores após a vírgula
		while(++b <= precisionLeft + precisionRight){
			c = b - precisionLeft;
            auxInt = 0;//(int) myData;
			aux = myData - auxInt;
			//avança o número de casas decimais necessário
			//ex: 10.75(antes do loop) 107.5 após o loop
			while(c--){
				aux *= 10;
			}
			//retira o último dígito do número inteiro
			//ex: 107.5 (antes do loop) 7 após o loop
			auxInt = (int) aux;
			auxInt %= 10;
			charater[b] = auxInt + '0';
		}
	}
	charater[b] = 0;
	return charater;
}


//......other declarations and functions
/*
void creditos()
{
	Glcd_Fill(0x00); 
	Glcd_Set_Font(Character8x7, 8, 7, 32);
	Glcd_Write_Text("Trabalho apresentado por:", 1, 3, 2);
	Delay_ms(2000);
	
	Glcd_Fill(0x00); 
	Glcd_Set_Font(Character8x7, 8, 7, 32);
	Glcd_Write_Text("Caio Gomes", 1, 3, 2);
	Delay_ms(2000);
	
	Glcd_Fill(0x00); 
	Glcd_Image(caio_bmp);
	Delay_ms(2000);
	
	Glcd_Fill(0x00); 
	Glcd_Set_Font(Character8x7, 8, 7, 32);
	Glcd_Write_Text("Michael Barney", 1, 3, 2);
	Delay_ms(2000);
	
	Glcd_Fill(0x00); 
	Glcd_Image(michael_bmp);
	Delay_ms(2000);

	Glcd_Fill(0x00); 
	Glcd_Set_Font(Character8x7, 8, 7, 32);
	Glcd_Write_Text("Otacilio Neto", 1, 3, 2);
	Delay_ms(2000);
	
	Glcd_Fill(0x00); 
	Glcd_Image(otacilio_bmp);
	Delay_ms(2000);
}
/*