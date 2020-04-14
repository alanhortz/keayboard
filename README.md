# Keyboard

Keayboard is a simple unit tested state machine in C. The project has been setup to demonstrate a Test Driven Development approach to the development of embedded systems. The project shows ho to configure and use a Build automation system (Ceedling) in addition to a Unit Testing framework (Unity) and a Mocking library (CMock).

## Prerequisites

  * Make sure you have `gcc` installed on your machine

## Installation

  * Install [Ceedling](https://www.throwtheswitch.org/ceedling), follow the installation instructions [here](https://github.com/ThrowTheSwitch/Ceedling).

## Get started

  * Set your current directory to the project folder 
  * execute `ceedling test:all` 
  * You should get an output like this one : 

   ```
    Test 'test_display_controller.c'
    --------------------------------
    Compiling test_display_controller_runner.c...
    Compiling test_display_controller.c...
    Compiling unity.c...
    Compiling display_controller.c...
    Compiling cmock.c...
    Linking test_display_controller.out...
    Running test_display_controller.out...


    Test 'test_keyboard.c'
    ----------------------
    Compiling test_keyboard_runner.c...
    Compiling test_keyboard.c...
    Compiling mock_display_controller.c...
    Compiling keyboard.c...
    Linking test_keyboard.out...
    Running test_keyboard.out...

    -----------
    TEST OUTPUT
    -----------
    [test_keyboard.c]
      - "Keyboard initializedState name : DEFAULTdefault::SHIFT_DEPRESSEDState name : SHIFTEDkey AState name : SHIFTED"

    --------------------
    IGNORED TEST SUMMARY
    --------------------
    [test_display_controller.c]
      Test: test_display_controller_NeedToImplement
      At line (15): "Need to Implement display_controller"

    --------------------
    OVERALL TEST SUMMARY
    --------------------
    TESTED:  2
    PASSED:  1
    FAILED:  0
    IGNORED: 1
   ```
