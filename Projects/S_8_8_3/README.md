# Example S_8_8_3
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 8: Scroll_

_Example: S_8_8_3 Scroll Enlargement / Reduction_

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

Screen modes. Sega Saturn supports up to **16 screens** modes. We have already configured this unconciously in all the previous steps by invoking the routine `slInitSystem`. But, what does this routine exactly? `slInitSystem(Unit16 type, TEXTURE *textptr, Uint, cnt)`
- Initializes the settings for **scrolls**
- Setup the screen mode by using the pre-defined macros **TV_** (default **TV_320_224**)
- Sets the starting memory address for textures. NULL when we do not use textures in the example at all.
- Drawing processing unit defined with an integer between 1-127. This defines the interval of re-writing an image. E.g. 1 means 1/60 seconds in non-interlaced mode and 1/30 in double interlaced mode. The shortest, the smoothest

Example is similar to *S_8_8_2*, but this time we are going to make Reduction and Enlargement of the background. This is only applicable to normal scrolls `Nbg0` and `Nbg1`.
- `slZoomModeNbg1` is just an auxiliar routine wrapping `slZoomMode` which allows to set the initial / static zoom mode of the scroll
    - `ZOOM_1`: Ratio 1/1x to 256x
    - `ZOOM_HALF`: Ratio 1/2x to 256x
    - `ZOOM_QUARTER`: Ratio 1/4x to 256x
- `slZoomNbg1` is a routine which applies a enlargement / reduction respectively to the X-Axis, Y-Axis. For example, if you wanna have a 2x zoom then you need to set the X and Y fixed points to 1/2.

