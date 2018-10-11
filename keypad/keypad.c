/* el8ltat
1) elfunction elly bycallha el module w el main my3rfha4 ..  lazem tb22a static + elprototype lazm gwa el C m4 .H
2) fe kol column hn5ly wa7d output w 3leh zero wl ba2y inputs + lw 3 columns m4 hnhtm awy bl pin elly na2sa
3) kolo fe function wa7da .. mfe4 function initazlie
*/
#include "keypad.h"

#define N_COLS 4
#define N_ROWS 4
int i ,j ;
static uint8 keypad_Convert(uint8);
uint8 keypad_read(void) //lazem de uint8 m4 void l2ny h call de m4 elconvert
{
while (1) //laazem while 1 34an yfdl ylf
{
for (i=0 ; i<N_COLS;i++)
{
#if (N_COLS == 3 )
	// ana deft el7ta de mn 3ndy fl 3 Columns 34an a2dr ast5dm el pin elly na2sa fl port " hwa bwzha fl code bta3o
	KEYPADPORTDATADIRECTION = (0b00010000<<i)&0x7F | (KEYPADPORTDATADIRECTION&0x80) ;


	KEYPADOUTPUTREG =(  (~(0b00010000<<i))&0x7F ) | (KEYPADOUTPUTREG&0x80)  ;

	// la8yy KEYPADOUTPUTREG =( KEYPADOUTPUTREG|0x70 ) & (~(1<<(4+i)) ) ;
#elif (N_COLS == 4 )
	KEYPADPORTDATADIRECTION = (0b00010000<<i);
KEYPADOUTPUTREG = (~(0b00010000<<i));
#endif
	for (j=0 ; j<N_ROWS;j++)
	{
		if(   BIT_IS_CLEAR(KEYPADINPUTREG,j))
			return (keypad_Convert( j*N_COLS +i +1)  );
	}
	}
}
}
uint8 keypad_Convert(uint8 NUM)
{
#if (N_COLS == 3 )
switch (NUM)
{
case 10 : return '*' ;
case 11 : return 0 ;
case 12 : return '#' ;
default : return NUM ;
}
#elif (N_COLS ==4 )
switch (NUM)
{
case 1: return 7 ;
case 2: return 8 ;
case 3: return 9 ;
case 4: return '/' ;
case 5: return 4 ;
case 6: return 5 ;
case 7: return 6 ;
case 8: return '*' ;

case 9: return 1 ;
case 10: return 2 ;
case 11: return 3 ;
case 12: return '-' ;

case 13: return 'o' ;
case 14: return 0 ;
case 15: return '=' ;
case 16: return '+' ;

}
#endif
}
