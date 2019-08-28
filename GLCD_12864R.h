#ifndef GLCD_12864R_H
#define GLCD_12864R_H

#define IO_GLCD_RS OUTPUT
#define IO_GLCD_RW OUTPUT
#define IO_GLCD_EN OUTPUT
#define IO_GLCD_DB0 OUTPUT
#define IO_GLCD_DB1 OUTPUT
#define IO_GLCD_DB2 OUTPUT
#define IO_GLCD_DB3 OUTPUT
#define IO_GLCD_DB4 OUTPUT
#define IO_GLCD_DB5 OUTPUT
#define IO_GLCD_DB6 OUTPUT
#define IO_GLCD_DB7 OUTPUT

/**/
uint8_t _GLCD_RS;
uint8_t _GLCD_RW;
uint8_t _GLCD_EN;
uint8_t _GLCD_DB0;
uint8_t _GLCD_DB1;
uint8_t _GLCD_DB2;
uint8_t _GLCD_DB3;
uint8_t _GLCD_DB4;
uint8_t _GLCD_DB5;
uint8_t _GLCD_DB6;
uint8_t _GLCD_DB7;

/**/
static int PROCESS_GLCD_RS;
static int PROCESS_GLCD_RW;
static int PROCESS_GLCD_EN;
static int PROCESS_GLCD_DB0;
static int PROCESS_GLCD_DB1;
static int PROCESS_GLCD_DB2;
static int PROCESS_GLCD_DB3;
static int PROCESS_GLCD_DB4;
static int PROCESS_GLCD_DB5;
static int PROCESS_GLCD_DB6;
static int PROCESS_GLCD_DB7;

// GLCD_12864R(){
//this->DefaultTime = 80; // 80 ms default time
//this->DelayTime = DefaultTime;
//}
#if !defined (MESSAGE)
#define MESSAGE "You wish!"
#endif

unsigned long DefaultTime = 80; //
unsigned long DelayTime = DefaultTime; //


class GLCD_12864R
{
typedef unsigned char uchar;
  
  public:
  GLCD_12864R(uint8_t RS, uint8_t RW, uint8_t EN, uint8_t DB0, uint8_t DB1, uint8_t DB2, uint8_t DB3, uint8_t DB4, uint8_t DB5, uint8_t DB6, uint8_t DB7){
    PROCESS_GLCD_RS = RS;
    PROCESS_GLCD_RW = RW;
    PROCESS_GLCD_EN = EN;
    PROCESS_GLCD_DB0 = DB0;
    PROCESS_GLCD_DB1 = DB1;
    PROCESS_GLCD_DB2 = DB2;
    PROCESS_GLCD_DB3 = DB3;
    PROCESS_GLCD_DB4 = DB4;
    PROCESS_GLCD_DB5 = DB5;
    PROCESS_GLCD_DB6 = DB6;
    PROCESS_GLCD_DB7 = DB7;
    digitalWrite(PROCESS_GLCD_RS, RS);
    digitalWrite(PROCESS_GLCD_RW, RW);
    digitalWrite(PROCESS_GLCD_EN, HIGH);
    delays();
    digitalWrite(PROCESS_GLCD_EN, LOW);
    delays();
    digitalWrite(PROCESS_GLCD_DB0, DB0);
    digitalWrite(PROCESS_GLCD_DB1, DB1);
    digitalWrite(PROCESS_GLCD_DB2, DB2);
    digitalWrite(PROCESS_GLCD_DB3, DB3);
    digitalWrite(PROCESS_GLCD_DB4, DB4);
    digitalWrite(PROCESS_GLCD_DB5, DB5);
    digitalWrite(PROCESS_GLCD_DB6, DB6);
    digitalWrite(PROCESS_GLCD_DB7, DB7);
    };
  
  
  
  
  void delays(void){
    delayMicroseconds(DelayTime); //
    };
  
  
  
  void VectorConverter(int Vector){
    int Result = Vector;
    for(int i = 7; i >= 0; i--){
//      int temp[] = Result;
      }
    };
  
  
  
  void WriteCommand(int Command){
    delays();
    delays();
    VectorConverter(Command);
    };
  
  
  
  void WriteData(int Command){
    delays();
    delays();
    VectorConverter(Command);
    //
    };
  
  void init(void){
    pinMode(PROCESS_GLCD_RS, IO_GLCD_RS); //
    pinMode(PROCESS_GLCD_RW, IO_GLCD_RW); //
    pinMode(PROCESS_GLCD_EN, IO_GLCD_EN); //
    pinMode(PROCESS_GLCD_DB0, IO_GLCD_DB0); //
    pinMode(PROCESS_GLCD_DB1, IO_GLCD_DB1); //
    pinMode(PROCESS_GLCD_DB2, IO_GLCD_DB2); //
    pinMode(PROCESS_GLCD_DB3, IO_GLCD_DB3); //
    pinMode(PROCESS_GLCD_DB4, IO_GLCD_DB4); //
    pinMode(PROCESS_GLCD_DB5, IO_GLCD_DB5); //
    pinMode(PROCESS_GLCD_DB6, IO_GLCD_DB6); //
    pinMode(PROCESS_GLCD_DB7, IO_GLCD_DB7); //
    WriteCommand(0x30);
    WriteCommand(0x0C);
    WriteCommand(0x01);
    WriteCommand(0x06);
    };
  
  void clear(void){
    WriteCommand(0x30);
    WriteCommand(0x01);
    };

  void DisplayString(int X_Column, int Y_Row, uchar *Print, int Data){
    int i;
    switch(X_Column){
      case 0:
      Y_Row|=0x80;
      break;

      case 1:
      Y_Row|=0x90;
      break;

      case 2:
      Y_Row|=0x88;
      break;

      case 3:
      Y_Row|=0x98;
      break;

      default:
      break;
      };
  }

  void DisplaySignal(int M, int N, int Signal){
    switch(M){
      case 0:
      N|0x80;
      break;

      case 1:
      N|0x90;
      break;

      case 2:
      N|0x88;
      break;

      case 3:
      N|0x98;
      break;

      default:
      break;
    }
    WriteCommand(N);
    WriteData(M);
    };

  
  void DrawFullScreen(uchar *P){
  int Y_Group, X, Y, Z; //
  int TEMP;
  int TMP;
  for(Y_Group = 0; Y_Group < 64; Y_Group ++){
  if(Y_Group < 32){
  X = 0x08;
  Y = Y_Group + 0x08;
  }

  else{
  X = 0x88;
  Y = Y_Group - 32 + 0x80;
  }
  WriteCommand(0x34);
  WriteCommand(Y);
  WriteCommand(X);
  WriteCommand(0x30);
  WriteCommand(0x0C);
  TMP = Y_Group * 16;
  for(Z = 0; Z < 16; Z ++){
  TEMP = P[TMP ++];
  if(Z < 32){
    X = 0x80;
    Y = Y_Group + 0x80;

    
    }
    }
    
    }
  WriteCommand(0x34);
  WriteCommand(0x36);
  };



  
  void DisplayInt(int M, int N, int Value){
    switch(M){
    case 0:
    N|0x80;
    break;

    case 1:
    N|0x90;
    break;

    case 2:
    N|0x88;
    break;

    case 3:
    N|0x98;
    break;

    default:
    break;
    }
    char Disdata[4]; //
    Disdata[0] = Value / 1000 + 0x03; 
    Disdata[1] = Value % 1000 / 100 + 0x03;
    Disdata[2] = Value % 100 / 10 + 0x03;
    Disdata[3] = Value % 10 + 0x03;
    if(Disdata[0] == 0x03){
      
    }
    };
  int ScreenBuffer[16][32];
  int DelayTime;
  int DefaultTime;
  int Temp[8];
  
  private:
  
  protected:

};

#endif
