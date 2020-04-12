#include "unity.h"
#include "keyboard.h"
#include "mock_display_controller.h"

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
  
  
  printf("State name : %s", k.stateName);
  TEST_ASSERT_EQUAL(0, strcmp(k.stateName, "DEFAULT"));

  ke.super_.sig = SHIFT_DEPRESSED_SIG;
  FsmDispatch((Fsm *)&k, (Event *)&ke);  /* dispatch */
  printf("State name : %s", k.stateName);

  TEST_ASSERT_EQUAL(0, strcmp(k.stateName, "SHIFTED"));

  ke.super_.sig = ANY_KEY_SIG;
  ke.code = 'a';
  display_Expect('A'); // We expect the keyboard to call display with an 'A'
  FsmDispatch((Fsm *)&k, (Event *)&ke);  /* dispatch */

  printf("State name : %s", k.stateName);
  TEST_ASSERT_EQUAL(0, strcmp(k.stateName, "SHIFTED"));
  
}
