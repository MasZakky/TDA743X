#include <TDA743X.h>

int8_t TDA7430::begin(){
  return TDA7430::begin(AddrTDA7430,0x00);
}

int8_t TDA7430::begin(byte Address){
  return TDA7430::begin(Address,0x00);
}

int8_t TDA7430::begin(byte Address,byte Addr){
  _Address = Address | (Addr<<1);
  return Process_OK;
}

int8_t TDA7430::Input(int8_t val){
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

int8_t TDA7430::Volume(int8_t val){
  val = Constrain(val,0,63);
  if((int8_t)(_DATA[0]&0x3F) == val) return Process_OK;
  
   _DATA[0] = (_DATA[0]&(~(0x3F))) | val;
  return TDA7430::setWrite(0,_DATA[0]);
}

int8_t TDA7430::Bass(int8_t val){
  val = constrain(val,-7,7);
  if(val < 0)  val = val  + 7;
  else val = 8 + (7 - val);

  if((int8_t)(_DATA[3]&0x0F) == val)  return Process_OK;
  
  _DATA[3] = (_DATA[3]&(~(0x0F))) |  val);
  return TDA7430::setWrite(3,_DATA[3]);
}

int8_t TDA7430::Middle(int8_t val){
  val = constrain(val,-7,7);
  if(val < 0)  val = val  + 7;
  else val = 8 + (7 - val);
  if((int8_t)(_DATA[4]&0x0F) == val)  return Process_OK;

  _DATA[4] = (_DATA[4]&(~(0x0F))) |  val);
  return TDA7430::setWrite(4,_DATA[4]);
}

int8_t TDA7430::Treble(int8_t val){
  val = constrain(val,-7,7);
  if(val < 0)  val = val  + 7;
  else val = 8 + (7 - val);
  if((int8_t)(_DATA[4]>>4) == val)  return Process_OK;

  _DATA[4] = (_DATA[4]&(~(0x0F<<4))) |  (val<<4));
  return TDA7430::setWrite(4,_DATA[4]);
}

int8_t TDA7430::Balance(int8_t val){
  TDA7430::Balance(val,ATT_LR);
  TDA7430::Balance(val,ATT_RR);
  TDA7430::Balance(val,ATT_LF);
  return TDA7430::Balance(val,ATT_RF);
}

int8_t TDA7430::Balance(int8_t val,int8_t val2){
  val = Constrain(val,0,79);
  val2 = constrain(val2,0,3);
  switch(val2){
    case ATT_LF: if(_DATA[5] != val)return TDA7430::setWrite(5,(_DATA[5]= val)); break;
    case ATT_RF: if(_DATA[6] != val)return TDA7430::setWrite(6,(_DATA[6]= val)); break; 
    case ATT_LR: if(_DATA[7] != val)return TDA7430::setWrite(7,(_DATA[7]= val)); break;
    case ATT_RR: if(_DATA[8] != val)return TDA7430::setWrite(8,(_DATA[8]= val)); break;
  }
  return Process_OK;
}

int8_t TDA7430::NaturalBase(int8_t val){
  val = constrain(val,0,1);
  if(((_DATA[3]>>4)&0x01) == val)  return Process_OK;

  _DATA[3] = (_DATA[3]&(~(0x01<<4))) | (val<<4);
  return TDA7430::setWrite(3,_DATA[3]);
}

int8_t TDA7430::EnableNaturalBase(){
  return TDA7430::NaturalBase(NATURALBASE_ACTIVE);
}

int8_t TDA7430::DisableNaturalBase(){
  return TDA7430::NaturalBase(NATURALBASE_OFF);
}

int8_t TDA7430::RearSwitch(int8_t val){
  val = constrain(val,0,1);
  if(((_DATA[0]>>6)&0x01) == val)  return Process_OK;

  _DATA[0] = (_DATA[0]&(~(0x01<<6))) | val<<6;
  return TDA7430::setWrite(0,_DATA[0]);  
}

int8_t TDA7430::EnableRear(){
  return TDA7430::RearSwitch(REAR_ACTIVE);
}

int8_t TDA7430::DisableRear(){
  return TDA7430::RearSwitch(REAR_OFF);
}

int8_t TDA7430::SurroundMode(int8_t val){
  val = cosntrain(val,0,3);
  if((_DATA[1]&0x03== val) return Process_OK;
  
  _DATA[1] = (_DATA[1]&(~(0x07))) | val;
  return TDA7430::setWrite(1,_DATA[1]);
}

int8_t TDA7430::Surround_SIMULATED(){
  return TDA7430::SurroundMode(Surround_SIMULATED);
}

int8_t TDA7430::Surround_MUSIC(){
  return TDA7430::SurroundMode(Surround_MUSIC);
}

int8_t TDA7430::Surround_MOVIE(){
  return TDA7430::SurroundMode(Surround_MOVIE);
}

int8_t TDA7430::Surround_OFF(){
  return TDA7430::SurroundMode(Surround_OFF);
}

int8_t TDA7430::EffectControl(int8_t val){
  val = constrain(val,-21,-6);
  val = (val*-1) - 6;
  if(((_DATA[1]>>3)&0x07)) == val) return Process_OK;
  
  _DATA[1] = (_DATA[1]&(~(0x07))) | (val<<3);
  return TDA7430::setWrite(1,_DATA[1]);
}

int8_t TDA7430::PhaseResistor(int8_t val){
  val = constrain(val,0,255);
  if(_DATA[2] == val) return Process_OK;
  
  _DATA[2] = val;
  return TDA7430::setWrite(2,_DATA[2]);
}

int8_t TDA7430::PhaseResistor(int8_t val,int8_t val1,int8_t val2,int8_t val3){
 val = constrain(val,0,3);
 val1= constrain(val1,0,3);
 val2= constrain(val2,0,3);
 val3= constrain(val3,0,3);
 return  TDA7430::PhaseResistor(val | (val1<<2) | (val2<<4) | (val3<<6));
}

// int8_t TDA7430::PhaseResistor1(int8_t val);    // 0 - 3
// int8_t TDA7430::PhaseResistor2(int8_t val);    // 0 - 3
// int8_t TDA7430::PhaseResistor3(int8_t val);    // 0 - 3
// int8_t TDA7430::PhaseResistor4(int8_t val);    // 0 - 3

int8_t TDA7430::VoiceCanceller(int8_t val){
  val = constrain(val,0,1);
  if((_DATA[9]&0x01) == val) return Process_OK;
  
  _DATA[9] = (_DATA[9]&(~(0x01))) | val;
  return TDA7430::setWrite(9,_DATA[9]);
}

int8_t TDA7430::DisableVoiceCanceller(){
  return TDA7430::VoiceCanceller(VOICECANCELLER_OFF);
}

int8_t TDA7430::EnableVoiceCanceller(){
  return TDA7430::VoiceCanceller(VOICECANCELLER_ON);
}

int8_t TDA7430::SelectorRecOut(int8_t val){
  TDA7430::SelectorRecOut(val,RecOut_L);
  return TDA7430::SelectorRecOut(val,RecOut_R);
}

int8_t TDA7430::SelectorRecOut(int8_t val,int8_t val2){
  val = constrain(val,0,3);
  val2 = constrain(val2,0,1);
  switch(val2){
    case RecOut_L: if(((_DATA[9]>>3)&0x03) != val) _DATA[9] = (_DATA[9]&(~(0x03<<3))) | (val << 3);
                   return TDA7430::setWrite(9,_DATA[9]); break;
    case RecOut_R: if(((_DATA[9]>>5)&0x03) != val) _DATA[9] = (_DATA[9]&(~(0x03<<5))) | (val << 5);
                   return TDA7430::setWrite(9,_DATA[9]); break;
  }
  return Process_OK;
}

int8_t TDA7430::RecOut_3BAND(){
  return TDA7430::SelectorRecOut(Out_3BAND);
}

int8_t TDA7430::RecOut_SURR(){
  return TDA7430::SelectorRecOut(Out_SURR);
}

int8_t TDA7430::RecOut_REAR(){
  return TDA7430::SelectorRecOut(Out_REAR);
}

int8_t TDA7430::RecOut_OFF(){
  return TDA7430::SelectorRecOut(Out_FLAT);
}

int8_t RecOut_FLAT(){
  return TDA7430::RecOut_OFF();
}

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
