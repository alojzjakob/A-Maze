void collector(){
/* ------- BUTTON PRESS ACTIONS ------- */
    bool wall;
    /* ------- BUTTON 1 - LEFT ------- */
    if(button1State==ACTIVATED){
      //generateMaze();
      if(posx-1>=0){
        wall=readPixel(posx-1,posy);
        if(!wall){
          --posx;
          tone(sound,1600,5);
        }else{
          tone(sound,100,50);  
        }
      }else{
        tone(sound,100,50);
      }
      delay(20);
    }
    /* ------- BUTTON 2 - RIGHT ------- */
    if(button2State==ACTIVATED){
      if(posx+1<=MAZEHEIGHT){
        wall=readPixel(posx+1,posy);
        if(!wall){
          ++posx;
          tone(sound,1600,5);
        }else{
          tone(sound,100,50);  
        }
      }else{
        tone(sound,100,50);
      }
      delay(20);
    }
    /* ------- BUTTON 3 - UP ------- */
    if(button3State==ACTIVATED){
      if(posy-1>=2){
        wall=readPixel(posx,posy-1);
        if(!wall){
          --posy;
          tone(sound,1600,5);
        }else{
          tone(sound,100,50);  
        }
      }else{
        tone(sound,100,50);
      }
      delay(20);
    }
    /* ------- BUTTON 4 - DOWN ------- */
    if(button4State==ACTIVATED){
      if(posy+1<=MAZEWIDTH){
        wall=readPixel(posx,posy+1);
        if(!wall){
          ++posy;
          tone(sound,1600,5);
        }else{
          tone(sound,100,50);  
        }
      }else{
        tone(sound,100,50);
      }
      delay(20);
    }
  
    if(button5State==ACTIVATED){//A
      //display.fillCircle(20,30,5,WHITE);
      delay(20);
    }
    if(button6State==ACTIVATED){//B
      //display.fillCircle(50,30,5,WHITE);
      delay(20);
    }
    if(button7State==ACTIVATED){//MENU
      //display.fillCircle(80,30,5,WHITE);
      delay(20);
    }
  
    
    display.setCursor(0,0);
  
    if(posx==MAZEHEIGHT){
      posx=0;
      posy=2;
      displayLevelSplash();
      level++;
      illuminatedRow=0;
      blinkPlayer=1;
      wallPhase=1;
    }else{
      drawMaze();
    }  
}
