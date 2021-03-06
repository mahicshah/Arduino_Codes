const int btnPin = 2;                                     
const int ledPin = 13;                                    
 
int currentLedState;                                      
int previousLedState;               
int currentBtnState;                                      
int previousBtnState;               
 
 
unsigned int count;                                       
unsigned int lastDebounceTime;      
unsigned int debounceDelay;                               

void setup()
{
    pinMode(btnPin, INPUT);
    pinMode(ledPin, OUTPUT);
 
    currentLedState = LOW;  
    previousLedState = LOW;
    currentBtnState = LOW;            
    previousBtnState = LOW;
 
    count = 0;
    lastDebounceTime = 0;  
    debounceDelay = 50;   
 
    Serial.begin(9600);
 
}
 
void loop() 
{
    currentBtnState = digitalRead(btnPin);
    if (currentBtnState != previousBtnState)           
        lastDebounceTime = millis();
 
    if ((millis() - lastDebounceTime) > debounceDelay) 
        currentLedState = currentBtnState;

 
    if ((previousLedState == LOW) && (currentLedState == HIGH)) 
    {
        count++; 
        Serial.println(count);
    }
 
 
    digitalWrite(ledPin, currentLedState);
    previousBtnState = currentBtnState;
    previousLedState = currentLedState;
}
