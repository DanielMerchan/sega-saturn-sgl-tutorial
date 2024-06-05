/*----------------------------------------------------------------------*/
/*	Horizontal Scroll Moving (X-Axis)									*/
/*----------------------------------------------------------------------*/
#include	"sgl.h"
#include	"ss_scrol.h"

// Refer to Scroll Data Storage Area in the documentation
// VRAM-A0 (0x25e00000), VRAM-A1 (0x25e20000), VRAM-B0(0x25e40000), VRAM-B1(0x25e60000)
// Color RAM, CRAM (0x25f00000)

#define	NBG1_CEL_ADR	( VDP2_VRAM_B1 + 0x02000 ) // Starting memory address for cells, remember the beginning for CEL is reserve until 0x25e61FFF
#define	NBG1_MAP_ADR	( VDP2_VRAM_B1 + 0x12000 ) // Starting memory address for the maps, remember the beginning for MAP is reserve until 0x25e76FFF
#define	NBG1_COL_ADR	( VDP2_COLRAM + 0x00200 ) // Starting memory address for the color RAM, remeber the beginning for CRAM is reserver until 0x25f0001F
#define	BACK_COL_ADR	( VDP2_VRAM_A1 + 0x1fffe ) // Background color address will be situated in A1 bank area. 

// Note that Sega Saturn has 4 banks of VRAM memory of 1 megabit each one (A0, A1, B1, B2)
/*
	The documentation has restrictions on how to store scroll data in those banks. 
		- Do not mix rotating and normal scroll data in the same VRAM bank
		- Store scroll data together choosing between (A0, B0) or (A1, B1), but do not mix or priority of screens will be affected.
*/

int main(void) {

	FIXED yama_posx = SIPOSX , yama_posy = SIPOSY;
	Uint16 scroll_flg = YOKO;

	/** Initializes the system 
	 * 1 - Initialization of the scroll settings
	 * 2 - Resolution to 320x224
	 * 3 - NULL as we are not using textures in this example
	 * 4 - Drawing processing unit to 1 (smooth interval)
	*/
	slInitSystem(TV_320x224,NULL,1);

	slTVOff(); // Stop the drawing after intializing the system
	slPrint("Sample program 8.8.2" , slLocate(9,2));

	slColRAMMode(CRM16_1024); // Set the Color RAM mode to mode 0 (16 bit and 1024 color)
	slBack1ColSet((void *)BACK_COL_ADR , CD_Black); // Set the background of the screen to color black and store it in VDP2 VRAM A1 bank

	// Setup of the scroll settings (Cells, Page, Planes and Map). In this case NBG1, please refer to Scroll Function Settings in the documentation
	slCharNbg1(COL_TYPE_256 , CHAR_SIZE_1x1); // Setup character pattern
	slPageNbg1((void *)NBG1_CEL_ADR , 0 , PNB_1WORD|CN_12BIT); // Setup pages
	slPlaneNbg1(PL_SIZE_1x1); // Setup up planes
	slMapNbg1((void *)NBG1_MAP_ADR , (void *)NBG1_MAP_ADR , (void *)NBG1_MAP_ADR , (void *)NBG1_MAP_ADR); // Setup maps

	// Scroll data storage
	// NOTE: This are auxuliar methods to store data in the VRAM banks THEY ARE NOT SGL FUNCTIONS
	Cel2VRAM(yama_cel , (void *)NBG1_CEL_ADR , 31808); // Storing the Cell information in VRAM (VDP2)
	Map2VRAM(yama_map , (void *)NBG1_MAP_ADR , 32 , 16 , 1 , 256); // Storing the Map information in VRAM (VDP2)
	Pal2CRAM(yama_pal , (void *)NBG1_COL_ADR , 256); // Storing Palette information in VRAM (VDP2)

	// Register the scroll screen
	slScrPosNbg1(yama_posx , yama_posy); // Position the Scroll NBG1 (Normal)
	slScrAutoDisp(NBG0ON | NBG1ON); // Registration of the Scrolls NBG0 and NBG1

	slTVOn(); // Start drawing again

	while(1) {
		if (scroll_flg == YOKO) { // Checks if scroll_flg is horizontal
			if (yama_posx >= (SX*2 + SIPOSX)) { // If we hit twice times scrolled the X-Axis 
				scroll_flg = TATE; // Set scroll_flg to vertical
				yama_posx = SIPOSX; // Reset the posx
			} else {
				yama_posx += POSX_UP; // If not, increase the X-Axis position
			}
		} else if (scroll_flg == TATE) { // Checks if scroll_flg is set to vertical
			if (yama_posy >= (SY * 2 + SIPOSY)) { // If we scrolled alrady twice in vertical axis
				scroll_flg = YOKO; // Set back to X-Axis
				yama_posy = SIPOSY; // Reset Y-Axis Position
			} else {
				yama_posy += POSY_UP; // If not, increase the Y-Axis
			}
		} 
		slScrPosNbg1(yama_posx , yama_posy); 
		
		slSynch();
	} 
}