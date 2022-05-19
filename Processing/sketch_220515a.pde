import processing.serial.*;
import gifAnimation.*;
import cc.arduino.*;
int Value ;
Serial myPort;
PImage GGif1,GGif2,GGif3,GGif4; 

void setup() {
  size(500, 500);
  background(255);
  myPort = new Serial(this, "COM3", 9600);
  GGif1 = loadImage("Alberto.gif"); 
  GGif2 = loadImage("Candidatos.gif"); 
  GGif3 = loadImage("fico.gif"); 
  GGif4 = loadImage("Duque.gif"); 
}
void draw (){
  if (myPort.available() >0){   
      Value = myPort.read(); 
      print(Value);
  
     if (Value == 1){
       image(GGif3, 0, 0);
     }
     if (Value == 2){
       image(GGif1, 0, 0);
     }   
     if (Value == 3){
       image(GGif2, 0, 0);
     } 
     if (Value == 4){
       image(GGif4, 0, 0);
    }
  }
}


  
