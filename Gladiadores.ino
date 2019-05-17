int REDPin1 = 22;    // RED pin of the LED to PWM pin 4
int GREENPin1 = 24;  // GREEN pin of the LED to PWM pin 5
int BLUEPin1 = 26;   // BLUE pin of the LED to PWM pin 6

int REDPin2 = 30;    // RED pin of the LED to PWM pin 4
int GREENPin2 = 32;  // GREEN pin of the LED to PWM pin 5
int BLUEPin2 = 34; 

int REDPin3 = 38;    // RED pin of the LED to PWM pin 4
int GREENPin3 = 40;  // GREEN pin of the LED to PWM pin 5
int BLUEPin3 = 42; 

int REDPin4 = 46;    // RED pin of the LED to PWM pin 4
int GREENPin4 = 48;  // GREEN pin of the LED to PWM pin 5
int BLUEPin4 = 50; 

int REDPin5 = 23;    // RED pin of the LED to PWM pin 4
int GREENPin5 = 25;  // GREEN pin of the LED to PWM pin 5
int BLUEPin5 = 27; 

int REDPin6 = 31;    // RED pin of the LED to PWM pin 4
int GREENPin6 = 33;  // GREEN pin of the LED to PWM pin 5
int BLUEPin6 = 35; 

int REDPin7 = 39;    // RED pin of the LED to PWM pin 4
int GREENPin7 = 41;  // GREEN pin of the LED to PWM pin 5
int BLUEPin7 = 43; 

int REDPin8 = 47;    // RED pin of the LED to PWM pin 4
int GREENPin8 = 49;  // GREEN pin of the LED to PWM pin 5
int BLUEPin8 = 51; 

int brightness = 0; // LED brightness
int increment = 5;  // brightness increment
const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;

void setup()
{
  pinMode(REDPin1, OUTPUT);
  pinMode(GREENPin1, OUTPUT);
  pinMode(BLUEPin1, OUTPUT);
  pinMode(REDPin2, OUTPUT);
  pinMode(GREENPin2, OUTPUT);
  pinMode(BLUEPin2, OUTPUT);
  pinMode(REDPin3, OUTPUT);
  pinMode(GREENPin3, OUTPUT);
  pinMode(BLUEPin3, OUTPUT);
  pinMode(REDPin4, OUTPUT);
  pinMode(GREENPin4, OUTPUT);
  pinMode(BLUEPin4, OUTPUT);
  pinMode(REDPin5, OUTPUT);
  pinMode(GREENPin5, OUTPUT);
  pinMode(BLUEPin5, OUTPUT);
  pinMode(REDPin6, OUTPUT);
  pinMode(GREENPin6, OUTPUT);
  pinMode(BLUEPin6, OUTPUT);
  pinMode(REDPin7, OUTPUT);
  pinMode(GREENPin7, OUTPUT);
  pinMode(BLUEPin7, OUTPUT);
  pinMode(REDPin8, OUTPUT);
  pinMode(GREENPin8, OUTPUT);
  pinMode(BLUEPin8, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  recvWithStartEndMarkers();

  showNewData();
  activateRGBLED();
}


void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
    }
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
 
    while (Serial.available() > 0 && newData == false) {
        Serial.print("estoy en while: ");
        
        rc = Serial.read();
        Serial.println(rc);

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
  
}


void activateRGBLED(){


  if(receivedChars[0] == 'G' && newData == true){
    Serial.println("MODIFICO GLADIADOR");

    if(receivedChars[1] == '1'){
        Serial.println("LED 1");
    
        if(receivedChars[2] == '1'){
          Serial.println("RED COLOR ON");
          analogWrite(REDPin1, 255);
          analogWrite(BLUEPin1, 0);
          analogWrite(GREENPin1, 0);
          newData = false;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '2'){
          
          Serial.println("BLUE COLOR ON");
          analogWrite(BLUEPin1,255);
          analogWrite(REDPin1, 0);
          analogWrite(GREENPin1, 0);
          newData = false;
          //receivedChars[0] = (char)0;
           memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '3'){
          Serial.println("GREEN COLOR ON");

          analogWrite(BLUEPin1,0);
          analogWrite(REDPin1, 0);
          analogWrite(GREENPin1, 255);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

         else{
          Serial.println("LED 1 OFF");
          analogWrite(BLUEPin1,0);
          analogWrite(REDPin1, 0);
          analogWrite(GREENPin1, 0);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }
      
    }

     if(receivedChars[1] == '2'){

         Serial.println("LED 2");
    
        if(receivedChars[2] == '1'){
          Serial.println("RED COLOR ON");
          analogWrite(REDPin2, 255);
          analogWrite(BLUEPin2, 0);
          analogWrite(GREENPin2, 0);
          newData = false;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '2'){
          
          Serial.println("BLUE COLOR ON");
          analogWrite(BLUEPin2,255);
          analogWrite(REDPin2, 0);
          analogWrite(GREENPin2, 0);
          newData = false;
          //receivedChars[0] = (char)0;
           memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '3'){
          Serial.println("GREEN COLOR ON");
    
          analogWrite(BLUEPin2,0);
          analogWrite(REDPin2, 0);
          analogWrite(GREENPin2, 255);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

         else{
          Serial.println("LED 2 OFF");
          analogWrite(BLUEPin2,0);
          analogWrite(REDPin2, 0);
          analogWrite(GREENPin2, 0);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }
      
    }

     if(receivedChars[1] == '3'){

        
         Serial.println("LED 3");
    
        if(receivedChars[2] == '1'){
          Serial.println("RED COLOR ON");
          analogWrite(REDPin3, 255);
          analogWrite(BLUEPin3, 0);
          analogWrite(GREENPin3, 0);
          newData = false;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '2'){
          
          Serial.println("BLUE COLOR ON");
          analogWrite(BLUEPin3,255);
          analogWrite(REDPin3, 0);
          analogWrite(GREENPin3, 0);
          newData = false;
          //receivedChars[0] = (char)0;
           memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '3'){
          Serial.println("GREEN COLOR ON");
    
          analogWrite(BLUEPin3,0);
          analogWrite(REDPin3, 0);
          analogWrite(GREENPin3, 255);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

         else{
          Serial.println("LED 3 OFF");
          analogWrite(BLUEPin3,0);
          analogWrite(REDPin3, 0);
          analogWrite(GREENPin3, 0);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }
      
    }

     if(receivedChars[1] == '4'){

        
         Serial.println("LED 4");
    
        if(receivedChars[2] == '1'){
          Serial.println("RED COLOR ON");
          analogWrite(REDPin4, 255);
          analogWrite(BLUEPin4, 0);
          analogWrite(GREENPin4, 0);
          newData = false;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '2'){
          
          Serial.println("BLUE COLOR ON");
          analogWrite(BLUEPin4,255);
          analogWrite(REDPin4, 0);
          analogWrite(GREENPin4, 0);
          newData = false;
          //receivedChars[0] = (char)0;
           memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '3'){
          Serial.println("GREEN COLOR ON");
    
          analogWrite(BLUEPin4,0);
          analogWrite(REDPin4, 0);
          analogWrite(GREENPin4, 255);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

         else{
          Serial.println("LED 4 OFF");
          analogWrite(BLUEPin4,0);
          analogWrite(REDPin4, 0);
          analogWrite(GREENPin4, 0);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }
      
    }

     if(receivedChars[1] == '5'){

        
         Serial.println("LED 5");
    
        if(receivedChars[2] == '1'){
          Serial.println("RED COLOR ON");
          analogWrite(REDPin5, 255);
          analogWrite(BLUEPin5, 0);
          analogWrite(GREENPin5, 0);
          newData = false;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '2'){
          
          Serial.println("BLUE COLOR ON");
          analogWrite(BLUEPin5,255);
          analogWrite(REDPin5, 0);
          analogWrite(GREENPin5, 0);
          newData = false;
          //receivedChars[0] = (char)0;
           memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '3'){
          Serial.println("GREEN COLOR ON");
    
          analogWrite(BLUEPin5,0);
          analogWrite(REDPin5, 0);
          analogWrite(GREENPin5, 255);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

         else{
          Serial.println("LED 5 OFF");
          analogWrite(BLUEPin5,0);
          analogWrite(REDPin5, 0);
          analogWrite(GREENPin5, 0);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }
      
    }

     if(receivedChars[1] == '6'){

        
         Serial.println("LED 6");
    
        if(receivedChars[2] == '1'){
          Serial.println("RED COLOR ON");
          analogWrite(REDPin6, 255);
          analogWrite(BLUEPin6, 0);
          analogWrite(GREENPin6, 0);
          newData = false;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '2'){
          
          Serial.println("BLUE COLOR ON");
          analogWrite(BLUEPin6,255);
          analogWrite(REDPin6, 0);
          analogWrite(GREENPin6, 0);
          newData = false;
          //receivedChars[0] = (char)0;
           memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '3'){
          Serial.println("GREEN COLOR ON");
    
          analogWrite(BLUEPin6,0);
          analogWrite(REDPin6, 0);
          analogWrite(GREENPin6, 255);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

         else{
          Serial.println("LED 6 OFF");
          analogWrite(BLUEPin6,0);
          analogWrite(REDPin6, 0);
          analogWrite(GREENPin6, 0);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }
      
    }

     if(receivedChars[1] == '7'){

        
         Serial.println("LED 7");
    
        if(receivedChars[2] == '1'){
          Serial.println("RED COLOR ON");
          analogWrite(REDPin7, 255);
          analogWrite(BLUEPin7, 0);
          analogWrite(GREENPin7, 0);
          newData = false;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '2'){
          
          Serial.println("BLUE COLOR ON");
          analogWrite(BLUEPin7,255);
          analogWrite(REDPin7, 0);
          analogWrite(GREENPin7, 0);
          newData = false;
          //receivedChars[0] = (char)0;
           memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '3'){
          Serial.println("GREEN COLOR ON");
    
          analogWrite(BLUEPin7,0);
          analogWrite(REDPin7, 0);
          analogWrite(GREENPin7, 255);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

         else{
          Serial.println("LED 7 OFF");
          analogWrite(BLUEPin7,0);
          analogWrite(REDPin7, 0);
          analogWrite(GREENPin7, 0);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }
      
    }


    if(receivedChars[1] == '8'){

        
         Serial.println("LED 8");
    
        if(receivedChars[2] == '1'){
          Serial.println("RED COLOR ON");
          analogWrite(REDPin8, 255);
          analogWrite(BLUEPin8, 0);
          analogWrite(GREENPin8, 0);
          newData = false;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '2'){
          
          Serial.println("BLUE COLOR ON");
          analogWrite(BLUEPin8,255);
          analogWrite(REDPin8, 0);
          analogWrite(GREENPin8, 0);
          newData = false;
          //receivedChars[0] = (char)0;
           memset(receivedChars, 0, sizeof(receivedChars));
        }

        else if(receivedChars[2] == '3'){
          Serial.println("GREEN COLOR ON");
    
          analogWrite(BLUEPin8,0);
          analogWrite(REDPin8, 0);
          analogWrite(GREENPin8, 255);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }

         else{
          Serial.println("LED 8 OFF");
          analogWrite(BLUEPin8,0);
          analogWrite(REDPin8, 0);
          analogWrite(GREENPin8, 0);
          newData = false;
          //receivedChars[0] = (char)0;
          memset(receivedChars, 0, sizeof(receivedChars));
        }
      
    }
    
  }

  else if (receivedChars[0] == 'G' && newData == false){
    
  }

  else{
    newData = false;
    memset(receivedChars, 0, sizeof(receivedChars));
  }
  
}
