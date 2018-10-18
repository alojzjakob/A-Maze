void displayLevelSplash(){
  int levely=-8,levelnoy=-8,completey=-8, i, j;
  
  display.setTextColor(WHITE);
  for(i=0;i<3;i++){
    for(j=0;j<50;j+=2){
      display.clearDisplay();
      if(levely<20){
        levely+=2;
        tone(sound,levely*65,5);
      }
      if(levely==20 and levelnoy<30){
        levelnoy+=2;
        tone(sound,levelnoy*65,5);
      }
      if(levely==20 and levelnoy==30 and completey<40){
        completey+=2;
        tone(sound,completey*65,5);
      }
      display.setCursor(15,levely);
      display.print("LEVEL");
      display.setCursor(45,levelnoy);
      display.print(level);
      display.setCursor(55,completey);
      display.print("COMPLETE!");
      display.display();
    }
  }
  
  delay(1000);
  
  levely=-8;
  levelnoy=-8;
  for(i=0;i<2;i++){
    for(j=0;j<50;j+=2){
      display.clearDisplay();
      if(levely<20){
        levely+=2;
        tone(sound,levely*65,5);
      }
      if(levely==20 and levelnoy<30){
        levelnoy+=2;
        tone(sound,levelnoy*65,5);
      }
      display.setCursor(15,levely);
      display.print("LEVEL");
      display.setCursor(45,levelnoy);
      display.print(level+1);
      display.display();
    }
  }
  
  delay(1500);
  
  generateMaze();
}
