#ifndef _TDA743X_H
#define _TDA743X_H

#include "Arduino.h"

#include "SendTrans.h"
 #if defined(Surround_SIMULATED) || defined(Surround_SIMULATED) || defined(Surround_MOVIE) || defined(Surround_OFF)
   #undef Surround_SIMULATED 
   #undef Surround_MUSIC     
   #undef Surround_MOVIE     
   #undef Surround_OFF      
 #endif
   #define Surround_SIMULATED 0
   #define Surround_MUSIC     1
   #define Surround_MOVIE     3
   #define Surround_OFF       2

 #if  defined(RecOut_3BAND) || defined(RecOut_SURR) ||  defined(RecOut_REAR) || defined(RecOut_OFF)
   #undef RecOut_3BAND       
   #undef RecOut_SURR       
   #undef RecOut_REAR        
   #undef RecOut_OFF         
 #endif
   #define RecOut_3BAND       0
   #define RecOut_SURR        1
   #define RecOut_REAR        2
   #define RecOut_OFF         3
   
 #if defined(ATT_LR)|| defined(ATT_RR) || defined(ATT_LF) || defined(ATT_RF)
   #undef ATT_LR
   #undef ATT_RR
   #undef ATT_LF
   #undef ATT_RF
  #endif
  #define ATT_LR 2
  #define ATT_RR 3
  #define ATT_LF 0
  #define ATT_RF 1
  
  #define AddrTDA7430 0x80

  #define Use_NEGATIVE -1
  #define Use_POSITIVE 1
  
class TDA7430 :public SendTransI2C{
  public:
  
  int8_t begin();             //
  int8_t begin(byte Address); //Address  
  int8_t begin(byte Address,  //Address
               byte Addr);    //Channel

  int8_t UseValue(int8_t val = Use_POSITIVE);
  
  int8_t Input(int8_t val);   //Input
  
  int8_t Volume(int8_t val);  //Volume
  int8_t Bass(int8_t val);    //Bass
  int8_t Middle(int8_t val);  //Middle
  int8_t Treble(int8_t val);  //Treble

  int8_t Balance(int8_t val);               //Value
  int8_t Balance(int8_t val,int8_t val2);   //Value,channel

  int8_t NaturalBase(int8_t val); //NaturalBase
  int8_t EnableNaturalBase();     //Enable
  int8_t DisableNaturalBase();    //Disable

  int8_t RearSwitch(int8_t val);  //Rear
  int8_t EnableRear();            //Enable
  int8_t DisableRear();           //Disable

  int8_t SurroundMode(int8_t val);  //Surround Mode
  int8_t Surround_SIMULATED();      //SIMULATED
  int8_t Surround_MUSIC();          //MUSIC
  int8_t Surround_MOVIE();          //MOVIE
  int8_t Surround_OFF();            //OFF

  int8_t EffectControl(int8_t val); //EffectControl
  
  int8_t PhaseResistor(int8_t val);     // 0 -  255
  int8_t PhaseResistor(int8_t val,      // 0 - 3
                       int8_t val1,     // 0 - 3
                       int8_t val2,     // 0 - 3
                       int8_t val3);    // 0 - 3
  int8_t PhaseResistor1(int8_t val);    // 0 - 3
  int8_t PhaseResistor2(int8_t val);    // 0 - 3
  int8_t PhaseResistor3(int8_t val);    // 0 - 3
  int8_t PhaseResistor4(int8_t val);    // 0 - 3

  int8_t VoiceCanceller(int8_t val);    //VoiceCanceler
  int8_t DisableVoiceCanceller():       //Disable
  int8_t EnableVoiceCanceller();        //Input

  int8_t SelectorRecOut(int8_t val);    // value
  int8_t SelectorRecOut(int8_t val,     // Value
                        int8_t val2);   // Channel
  int8_t RecOut_3BAND();                // 3Band
  int8_t RecOut_SURR();                 // Surr
  int8_t RecOut_REAR();                 // Rear
  int8_t RecOut_OFF();                  // Off

  private :
    byte _DATA[10];
    int16_t Constrain(int16_t val,int8_t val2,int8_t val3);
    int8_t MaxInput(int8_t val = 4);
    int8_t _MInput;
    int8_t _UPN;
};

class TDA7431 :public TDA7430{
  public :
  private :
    int8_t MaxInput(int8_t val = 1);
};
#endif
