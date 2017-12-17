#define BUTTON1_bm	(1<<4)
#define BUTTON2_bm	(1<<6)
#define BUTTON3_bm	(1<<5)
#define BUTTON4_bm	(1<<7)

char ReadButton1(void);
void KeyboardInit(void);
char eKeyboarRead(void);
unsigned char ReadKey(void);
