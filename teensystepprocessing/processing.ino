#define NBPASPARTOUR 6400   // used to compute datas from Processing
boolean newData = false;
const byte numChars = 200;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

      // variables to hold the parsed data
      // in void loop //   Receive with start- and end-markers combined with parsing

char messageFromPC[numChars] = {0}; //or 5 doesn't change anything

int integerFromPC0 = 0;
int integerFromPC1 = 0;
int integerFromPC2 = 0;
int integerFromPC3 = 0;
int integerFromPC4 = 0;
int integerFromPC5 = 0;
int integerFromPC6 = 0;
int integerFromPC7 = 0;
int integerFromPC8 = 0;
int integerFromPC9 = 0;

int PC0= 0;
int PC1= 0;
int PC2= 0;
int PC3= 0;
int PC4= 0;
int PC5= 0;
int PC6= 0;
int PC7= 0;
int PC8= 0;
int PC9= 0;


int PCTer0= 0;
int PCTer1= 0;
int PCTer2= 0;
int PCTer3= 0;
int PCTer4= 0;
int PCTer5= 0;
int PCTer6= 0;
int PCTer7= 0;
int PCTer8= 0;
int PCTer9= 0;
int PCTer10= 0;
int PCTer11= 0;

int orderTrigger = 0;
int orderCohesion  = 0;
int orderCohesionB = 0;
int startStop = 0;

// end datas from Processing

int led = 13;
 
float floatFromPC = 0.0; // not used for the moment


//==================================================================== CHECK NUMBEROF ROUND AND GOOD MOVEMENT


int tourTest;
// IntervalTimer t1;

#define TX_SIZE 512
uint8_t tx_buffer[TX_SIZE];

//==================================================================    Jonathan computingDelta between actual and previous position.

int processingPosition, processingPosition1,processingPosition2, processingPosition3, processingPosition4; 
int processingPosition5, processingPosition6, processingPosition7, processingPosition8, processingPosition9;


int positionX, positionX1, positionX2, positionX3,positionX4,positionX5, positionX6, positionX7, positionX8, positionX9; 
int previousX, previousX1; //  positionX precedente

bool recvData() {
    bool result = false;
    recvWithStartEndMarkers(); // recevoir chaine de character et disperse en unité 
    if (newData == true) {
        strcpy(tempChars, receivedChars);
            // this temporary copy is necessary to protect the original data
            //   because strtok() used in parseData() replaces the commas with \0
        parseData();
       
        //readDataFromProcessingToSerial1(); // READ 30 datas even if there is ony 24 datas from Processing
        
        newData = false;
        result = true;
    }
    return result;
}
 // fin de recevoir chaine de character et disperse en unité 
 

int16_t computeDeltaPosition( uint16_t processingPosition) { //Moteur 11, le plus à droite des drivers
      static uint16_t oldPositionAbsolue = 0;
   uint16_t positionAbsolue = processingPosition;
   int16_t resultat;
   if(positionAbsolue < oldPositionAbsolue)
    positionAbsolue+=NBPASPARTOUR*1;
   if(positionAbsolue - oldPositionAbsolue < NBPASPARTOUR*1/2)
   resultat = positionAbsolue - oldPositionAbsolue;
  else
    resultat = positionAbsolue - oldPositionAbsolue - NBPASPARTOUR*1;
  oldPositionAbsolue = processingPosition;
  return resultat;

}

int16_t computeDeltaPosition1( uint16_t processingPosition1) {
   static uint16_t oldPositionAbsolue = 0;
   uint16_t positionAbsolue = processingPosition1;
   int16_t resultat;
   if(positionAbsolue < oldPositionAbsolue)
    positionAbsolue+=NBPASPARTOUR*1;
   if(positionAbsolue - oldPositionAbsolue < NBPASPARTOUR*1/2)
   resultat = positionAbsolue - oldPositionAbsolue;
  else
    resultat = positionAbsolue - oldPositionAbsolue - NBPASPARTOUR*1;
  oldPositionAbsolue = processingPosition1;
  return resultat;

}

int16_t computeDeltaPosition2( uint16_t processingPosition2) {
   static uint16_t oldPositionAbsolue = 0;
    uint16_t positionAbsolue = processingPosition2;
    int16_t resultat;
   if(positionAbsolue < oldPositionAbsolue)
    positionAbsolue+=NBPASPARTOUR*1;
   if(positionAbsolue - oldPositionAbsolue < NBPASPARTOUR*1/2)
   resultat = positionAbsolue - oldPositionAbsolue;
  else
    resultat = positionAbsolue - oldPositionAbsolue - NBPASPARTOUR*1;
  oldPositionAbsolue = processingPosition2;
  return resultat;

}


int16_t computeDeltaPosition3( uint16_t processingPosition3) {
   static uint16_t oldPositionAbsolue = 0;
   uint16_t positionAbsolue = processingPosition3;
   int16_t resultat;
   if(positionAbsolue < oldPositionAbsolue)
    positionAbsolue+=NBPASPARTOUR;
   if(positionAbsolue - oldPositionAbsolue < NBPASPARTOUR/2)
   resultat = positionAbsolue - oldPositionAbsolue;
  else
    resultat = positionAbsolue - oldPositionAbsolue - NBPASPARTOUR;
  oldPositionAbsolue = processingPosition3;
  return resultat;

}
int16_t computeDeltaPosition4( uint16_t processingPosition4) {
   static uint16_t oldPositionAbsolue = 0;
   uint16_t positionAbsolue = processingPosition4;
   int16_t resultat;
   if(positionAbsolue < oldPositionAbsolue)
    positionAbsolue+=NBPASPARTOUR;
   if(positionAbsolue - oldPositionAbsolue < NBPASPARTOUR/2)
   resultat = positionAbsolue - oldPositionAbsolue;
  else
    resultat = positionAbsolue - oldPositionAbsolue - NBPASPARTOUR;
  oldPositionAbsolue = processingPosition4;
  return resultat;

}

int16_t computeDeltaPosition5( uint16_t processingPosition5) {
   static uint16_t oldPositionAbsolue = 0;
   uint16_t positionAbsolue = processingPosition5;
   int16_t resultat;
   if(positionAbsolue < oldPositionAbsolue)
    positionAbsolue+=NBPASPARTOUR;
   if(positionAbsolue - oldPositionAbsolue < NBPASPARTOUR/2)
   resultat = positionAbsolue - oldPositionAbsolue;
  else
    resultat = positionAbsolue - oldPositionAbsolue - NBPASPARTOUR;
  oldPositionAbsolue = processingPosition5;
  return resultat;

}

int16_t computeDeltaPosition6( uint16_t processingPosition6) {
   static uint16_t oldPositionAbsolue = 0;
   uint16_t positionAbsolue = processingPosition6;
   int16_t resultat;
   if(positionAbsolue < oldPositionAbsolue)
    positionAbsolue+=NBPASPARTOUR;
   if(positionAbsolue - oldPositionAbsolue < NBPASPARTOUR/2)
   resultat = positionAbsolue - oldPositionAbsolue;
  else
    resultat = positionAbsolue - oldPositionAbsolue - NBPASPARTOUR;
  oldPositionAbsolue = processingPosition6;
  return resultat;

}

int16_t computeDeltaPosition7( uint16_t processingPosition7) {
   static uint16_t oldPositionAbsolue = 0;
   uint16_t positionAbsolue = processingPosition7;
   int16_t resultat;
   if(positionAbsolue < oldPositionAbsolue)
    positionAbsolue+=NBPASPARTOUR;
   if(positionAbsolue - oldPositionAbsolue < NBPASPARTOUR/2)
   resultat = positionAbsolue - oldPositionAbsolue;
  else
    resultat = positionAbsolue - oldPositionAbsolue - NBPASPARTOUR;
  oldPositionAbsolue = processingPosition7;
  return resultat;

}
int16_t computeDeltaPosition8( uint16_t processingPosition8) {
   static uint16_t oldPositionAbsolue = 0;
   uint16_t positionAbsolue = processingPosition8;
   int16_t resultat;
   if(positionAbsolue < oldPositionAbsolue)
    positionAbsolue+=NBPASPARTOUR;
   if(positionAbsolue - oldPositionAbsolue < NBPASPARTOUR/2)
   resultat = positionAbsolue - oldPositionAbsolue;
  else
    resultat = positionAbsolue - oldPositionAbsolue - NBPASPARTOUR;
  oldPositionAbsolue = processingPosition8;
  return resultat;

}

int16_t computeDeltaPosition9( uint16_t processingPosition9) {
   static uint16_t oldPositionAbsolue = 0;
   uint16_t positionAbsolue = processingPosition9;
   int16_t resultat;
   if(positionAbsolue < oldPositionAbsolue)
    positionAbsolue+=NBPASPARTOUR;
   if(positionAbsolue - oldPositionAbsolue < NBPASPARTOUR/2)
   resultat = positionAbsolue - oldPositionAbsolue;
  else
    resultat = positionAbsolue - oldPositionAbsolue - NBPASPARTOUR;
  oldPositionAbsolue = processingPosition9;
  return resultat;

}


void noJoeTransformation()
 { 
/*
       stepper[9].moveTo(PC9);
       stepper[9].run();      
       stepper[8].moveTo(PC8);
       stepper[8].run();      
       stepper[7].moveTo(PC7);
       stepper[7].run();    
       stepper[6].moveTo(PC6);
       stepper[6].run();
       stepper[5].moveTo(PC5); 
       stepper[5].run();            
       stepper[4].moveTo(PC4);
       stepper[4].run();
       stepper[3].moveTo(PC3);
       stepper[3].run();       
       stepper[2].moveTo(PC2);
       stepper[2].run();
       stepper[1].moveTo(PC1);
       stepper[1].run();       
       stepper[0].moveTo(PC0); // premiere donnée envoyée dansla chaine de String de Processing = virtualPositon
       stepper[0].run();
*/
} 

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        
        rc = Serial.read();
        //Serial.println(rc);
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

//================================================================= RECEIVE 24 DATAS FROM PROCESSING

void parseData() {      // split the data into its parts

    char * strtokIndx; // this is used by strtok() as an index

    strtokIndx = strtok(tempChars,",");      // get the first part - the string
 /*
    integerFromPC0 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC1 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC2 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC3 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC4 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC5 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC6 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC7 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC8 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    integerFromPC9 = atoi(strtokIndx);     // convert this part to an integer
*/

 //   strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PC0 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PC1 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PC2 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PC3 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PC4 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PC5 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PC6 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PC7 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PC8 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PC9 = atoi(strtokIndx);     // convert this part to an integer

    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PCTer0 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PCTer1 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PCTer2 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PCTer3 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PCTer4 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PCTer5 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PCTer6 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PCTer7 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PCTer8 = atoi(strtokIndx);     // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    PCTer9 = atoi(strtokIndx);     // convert this part to an integer

    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    orderTrigger = atoi(strtokIndx); // convert this part to an integer 
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    orderCohesion  = atoi(strtokIndx); // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    orderCohesionB  = atoi(strtokIndx); // convert this part to an integer
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    startStop = atoi(strtokIndx); // convert this part to an integer

}

int32_t getPosition(uint8_t number) {
  switch(number) {
    case 0: 
      return PC0;
    break;
    case 1: 
      return PC1;
    break;
    case 2: 
      return PC2;
    break;
    case 3: 
      return PC3;
    break;
    case 4: 
      return PC4;
    break;
    case 5: 
      return PC5;
    break;
  }
}
//============


 void readDataFromProcessingToSerial1() {  // READ 30 datas even if there is ony 24 datas from Processing

// DONT FORGET SerialUSB.println at the end of each line!!!!! 
    Serial1.print ("A "); Serial1.println (integerFromPC0);      
    Serial1.print ("B "); Serial1.println (integerFromPC1);         
    Serial1.print ("C "); Serial1.println (integerFromPC2);    
    Serial1.print ("D "); Serial1.println (integerFromPC3);         
    Serial1.print ("E "); Serial1.println (integerFromPC4);   
    Serial1.print ("F "); Serial1.println (integerFromPC5);    
    Serial1.print ("G "); Serial1.println (integerFromPC6);        
    Serial1.print ("H "); Serial1.println (integerFromPC7);    
    Serial1.print ("I "); Serial1.println (integerFromPC8);         
    Serial1.print ("J "); Serial1.println (integerFromPC9);
 
  Serial1.print ("K ");Serial1.println(PC0);
  Serial1.print ("L ");Serial1.println(PC1);
  Serial1.print ("M ");Serial1.println(PC2);
  Serial1.print ("N ");Serial1.println(PC3);
  Serial1.print ("O ");Serial1.println(PC4); 
  Serial1.print ("P ");Serial1.println(PC5);
  Serial1.print ("Q ");Serial1.println(PC6);
  Serial1.print ("R ");Serial1.println(PC7);
  Serial1.print ("S ");Serial1.println(PC8);
  Serial1.print ("T ");Serial1.println(PC9);  

  Serial1.print ("U ");Serial1.println(positionX);
  Serial1.print ("V ");Serial1.println(positionX1);
  Serial1.print ("W ");Serial1.println(positionX2);
  Serial1.print ("X ");Serial1.println(positionX3);
  Serial1.print ("Y ");Serial1.println(positionX4); 
  Serial1.print ("Z ");Serial1.println(positionX5);
  Serial1.print ("a ");Serial1.println(positionX6);
  Serial1.print ("b ");Serial1.println(positionX7);
  Serial1.print ("c ");Serial1.println(positionX8);
  Serial1.print ("d ");Serial1.println(positionX9);  
    
} 
