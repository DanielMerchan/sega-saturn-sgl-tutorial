# Example S_8_8_1
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 8: Scroll_

_Example: S_8_8_1 Graphic Scroll (X axis)_

## Learning  

This chapter explains how **Scrolling** works in Sega Saturn.

In the context of Sega Saturn development using the Sega Graphics Library (SGL), the term "Scroll" refers to a data structure used to define the properties and behavior of a scrollable plane within the game environment. The Sega Saturn hardware supports complex scrolling techniques for creating 2D backgrounds.

E.g.: You can have 3 layers where:
- Front layer displays text likes scores, and messages
- 3D graphics layer where the main game is being rendered
- Background scroll layer to display some map or backgrounds to make the 3D environment more friendly

The chapter is longer and more complex than the previous ones. I totally recommend you go through the _SGL Developer's Manual Tutorial.pdf_ as it contains a lot of visualization examples, important memory address ranges (VDP2) and macros for setting up the data required.

Here, you are going to find a summary of the learnings, some concepts and briefly explained some concepts.

So, let's go to this example in particular!.
Scroll configuration units can be defined hierarchically as following:
- A 8x8 **group of dots** is called a **cell**.
- A **group of cells** is called a **character pattern**
- A **group of character patterns** is called a **page**
- A **group of pages** is called a **map**

Screen modes. Sega Saturn supports up to **16 screens** modes. We have already configured this unconciously in all the previous steps by invoking the routine `slInitSystem`. But, what does this routine exactly? `slInitSystem(Unit16 type, TEXTURE *textptr, Uint, cnt)
- Initializes the settings for **scrolls**
- Setup the screen mode by using the pre-defined macros **TV_** (default **TV_320_224**)
- Sets the starting memory address for textures. NULL when we do not use textures in the example at all.
- Drawing processing unit defined with an integer between 1-127. This defines the interval of re-writing an image. E.g. 1 means 1/60 seconds in non-interlaced mode and 1/30 in double interlaced mode. The shortest, the smoothest

Example steps:
- Initializes the system by invoking `slInitSystem`
- (Not in the example as we are not using RGB0 rotating screen) Setup the rotating screen using `slRparaInitSet`
- Stop drawing by invoking `slTVOff`
- Set the color mode with `slColRam` rountine. In this case we use `CRM16_1024` (mode 0, 16 bit x 1024 color). This control the color for all palette-type sprites and scroll screens
- Set background screen (single color) invoking `slBack1ColSet`
    - The first parameter indicates where in VRAM Memory to store it. There is a macro defined `BACK_COL_ADR` pointing to the A1 bank of the VRAM VDP2
    - The second parameter is the actual color, there are some macro `CD_[Color]` defines in SGL. But, 0 or CD_BLACK is black
- Setup of the **Character patterns** by invoking `slCharNbg1`. The example uses the NBG1 normal scroll
    - `COL_TYPE_256` refers to 256 colors
    - `CHAR_SIZE_1x1` refers to the character size
- Setup of the **Pages** by invoking `slPageNbg1`:
    - The first parameter `NBG1_CEL_ADR` macro defined is the starting memory address of the character pattern data used on the scroll screen
    - The second parameter `0` indicates the starting address in color RAM of color data used by cells
    - The third parameter indicates the type (pattern name) word size used. In this case is configured to `Low-order 12 bit` `PNB_1WORD|CN_12BIT`. It is very important to have the Developer Guide and Reference for understanding what this means (Fig 8-10 Pattern Name Data Concept).
- Setup of the **Planes** size with the routine `slPlaneNbg1`
    - `PL_SIZE_1x1` indicates 1 horizontal x 1 vertical
- Setup of the normal scroll **Map** with the routine `slMapNbg1` which parameters (starting address in VRAM of the pattern name data table) points to the same memory address in VRAM
- Store of the **Cell** and **Map** in VRAM using some auxiliar routines defined in `scl_func.c`. **Note** that this is not part of SGL, but can be re-used
    - `Cel2VRAM` is a routine that receives the **Cel** data, the starting address memory for **Cel** data and the character size
    - `Map2VRAM` is the routine to store the map information
- Store **Color Palette** in Color RAM using the routine `Pal2CRAM` defined in `scl_func.c` 
- Register the initial position of the Scroll invoking `slScrPosNbg1`
- Register the Scrolls NBG0 and NBG1 by invoking `slScrAutoDisp` OR separated every scroll
- Turn on the drawing again by invoking `slTVOn`
- The main loop will:
    - Position in the screen in the new calculated position by invoking `slScrPosNbg1`
    - Update the X position
    - Synchronize with event processing unit time `slSynch` as previous examples



