https://www.tinkercad.com/things/4LELb1XIrrd-uart-between-2-arduinos

Sending:

char string[] = "Hello";  //String data

void setup()
{
  Serial.begin(9600);  //Baud rate set to 9600
}

void loop()
{
  Serial.write(string,5);  //Write the string data
  delay(1000);
}



Receiving:

char string[10];  //Initialized variable to store variable data

void setup()
{
  Serial.begin(9600);  //Baud rate set to 9600
}

void loop()
{
  Serial.readBytes(string,5);  //Read data
  Serial.println(string);  //Print data on serial monitor
  delay(1000);
}
