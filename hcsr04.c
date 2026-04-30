// ============================================================
//  hcsr04.c — Sensor ultrasónico HC-SR04 para PICasp
//  Versión: 1.0.0
// ============================================================

#include "hcsr04.h"

// ── Función interna — dispara pulso y mide eco ────────────────
static uint32_t _HCSR04_pulse(HCSR04* sensor) {
    digitalWrite(sensor->trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(sensor->trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(sensor->trigPin, LOW);
    return pulseIn(sensor->echoPin, HIGH, HCSR04_TIMEOUT_US);
}

// ── API pública ───────────────────────────────────────────────
void HCSR04_begin(HCSR04* sensor, pin_t trigPin, pin_t echoPin) {
    sensor->trigPin = trigPin;
    sensor->echoPin = echoPin;
    pinMode(trigPin,  OUTPUT);
    pinMode(echoPin,  INPUT);
    digitalWrite(trigPin, LOW);
    delay(50);
}

uint16_t HCSR04_readCm(HCSR04* sensor) {
    uint32_t duration = _HCSR04_pulse(sensor);
    if (duration == 0) return 0;
    return (uint16_t)(duration / 58UL);
}

uint16_t HCSR04_readMm(HCSR04* sensor) {
    uint32_t duration = _HCSR04_pulse(sensor);
    if (duration == 0) return 0;
    return (uint16_t)(duration / 6UL);
}

uint16_t HCSR04_readInch(HCSR04* sensor) {
    uint32_t duration = _HCSR04_pulse(sensor);
    if (duration == 0) return 0;
    return (uint16_t)(duration / 148UL);
}
