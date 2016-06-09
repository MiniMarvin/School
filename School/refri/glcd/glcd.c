#include <8052.h>

__sfr __at (0xA1) P4;

#define RST      P2_5
#define LCD_RS   P2_2
#define LCD_CS   P2_0
#define LCD_SCL  1
#define LCD_SDA  4
#define PAGE_SEL 0xB0
#define COL_SEL  0x10

#ifdef CONFIG_LARGE_MEMORY
static unsigned char gfx_buf[8][128];

int _sdcc_external_startup()
{
        __sfr __at (0x8E) AUXR;
        AUXR = 0x0;

        return 0;
}
#endif

void delay(int x)
{
        int n,j;
        for(n = 0; n < x; n++)
                for(j = 0; j <= 50; j++);

}

void glcd_write_data(unsigned char dat)
{
        unsigned char maskdata = 0x80;

        LCD_CS = 0;
        LCD_RS = 1;

        while (maskdata) {
                P4 = P4 & ~LCD_SCL;

                if (dat & maskdata)
                        P4 = P4 | LCD_SDA;
                else
                        P4 = P4 & ~LCD_SDA;

                maskdata >>= 1;
                delay(200);
                P4 = P4 | LCD_SCL;
        }

        LCD_CS = 1;

}

void glcd_write_cmd(unsigned char cmd)
{
        unsigned char maskdata = 0x80;

        LCD_RS = 0;
        LCD_CS = 0;

        while (maskdata) {

                P4 = P4 &  ~LCD_SCL;

                if (cmd & maskdata)
                        P4 = P4 | LCD_SDA;
                else
                        P4 = P4 & ~LCD_SDA;

                maskdata >>= 1;
                delay(2);
                P4 = P4 | LCD_SCL ;

        }
        LCD_CS = 1;
}

void glcd_init(void)
{
        RST = 0;
        delay(1000);
        RST = 1;

        glcd_write_cmd(0xE2);            // S/W RESWT
        glcd_write_cmd(0xA3);            // LCD bias
        glcd_write_cmd(0xAF);            // Display ON
        glcd_write_cmd(0xA0);            // segment direction.
        glcd_write_cmd(0xC8);            // Common Direction.
        glcd_write_cmd(0x22);            // Regultion resistor select  //25
        glcd_write_cmd(0x81);            // EV Select.
        glcd_write_cmd(0x2f);            // Select EV value.
        glcd_write_cmd(0x2f);            // Power control


        glcd_write_cmd(0x40);            // Initial display line 40
        glcd_write_cmd(0xB0);            // Set page address
        glcd_write_cmd(0x10);            // Set coloumn addr  MSB
        glcd_write_cmd(0x00);            // Set coloumn addr LSB
        glcd_write_cmd(0xAF);            // Display ON
        glcd_write_cmd(0xA4);            // A5 .Normal display, all pixels OFF.
        glcd_write_cmd(0xA6);            // A7 .Normal display (Inverse Pixel)
}

void glcd_set_pixel(int x, int y, int color)
{
        int page,col;
        int row_in_page;

        page = y / 8;

        /* Selecting Page */
        glcd_write_cmd(PAGE_SEL | page);

        /* Selecting Column */
        col = ((x & 0xF0) >> 4) | 0x10;
        glcd_write_cmd(COL_SEL|col);
        glcd_write_cmd(x & 0xf);

        /* Pixel location */
        row_in_page = y % 8;

#ifdef CONFIG_LARGE_MEMORY
        if (color)
                gfx_buf[page][col] |= 1 << row_in_page;
        else
                gfx_buf[page][col] &= ~(1 << row_in_page);

        glcd_write_data(gfx_buf[page][col]);
#else
        if (color)
                glcd_write_data(1 << row_in_page);
#endif

}

int main()
{
        int i = 0, j = 0;

        glcd_init();

        for (i = 0; i < 128; i++)
                for (j = 0; j < 64; j++)
                        glcd_set_pixel(i, j, 1);
        return 0;
}