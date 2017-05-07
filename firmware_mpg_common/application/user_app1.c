/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp1Initialize(void)
{
	LedOff(BLUE);
	LedOff(YELLOW);
	LedOff(RED);
	LedOff(PURPLE);
/*
 LedOn(BLUE);
 LedToggle(PURPLE);
 LedPWM(RED,LED_PWM_10);
 LedBlink(YELLOW,LED_2HZ);
 */
  /* If good initialization, set state to Idle */
  if( 1 )
  {
   // UserApp1_StateMachine = UserApp1SM_Idle;
   UserApp1_StateMachine =   password_button;
     //UserApp1_StateMachine =BCD_code_display;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_FailedInit;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */
//
void password_button(void)
{  
     static u8 u8_password[4]={0,2,3,1};
	 static u8 u8_input_button[4]={0};
	 static  u8 u8_counter_buttton_press=0;
	 static  BOOL B_Pass_No[3]= FALSE;
	 u8 u8_temp_number     =0;
	 if(u8_counter_buttton_press<=3)//you can input the password
		 	{
		 	B_Pass_No[0] = FALSE;//initation the logic parameter
		 	
		 if(WasButtonPressed(BUTTON0))
		 	{
		 	  u8_input_button[u8_counter_buttton_press]=0;
			  LedOn(WHITE);
		 	  
		 	  ButtonAcknowledge(BUTTON0);
			  u8_counter_buttton_press++;
		 	}

		 if(WasButtonPressed(BUTTON1))
		 	{
		 	 u8_input_button[u8_counter_buttton_press]=1;
			 ButtonAcknowledge(BUTTON1);
			 u8_counter_buttton_press++;
		 	}
		 if(WasButtonPressed(BUTTON2))
		 	{
		 	u8_input_button[u8_counter_buttton_press]=2;
			ButtonAcknowledge(BUTTON2);
			u8_counter_buttton_press++;
		 	}
		 if(WasButtonPressed(BUTTON3))
		 	{
		 	  u8_input_button[u8_counter_buttton_press]=3;
			  	ButtonAcknowledge(BUTTON3);
			  u8_counter_buttton_press++;
		 	}
	 	}
	 if(u8_counter_buttton_press==4)//stop input password
	 	LedOn(RED);
	// for(u8_temp_number=0;u8_temp_number<=3;u8_temp_number++)
	 	//{
	 	do{
	 	  if(u8_password[u8_temp_number]==u8_input_button[u8_temp_number])
		  	{u8_temp_number++;
		     B_Pass_No[0]= TRUE;
	 	  	}
		  else
		  	{
		  	  B_Pass_No[0]=FALSE;
			  break;
		  	}
		  	
	      } 	
		 while(u8_temp_number<=3);//}
   if(B_Pass_No[0]==TRUE)
   	{
   	    if(G_u32SystemTime1ms%1000==0)
			LedToggle(BLUE);
		u8_counter_buttton_press=0;// start new input 
   	}
	 
}
//
void Eie_classmate_work()
{

   static  u32 u32counter=0;
        u32 u32randvalue;
        u8  u8value=0;
        u8  u8counter=0;
         u32counter++;
         if(u32counter<500){
            return; 
         }
         u32counter=0;
         u32randvalue=rand();
         u8value=0;
         for(u8counter=0;u8counter<4;u8counter++){
           
             u8value+=(u32randvalue&0x000000ff);
             u32randvalue>>=8;
           
         }
         u8value&=0x0f;
         if(u8value>7){
            u8value-=8; 
         }
         for(u8counter=0;u8counter<8;u8counter++)
         {
           LedOff(u8counter);
          }
   
}
void button_pressed(void)
{ 
  static bool B_ispressed[3] = FALSE;
 if(  IsButtonPressed(BUTTON0)==TRUE)
 	{
 	  if(B_ispressed[0]==FALSE)
 	  	{
 	  	   LedOn(RED);
 	  	  B_ispressed[0] =TRUE;
 	  	}
	  else
	  	{
	  	B_ispressed[0]=FALSE;
		LedOff(RED);
	  	}
	  
 	   //LedOn(RED);
 	}

 if(WasButtonPressed(BUTTON1))
 	{
 	    if(B_ispressed[1]==FALSE)
 	    	{
 	    	B_ispressed[1]= TRUE;
			LedOn(BLUE);
 	    	}
		else
			{
			B_ispressed[1]=FALSE;
			LedOff(BLUE);
			}
		ButtonAcknowledge(BUTTON1);
 	}
    
}
//pwm toggle test
void Led_API_test(void)
	{bool B_button_pressed[4]= FALSE;
	
     if(WasButtonPressed(BUTTON0))
     	{
     	  if(B_button_pressed[0]==FALSE)
		  	B_button_pressed[0]= TRUE;
		  else
		  	B_button_pressed[0] = FALSE;
     	 ButtonAcknowledge(BUTTON0);
     	}
	 if(WasButtonPressed(BUTTON1))
	 	{
	 	if(B_button_pressed[1]==FALSE)
			B_button_pressed[1]=TRUE;
		else
			B_button_pressed[1]=FALSE;
	 	 ButtonAcknowledge(BUTTON1);
		 
	 	}
	 if(B_button_pressed[0]==TRUE)
	 	{
	 	if(G_u32SystemTime1ms%1000==0)
	 	LedToggle(RED);
	 	}
	 if(B_button_pressed[1]==TRUE)
	 	{
	 	//LedPWM(LedNumberType eLED_,LedRateType ePwmRate_)
	 	}
	}

/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/
//test 2017-5-6
void BCD_code_display(void)
{
  static u16 u16_counter = 0;//this varible for counter the 1S
  static u8 a_u8_binary[8] =0;//to determine what light on
  u8 u8_temp_counter =0;//for tempoary save 
  static u8 u8_temp_counter_on=0;//for change the the decema 
  if(G_u32SystemTime1ms%1000==0)
  {
     u16_counter++;
	 if(u16_counter>=99)
	 	u16_counter=0;
  }
  ///decade 
  u8_temp_counter_on=u16_counter/10;
  for(u8_temp_counter=4;u8_temp_counter<=7;u8_temp_counter++)
  	{
     a_u8_binary[u8_temp_counter] = u8_temp_counter_on%2;
	 u8_temp_counter_on=u8_temp_counter_on/2;
  	}
  ///signal 
  u8_temp_counter_on=u16_counter%10;
  	for(u8_temp_counter=0;u8_temp_counter<=3;u8_temp_counter++)
  		{a_u8_binary[u8_temp_counter]=u8_temp_counter_on%2;
	     u8_temp_counter_on=u8_temp_counter_on/2;
  		}
	for(u8_temp_counter=0;u8_temp_counter<=7;u8_temp_counter++)
		{
		 if(a_u8_binary[u8_temp_counter]==1)
		 	LedOn(u8_temp_counter);
		 else
		 	LedOff(u8_temp_counter);
		}

	
  
}

/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

//
void double_led(void)
{
  u8 u8_counter = 0;
  if(G_u32SystemTime1ms%500==0)
    for(u8_counter=0;u8_counter<=4;u8_counter++)
    {
      LedOn(u8_counter+2);
    }
  if(G_u32SystemTime1ms%2000==0)
  {
     for(u8_counter=0;u8_counter<=7;u8_counter++)
       LedOff(u8_counter);
  }
  if(G_u32SystemTime1ms%10000==0)
      UserApp1_StateMachine = all_led;
    
    
}

//all led light.
void all_led(void)
{u8 u8_counter=0;
    if(G_u32SystemTime1ms%1000==0)
    {
     for(u8_counter=0;u8_counter<=7;u8_counter++)
     {
       LedOn(u8_counter);
      //LedOn(RED);
     }
    }
    if(G_u32SystemTime1ms%2000==0)
    {
      for(u8_counter=0;u8_counter<=7;u8_counter++)
      {
        LedOff(u8_counter);
      }
    }
    if(G_u32SystemTime1ms%10000==0)//10
      UserApp1_StateMachine = double_led;
   
    
      
}
///
/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp1SM_Idle(void)
{
static u8 u8_pwm_red = 0;
 if(G_u32SystemTime1ms%1000==0)//blink purple
 	{
 	LedToggle(PURPLE);
	u8_pwm_red++;
	if(u8_pwm_red>=20)
		u8_pwm_red=0;

	LedPWM(RED,u8_pwm_red);
 	}
 
 
} /* end UserApp1SM_Idle() */
    
#if 0
/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* State to sit in if init failed */
static void UserApp1SM_FailedInit(void)          
{
    
} /* end UserApp1SM_FailedInit() */


/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
