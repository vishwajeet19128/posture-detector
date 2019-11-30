//TR_CapaFenLisesi
//Measure Angle with a MPU-6050(GY-521)

#include<Wire.h>

const int MPU_addr=0x68;
const int A=4;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

int minVal=265;
int maxVal=402;

double x1;
double y1;
double z1;
 


void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  pinMode(A,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  Wire.beginTransmission(MPU_addr);   
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);
  AcX=Wire.read()<<8|Wire.read();
  AcY=Wire.read()<<8|Wire.read();
  AcZ=Wire.read()<<8|Wire.read();
  GyX=Wire.read()<<8|Wire.read();
  GyY=Wire.read()<<8|Wire.read();
  GyZ=Wire.read()<<8|Wire.read();
  
    int x1Ang = map(AcX,minVal,maxVal,-90,90);
    int y1Ang = map(AcY,minVal,maxVal,-90,90);
    int z1Ang = map(AcZ,minVal,maxVal,-90,90);
    /*int x2Ang = map(GyXminVal,maxVal,-90,90);
    int y2Ang = map(GyY,minVal,maxVal,-90,90);
    int z2Ang = map(GyZ,minVal,maxVal,-90,90);*/
       x1= RAD_TO_DEG * (atan2(-y1Ang, -z1Ang)+PI);
       y1= 115-RAD_TO_DEG * (atan2(-x1Ang, -z1Ang)+PI);
       z1= 360- RAD_TO_DEG * (atan2(-y1Ang, -x1Ang)+PI);
       /*x2= RAD_TO_DEG * (atan2(-y2Ang, -z2Ang)+PI);
       y2= 90-RAD_TO_DEG * (atan2(-x2Ang, -z2Ang)+PI);
       z2= 360- RAD_TO_DEG * (atan2(-y2Ang, -x2Ang)+PI);  */     

    // Serial.print("AngleXneck= ");
    // Serial.print(x1);
    //Serial.print("AngleY1= ");
    Serial.println(y1);
    if(y1<10)
    {
      digitalWrite(A,LOW);
    }
    else if(10<y1 and y1<20)
    {
      digitalWrite(A,LOW);
    }
    else if (20<y1 and y1<35)
    {
      digitalWrite(A,LOW);
    }
    else if (35<y1 and y1<50)
    {
      //Serial.print("a");
      digitalWrite(A,HIGH);
    }
    else if (50<y1 and y1<100)
    {
      digitalWrite(A,HIGH);
    }
    delay(400);
    /* Serial.print("AngleY1= ");
     Serial.println(y1);
     delay(500);
     Serial.print("   AngleY2= ");
     Serial.println(y2);
     Serial.print("AngleZ= ");
     Serial.println(z);
     Serial.println("-----------------------------------------");
     delay(400);*/
}
