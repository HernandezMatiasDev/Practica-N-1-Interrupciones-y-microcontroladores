# Práctica Nº 1 - Interrupciones y microcontroladores

Resolución del [Practica_Nro_1.pdf](Trabajo Práctico Nº 1) de Programación en Tiempo Real (Ingeniería en Informática, UNAJ).

Los programas están escritos en C para microcontroladores PIC, se compilan con **HI-TECH PICC (modo Lite)** y se simulan en **ISIS (Proteus)**.

## Contenido

| Archivo | Microcontrolador | Descripción |
|---|---|---|
| `ejercicio_1.c` | PIC16F84A | Dos LEDs (RB4 y RB5) que alternan cada 250 ms usando `__delay_ms`. Arrancan encendidos y empiezan a titilar al presionar un pulsador (RA0 o RA1). |
| `ejercicio_2.c` | PIC16F84A | Misma funcionalidad que el ejercicio 1, pero usando el **Timer0** con prescaler 1:256 y su **interrupción** para alternar los LEDs. |
| `ejercicio_3.c` | PIC16F877 | Lectura de una entrada analógica (AN0) por **polling** y visualización del valor decimal en 4 displays de 7 segmentos a través de dos latches 74LS373. |

## Resumen de cada ejercicio

- **Ejercicio 1:** espera activa con `__delay_ms` y un flag que recuerda si ya se presionó algún pulsador.
- **Ejercicio 2:** `TMR0` se precarga con 12, de modo que con prescaler 1:256 y reloj de 1 MHz el desborde ocurre cada ~250 ms. La rutina de interrupción invierte los LEDs y limpia `T0IF`.
- **Ejercicio 3:** el conversor A/D se configura con justificación a derecha y VDD como referencia. El valor de 10 bits se separa en miles, centenas, decenas y unidades (BCD), y se envía por el puerto B a cada latch, que se habilita con un pulso en RD6 o RD7.

## Compilación

```
picc --chip=16f84a .\ejercicio_1.c
picc --chip=16f84a .\ejercicio_2.c
picc --chip=16f877 .\ejercicio_3.c
```

## Simulación

Los circuitos son los ejemplos que vienen con Proteus (`Samples\VSM for PICMICRO\VSM for PIC16`):

- Ejercicios 1 y 2: **PIC Doorbell**
- Ejercicio 3: **PIC ADC Example**

Reloj del sistema: 1 MHz.
