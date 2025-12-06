/*----------------------------------------------------------------------*/
/*	Graphic Rotation (RBG0 - Rotational Background)                    */
/*----------------------------------------------------------------------*/

#include "sgl.h"
#include "ss_scrol.h"

/* VRAM and CRAM addresses for RBG0 data */
#define RBG0_CEL_ADR VDP2_VRAM_A0               // Character patterns for RBG0
#define RBG0_MAP_ADR VDP2_VRAM_B0               // Map (tile layout)
#define RBG0_COL_ADR (VDP2_COLRAM + 0x00200)    // Color RAM (palette)
#define RBG0_PAR_ADR (VDP2_VRAM_A1 + 0x1fe00)   // Parameter RAM (affine transforms)
#define BACK_COL_ADR (VDP2_VRAM_A1 + 0x1fffe)   // Background color storage

int main(void) {
    ANGLE yama_angz = DEGtoANG(0.0);             // Rotation angle for RBG0
    FIXED posx = toFIXED(128.0), posy = toFIXED(64.0);

    /* Initialize system */
    slInitSystem(TV_320x224, NULL, 1);
    slTVOff();                                   // Stop rendering during setup
    slPrint("Sample program 8.9.1:", slLocate(9,2));

    /* Setup color mode and background color */
    slColRAMMode(CRM16_1024);                    // 16-bit, 1024-color mode
    slBack1ColSet((void*)BACK_COL_ADR, CD_Black);       // Background set to color 0

    /* Initialize rotational parameter table (essential for RBG mode) */
    slRparaInitSet((void*) RBG0_PAR_ADR);

    /* RBG0 layer setup: characters, map, planes */
    slCharRbg0(COL_TYPE_256, CHAR_SIZE_1x1);     // Set charset for RBG0
    slPageRbg0((void *)RBG0_CEL_ADR ,0 ,PNB_1WORD|CN_10BIT);     // Load cell patterns
    slPlaneRA(PL_SIZE_1x1);                      // Plane size = 1x1
    sl1MapRA((void*) RBG0_MAP_ADR);                // Set the tile map location
    slOverRA(2);                                 // Priority level

    /* Load image data into VRAM/CRAM */
    Cel2VRAM(yama_cel, (void*)RBG0_CEL_ADR, 31808);
    Map2VRAM(yama_map, (void*)RBG0_MAP_ADR, 32, 16, 1, 0);
    Pal2CRAM(yama_pal, (void*)RBG0_COL_ADR, 256);

    /* Setup rotational center and camera parameters */
    slDispCenterR(toFIXED(160.0), toFIXED(112.0)); // Center of rotation on screen
    slLookR(toFIXED(128.0), toFIXED(112.0));       // Look-at position for affine matrix

    /* Enable RBG0 and NBG0 */
    slScrAutoDisp(NBG0ON | RBG0ON);
    slTVOn();

    while (1) {
        slZrotR(yama_angz);                        // Apply rotation around Z-axis
        yama_angz += DEGtoANG(1.0);                // Increase rotation angle
        slSynch();                                 // Wait next frame
    }
}