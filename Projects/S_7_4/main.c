/*----------------------------------------------------------------------*/
/*	Polygon and texture mapping				*/
/*----------------------------------------------------------------------*/
#include "SGL.H"

#define	max_texture	2 // Indicates the number of texture registrations, we are registering Sonic and AM2 logo textures in this example

extern PDATA PD_PLANE;
extern TEXTURE tex_sample[]; // Contains the texture table for SGL (pointer than can  be used later)
extern PICTURE pic_sample[]; // Contains the texture table for being loaded into VDP1 VRAM

/*
 * This routine stores the texture data into VDP1 VRAM
 * slDMACopy receives
 * - src: Starting addresss of source memory area
 * - dst: Starting address of destination memory area
 * - cnt: Block transfer amount (bytes)
 * 
 * pcptr is a pointer to our PICTURE defined in texture.c containing the texture data along with the texture number (texno), Color mode (cmode), Pointer to the texture data (ptrsrc) defined by "TEXDAT"
 * NbPicture the number of Pictures to load into VDP1 VRAM (starting in SpriteVRAM=0x25c00000)
*/
void set_texture(PICTURE *pcptr, Uint32 NbPicture) {
    TEXTURE *txptr;
    for(; NbPicture-->0; pcptr++) {
        txptr = tex_sample + pcptr->texno;
        slDMACopy((void*)pcptr->pcsrc,
        (void*)(SpriteVRAM+((txptr-> CGadr) << 3)),
        (Uint32)((txptr->Hsize * txptr->Vsize * 4) >> (pcptr->cmode)));
    }
}

/**
 * Auxiliar routine for displaying the plane and making the code more readable in the main loop
*/
void display_plane(FIXED pos[XYZ], ANGLE ang[XYZ]) {
    slPushMatrix(); {
        slTranslate(pos[X], pos[Y], pos[Z]);
        slRotX(ang[X]);
        slRotY(ang[Y]);
        slRotZ(ang[Z]);
        slPutPolygon(&PD_PLANE);
    }
    slPopMatrix();
}

/* Main videogame routine */
int main() {
    static ANGLE ang[XYZ];
    static FIXED pos[XYZ];

    /* System initialization, now the second parameter contains the memory address where the texture data is stored */
    slInitSystem(TV_320x224, tex_sample, 1);
    /* Load into VRAM the texture data and how many of the textures included in the pic_sample */
    set_texture(pic_sample, max_texture);
    slPrint("Sample program 7.4" , slLocate(9,2));

    /* Initialization of the position of the plane */
	ang[X] = ang[Y] = ang[Z] = DEGtoANG(0.0);
	pos[X] = toFIXED(0.0);
	pos[Y] = toFIXED(0.0);
	pos[Z] = toFIXED(170.0);

    /* Main game loop which displays the plane and make it rotate over its Y axis*/
    while(-1) {
        slPushMatrix(); {
            display_plane(pos, ang);
            ang[Y] += DEGtoANG(2.0);
        }
        slPopMatrix();
        slSynch();
    }

}