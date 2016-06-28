sbit add_25                at        P1_0_bit;
sbit add_50                at        P1_1_bit;
sbit add_100        at        P1_2_bit;
sbit select         at        P3_6_bit;
sbit abortit        at        P3_7_bit;
sbit next                at         P3_5_bit;
sbit back                at         P3_2_bit;

sbit tipo1                 at         P3_1_bit;

//#include "background.c"
#include "images.c"

///Function prototypes
unsigned short check(unsigned short pt);
void configit();
void selectRefri();
void returnMoney();
void noMoney();


//global variables
int total = 0;
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


const code unsigned char Const_Text4[] = "Apresentado por:";
const code unsigned char Const_Text5[] = "Caio Gomes";
const code unsigned char Const_Text6[] = "Michael Barney";
const code unsigned char Const_Text7[] = "Otacilio Neto";

const code unsigned char Const_Text8[] = "Operacao Cancelada.";
const code unsigned char Const_Text9[] = "Valor retornado:   ";
const code unsigned char Const_Text10[] = "P. ENTER TO CONTINUE";
const code unsigned char Const_Text11[] = "Qtd. insuficiente";
const code unsigned char Const_Text12[] = "Saldo insuficiente";

const code unsigned char nomeRefri_0[] = "Coca: ";
const code unsigned char nomeRefri_1[] = "Pespsi:";
const code unsigned char nomeRefri_2[] = "Fanta:";
const code unsigned char nomeRefri_3[] = "Sprite:";
char* vartxt;

//images
//const unsigned char caio_bmp[1024];
//const unsigned char michael_bmp[1024];
//const unsigned char otacilio_bmp[1024];

//extern unsigned char const background_bmp[1024];
//extern unsigned char const caio_bmp[1024];
//extern unsigned char const otacilio_bmp[1024];
//extern unsigned char const michael_bmp[1024];
// End Glcd module connections--------------------------------------------//

char* codetxt_to_ramtxt(const char* ctxt);
void atualizaP();
void creditos();
unsigned short refris[4] = {5, 5, 5, 5};//{20, 20, 20, 20};
unsigned short rselect = 0;
unsigned int buff = 0;
void nonRefri();
void paintRefri();
void writeGLCDTextCenter(const char* text, unsigned short linha, unsigned short cor);

void main() {
        Glcd_Init();                              // Initialize GLCD
        configit();
        //atualizaP();
        //P2 = 0xFF;

        selectFlag = 1;

        while(1){

                //check the refrigerant selection buttons
                if( check(next) ) {
                        if( ++rselect > 3) rselect = 0;
                        //atualizaP();
                        configit();
                        while( check(next) );
                }

                if( check(back) ) {
                        if( --rselect > 10) rselect = 3;
                        //atualizaP();
                        configit();
                        while( check(back) );
                }

                //check the buttons from adding.
                if( check(add_25) ) {
                        total = total + 25;
                        buff = buff + 25;
                        atualizaP();
                        while( check(add_25) );
                }

                if( check(add_50) ) {
                        total =  total + 50;
                        buff = buff + 50;
                        atualizaP();
                        while( check(add_50) );
                }
                if( check(add_100) ) {
                        total = total + 100;
                        buff = buff + 100;
                        atualizaP();
                        while( check(add_100) );
                }

                //check if it's going to abort the operation.
                if( check(abortit) ) {
                        returnMoney();
                }

                //check if it has already enought money to choose a refrigerant.
                if(total >= 350 && check(select)) {
                        if(total >= 1000){
                                Glcd_Fill(0x00); 
                                //Glcd_Write_Text("creditos", 1,0,1);
                                creditos();
                                while( !check(abortit) );
                        }
                        selectRefri();
                }
                else if(total <= 350 && check(select)) {
                        noMoney();
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
        /*
        IntToStr( total, vartxt);
        Glcd_Write_Text(vartxt, 56,1,1);
        
        ShortToStr( refris[0], vartxt );
        Glcd_Write_Text(vartxt, 56,2,1);
        ShortToStr( refris[1], vartxt );
        Glcd_Write_Text(vartxt, 56,3,1);
        ShortToStr( refris[2], vartxt );
        Glcd_Write_Text(vartxt, 56,4,1);
        ShortToStr( refris[3], vartxt );
        Glcd_Write_Text(vartxt, 56,5,1);

        Glcd_Write_Text("  ", 88,2,1);
        Glcd_Write_Text("  ", 88,3,1);
        Glcd_Write_Text("  ", 88,4,1);
        Glcd_Write_Text("  ", 88,5,1);
        Glcd_Write_Text("*", 90,rselect+2,1);
        */
        
        Glcd_Write_Text(" ", 3,1,1);

        IntToStr( total, vartxt-2);
        Glcd_Write_Text(vartxt, 3,1,1);
        
        Glcd_Write_Text(" ", 110,4,1);
        
        ShortToStr( refris[rselect], vartxt-1);
        Glcd_Write_Text(vartxt, 100,4,1);
        
        paintRefri();

        //Glcd_Write_Text(" ", 1,2,1);
        //Glcd_Write_Text(" ", 1,3,1);
        //Glcd_Write_Text(" ", 1,4,1);
        //Glcd_Write_Text(" ", 1,5,1);
        //Glcd_Write_Text("*", 1,rselect+2,1);
        
        
}     

void paintRefri() {
    //unsigned short i = 0;
    //unsigned short j = 0;
    //unsigned short px = 0;
    //Glcd_Rectangle(unsigned short x_upper_left, unsigned short y_upper_left, unsigned short x_bottom_right, unsigned short y_bottom_right, unsigned short color);
    //Glcd_Rectangle(19+11*rselect, 1, 30+11*rselect, 29, 1);
    Glcd_Rectangle(1,19+11*rselect, 28,30+11*rselect - 1, 1);

    /*
    for (i = 19 + 11*rselect; i < 30 + 11*rselect; ++i)
    {
        for (j = 1; j < 29; ++j)
        {
        	px = !background_bmp[128*j+64*i];
            Glcd_Dot(j, i, px);//1);
        }
    }
    */
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
        
          //Glcd_Write_Text(codetxt_to_ramtxt(Const_Text1), 1,0,1);
          //Glcd_Write_Text(codetxt_to_ramtxt(Const_Text3), 1,1,1);
          
        //Glcd_Write_Text(codetxt_to_ramtxt( nomeRefri_0 ), 1,2,1);
        //Glcd_Write_Text(codetxt_to_ramtxt( nomeRefri_1 ), 1,3,1);
        //Glcd_Write_Text(codetxt_to_ramtxt( nomeRefri_2 ), 1,4,1);
        //Glcd_Write_Text(codetxt_to_ramtxt( nomeRefri_3 ), 1,5,1);
        
        Glcd_Image(background_bmp);
          
        atualizaP();

}

/**
 * @brief The Refrigerant select section.
 * @details The selection section in GLCD and in the system, waiting for the refri selection.
 */
void selectRefri() {
        total -= 350;
        buff -= 350;
        if(refris[rselect] != 0) {
                refris[rselect]--;
                configit();
                
                Glcd_Image(background1_bmp);
                atualizaP();
                delay_ms(500);
                
                Glcd_Image(background2_bmp);
                atualizaP();
                delay_ms(500);
                
                Glcd_Image(background3_bmp);
                atualizaP();
                delay_ms(500);
                
                while( !check(select) );
                
                configit();
        }
        else nonRefri();
}

/**
 * 
 */
void nonRefri(){
        writeGLCDTextCenter(Const_Text11, 5, 1);
        writeGLCDTextCenter(Const_Text10, 6, 1);
        while(check(select));
        while(!check(select));
        configit();
}

/**
 * @brief Return the money to the user.
 * @details Show in the graphic interface that it's going to return the money.
 */
void returnMoney() {

        Glcd_Fill(0x00);
        writeGLCDTextCenter(Const_Text8, 2, 1);
        writeGLCDTextCenter(Const_Text9, 3, 1);
        writeGLCDTextCenter(Const_Text10, 5, 1);
        IntToStr(buff, vartxt);
        Glcd_Write_Text(vartxt, 80, 3, 1);
        while(!check(select));

        if(total >= buff) total = total - buff;
        buff = 0;

        configit();
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
void writeGLCDTextCenter(const char* text, unsigned short linha, unsigned short cor) {
        unsigned char* txt;
        unsigned short charNum = 0;

        txt = codetxt_to_ramtxt(text);
        
        while(txt[charNum++]);
        Glcd_Write_Text(txt, 58 - charNum*5/2, linha, cor);
}

//......other declarations and functions

//......other declarations and functions

void creditos()
{
        Glcd_Fill(0x00); 
        Glcd_Set_Font(Character8x7, 8, 7, 32);
        //Glcd_Write_Text( codetxt_to_ramtxt(Const_Text4), 1, 3, 2);
        writeGLCDTextCenter(Const_Text4, 3, 2);
        Delay_ms(2000);
        
        Glcd_Fill(0x00); 
        Glcd_Set_Font(Character8x7, 8, 7, 32);
        Glcd_Write_Text( codetxt_to_ramtxt(Const_Text5), 1, 3, 2);
        writeGLCDTextCenter(Const_Text5, 3, 2);
        Delay_ms(2000);
        
        /*
        Glcd_Fill(0x00); 
        Glcd_Image(background_bmp);
        Delay_ms(2000);
        */
        
        //Glcd_Fill(0x00); 
        //Glcd_Image(caio_bmp);
        //Delay_ms(2000);
        
        Glcd_Fill(0x00); 
        Glcd_Set_Font(Character8x7, 8, 7, 32);
        //Glcd_Write_Text(codetxt_to_ramtxt(Const_Text6), 1, 3, 2);
        writeGLCDTextCenter(Const_Text6, 3, 2);
        Delay_ms(2000);
        
        Glcd_Fill(0x00); 
        Glcd_Image(michael_bmp);
        Delay_ms(2000);

        Glcd_Fill(0x00); 
        Glcd_Set_Font(Character8x7, 8, 7, 32);
        //Glcd_Write_Text(codetxt_to_ramtxt(Const_Text7), 1, 3, 2);
        writeGLCDTextCenter(Const_Text7, 3, 2);
        Delay_ms(2000);
        
        Glcd_Fill(0x00); 
        Glcd_Image(otacilio_bmp);
        Delay_ms(2000);
}

void noMoney() {
        writeGLCDTextCenter(Const_Text12, 5, 1);
        writeGLCDTextCenter(Const_Text10, 6, 1);
        while(check(select));
        while(!check(select));
        configit();
}
