// ============================================================
//  hcsr04.c — Sensor ultrasónico HC-SR04 para PICasp
//  Versión: 1.1.0
// ============================================================
#include "hcsr04.h"

// ── Estado interno del sensor ─────────────────────────────────
static pin_t _trigPin = 0;
static pin_t _echoPin = 0;

#define HCSR04_TIMEOUT_US 38000UL

// ── Función interna ───────────────────────────────────────────
static uint32_t _HCSR04_pulse(void) {
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    return pulseIn(_echoPin, HIGH, HCSR04_TIMEOUT_US);
}

// ── API pública ───────────────────────────────────────────────
void HCSR04_begin(pin_t trigPin, pin_t echoPin) {
    _trigPin = trigPin;
    _echoPin = echoPin;
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
    digitalWrite(_trigPin, LOW);
    delay(50);
}

uint16_t HCSR04_readCm(void) {
    uint32_t duration = _HCSR04_pulse();
    if (duration == 0) return 0;
    return (uint16_t)(duration / 58UL);
}

uint16_t HCSR04_readMm(void) {
    uint32_t duration = _HCSR04_pulse();
    if (duration == 0) return 0;
    return (uint16_t)(duration / 6UL);
}

uint16_t HCSR04_readInch(void) {
    uint32_t duration = _HCSR04_pulse();
    if (duration == 0) return 0;
    return (uint16_t)(duration / 148UL);
}

// ── Instancia global del objeto ───────────────────────────────
HCSR04_t HCSR04 = {
    .begin    = HCSR04_begin,
    .readCm   = HCSR04_readCm,
    .readMm   = HCSR04_readMm,
    .readInch = HCSR04_readInch,
};
