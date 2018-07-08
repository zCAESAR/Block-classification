#include <Servo.h> //引入lib  
  
Servo myservo2;  // 创建一个伺服电机对象  
Servo myservo3; 
Servo myservo4; 
Servo myservo5;   
char inByte = 0; //串口接收的数据  
int angle = 0;  //角度值  
String temp = "";//临时字符变量，又或者说是缓存用的吧  
int i=0;
int ii=0; 
void setup()   
{  
  myservo2.attach(2);    
  myservo3.attach(4);
  myservo4.attach(6);
  myservo5.attach(8);
  Serial.begin(9600);  //设置波特率  
}  
  
  
void loop()   
{  
  
  while (Serial.available() > 0) //判断串口是否有数据  
  { 
    if (Serial.available()=="a")
    {
       inByte = Serial.read();//读取数据，串口一次只能读1个字符     
       temp += inByte;
       Serial.println(temp);
        inByte = Serial.read();//读取数据，串口一次只能读1个字符     
        temp += inByte;
     inByte = Serial.read();//读取数据，串口一次只能读1个字符     
    temp += inByte;
     inByte = Serial.read();//读取数据，串口一次只能读1个字符     
    temp += inByte;
    inByte="";
    }
    else 
      break;
    //inByte = Serial.read();//读取数据，串口一次只能读1个字符     
    //temp += inByte;//把读到的字符存进临时变量里面缓存，  
                   //再继续判断串口还有没有数据，知道把所有数据都读取出来  
   }  
  
   if(temp != "")   //判断临时变量是否为空  
   {  
    i=temp.toInt();
    ii=i/1000;
    angle=i-1000*ii;
    ii=ii+2;
    //1angle = temp.toInt();    //把变量字符串类型转成整型  
    Serial.println(ii-2);
    Serial.println(angle);  //输出数据到串口上，以便观察  
   }  
  temp = "";//请看临时变量  
  switch (ii)
  {
    case 2:
      myservo2.write(angle); 
      delay(15);//延时100毫秒  
      break;
    case 3:
      myservo3.write(angle); 
      delay(15);//延时100毫秒 
      break;
    case 4:
      myservo4.write(angle); 
      delay(15);//延时100毫秒
      break; 
    case 5:
      myservo5.write(angle); 
      delay(105);//延时100毫秒 
      break;
  }
  
}  
