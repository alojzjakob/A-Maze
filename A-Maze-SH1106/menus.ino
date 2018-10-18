void mainMenu(){

  menuItemPointerAnimation();
  
  display.setCursor(45,15);
  display.print("walker");
  if(selectedOption==1){
    display.setCursor(30+menuPointerPos,15);
    display.print(">");
  }
  display.setCursor(45,25);
  display.print("collector");
  if(selectedOption==2){
    display.setCursor(30+menuPointerPos,25);
    display.print(">");
  }

  /* ------- BUTTON 3 - UP ------- */
  if(button3State==ACTIVATED){
    selectedOption--;
    if(selectedOption==0){
      selectedOption=2;
    }
    tone(sound,1600,5);
    delay(100);
  }
  /* ------- BUTTON 4 - DOWN ------- */
  if(button4State==ACTIVATED){
    selectedOption++;
    if(selectedOption==3){
      selectedOption=1;
    }
    tone(sound,1600,5);
    delay(100);
  }
  if(button7State==ACTIVATED){
    gameMode=selectedOption;
    generateMaze();
    delay(250);
    button7State = digitalRead(button7Pin);
  }  
}

void gameMenu(){

  menuItemPointerAnimation();
  
  display.fillRect(24,8,80,45,WHITE);
  display.fillRect(25,9,78,43,BLACK);
  display.setTextColor(WHITE);
  display.setCursor(45,15);
  display.print("resume");
  if(selectedOption==1){
    display.setCursor(30+menuPointerPos,15);
    display.print(">");
  }
  display.setCursor(45,25);
  display.print("quit");
  if(selectedOption==2){
    display.setCursor(30+menuPointerPos,25);
    display.print(">");
  }

  /* ------- BUTTON 3 - UP ------- */
  if(button3State==ACTIVATED){
    selectedOption--;
    if(selectedOption==0){
      selectedOption=2;
    }
    tone(sound,1600,5);
    delay(100);
  }
  /* ------- BUTTON 4 - DOWN ------- */
  if(button4State==ACTIVATED){
    selectedOption++;
    if(selectedOption==3){
      selectedOption=1;
    }
    tone(sound,1600,5);
    delay(100);
  }
  if(button7State==ACTIVATED){
    if(selectedOption==1){
       gamePaused=false;
       delay(100);
       button7State = digitalRead(button7Pin);
    }
    if(selectedOption==2){
       asm volatile ("  jmp 0");
    }
    tone(sound,1600,5);
  }
}

void menuItemPointerAnimation(){
  if(menuPointerPosDir){
    menuPointerPos++;
    if(menuPointerPos==6){
      menuPointerPosDir=!menuPointerPosDir;
    }
  }else{
    menuPointerPos--;
    if(menuPointerPos==-1){
      menuPointerPosDir=!menuPointerPosDir;
    }
  }
}

