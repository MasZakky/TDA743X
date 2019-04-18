# TDA743X => 
<h3>Library</h3>
<ul>
  <li><a text-decoration="none" style="color:red" href="https://www.mouser.com/datasheet/2/389/CD00000226-470817.pdf">TDA7430</a></li>
  <li><a text-decoration="none" style="color:red" href="https://www.mouser.com/datasheet/2/389/CD00000226-470817.pdf">TDA7431</a></li>
  <li><a text-decoration="none" style="color:red" href="https://www.st.com/resource/en/datasheet/CD00000874.pdf">TDA7432</a></li>
<ul>


<h5>Example Param</h5>

    #include "TDA743X.h"
    TDA7430 uPA;  

    void setup(){ 
      Wire.begin();
      Serial.begin(9600); 
      
      int value = uPA.begin(); 
      if(value == Process_OK){ 
        Serial.println("Process_OK");
        return; 
      } // if 
      else{ 
        Serial.println("Process_ERROR"); 
      } // else
    } // void setup
    
    void loop(){
    // Do something?
    } 

    ////////////////////////////////////////////////////////////////////

<h3>TDA7430 & TDA7431 </h3>

    int8_t begin();            
    int8_t begin(byte Address); 
    int8_t begin(byte Address,byte Addr);
       Address => 0x80 (FIX => TDA7430) 
       Addr    => pinAddr (Only TDA7431) 

    int8_t UseValue(int8_t val); 
       Default      => Use_POSITIVE 
       Use_POSITIVE or Use_NEGATIVE 

    int8_t Input(int8_t val); 
       TDA7430 maks Input => 4 
       TDA7431 maks Input => 1 (FIX)
    
    int8_t Volume(int8_t val);
       UserValue == Use_POSITIVE => Volume 0 ~ 63 
       UserValue == Use_NEGATIVE => Volume -63 ~ 0
    
    int8_t Bass(int8_t val);
       Value => -7 ~ 7 
    
    int8_t Middle(int8_t val);
       Value => -7 ~ 7
    
    int8_t Treble(int8_t val);
       Value => -7 ~ 7 
  
    int8_t Balance(int8_t val);
    int8_t Balance(int8_t val,int8_t val2);   
                   Value     ,Channel 
       UserValue == Use_POSITIVE => Balance 0 ~ 79 
       UserValue == Use_NEGATIVE => Balance -79 ~ 0 
       Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF 
  
    int8_t NaturalBase(int8_t val);
       Value => NATURALBASE_ACTIVE or NATURALBASE_OFF 
    
    int8_t EnableNaturalBase(); 
    int8_t DisableNaturalBase();
 
    int8_t RearSwitch(int8_t val);
       Value => REAR_ACTIVE or REAR_OFF 
   
    int8_t EnableRear();            
    int8_t DisableRear();           
   
    int8_t SurroundMode(int8_t val);  
    int8_t Surround_SIMULATED();    
    int8_t Surround_MUSIC();         
    int8_t Surround_MOVIE();        
    int8_t Surround_OFF();          
       Value => Surr_SIMULATED,Surr_MUSIC,Surr_MOVIE, or Surround_OFF 
    
    int8_t EffectControl(int8_t val);
       Value => -6 ~ -21 
    
    int8_t PhaseResistor(int8_t val);     // 0 -  255 
    int8_t PhaseResistor(int8_t val,      // 0 - 3 
                         int8_t val1,     // 0 - 3 
                         int8_t val2,     // 0 - 3 
                         int8_t val3);    // 0 - 3 
   
    int8_t VoiceCanceller(int8_t val);    
       Value => VOICECANCELLER_OFF or VOICECANCELLER_ON 
    
    int8_t DisableVoiceCanceller();
    int8_t EnableVoiceCanceller();
   
    int8_t SelectorRecOut(int8_t val);
    int8_t SelectorRecOut(int8_t val,int8_t val2);
                          Value     ,Channel
    int8_t RecOut_3BAND();
    int8_t RecOut_SURR(); 
    int8_t RecOut_REAR(); 
    int8_t RecOut_OFF();  
    int8_t RecOut_FLAT(); 
       Value   => Out_3BAND,Out_SURR,Out_REAR,Out_OFF, or Out_FLAT 
       Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF
     
    int8_t Mute(int8_t val);              
    int8_t Mute(int8_t val,int8_t val2);  
                Value     ,Channel
    int8_t DisableMute();                 
    int8_t EnableMute();                  
       Value   => MUTE_OFF or MUTE_ON
       Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF 
     
    ////////////////////////////////////////////////////////////////////

<h3>TDA7432</h3>

    int8_t Volume(int8_t val);  
       UserValue == Use_POSITIVE => Volume 0 ~ 63 
       UserValue == Use_NEGATIVE => Volume -63 ~ 0
    
    int8_t Bass(int8_t val);
       Value => -7 ~ 7 
    
    int8_t Treble(int8_t val);
       Value => -7 ~ 7 
    
    int8_t UseValue(int8_t val);
       Default => Use_POSITIVE 
       Value   => Use_POSITIVE or Use_NEGATIVE 
    
    int8_t Balance(int8_t val);               
    int8_t Balance(int8_t val,int8_t val2);   
                   Value     ,Channel
       UserValue == Use_POSITIVE => Balance 0 ~ 79 
       UserValue == Use_NEGATIVE => Balance -79 ~ 0
       Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF

    int8_t Input(int8_t val);
       TDA7430 maks Input => 2 
     
    int8_t Mute(int8_t val);              
    int8_t Mute(int8_t val,int8_t val2);  
                Value     ,Channel
                
    int8_t DisableMute();                 
    int8_t EnableMute();
       Value => MUTE_OFF or MUTE_ON 
       Channel => ATT_LR,ATT_RR,ATT_LF, or ATT_RF 

    int8_t Loudness(int8_t val);          
       UserValue == Use_POSITIVE => Loudness 0 ~ 15 
       UserValue == Use_NEGATIVE => Loudness -15 ~ 0
     
    int8_t ModeLoudness(int8_t val);      
       Value => Loudness_ON or Loudness_OFF
    
    int8_t EnableModeLoudness(); 
    int8_t DisableModeLoudness();

