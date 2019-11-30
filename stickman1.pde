import processing.serial.*;
Serial myPort;  // Create object from Serial class
String val="0";     // Data received from the serial port
float x1,y1,x2,y2,y;
double d;
void setup()
{
  // I know that the first port in the serial list on my mac
  // is Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  size(500,500);
  //String portName = Serial.list()[5]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, "COM5", 9600);
  PFont f= createFont("Georgia",20);
  textFont(f);
}
void draw()
{
 x1=150;
 y1=185;
 x2=150;
 y2=110;
  if ( myPort.available() > 0) 
  { // If data is available,
    val = myPort.readStringUntil('\n');         // read it and store it in val
    //println(val); //print it out in the console
    d= (Math.sqrt((Math.pow((x2-x1),2)+Math.pow((y2-y1),2))));
    x2=x1-(float)(d*Math.sin(Math.toRadians(Float.parseFloat(val))));
    y2=y1+(float)(d*Math.cos(Math.toRadians(Float.parseFloat(val))));
    line (x1,y1,x2,y2);//neck
    line (150,110,150,185); //back
    println(x2,y2);
    y=Float.parseFloat(val);
    println(y);
    textSize(20);
    background(0);
     if(y<10)
    {
      text("payload is = 10-12lbs",250,250);
    }
    else if(10<y && y<20)
    {
      text("payload is = 20-30lbs",250,250);
    }
    else if (20<y && y<40)
    {   
      text("payload is = 40lbs",250,250);
    }
    else if (40<y && y<50)
    {
      text("payload is = 47-52lbs",250,250);
    }
    else if (50<y && y<70)
    {
      text("payload is = 57-65lbs",250,250);
    }

  }
  delay(700);
}
