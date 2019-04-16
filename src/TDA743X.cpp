#include <TDA743X.h>

int8_t TDA7430::begin()             //
{
  return TDA7430::begin(AddrTDA7430,0x00);
}
int8_t TDA7430::begin(byte Address) //Address  
{
  return TDA7430::begin(Address,0x00);
}
int8_t TDA7430::begin(byte Address,  //Address
                      byte Addr)     //Channel
{
  _Address = Address | (Addr<<1);
  return Process_OK;
}

int8_t TDA7430::Input(int8_t val)   //Input
{
  if(_MInput ==  1){
    _DATA[9]  &= ~(0x03);
    return Process_OK;
  }
  else{
    val -=  1;
    constrain(val,0,3);
    if((int8_t)(_DATA[9]&0x03) != val) return Process_OK;
    
    _DATA[9] |= (_DATA[9]&(~(0x03))) | val;
  }
  return TDA7430::setWrite(9,_DATA[9]);
}

int8_t TDA7430::Volume(int8_t val)  //Volume
{
  val = constrain(val,0,63);
  if((int8_t)(_DATA[0]&0x3F) == val) return Process_OK;
  
   _DATA[0] = (_DATA[0]&(~(0x3F))) | val;
  return TDA7430::setWrite(0,_DATA[0]);
}
int8_t TDA7430::Bass(int8_t val)    //Bass
{
  val = constrain(val,-7,7);
  if(val < 0)  val = val  + 7;
  else val = 8 + (7 - val);

  if((int8_t)(_DATA[3]&0x0F) == val)  return Process_OK;
  
  _DATA[3] = (_DATA[3]&(~(0x0F))) |  val);
  return TDA7430::setWrite(3,_DATA[3]);
}
int8_t TDA7430::Middle(int8_t val)  //Middle
{
  val = constrain(val,-7,7);
  if(val < 0)  val = val  + 7;
  else val = 8 + (7 - val);
  if((int8_t)(_DATA[4]&0x0F) == val)  return Process_OK;

  _DATA[4] = (_DATA[4]&(~(0x0F))) |  val);
  return TDA7430::setWrite(4,_DATA[4]);
}
int8_t TDA7430::Treble(int8_t val)  //Treble
{
  val = constrain(val,-7,7);
  if(val < 0)  val = val  + 7;
  else val = 8 + (7 - val);
  if((int8_t)(_DATA[4]>>4) == val)  return Process_OK;

  _DATA[4] = (_DATA[4]&(~(0x0F<<4))) |  (val<<4));
  return TDA7430::setWrite(4,_DATA[4]);
}

int8_t TDA7430::Balance(int8_t val)                //Value
{
  TDA7430::Balance(val,ATT_LR);
  TDA7430::Balance(val,ATT_RR);
  TDA7430::Balance(val,ATT_LF);
  return TDA7430::Balance(val,ATT_RF);
}
int8_t TDA7430::Balance(int8_t val,int8_t val2)   //Value,channel
{
  val = constrain(val,0,79);
  switch(val2){
    case ATT_LF: if(_DATA[5] != val)return TDA7430::setWrite(5,(_DATA[5]= val)); break;
    case ATT_RF: if(_DATA[6] != val)return TDA7430::setWrite(6,(_DATA[6]= val)); break; 
    case ATT_LR: if(_DATA[7] != val)return TDA7430::setWrite(7,(_DATA[7]= val)); break;
    case ATT_RR: if(_DATA[8] != val)return TDA7430::setWrite(8,(_DATA[8]= val)); break;
  }
  return Process_OK;
}

int8_t TDA7430::NaturalBase(int8_t val) //NaturalBase
{
  val = constrain(val,0,1);
  if(((_DATA[3]>>4)&0x01) == val)  return Process_OK;

  _DATA[3] = (_DATA[3]&(~(0x01<<4))) | val<<4;
  return TDA7430::setWrite(3,_DATA[3]);
}
int8_t TDA7430::EnableNaturalBase()     //Enable
{
  return TDA7430::NaturalBase(0);
}
int8_t TDA7430::DisableNaturalBase()    //Disable
{
  return TDA7430::NaturalBase(1);
}

int8_t TDA7430::RearSwitch(int8_t val)  //Rear
{
  val = constrain(val,0,1);
  if(((_DATA[0]>>6)&0x01) == val)  return Process_OK;

  _DATA[0] = (_DATA[0]&(~(0x01<<6))) | val<<6;
  return TDA7430::setWrite(0,_DATA[0]);  
}
int8_t TDA7430::EnableRear()            //Enable
{
  return TDA7430::RearSwitch(0);
}
int8_t TDA7430::DisableRear()           //Disable
{
  return TDA7430::RearSwitch(1);
}

int8_t TDA7430::SurroundMode(int8_t val);  //Surround Mode
int8_t TDA7430::Surround_SIMULATED();      //SIMULATED
int8_t TDA7430::Surround_MUSIC();          //MUSIC
int8_t TDA7430::Surround_MOVIE();          //MOVIE
int8_t TDA7430::Surround_OFF();            //OFF

int8_t TDA7430::EffectControl(int8_t val); //EffectControl

int8_t TDA7430::PhaseResistor(int8_t val);     // 0 -  255
int8_t TDA7430::PhaseResistor(int8_t val,      // 0 - 3
                              int8_t val1,     // 0 - 3
                              int8_t val2,     // 0 - 3
                              int8_t val3);    // 0 - 3
int8_t TDA7430::PhaseResistor1(int8_t val);    // 0 - 3
int8_t TDA7430::PhaseResistor2(int8_t val);    // 0 - 3
int8_t TDA7430::PhaseResistor3(int8_t val);    // 0 - 3
int8_t TDA7430::PhaseResistor4(int8_t val);    // 0 - 3

int8_t TDA7430::VoiceCanceller(int8_t val);    //VoiceCanceler
int8_t TDA7430::DisableVoiceCanceller():       //Disable
int8_t TDA7430::EnableVoiceCanceller();        //Input

int8_t TDA7430::SelectorRecOut(int8_t val);    // value
int8_t TDA7430::SelectorRecOut(int8_t val,     // Value
                               int8_t val2);   // Channel
int8_t TDA7430::RecOut_3BAND();                // 3Band
int8_t TDA7430::RecOut_SURR();                 // Surr
int8_t TDA7430::RecOut_REAR();                 // Rear
int8_t TDA7430::RecOut_OFF();                  // Off


int8_t UseValue(int8_t val){
  _UPN = val;
  return Process_OK;
}

int16_t Constrain(int16_t val,int8_t val2,int8_t val3){
  if(_UPN != Use_POSITIVE){
    return constrain(val,-1*val3,val2;
  }
  else{
    return constrain(val,val2,val3);
  }
}

int8_t MaxInput(int8_t val){
  _MInput = val;
}
