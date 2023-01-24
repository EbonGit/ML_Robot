#include "pico/stdlib.h"
#include "src/pico_servo.h"
#include <stdio.h>
#include <stdlib.h>

const uint min_ = 0;
const uint max_ = 720;

const uint SERVO_PIN_15 = 15;
const uint SERVO_PIN_14 = 14;

const uint SERVO_PIN_13 = 13;
const uint SERVO_PIN_12 = 12;


const uint SERVO_PIN_16 = 16;
const uint SERVO_PIN_17 = 17;

const uint SERVO_PIN_18 = 18;
const uint SERVO_PIN_19 = 19;

int l_number [] = {12, 13, 14, 15, 16, 17, 18, 19};
int l_valeurs [] = {360, 360, 360, 360, 360, 360, 360, 360};

void move(int number, int angle){
    
    if (number == 7 || number == 0 || number == 5 || number == 2){
        l_valeurs[number] -= angle;
        if (l_valeurs[number] > 360 - 180 && l_valeurs[number] < 360 + 180){
            servo_set_position(l_number[number], l_valeurs[number]);
        }
        else{
            l_valeurs[number] += angle;
        }
        

    }
    else{
        l_valeurs[number] += angle;
        if (l_valeurs[number] > 360 - 180 && l_valeurs[number] < 360 + 180){
            servo_set_position(l_number[number], l_valeurs[number]);
        }
        else{
            l_valeurs[number] -= angle;
        }
        
    }
}

int main()
{
    stdio_init_all();
	

    servo_enable(SERVO_PIN_12);
    servo_enable(SERVO_PIN_13);
    servo_enable(SERVO_PIN_14);
    servo_enable(SERVO_PIN_15);

    servo_enable(SERVO_PIN_16);
    servo_enable(SERVO_PIN_17);
    servo_enable(SERVO_PIN_18);
    servo_enable(SERVO_PIN_19);

    //bool clockwise = true;

    for (int i = 0; i < 8; i++) {
            move(i, 0);   
        }
    
    int dic_index[110];
    int dic_value[110];



    dic_index[48] = 0;
    dic_value[48] = 1;
    dic_index[49] = 1;
    dic_value[49] = 1;
    dic_index[50] = 2;
    dic_value[50] = 1;
    dic_index[51] = 3;
    dic_value[51] = 1;
    dic_index[52] = 4;
    dic_value[52] = 1;
    dic_index[53] = 5;
    dic_value[53] = 1;
    dic_index[54] = 6;
    dic_value[54] = 1;
    dic_index[55] = 7;
    dic_value[55] = 1;

    dic_index[97] = 0;
    dic_value[97] = -1;
    dic_index[98] = 1;
    dic_value[98] = -1;
    dic_index[99] = 2;
    dic_value[99] = -1;
    dic_index[100] = 3;
    dic_value[100] = -1;
    dic_index[101] = 4;
    dic_value[101] = -1;
    dic_index[102] = 5;
    dic_value[102] = -1;
    dic_index[103] = 6;
    dic_value[103] = -1;
    dic_index[104] = 7;
    dic_value[104] = -1;

    while (1) {
        
        int c = PICO_ERROR_TIMEOUT;
        
        
        
        
        while (c == PICO_ERROR_TIMEOUT){
            c = getchar_timeout_us(10);
            
        }
        
        int index = dic_index[c];
        int value = dic_value[c];

        printf("(%d %d) ", index, value);
        move(index, value);
    }
    return 0;
}

