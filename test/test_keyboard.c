#include "unity.h"
#include "keyboard.h"

Keyboard k;

void setUp(void)
{
  KeyboardCtor(&k);
  FsmInit((Fsm *)&k, 0);
}

void tearDown(void)
{
}

void test_Given_KeyboardInDefaultState_When_ShiftIsDepressed_Then_EntryIsUpperCased(void)
{
  KeyboardEvt ke;
  ke.super_.sig = SHIFT_DEPRESSED_SIG;
  FsmDispatch((Fsm *)&k, (Event *)&ke);  /* dispatch */
}
