#ifndef GLCD_12864R_SPI_H
#define GLCD_12864R_SPI_H

#define IO_MCU_GLCD_RS OUTPUT
#define IO_MCU_GLCD_RW OUTPUT
#define IO_MCU_GLCD_EN OUTPUT

typedef unsigned char uchar; //

class GLCD_12864R_SPI{
  public:
  GLCD_12864R_SPI(int RS, int RW, int EN){
    }
 void Driver(int CLK, int LATCH, int SDA){
    PROCESS_GLCD_RS = CLK;
    PROCESS_GLCD_RW = LATCH;
    PROCESS_GLCD_EN = SDA;
  };
 void init(void){
  pinMode(PROCESS_GLCD_RS, IO_MCU_GLCD_RS); //
  pinMode(PROCESS_GLCD_RW, IO_MCU_GLCD_RW); //
  pinMode(PROCESS_GLCD_EN, IO_MCU_GLCD_EN); //
  digitalWrite(PROCESS_GLCD_RW, LOW); //
  //digitalWrite(); //
  //digitalWrite(); //
  Delays(); //
  WriteCommand(0x30);
  WriteCommand(0x0C);
  WriteCommand(0x01);
  WriteCommand(0x06);
      };

 void Delays(){
      
    }

 void WriteByte(int DATA){
  
 }

 void WriteCommand(int COMMAND){
  
 }

void WriteData(int COMMAND){
  
}

void clear(){
WriteCommand(0x30); //
WriteCommand(0x01); //
}

void DisplayString(){
  
}

void DisplaySignal(){
  
}

void DrawFullScreen(){
  
}

void Image1(){

}

void Image2(){

}

int DelayTime; //
int DefaultTime; //

int PROCESS_GLCD_RS;
int PROCESS_GLCD_RW;
int PROCESS_GLCD_EN;
  
  private:
  
  protected:


};

#endif
