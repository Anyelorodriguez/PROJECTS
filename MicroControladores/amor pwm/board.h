#ifndef __board_H__
#define __board_H__

// colores :3
#define 	ROJO			0x02
#define 	AZUL  		0x04
#define 	VERDE 		0x08
#define 	MORADO		0x06
#define 	MAGENTA		0x0C
#define 	AMARRILLO	0x0A
#define 	BLANCO		0x0E
#define 	APAGADO		0x00

/* Prototipo de la funcion */

//ahora este se va a board.c
 
void board_init(void);// (funcion ciclica)
int Lectura(void);     //funcion que devuelve un valor (buscar en .c)
//void delay_ms(int delay);

#endif // __board_H__