#include <serialio.h>

float pi=3.1459;
float bi;
uint16_t adc = 1024;

void setup() {
    Serial.begin(9600); // Initialize USART
    delay(500);
    
    float2serial(pi);   // send a float variable (byte by byte) over UART bus
    delay(500);

    bi=serial2float();      // loopback Tx and Rx together, this converts the four received bytes into a float`
    bi+= 0.234;             // add 0.0234 to to received float for testing 
    Serial.println(bi, 4);  // print the float with 4 decimal value (Ans should be 3.1459 + 0.234 = 3.3799)
}

void loop() {

}
