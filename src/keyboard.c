#include "keyboard.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "display_controller.h"

// We can also have a conditional include : TEST -> Running tests under ceedling test:all

// #ifdef TEST
//   #include my_testable_substitute_layer.h
// #else
//   #include <avr/interrupt.h>
// #endif



 void KeyboardCtor(Keyboard *me)
 {
    FsmCtor_(&me->super_, &Keyboard_initial);
 }
  
 void Keyboard_initial(Keyboard *me, Event const *e)
 {
    

    /* ... initialization of Keyboard attributes */
    printf("Keyboard initialized");
    FsmTran_((Fsm *)me, &Keyboard_default);
    strncpy(me->stateName, "DEFAULT", 16);
 }
 
 void Keyboard_default(Keyboard *me, Event const *e)
 {

    switch (e->sig)
    {
       case SHIFT_DEPRESSED_SIG:
          printf("default::SHIFT_DEPRESSED");
          FsmTran_((Fsm *)me, &Keyboard_shifted);
          strncpy(me->stateName, "SHIFTED", 16);
          break;
       case ANY_KEY_SIG:
          
          printf("key %c", (char)tolower(((KeyboardEvt *)e)->code));
          break;
    }
 }
 
 void Keyboard_shifted(Keyboard *me, Event const *e)
 {

    switch (e->sig)
    {
       case SHIFT_RELEASED_SIG:
          
          printf("shifted::SHIFT_RELEASED");
          FsmTran_((Fsm *)me, &Keyboard_default);
          strncpy(me->stateName, "DEFAULT", 16);
          break;
       case ANY_KEY_SIG:
          
          printf("key %c", (char)toupper(((KeyboardEvt *)e)->code));
          display((char)toupper(((KeyboardEvt *)e)->code));
          
          break;
    }
 }
