/*----------------------------------------------------------------------*/
/*	Scroll Enlargement and Reduction									*/
/*----------------------------------------------------------------------*/
#include	"sgl.h"
#include	"ss_scrol.h"

// Refer to Scroll Data Storage Area in the documentation
// VRAM-A0 (0x25e00000), VRAM-A1 (0x25e20000), VRAM-B0(0x25e40000), VRAM-B1(0x25e60000)
// Color RAM, CRAM (0x25f00000)

// Using NBG1 Scroll Mode
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

	FIXED yama_posx = toFIXED(0.0), yama_posy = toFIXED(0.0); // Scroll position respecting X and Y Axis (2D Background)
	FIXED yama_zoom = toFIXED(1.0); // Coordinates for the expansion / reduction ratio for X and Y axis at the same time
	FIXED up_down = toFIXED(-0.1); // Auxiliar variable

	/** Initializes the system 
	 * 1 - Initialization of the scroll settings
	 * 2 - Resolution to 320x224
	 * 3 - NULL as we are not using textures in this example
	 * 4 - Drawing processing unit to 1 (smooth interval)
	*/
	slInitSystem(TV_320x224,NULL,1);

	slTVOff(); // Stop the drawing after intializing the system
	slPrint("Sample program 8.8.3" , slLocate(9,2));

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

	// Reduction settings 
	
	/* When you set a zoom mode using slZoomModeNbg1, 
	it establishes a baseline zoom level for the NBG1 layer. 
	The slZoomNbg1 function can then be used to dynamically adjust the zoom relative to this baseline.
	If you use slZoomModeNbg1 to set the zoom mode to ZOOM_HALF, for instance, and then use slZoomNbg1 to zoom further, 
	your zoom adjustments will be based on the already halved size of the layer.
	*/

	// slZoomModeNbg1(ZOOM_1); // Normal size
	// slZoomModeNbg1(ZOOM_QUARTER); // Scales background to a quarter of its size
	slZoomModeNbg1(ZOOM_HALF); // Scales background to a half of its size

	// Register the scroll screen
	slScrPosNbg1(yama_posx , yama_posy); // Position the Scroll NBG1 (Normal)
	slScrAutoDisp(NBG0ON | NBG1ON); // Registration of the Scrolls NBG0 and NBG1

	slTVOn(); // Start drawing again

	while(1) {

		// Debug
		// slPrint("yama_zoom", slLocate(4,7));
		// slPrintFX(yama_zoom, slLocate(8,7));
		
		// Check if the Scroll reached the limit which is
		if (yama_posx >= SX) { // These FIXED coordinates of the max limits are defined in ss_scrol.h
			if (yama_zoom >= toFIXED(1.5)) {  // When reaching the maximum reduction (> 1.0) we scale back to enlarge the background
				up_down = toFIXED(-0.1);
			} else if (yama_zoom <= toFIXED(0.7)) { // When reaching the maximum enlargement (< 1.0) we scale back to reduce background
				up_down = toFIXED(0.1);
			}
			yama_zoom += up_down; // Apply the accumulative to the zoom enlargement / reduction
			yama_posx = toFIXED(0.0); // Reset the X position
			slZoomNbg1(yama_zoom,yama_zoom); // Apply same Zoom enlargement / reduction fixed point in X-axis and Y-axis
		}
		
		slScrPosNbg1(yama_posx, yama_posy);
		yama_posx += POSX_UP;
		
		slSynch();
	} 
}