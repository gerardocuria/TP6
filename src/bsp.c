#include "digital.h"
#include "bsp.h"
#include "chip.h"
// minuto 40 bsp
//46 main
// 1:06 cambios

#ifndef PONCHO_H
#define PONCHO_H

#include "chip.h"

// Definiciones de los recursos asociados a los DIGITs de la pantalla
#define DIGITS_GPIO   0

#define DIGIT_1_PORT 0
#define DIGIT_1_PIN  0
#define DIGIT_1_FUNC SCU_MODE_FUNC0
#define DIGIT_1_GPIO DIGITS_GPIO
#define DIGIT_1_BIT  0
#define DIGIT_1_MASK (1 << DIGIT_1_BIT)

#define DIGIT_2_PORT 0
#define DIGIT_2_PIN  1
#define DIGIT_2_FUNC SCU_MODE_FUNC0
#define DIGIT_2_GPIO DIGITS_GPIO
#define DIGIT_2_BIT  1
#define DIGIT_2_MASK (1 << DIGIT_2_BIT)

#define DIGIT_3_PORT 1
#define DIGIT_3_PIN  15
#define DIGIT_3_FUNC SCU_MODE_FUNC0
#define DIGIT_3_GPIO DIGITS_GPIO
#define DIGIT_3_BIT  2
#define DIGIT_3_MASK (1 << DIGIT_3_BIT)

#define DIGIT_4_PORT 1
#define DIGIT_4_PIN  17
#define DIGIT_4_FUNC SCU_MODE_FUNC0
#define DIGIT_4_GPIO DIGITS_GPIO
#define DIGIT_4_BIT  3
#define DIGIT_4_MASK (1 << DIGIT_4_BIT)

#define DIGITS_MASK (DIGIT_1_MASK | DIGIT_2_MASK | DIGIT_3_MASK | DIGIT_4_MASK)

// Definiciones de los recursos asociados a los SEGMENTs de la pantalla
#define SEGMENTS_GPIO 2

#define SEGMENT_A_PORT 4
#define SEGMENT_A_PIN  0
#define SEGMENT_A_FUNC SCU_MODE_FUNC0
#define SEGMENT_A_GPIO SEGMENTS_GPIO
#define SEGMENT_A_BIT  0
#define SEGMENT_A_MASK (1 << SEGMENT_A_BIT)

#define SEGMENT_B_PORT 4
#define SEGMENT_B_PIN  1
#define SEGMENT_B_FUNC SCU_MODE_FUNC0
#define SEGMENT_B_GPIO SEGMENTS_GPIO
#define SEGMENT_B_BIT  1
#define SEGMENT_B_MASK (1 << SEGMENT_B_BIT)

#define SEGMENT_C_PORT 4
#define SEGMENT_C_PIN  2
#define SEGMENT_C_FUNC SCU_MODE_FUNC0
#define SEGMENT_C_GPIO SEGMENTS_GPIO
#define SEGMENT_C_BIT  2
#define SEGMENT_C_MASK (1 << SEGMENT_C_BIT)

#define SEGMENT_D_PORT 4
#define SEGMENT_D_PIN  3
#define SEGMENT_D_FUNC SCU_MODE_FUNC0
#define SEGMENT_D_GPIO SEGMENTS_GPIO
#define SEGMENT_D_BIT  3
#define SEGMENT_D_MASK (1 << SEGMENT_D_BIT)

#define SEGMENT_E_PORT 4
#define SEGMENT_E_PIN  4
#define SEGMENT_E_FUNC SCU_MODE_FUNC0
#define SEGMENT_E_GPIO SEGMENTS_GPIO
#define SEGMENT_E_BIT  4
#define SEGMENT_E_MASK (1 << SEGMENT_E_BIT)

#define SEGMENT_F_PORT 4
#define SEGMENT_F_PIN  5
#define SEGMENT_F_FUNC SCU_MODE_FUNC0
#define SEGMENT_F_GPIO SEGMENTS_GPIO
#define SEGMENT_F_BIT  5
#define SEGMENT_F_MASK (1 << SEGMENT_F_BIT)

#define SEGMENT_G_PORT 4
#define SEGMENT_G_PIN  6
#define SEGMENT_G_FUNC SCU_MODE_FUNC0
#define SEGMENT_G_GPIO SEGMENTS_GPIO
#define SEGMENT_G_BIT  6
#define SEGMENT_G_MASK (1 << SEGMENT_G_BIT)

#define SEGMENTS_MASK (SEGMENT_A_MASK | SEGMENT_B_MASK | SEGMENT_C_MASK | \
        SEGMENT_D_MASK | SEGMENT_E_MASK | SEGMENT_F_MASK | SEGMENT_G_MASK )

#define SEGMENT_P_PORT 6
#define SEGMENT_P_PIN  8
#define SEGMENT_P_FUNC SCU_MODE_FUNC4
#define SEGMENT_P_GPIO 5
#define SEGMENT_P_BIT  16

// Definiciones de los recursos asociados a las teclas del puncho
#define KEY_F1_PORT 4
#define KEY_F1_PIN  8
#define KEY_F1_FUNC SCU_MODE_FUNC4
#define KEY_F1_GPIO 5
#define KEY_F1_BIT  12

#define KEY_F2_PORT 4
#define KEY_F2_PIN  9
#define KEY_F2_FUNC SCU_MODE_FUNC4
#define KEY_F2_GPIO 5
#define KEY_F2_BIT  13

#define KEY_F3_PORT 4
#define KEY_F3_PIN  10
#define KEY_F3_FUNC SCU_MODE_FUNC4
#define KEY_F3_GPIO 5
#define KEY_F3_BIT  14

#define KEY_F4_PORT 6
#define KEY_F4_PIN  7
#define KEY_F4_FUNC SCU_MODE_FUNC4
#define KEY_F4_GPIO 5
#define KEY_F4_BIT  15

#define KEY_ACCEPT_PIN  2
#define KEY_ACCEPT_PORT 3
#define KEY_ACCEPT_FUNC SCU_MODE_FUNC4
#define KEY_ACCEPT_GPIO 5
#define KEY_ACCEPT_BIT  9

#define KEY_CANCEL_PORT 3
#define KEY_CANCEL_PIN  1
#define KEY_CANCEL_FUNC SCU_MODE_FUNC4
#define KEY_CANCEL_GPIO 5
#define KEY_CANCEL_BIT  8

// Definiciones de los recursos asociados al zumbador
#define BUZZER_PORT 2
#define BUZZER_PIN 2
#define BUZZER_FUNC SCU_MODE_FUNC4
#define BUZZER_GPIO 5
#define BUZZER_BIT 2


/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */


static struct board_s board = {0};


void DigitsInit (void);

void SegmentsInit(void);

void BuzzerInit(void);

void KeysInit(void);

void ScreenTurnOff(void);

void SegmnetsTurnOn(uint8_t segments);

void DigitTurnOn(uint8_t digit);


void DigitsInit(void){

    Chip_SCU_PinMuxSet(DIGIT_1_PORT, DIGIT_1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | DIGIT_1_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, DIGIT_1_GPIO, DIGIT_1_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, DIGIT_1_GPIO, DIGIT_1_BIT, true);

    Chip_SCU_PinMuxSet(DIGIT_2_PORT, DIGIT_2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | DIGIT_2_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, DIGIT_2_GPIO, DIGIT_2_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, DIGIT_2_GPIO, DIGIT_2_BIT, true);

    Chip_SCU_PinMuxSet(DIGIT_3_PORT, DIGIT_3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | DIGIT_3_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, DIGIT_3_GPIO, DIGIT_3_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, DIGIT_3_GPIO, DIGIT_3_BIT, true);

    Chip_SCU_PinMuxSet(DIGIT_4_PORT, DIGIT_4_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | DIGIT_4_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, DIGIT_4_GPIO, DIGIT_4_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, DIGIT_4_GPIO, DIGIT_4_BIT, true);

}

void SegmentsInit(void){

    Chip_SCU_PinMuxSet(SEGMENT_A_PORT, SEGMENT_A_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_A_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_A_GPIO, SEGMENT_A_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_A_GPIO, SEGMENT_A_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_B_PORT, SEGMENT_B_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_B_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_B_GPIO, SEGMENT_B_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_B_GPIO, SEGMENT_B_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_C_PORT, SEGMENT_C_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_C_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_C_GPIO, SEGMENT_C_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_C_GPIO, SEGMENT_C_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_D_PORT, SEGMENT_D_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_D_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_D_GPIO, SEGMENT_D_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_D_GPIO, SEGMENT_D_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_E_PORT, SEGMENT_E_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_E_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_E_GPIO, SEGMENT_E_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_E_GPIO, SEGMENT_E_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_F_PORT, SEGMENT_F_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_F_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_F_GPIO, SEGMENT_F_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_F_GPIO, SEGMENT_F_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_G_PORT, SEGMENT_G_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_G_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_G_GPIO, SEGMENT_G_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_G_GPIO, SEGMENT_G_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_P_PORT, SEGMENT_P_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_P_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_P_GPIO, SEGMENT_P_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_P_GPIO, SEGMENT_F_BIT, true);

}

void BuzzerInit(void){

    Chip_SCU_PinMuxSet(BUZZER_PORT, BUZZER_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | BUZZER_FUNC);
    board.buzzer = DigitalOutputCreate(BUZZER_GPIO, BUZZER_BIT);

}

void KeysInit (void){

    Chip_SCU_PinMuxSet(KEY_ACCEPT_PORT, KEY_ACCEPT_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | KEY_ACCEPT_FUNC);
    board.accept = DigitalOutputCreate(KEY_ACCEPT_GPIO, KEY_ACCEPT_BIT, false);

    Chip_SCU_PinMuxSet(KEY_CANCEL_PORT, KEY_CANCEL_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | KEY_CANCEL_FUNC);
    board.cancel = DigitalOutputCreate(KEY_CANCEL_GPIO, KEY_CANCEL_BIT, false);

    Chip_SCU_PinMuxSet(KEY_F1_PORT, KEY_F1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | KEY_F1_FUNC);
    board.set_time = DigitalOutputCreate(KEY_F1_GPIO, KEY_F1_BIT, false); //38:30

    Chip_SCU_PinMuxSet(KEY_F2_PORT, KEY_F2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | KEY_F2_FUNC);
    board.set_alarm = DigitalOutputCreate(KEY_F2_GPIO, KEY_F2_BIT, false);

    Chip_SCU_PinMuxSet(KEY_F3_PORT, KEY_F3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | KEY_F3_FUNC);
    board.decrement = DigitalOutputCreate(KEY_F3_GPIO, KEY_F3_BIT, false);

    Chip_SCU_PinMuxSet(KEY_F4_PORT, KEY_F4_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | KEY_F4_FUNC);
    board.increment = DigitalOutputCreate(KEY_F4_GPIO, KEY_F4_BIT, false);

}

void ScreenTurnOff(void){

    Chip_GPIO_ClearValue(LPC_GPIO_PORT, DIGITS_GPIO, DIGITS_MASK);
    Chip_GPIO_ClearValue(LPC_GPIO_PORT, SEGMENTS_GPIO, SEGMENTS_MASK);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_P_GPIO, SEGMENT_P_BIT, false);
}

void SegmnetsTurnOn(uint8_t segments){

    Chip_GPIO_SetValue(LPC_GPIO_PORT,SEGMENTS_GPIO, (segments) & SEGMENTS_MASK);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_P_GPIO, SEGMENT_P_BIT, (segments & SEGMENT_P));

}

void DigitTurnOn(uint8_t digit){

    Chip_GPIO_SetValue(LPC_GPIO_PORT,DIGITS_GPIO, (1<<(digit))& DIGITS_MASK);

}




board_t BoardCreate(void){
    DigitsInit();
    SegmentsInit();
    BuzzerInit();
    KeysInit();

    board.display = DisplayCreate(4,&(struct display_driver_s){
        .ScreenTurnOff = ScreenTurnOff,
        .SegmnetsTurnOn = SegmnetsTurnOn,
        .DigitTurnOn = DigitTurnOn,
    });

    return &board;
};