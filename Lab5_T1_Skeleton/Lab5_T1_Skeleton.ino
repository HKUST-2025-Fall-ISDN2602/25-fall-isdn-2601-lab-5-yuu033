/*Change all the ? in the code and add code in ??? to Control the speed of rotation.*/

#define IN1   26  // Replace the ? with the GPIO pin you selected to connect IN1
#define IN2   25   // Replace the ? with the GPIO pin you selected to connect IN2
#define A  34 // Replace the ? with the GPIO pin you selected to connect encoder A
#define B  35 // Replace the ? with the GPIO pin you selected to connect encoder B
#define PWM 14  // Replace the ? with the GPIO pin you selected to output PWM

int A_data=0;
int B_data=0;

String command;

void setup() {
  /*setup baud and pin mode */
  Serial.begin(115200);
  pinMode(26,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(34,INPUT);
  pinMode(35,INPUT);
  pinMode(14,OUTPUT);

  /*Set a rotation direction*/
  
}

void loop() {

    digitalWrite(IN1, 0);   // cloclwise
    digitalWrite(IN2, 1);
    if (Serial.available() > 0) {
        command = Serial.readStringUntil('\n'); // Read the incoming command
        command.trim(); // Remove any leading or trailing whitespace
        if (command == "0") {
        // output PWM signals with 0% duty cycle
        analogWrite(PWM,0);  
        } 
        else if (command == "25") {
        // output PWM signals with 25% duty cycle
        analogWrite(PWM,63.75);   
        }
        else if (command == "50") {
        // output PWM signals with 50% duty cycle
        analogWrite(PWM,127.5);   
        }
        else if (command == "75") {
        // output PWM signals with 75% duty cycle
        analogWrite(PWM,191.25);   
        }
        else if (command == "100") {
        // output PWM signals with 100% duty cycle
        analogWrite(PWM,255);   
        }
        }
    // Read values of A and B
        A_data=digitalRead(A);
        B_data=digitalRead(B);
    // Plot A B in Serial Plotter
        Serial.print("A:");
        Serial.print(A_data);
        Serial.print(",");
        Serial.print("B:");
        Serial.print(B_data);
        Serial.println("\t"); 
    
}
