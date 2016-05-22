    int curent_avg0 = 0;
    int curent_avg1 = 0;
    int curent_avg2 = 0;
    int curent_avg3 = 0;

    int threshold = 30;
    int max_threshold = 25;
    int min_threshold = 7;

    int sensorVals0[10];
    int sensorVals1[10];
    int sensorVals2[10];
    int sensorVals3[10];

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:

  check_all();

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}

void message() {
  Serial.println("X33:" + String(analogRead(A0), HEX) + "," + String(analogRead(A1), HEX) + "," +String(analogRead(A2), HEX) + "," +String(analogRead(A3), HEX)+ ";");
}

void check_all() {

  int temp_avg0 = moving_avg(sensorVals0, analogRead(A0));
  int temp_avg1 = moving_avg(sensorVals1, analogRead(A1));
  int temp_avg2 = moving_avg(sensorVals2, analogRead(A2));
  int temp_avg3 = moving_avg(sensorVals3, analogRead(A3));


  bool display_msg = false;
  
   if(check(curent_avg0, temp_avg0)) {
      curent_avg0 = temp_avg0;
//      Serial.print("Curent Avg ");
//      Serial.println(String(curent_avg0));
//      Serial.println("A0 - Changed");
      display_msg = true;
    }

    if(check(curent_avg1, temp_avg1)) {
      curent_avg1 = temp_avg1;
//      Serial.println("A1 - Changed");
      display_msg = true;
    }
    
    if(check(curent_avg2, temp_avg2)) {
      curent_avg2 = temp_avg2;
//      Serial.println("A2 - Changed");
      display_msg = true;
    }

    
    if(check(curent_avg3, temp_avg3)) {
      curent_avg3 = temp_avg3;
//      Serial.println("A3 - Changed");
      display_msg = true;
    }

    if(display_msg) {
      message();
    }

}

int check(int curent_avg, int temp_avg) {
   if(curent_avg != temp_avg && abs(curent_avg-temp_avg) > threshold) {
    curent_avg = temp_avg;
    if(threshold > min_threshold) {
      threshold-10;
    }
    else {
      threshold = min_threshold;
    }
    return true;
  } else {
    if(threshold < max_threshold) {
      threshold+10;
    }
    else {
      threshold = max_threshold;
    }
    return false;
  }
}

int moving_avg(int work_array[], int curentVal) {
  for(int i = 1; i<10; i++ ){
    work_array[i-1] = work_array[i];
  }
  work_array[9] = curentVal;

  int summ = 0;
  for(int i = 0; i<9; i++ ){
    summ+=work_array[i];
  }

  return summ/10;
}
