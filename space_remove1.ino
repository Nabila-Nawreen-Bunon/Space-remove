String inputString="";
bool stringComplete=false;
void setup()
{
 Serial.begin(9600);
  inputString.reserve(200);
  Serial.println("Enter a String:");
}

void loop()
{
  if(stringComplete){
    String resultString="";
    for(int i=0;i<inputString.length();i++){
      if(inputString[i]!=' '){
        resultString+=inputString[i];
      }
    }
    Serial.print("String without spaces:");
    Serial.println(resultString);
    inputString="";
    resultString="";
    stringComplete=false;
    Serial.print("Enter a string:");
  }
}
void serialEvent(){
  while(Serial.available()){
    char inChar=(char)Serial.read();
    inputString+=inChar;
    if(inChar=='\n'){
      stringComplete=true;
    }
  }
}
  