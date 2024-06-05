# Example S_8_8_2
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 8: Scroll_

_Example: S_8_8_2 Graphic Scroll (X axis)_

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

Example is similar to *S_8_8_1*, but we are also adding Y axis scrolling in this example. Things to consider in this particular example (read *S_8_8_1* readme for the other code about scrolling initialisation, background and load of the maps)
- `scroll_flg` can be intiialize to **YOKO** (X-Axis, Horizontal) or **TATE** (Y-Axis, Vertical). This is legacy names from japanese examples :)
- `yama_posx` gets increased by 2 in the X-Axis every iteration until it reachs to be rotated by two times (`(SX*2 + SIPOSX)`)
- `scroll_flg` is switched between **YOKO** and **TATE** every 2 iteration in X-Axis and Y-Axis respectively.
- Do no get lost with the macro definition names. They look weird names.

