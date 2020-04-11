#include "keyboard.h"
 
 void KeyboardCtor(Keyboard *me)
 {
    FsmCtor_(&me->super_, &Keyboard_initial);
 }
  
 void Keyboard_initial(Keyboard *me, Event const *e)
 {
    /* ... initialization of Keyboard attributes */
    printf("Keyboard initialized");
    FsmTran_((Fsm *)me, &Keyboard_default);
 }
 
 void Keyboard_default(Keyboard *me, Event const *e)
 {
    switch (e->sig)
    {
       case SHIFT_DEPRESSED_SIG:
          printf("default::SHIFT_DEPRESSED");
          FsmTran_((Fsm *)me, &Keyboard_shifted);
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
          break;
       case ANY_KEY_SIG:
          printf("key %c", (char)toupper(((KeyboardEvt *)e)->code));
          break;
    }
 }
