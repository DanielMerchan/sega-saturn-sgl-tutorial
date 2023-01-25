/****
    SGL Baseline environment as extracted from XL2's Sonic Z-Treme
****/

//  Include
#include    "sgl.h"


//  Functions
int main(void)
{
    /*
        Main Program
        
        Game starts here
    */
    
    //  Initialize Systems 
    slInitSystem(TV_320x224, NULL, 1);
    
    //  Start Main Game Loop
	while(1)
	{
	    //  Hello World
        slPrint("Hello World", slLocate(0,0));
	}
    
    //  End Program
	return 0;
}
