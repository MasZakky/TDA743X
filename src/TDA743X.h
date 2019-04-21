#ifndef _TDA743X_H_
#define _TDA743X_H_

#include "Arduino.h"

#include "SendTrans.h"

 #if defined(Surr_SIMULATED) || defined(Surr_MUSIC) || defined(Surr_MOVIE) || defined(Surr_OFF)
   #undef Surr_SIMULATED 
   #undef Surr_MUSIC     
   #undef Surr_MOVIE     
   #undef Surr_OFF      
 #endif
   #define Surr_SIMULATED 0
   #define Surr_MUSIC     1
   #define Surr_MOVIE     3
   #define Surr_OFF       2

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
  
  #if defined(REAR_ACTIVE) || defined(REAR_OFF)
   #undef REAR_ACTIVE
   #undef REAR_OFF
  #endif
    #define REAR_ACTIVE 0
    #define REAR_OFF    1
  
  #if defined(NATURALBASE_ACTIVE) || defined(NATURALBASE_OFF)
   #undef NATURALBASE_ACTIVE
   #undef NATURALBASE_OFF
  #endif
    #define NATURALBASE_ACTIVE 0
    #define NATURALBASE_OFF    1

  #if defined(VOICECANCELLER_OFF) || defined(VOICECANCELLER_ON)
   #undef VOICECANCELLER_OFF
   #undef VOICECANCELLER_ON
  #endif
    #define VOICECANCELLER_OFF 0
    #define VOICECANCELLER_ON  1
  
  #if defined(Out_3BAND) || defined(Out_SURR) || defined(Out_REAR) || defined(Out_FLAT)
   #undef Out_3BAND
   #undef Out_SURR
   #undef Out_REAR
   #undef Out_FLAT
   #undef Out_OFF
  #endif
    #define Out_3BAND 0
    #define Out_SURR  1
    #define Out_REAR  2
    #define Out_FLAT  3
    #define Out_OFF   3

  #if defined(RecOut_L) || defined(RecOut_R)
   #undef RecOut_L
   #undef RecOut_R
  #endif
    #define RecOut_L 0
    #define RecOut_R 1
  
  #if defined(Use_NEGATIVE) || defined(Use_POSITIVE)
    #undef Use_NEGATIVE 
    #undef Use_POSITIVE 
  #endif
    #define Use_NEGATIVE -1
    #define Use_POSITIVE 1

  #if defined(MUTE_OFF) || defined(MUTE_ON)
    #undef MUTE_OFF  
    #undef MUTE_ON 
  #endif
    #define MUTE_OFF  0
    #define MUTE_ON   1
  
  #if defined(Loudness_ON) || defined(Loudness_OFF)
    #undef Loudness_ON
    #undef Loudness_OFF
  #endif
    #define Loudness_ON 0
    #define Loudness_OFF 1

  #if defined(Yes_ExtendedBassRange) || defined(Not_ExtendedBassRange)
    #undef Yes_ExtendedBassRange
    #undef Not_ExtendedBassRange
  #endif
    #define Yes_ExtendedBassRange 0
    #define Not_ExtendedBassRange 1

  #if defined(Yes_SymmetricalBassCut) || defined(Not_SymmetricalBassCut)
    #undef Not_SymmetricalBassCut
    #undef Yes_SymmetricalBassCut
  #endif
    #define Not_SymmetricalBassCut 0
    #define Yes_SymmetricalBassCut 1
    
  #define AddrTDA7430 0x80 //Address TDA7430 & TDA7431
  #define AddrTDA7433 0x8A //Address TDA7432 & TDA7433 & TDA7434
  #define AddrTDA7438 0x88 //Address TDa7438 & TDA7439
  
class TDA7430 :public SendTransI2C{
  public:
  
    int8_t begin();             //
    int8_t begin(byte Address = AddrTDA7430); //Address  
    int8_t begin(byte Address, byte Addr);    //Address,Channel
  
    int8_t UseValue(int8_t val = Use_POSITIVE);
    
    int8_t Input(int8_t val = 1);   //Input
    
    int8_t Volume(int8_t val = 1);  //Volume
    int8_t Bass(int8_t val = 7);    //Bass
    int8_t Middle(int8_t val = 7);  //Middle
    int8_t Treble(int8_t val = 7);  //Treble
  
    int8_t Balance(int8_t val = 0);           //Value
    int8_t Balance(int8_t val,int8_t val2);   //Value,channel
  
    int8_t NaturalBase(int8_t val= NATURALBASE_ACTIVE); //NaturalBase
    int8_t EnableNaturalBase();     //Enable
    int8_t DisableNaturalBase();    //Disable
  
    int8_t RearSwitch(int8_t val = REAR_ACTIVE);  //Rear
    int8_t EnableRear();            //Enable
    int8_t DisableRear();           //Disable
  
    int8_t SurroundMode(int8_t val = Surr_OFF);  //Surround Mode
    int8_t Surround_SIMULATED();      //SIMULATED
    int8_t Surround_MUSIC();          //MUSIC
    int8_t Surround_MOVIE();          //MOVIE
    int8_t Surround_OFF();            //OFF
  
    int8_t EffectControl(int8_t val); //EffectControl

    int8_t VoiceCanceller(int8_t val = VOICECANCELLER_OFF);    //VoiceCanceler
    int8_t DisableVoiceCanceller();       //Disable
    int8_t EnableVoiceCanceller();        //Enable
    
    int8_t PhaseResistor(int8_t val = 255);     // 0 -  255
    int8_t PhaseResistor(int8_t val,      // 0 - 3
                         int8_t val1,     // 0 - 3
                         int8_t val2,     // 0 - 3
                         int8_t val3);    // 0 - 3
   
    int8_t SelectorRecOut(int8_t val = Out_3BAND);    // Value
    int8_t SelectorRecOut(int8_t val,int8_t val2);    // Value,Channel
    int8_t RecOut_3BAND();                // 3Band
    int8_t RecOut_SURR();                 // Surr
    int8_t RecOut_REAR();                 // Rear
    int8_t RecOut_OFF();                  // Off
    int8_t RecOut_FLAT();                 // Flat
  
    int8_t Mute(int8_t val = MUTE_OFF);   // Value
    int8_t Mute(int8_t val,int8_t val2);  // Value,Channel
    int8_t DisableMute();                 // Disable
    int8_t EnableMute();                  // Enable

  protected:
    byte _DATA[10];
    int16_t Constrain(int16_t val,int16_t val2,int16_t val3);
    int8_t MaxInput(int8_t val = 4);
    int8_t _MInput,_UPN;
};

class TDA7431 :public TDA7430{
  public :
  protected:
    int8_t MaxInput(int8_t val = 1);
};

class TDA7433 :public SendTransI2C{
  public:
    int8_t begin();
    
    int8_t Volume(int8_t val = 0);
    int8_t Bass(int8_t val = 7);
    int8_t Treble(int8_t val = 7);

    int8_t ExtendedBassRange(int8_t val = Yes_ExtendedBassRange);
    int8_t SymmetricalBassCut(int8_t val = Not_SymmetricalBassCut);
    
    int8_t UseValue(int8_t val = Use_POSITIVE);
        
    int8_t Balance(int8_t val = 0);
    int8_t Balance(int8_t val,int8_t val2);

    int8_t Input(int8_t val = 1);

    int8_t Mute(int8_t val = MUTE_OFF);
    int8_t Mute(int8_t val,int8_t val2);
    int8_t DisableMute();
    int8_t EnableMute();
    
  protected:
    byte _DATA[8];
    int16_t Constrain(int16_t val,int16_t val2,int16_t val3);
    int8_t MaxInput(int8_t val = 3);
    int8_t _UPN,_MInput;
};

class TDA7432 :public TDA7433{
  public:
    int8_t Volume(int8_t val = 0);

    int8_t Loudness(int8_t val = Loudness_ON);
    int8_t ModeLoudness(int8_t val = 0);
    int8_t EnableModeLoudness();
    int8_t DisableModeLoudness();

  protected:
     int8_t MaxInput(int8_t val = 2);
};

class TDA7434 :public TDA7432{
  public:
  protected:
     int8_t MaxInput(int8_t val = 3);
};

class TDA7438 :public SendTransI2C{
  public:
    int8_t begin();

    int8_t Input(int8_t val = 1);
    int8_t Gain(int8_t val = 0);

    int8_t UseValue(int8_t val = Use_POSITIVE);
        
    int8_t Volume(int8_t val = 15);
    int8_t Bass(int8_t val = 7);
    int8_t Middle(int8_t val = 7);
    int8_t Treble(int8_t val = 7);

    int8_t Balance(int8_t val = 0);
    int8_t Balance(int8_t val,int8_t val2);

    int8_t Mute(int8_t val = MUTE_OFF);
    int8_t Mute(int8_t val,int8_t val2);
    int8_t DisableMute();
    int8_t EnableMute();

  protected:
    byte _DATA[8];
    int16_t Constrain(int16_t val,int16_t val2,int16_t val3);
    int8_t MaxInput(int8_t val = 3);
    int8_t _UPN,_MInput;
};

class TDA7439 :public TDA7438{
  public:
  protected:
    int8_t MaxInput(int8_t val = 4);  
};
#endif
