#define MAZEHEIGHT  32
#define MAZEWIDTH  15

uint16_t  Maze[] = {
  0b1101111111111111,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1100000000000001,
  0b1101010101010101,
  0b1111111111111101,
  0b0000000000000000
};

uint8_t geni, genj, genk, genval, genmod;
int8_t  genx, geny;



void drawMaze(){
  uint8_t i, j;
  bool wall;
  
  for(i=0;i<=MAZEHEIGHT;i++){
    for(j=0;j<=MAZEWIDTH;j++){
      wall=readPixel(i,j);
      if(wall){

        //walls
        
        if(wallPhase==1){
          if(illuminatedRow>=i){
            display.drawPixel(i*4,j*4,WHITE);
            display.drawPixel(i*4,j*4+2,WHITE);
            display.drawPixel(i*4+1,j*4+1,WHITE);
            display.drawPixel(i*4+1,j*4+3,WHITE);
            display.drawPixel(i*4+2,j*4+2,WHITE);
            display.drawPixel(i*4+2,j*4+4,WHITE);
            display.drawPixel(i*4+3,j*4+1,WHITE);
            display.drawPixel(i*4+3,j*4+3,WHITE);
          }else{
            display.drawPixel(i*4+2,j*4+2,WHITE);
          }
        }else if(wallPhase==2){
          if(illuminatedRow>=i){
            display.fillRect(i*4,j*4,4,4,WHITE);
          }else{
            //display.drawRect(i*4,j*4,4,4,WHITE);
            display.drawPixel(i*4,j*4,WHITE);
            display.drawPixel(i*4,j*4+2,WHITE);
            display.drawPixel(i*4+1,j*4+1,WHITE);
            display.drawPixel(i*4+1,j*4+3,WHITE);
            display.drawPixel(i*4+2,j*4+2,WHITE);
            display.drawPixel(i*4+2,j*4+4,WHITE);
            display.drawPixel(i*4+3,j*4+1,WHITE);
            display.drawPixel(i*4+3,j*4+3,WHITE);
          }
        }else if(wallPhase==3){
          display.fillRect(i*4,j*4,4,4,WHITE);
        }
        //display.drawBitmap(i*4, j*4, brick , 4, 4, WHITE);

        if(wallPhase==3 and (i==posx or j==posy) and j!=0){
          //draw crosshair
          display.drawPixel(i*4+2,j*4+2,BLACK);
        }
        
      }else{

        //not walls
        
        if(wallPhase==3 and (i==posx or j==posy) and j!=0){
          //draw crosshair
          display.drawPixel(i*4+2,j*4+2,WHITE);
        }
        //display.drawBitmap(i*4, j*4, checker , 4, 4, WHITE);
        /*display.drawPixel(i*4,j*4,WHITE);
        display.drawPixel(i*4,j*4+2,WHITE);
        display.drawPixel(i*4+1,j*4+1,WHITE);
        display.drawPixel(i*4+1,j*4+3,WHITE);
        display.drawPixel(i*4+2,j*4+2,WHITE);
        display.drawPixel(i*4+2,j*4+4,WHITE);
        display.drawPixel(i*4+3,j*4+1,WHITE);
        display.drawPixel(i*4+3,j*4+3,WHITE);
        */
      }
    }
  }  


    //display level
  //display.fillRect(0,0,128,8,WHITE);
  if(wallPhase>1){
    display.setTextColor(BLACK);
    display.setCursor(0,0);
    display.print("level: ");
    display.print(level);
  }


  //draw player
  /*
  display.drawPixel(posx*4,posy*4+1,WHITE);
  display.drawPixel(posx*4,posy*4+2,WHITE);
  
  display.drawPixel(posx*4+1,posy*4,WHITE);
  display.drawPixel(posx*4+2,posy*4,WHITE);
  
  display.drawPixel(posx*4+3,posy*4+1,WHITE);
  display.drawPixel(posx*4+3,posy*4+2,WHITE);
  
  display.drawPixel(posx*4+1,posy*4+3,WHITE);
  display.drawPixel(posx*4+2,posy*4+3,WHITE);
  */
  if(blinkPlayer==1){
    display.fillCircle(posx*4+1,posy*4+1,3,WHITE);
    display.fillCircle(posx*4+1,posy*4+1,1,BLACK);
  }else{
    display.fillCircle(posx*4+1,posy*4+1,3,BLACK);
    display.fillCircle(posx*4+1,posy*4+1,1,WHITE);
  }
  /*
  if(blinkPlayer==1){
    display.drawPixel(posx*4+1,posy*4+1,WHITE);
  }
  if(blinkPlayer==2){
    display.drawPixel(posx*4+2,posy*4+1,WHITE);
  }
  if(blinkPlayer==3){
    display.drawPixel(posx*4+1,posy*4+2,WHITE);
  }
  if(blinkPlayer==4){
    display.drawPixel(posx*4+2,posy*4+2,WHITE);
  }
  */
  blinkPlayer++;
  if(blinkPlayer>16){
    blinkPlayer=1;
  }
  
  if(illuminatedRow<MAZEHEIGHT+1){
    illuminatedRow++;
  }else{
    if(wallPhase<3){
      wallPhase++;
      if(wallPhase==2){
        illuminatedRow=0;
      }
    }
  }

  

}

bool readPixel(uint8_t i, uint8_t j){
  uint16_t Data = Maze[i];
  byte Hi = (Data & 0xFF00)>>8;
  byte Lo = Data & 0x00FF;  
  if(j>7){
    return bitRead(Lo, 7 - (j % 8));
  }else{
    //j=j-8;
    return bitRead(Hi, 7 - (j % 8));
  }
}





void generateMaze(){
  bool alternate=false;
  for (geni = 1; geni < MAZEHEIGHT-1; geni++) {
    if(!alternate){
      Maze[geni] = 0b1100000000000001;
    }else{
      Maze[geni] = 0b1101010101010101;
    }
    alternate=!alternate;
  }
  genmod = 4;
  for (geni = 2; geni < MAZEHEIGHT - 2; geni += 2) {
    for (genj = 3; genj < MAZEWIDTH - 1; genj += 2) {
      Maze[geni] |= (0x8000 >> genj);
      do{
        //Roll a stick
        randomSeed(analogRead(A0));
        //genval = (uint8_t)(analogRead(A0) & 0x00FF) % genmod;
        genval = (uint8_t)(random(10000) & 0x00FF) % genmod;
        //val = analogRead(A0) % mod;
        genx = 0, geny = 0;
        if (genval == 0)geny = 1;
        if (genval == 1)genx = -1;
        if (genval == 2)genx = 1;
        if (genval == 3)geny = -1;
      }while ((Maze[geni + geny] & (0x8000 >> (genj + genx)))); 
      Maze[geni + geny] |= (0x8000 >> (genj + genx));
    }
    genmod = 3;
  }
}



/*
void drawMazeSerial(){
  uint8_t i, j;
  bool dot;
  for(i=0;i<=MAZEHEIGHT;i++){
    for(j=0;j<=MAZEWIDTH;j++){
      dot=readPixel(i,j);
      if(dot){
        Serial.print("*");
      }else{
        Serial.print(" ");
      }
    }
    Serial.println();
  }  
}
*/

