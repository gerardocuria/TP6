#include "bsp.h"
#include "digital.h"
#include <stdbool.h>
#include <stddef.h>



int main(void){
    board_t board = BoardCreate();

    while(true){
        if(DigitalInputHasActivated(board->set_time)){
            DisplayWriteBCD(board->display, (uint8_t[]){1,2,3,4},4);
        }

        if (DigitalInputHasActivated(board->cancel)){
            DisplayWriteBCD(board->display, NULL, 0);
        }

        if(DigitalInputHasActivated(board->set_time)){
    
        }

        if(DigitalInputHasActivated(board->set_alarm)){

        }

        if(DigitalInputHasActivated(board->decrement)){

        }

        if(DigitalInputHasActivated(board->increment)){

        }

        DisplayRefresh(board->display);


    }
}