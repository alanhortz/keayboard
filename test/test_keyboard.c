#include "unity.h"
#include <string.h>
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

void test_Given_KeyboardInDefaultState_When_ShiftIsDepressed_Then_EntryIsDisplayedUpperCased(void)
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
  display_Expect('A'); // We set the expectation that the keyboard have to call display with an 'A'
  FsmDispatch((Fsm *)&k, (Event *)&ke);  /* dispatch */

  printf("State name : %s", k.stateName);
  TEST_ASSERT_EQUAL(0, strcmp(k.stateName, "SHIFTED"));
  
}
