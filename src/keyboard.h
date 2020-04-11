#ifndef KEYBOARD_H
#define KEYBOARD_H

 #include "fsm.h"
  
  typedef struct Keyboard Keyboard;
  struct Keyboard
  {
     Fsm super_; /* extend the Fsm class */
     /* ... other attributes of Keyboard */
  };
  
 void KeyboardCtor(Keyboard *me);
 void Keyboard_initial(Keyboard *me, Event const *e);
 void Keyboard_default(Keyboard *me, Event const *e);
 void Keyboard_shifted(Keyboard *me, Event const *e);
 
 typedef struct KeyboardEvt KeyboardEvt;
 struct KeyboardEvt
 {
    Event super_; /* extend the Event class */
    char code;
 };
 
 /* signals used by the Keyboard FSM */
 enum
 {
    SHIFT_DEPRESSED_SIG,
    SHIFT_RELEASED_SIG,
    ANY_KEY_SIG,
 };


#endif // KEYBOARD_H
