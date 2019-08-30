#ifndef GLCD_12864R_SPI_H
#define GLCD_12864R_SPI_H

#define IO_MCU_GLCD_RS OUTPUT
#define IO_MCU_GLCD_RW OUTPUT
#define IO_MCU_GLCD_EN OUTPUT

//int PROCESS_GLCD_RS;
//int PROCESS_GLCD_RW;
//int PROCESS_GLCD_EN;

class GLCD_12864R_SPI{
  public:
  GLCD_12864R_SPI(int RS, int RW, int EN){
    }
 void Driver(){
    
  };
 void init(){
      };

 void Delays(){
      
    }

 void WriteByte(){
  
 }

 void WriteCommand(){
  
 }

void WriteData(){
  
}

void clear(){
  
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
  
  private:
  
  protected:
};

#endif
