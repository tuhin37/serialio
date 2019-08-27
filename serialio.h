void float2serial(float inData) { 
    uint8_t bytes[sizeof(float)];
    *(float*)(bytes) = inData;  // convert float to bytes
    Serial.write(bytes[0]);
    Serial.write(bytes[1]);
    Serial.write(bytes[2]);
    Serial.write(bytes[3]);
    Serial.flush(); // wait for the transmission to complete
}

float serial2float() {
    if(Serial.available()<4) {
        return -1;
    }
    else {
        uint8_t bytes[sizeof(float)];
        float outData;
        bytes[0] = Serial.read();
        bytes[1] = Serial.read();
        bytes[2] = Serial.read();
        bytes[3] = Serial.read();
        outData = *(float*)(bytes);
        return outData;
    }
}

void dword2serial(uint16_t inData) {
    Serial.write((inData>>8) & 0xFF);
    Serial.write(inData & 0xFF);
    Serial.flush(); // wait for the transmission to complete
}

uint16_t serial2dward() {
    if(Serial.available()<2) {
        return 65535; // largest number of 16 bit
    }
    else {
        uint16_t outData;
        uint8_t hbyte, lbyte;
        hbyte = (uint8_t) Serial.read();
        lbyte = (uint8_t) Serial.read();
        outData |= hbyte << 8;
        outData |= lbyte;
        return outData;
    }
}
