//************************************************************************************
//**  
//**  File name:     E:\Mirkoracunari\Sedmo segmentni displej sa Up i Down\Sedmosegmentni_display.c
//**  Title:         
//**  Description:   
//**  
//**  Generated by:  Flowcode v5.5.2.1
//**  Date:          Sunday, November 26, 2017 19:50:33
//**  Licence:       Professional
//**  Registered to: xyz
//**  Licence key:   WUK7B9
//**  
//**  
//**  http://www.matrixmultimedia.com
//**  
//************************************************************************************


#define MX_PIC

#define MX_USES_UINT8 1
#define MX_USES_SINT16 0
#define MX_USES_CHAR 0
#define MX_USES_FLOAT 0
#define MX_USES_SINT32 0
#define MX_USES_BOOL 1
#define MX_USES_UINT16 0
#define MX_USES_UINT32 0
//Defines for microcontroller
#define P16F877
#define FC_CAL_PIC
#define MX_ADC
#define MX_ADC_TYPE_30
#define MX_ADC_BITS_10
#define MX_EE
#define MX_EE_TYPE2
#define MX_EE_SIZE 256
#define MX_SPI_1
#define MX_SPI_1_MISO_PORT portc
#define MX_SPI_1_MISO_TRIS trisc
#define MX_SPI_1_MISO_PIN 4
#define MX_SPI_1_MOSI_PORT portc
#define MX_SPI_1_MOSI_TRIS trisc
#define MX_SPI_1_MOSI_PIN 5
#define MX_SPI_1_CLK_PORT portc
#define MX_SPI_1_CLK_TRIS trisc
#define MX_SPI_1_CLK_PIN 3
#define MX_SPI_1_SS_PORT portc
#define MX_SPI_1_SS_TRIS trisc
#define MX_UART_1
#define MX_UART_1_TX_PORT portc
#define MX_UART_1_TX_TRIS trisc
#define MX_UART_1_TX_PIN 6
#define MX_UART_1_RX_PORT portc
#define MX_UART_1_RX_TRIS trisc
#define MX_UART_1_RX_PIN 7
#define MX_I2C
#define MX_MI2C
#define MX_I2C_1
#define MX_I2C_1_SDA_PORT portc
#define MX_I2C_1_SDA_TRIS trisc
#define MX_I2C_1_SDA_PIN 4
#define MX_I2C_1_SCL_PORT portc
#define MX_I2C_1_SCL_TRIS trisc
#define MX_I2C_1_SCL_PIN 3
#define MX_PWM
#define MX_PWM_CNT 2
#define MX_PWM_PSCA1
#define MX_PWM_PSCA4
#define MX_PWM_PSCA16
#define MX_PWM_1_PORT portc
#define MX_PWM_1_TRIS trisc
#define MX_PWM_1_PIN 2
#define MX_PWM_2_PORT portc
#define MX_PWM_2_TRIS trisc
#define MX_PWM_2_PIN 1

//Functions
#define MX_CLK_SPEED 10000000
#ifdef _BOOSTC
#include <system.h>
#endif
#ifdef HI_TECH_C
#include <pic.h>
#endif

//Configuration data
#ifdef _BOOSTC
#pragma DATA 0x2007, 0x3f7a
#endif
#ifdef HI_TECH_C
__CONFIG(0x3f7a);
#endif

//Internal functions
#include "C:\Program Files (x86)\Flowcode\v5\FCD\internals.c"

//Macro function declarations


//Variable declarations
#define FCV_FALSE (0)
#define FCV_TRUE (1)
MX_UINT8 FCV_DOWN;
MX_UINT8 FCV_UP;
MX_UINT8 FCV_BROJAC;




//led7seg(0): //Defines:

/**** Macro Substitutions ****
a = Unique Reference
b = Segment Port letter
c = Common Port letter
d = Segment Pin 0
e = Segment Pin 1
f = Segment Pin 2
g = Segment Pin 3
h = Segment Pin 4
i = Segment Pin 5
j = Segment Pin 6
k = Segment Pin 7
l = Common Pin
m = Display Type 0=Common Cathode, 1=Common Anode
******************************/

#define SEVENSEG1_1_SEG_PORT		portb
#define SEVENSEG1_1_SEG_TRIS		trisb
#define SEVENSEG1_1_COM_PORT		porta
#define SEVENSEG1_1_COM_TRIS		trisa
#define SEVENSEG1_1_SEG_PIN0		0
#define SEVENSEG1_1_SEG_PIN1		1
#define SEVENSEG1_1_SEG_PIN2		2
#define SEVENSEG1_1_SEG_PIN3		3
#define SEVENSEG1_1_SEG_PIN4		4
#define SEVENSEG1_1_SEG_PIN5		5
#define SEVENSEG1_1_SEG_PIN6		6
#define SEVENSEG1_1_SEG_PIN7		7
#define SEVENSEG1_1_COM_PIN		3
#define SEVENSEG1_1_COM_TYPE		0

#ifndef SEVENSEG1_1_ARRAY
 #define SEVENSEG1_1_ARRAY
 ROMARRAY_S SEVENSEG1_1_SegmentArray ROMARRAY_E = {192, 249, 164, 176, 153, 146, 130, 248, 128, 152};		//Create ROM pattern array for the display
#endif




//led7seg(0): //Macro function declarations

void FCD_led7seg0_ShowDigit(MX_UINT8 Value, MX_UINT8 DecimalPoint);
void FCD_led7seg0_ClearDigit();



//led7seg(0): //Macro implementations


void FCD_led7seg0_ShowDigit(MX_UINT8 Value, MX_UINT8 DecimalPoint)
{
	
		MX_UINT8 cSegmentValue = SEVENSEG1_1_SegmentArray[Value % 10];

		if (DecimalPoint)
			cSegmentValue = cSegmentValue & 0x7F;			//Clear decimal point bit

		//display the digit
	    #if (SEVENSEG1_1_COM_TYPE == 1)						//Common Anode - Low = on, High = off

			if (cSegmentValue & 0x01)
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN0);
			}
			else
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN0);
			}

			if (cSegmentValue & 0x02)
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN1);
			}
			else
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN1);
			}

			if (cSegmentValue & 0x04)
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN2);
			}
			else
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN2);
			}

			if (cSegmentValue & 0x08)
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN3);
			}
			else
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN3);
			}

			if (cSegmentValue & 0x10)
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN4);
			}
			else
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN4);
			}

			if (cSegmentValue & 0x20)
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN5);
			}
			else
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN5);
			}

			if (cSegmentValue & 0x40)
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN6);
			}
			else
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN6);
			}

			if (cSegmentValue & 0x80)
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN7);
			}
			else
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN7);
			}

			FC_CAL_Bit_High_DDR(SEVENSEG1_1_COM_PORT, SEVENSEG1_1_COM_TRIS, SEVENSEG1_1_COM_PIN);

		#else												//Common Cathode - Low = off, High = on

			if (cSegmentValue & 0x01)
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN0);
			}
			else
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN0);
			}

			if (cSegmentValue & 0x02)
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN1);
			}
			else
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN1);
			}

			if (cSegmentValue & 0x04)
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN2);
			}
			else
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN2);
			}

			if (cSegmentValue & 0x08)
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN3);
			}
			else
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN3);
			}

			if (cSegmentValue & 0x10)
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN4);
			}
			else
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN4);
			}

			if (cSegmentValue & 0x20)
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN5);
			}
			else
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN5);
			}

			if (cSegmentValue & 0x40)
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN6);
			}
			else
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN6);
			}

			if (cSegmentValue & 0x80)
			{
				FC_CAL_Bit_Low_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN7);
			}
			else
			{
				FC_CAL_Bit_High_DDR(SEVENSEG1_1_SEG_PORT, SEVENSEG1_1_SEG_TRIS, SEVENSEG1_1_SEG_PIN7);
			}

			FC_CAL_Bit_Low_DDR(SEVENSEG1_1_COM_PORT, SEVENSEG1_1_COM_TRIS, SEVENSEG1_1_COM_PIN);

		#endif

}

void FCD_led7seg0_ClearDigit()
{
	
		#if (SEVENSEG1_1_COM_TYPE == 1)
			FC_CAL_Bit_Low_DDR(SEVENSEG1_1_COM_PORT, SEVENSEG1_1_COM_TRIS, SEVENSEG1_1_COM_PIN);		//common anode
		#else
			FC_CAL_Bit_High_DDR(SEVENSEG1_1_COM_PORT, SEVENSEG1_1_COM_TRIS, SEVENSEG1_1_COM_PIN);		//common cathode
		#endif

}

#include "C:\Program Files (x86)\Flowcode\v5\CAL\includes.c"

//Macro implementations

//U ovom zadatku cemo prikazati rad sedmosegmentnog displaya sa mogucnosti mjenjanja vrijednosti cifre tasterom


void main()
{
	//Initialization
	adcon1 = 0x07;


	//Interrupt initialization code
	option_reg = 0xC0;


	//Definisemo imena varijabli njihove pocetne vrijednosti i njihove
	//Calculation:
	//  Brojac = 5
	//  Up = 1
	//  Down = 1
	FCV_BROJAC = 5;
	FCV_UP = 1;
	FCV_DOWN = 1;

	//Prikaz vrijednosti iz varijable Brojac
	//Call Component Macro: ShowDigit(Brojac, 0)
	FCD_led7seg0_ShowDigit(FCV_BROJAC, 0);

	//Beskonacna petlja jer zelimo da nam displej radi pomocu tastera 
	//Loop: While 1
	while (1)
	{

		//Taster Up je upolozaju  1
		//Input: A1 -> Up
		trisa = trisa | 0x02;
		FCV_UP = ((porta & 0x02) == 0x02);

		//Comment:
		//Donosi odluku u odnosu na vrijednost varijable Up

		//Decision
		//Decision: Up = 0?
		if (FCV_UP == 0)
		{

			//Povecanje vrijednosti varijable za jedan
			//Calculation:
			//  Brojac = Brojac + 1
			FCV_BROJAC = FCV_BROJAC + 1;

			//Prikaz varijable Brojac na displeju
			//Call Component Macro: ShowDigit(Brojac, 0)
			FCD_led7seg0_ShowDigit(FCV_BROJAC, 0);

			//Comment:
			//Ako je brojac veci od 9 vrijednost varijable brojac ce postaviti na 0
			//to nam ogranicava brojac da broji u opsego od 0 do 9 

			//Loop
			//Loop: While Brojac > 9
			while (FCV_BROJAC > 9)
			{

				//Definisem vrijednost varijable Brojac da je jednako nula
				//Calculation:
				//  Brojac = 0
				FCV_BROJAC = 0;

				//Prikaz varijable Brojac na displeju
				//Call Component Macro: ShowDigit(Brojac, 0)
				FCD_led7seg0_ShowDigit(FCV_BROJAC, 0);


			}

			//Ako je taster Up=0
			//Loop: While Up = 0
			while (FCV_UP == 0)
			{

				//Polozaj tastera je u stanju varijable Up
				//Input: A1 -> Up
				trisa = trisa | 0x02;
				FCV_UP = ((porta & 0x02) == 0x02);


			}

			//Comment:
			//Ako je Up = 0  onda ce proces zadrzati u petlji i postaviti Up = 1

		// } else {

		}

		//Taster Down je u polozaju varijable Down 1
		//Input: A0 -> Down
		trisa = trisa | 0x01;
		FCV_DOWN = ((porta & 0x01) == 0x01);

		//Donosi odluku u odnosu na varijablu Down
		//Decision: Down = 0?
		if (FCV_DOWN == 0)
		{

			//Vrijednost na displayu se umanjuje za jedan
			//Calculation:
			//  Brojac = Brojac - 1
			FCV_BROJAC = FCV_BROJAC - 1;

			//Prikaz vrijednosti varijable Brojac na displeju
			//Call Component Macro: ShowDigit(Brojac, 0)
			FCD_led7seg0_ShowDigit(FCV_BROJAC, 0);

			//Comment:
			//Ako je brojac = 0 onda ce varijablu brojac postaviti na 9
			//to nam onemogucava da brojac prikazuje brojeve manje od 0

			//Loop
			//Loop: While Brojac = 0
			while (FCV_BROJAC == 0)
			{

				//Definisemo vrijednost varijable Brojac
				//Calculation:
				//  Brojac = 9
				FCV_BROJAC = 9;

				//Prikaz vrijednosti varijable Brojac na displeju
				//Call Component Macro: ShowDigit(Brojac, 0)
				FCD_led7seg0_ShowDigit(FCV_BROJAC, 0);


			}

			//
			//Loop: While Down = 0
			while (FCV_DOWN == 0)
			{

				//Input
				//Input: A0 -> Down
				trisa = trisa | 0x01;
				FCV_DOWN = ((porta & 0x01) == 0x01);


			}

			//Comment:
			//Ako je Down = 0 onda ce proces zadrzati u petlji i postaviti  Down = 1

		// } else {

		}


	}

	mainendloop: goto mainendloop;
}

void MX_INTERRUPT_MACRO(void)
{
}



