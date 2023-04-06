int condition_navy(int year, int month , int day){
  if(year <= 2015) return 0;
  

  else if(year == 2016){
    if(month <= 10) return 0;
    else if(month == 11){
      if(day<=2) return 0;
      else if(day<=16) return 1;
      else return 2;
    }
    else{
      if(day<=14) return 3;
      else if(day<=28) return 4;
      else return 5;
    }
  }
  

  else if(year == 2017){
    if(month == 1){
      if(day<=11) return 5;
      else if(day<=25) return 6;
      else return 7;
    } 
    else if(month == 2){
      if(day<=8) return 7;
      else if(day<=22) return 8;
      else return 9;
    } 
    else if(month == 3){
      if(day<=8) return 9;
      else if(day<=22) return 10;
      else return 11;
    } 
    else if(month == 4){
      if(day<=5) return 11;
      else if(day<=19) return 12;
      else return 13;
    } 
    else if(month == 5){
      if(day<=3) return 13;
      else if(day<=17) return 14;
      else return 15;
    } 
    else if(month == 6){
      if(day<=1) return 15;
      else if(day<=14) return 16;
      else if(day<=28) return 17;
      else return 18;
    } 
    else if(month == 7){
      if(day<=12) return 18;
      else if(day<=26) return 19;
      else return 20;
    } 
    else if(month == 8){
      if(day<=9) return 20;
      else if(day<=23) return 21;
      else return 22;
    } 
    else if(month == 9){
      if(day<=6) return 22;
      else if(day<=20) return 23;
      else return 24;
    } 
    else if(month == 10){
      if(day<=4) return 24;
      else if(day<=18) return 25;
      else return 26;
    } 
    else if(month == 11){
      if(day<=1) return 26;
      else if(day<=15) return 27;
      else if(day<=29) return 28;
      else return 29;
    } 
    else{
      if(day<=13) return 29;
      else if(day<=27) return 30;
      else return 31;
    } 
  }
  

  else if(year == 2018){
    if(month == 1){
      if(day<=10) return 31;
      else if(day<=24) return 32;
      else return 33;
    }
    else if(month == 2){
      if(day<=7) return 33;
      else if(day<=21) return 34;
      else return 35;
    }
    else if(month == 3){
      if(day<=7) return 35;
      else if(day<=21) return 36;
      else return 37;
    }
    else if(month == 4){
      if(day<=4) return 37;
      else if(day<=18) return 38;
      else return 39;
    }
    else if(month == 5){
      if(day<=2) return 39;
      else if(day<=16) return 40;
      else if(day<=30) return 41;
      else return 42;
    }
    else if(month == 6){
      if(day<=13) return 42;
      else if(day<=27) return 43;
      else return 44;
    }
    else if(month == 7){
      if(day<=11) return 44;
      else if(day<=25) return 45;
      else return 46;
    }
    else if(month == 8){
      if(day<=8) return 46;
      else if(day<=22) return 47;
      else return 48;
    }
    else if(month == 9){
      if(day<=5) return 48;
      else if(day<=19) return 49;
      else return 50;
    }
    else if(month == 10){
      if(day<=3) return 50;
      else if(day<=17) return 51;
      else return 52;
    }
    else if(month == 11){
      if(day<=1) return 52;
      else if(day<=14) return 53;
      else if(day<=28) return 54;
      else return 55;
    }
    else {
      if(day<=12) return 55;
      else if(day<=26) return 56;
      else return 57;
    }
  }


  else if(year == 2019){
    if(month == 1){
      if(day<=9) return 57;
      else if(day<=23) return 58;
      else return 59;
    }
    else if(month == 2){
      if(day<=6) return 59;
      else if(day<=20) return 60;
      else return 61;
    }
    else if(month == 3){
      if(day<=6) return 61;
      else if(day<=20) return 62;
      else return 63;
    }
    else if(month == 4){
      if(day<=3) return 63;
      else if(day<=17) return 64;
      else return 65;
    }
    else if(month == 5){
      if(day<=1) return 65;
      else if(day<=15) return 66;
      else if(day<=29) return 67;
      else return 68;
    }
    else if(month == 6){
      if(day<=12) return 68;
      else if(day<=26) return 69;
      else return 70;
    }
    else if(month == 7){
      if(day<=10) return 70;
      else if(day<=24) return 71;
      else return 72;
    }
    else if(month == 8){
      if(day<=7) return 72;
      else if(day<=21) return 73;
      else return 74;
    }
    else if(month == 9){
      if(day<=4) return 74;
      else if(day<=18) return 75;
      else return 76;
    }
    else if(month == 10){
      if(day<=2) return 76;
      else if(day<=16) return 77;
      else if(day<=30) return 78;
      else return 79;
    }
    else if(month == 11){
      if(day<=13) return 79;
      else if(day<=27) return 80;
      else return 81;
    }
    else {
      if(day<=11) return 81;
      else if(day<=25) return 82;
      else return 83;
    }
  }
  

  else if(year == 2020){
    if(month == 1){
      if(day<=8) return 83;
      else if(day<=22) return 84;
      else return 85;
    }
    else if(month == 2){
      if(day<=5) return 85;
      else if(day<=19) return 86;
      else return 87;
    }
    else if(month == 3){
      if(day<=4) return 87;
      else if(day<=18) return 88;
      else return 89;
    }
    else if(month == 4){
      if(day<=1) return 89;
      else if(day<=15) return 90;
      else return 90;
    }
    else return 90;
  }

  else return 90;
} 