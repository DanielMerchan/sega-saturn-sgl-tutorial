# Example S_7_4
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 7: Polygon Face Attributes_

_Example: S_7_4 Polygon and Texture_

## Learning  

This chapter explains the attributes which are used to describe a polygon / plane, apply texture mapping and other important settings.

The specification of the polygons used in the samples are in the `polygon.c` source file.

**Note:** In this example we will play with the `texture` attribute (which is the third one in a polyfon / plane definition)

This particular example contains an extra source file, `texture.c`, which contains:

Explaining how the example works.
- The `texture.c` defines the texture data as following:
    - `TEXDAT sonic_64x64[]`: It is the texture data of our loved Sonic :)
    - `TEXDAT am_64x32[]`: Contains a texture data of the AM2 logo
    - `TEXTURE tex_sample[]:` Texture table to be passed to SGL. This macro sets the size (horizontal x vertical) of the texture and the offset from the start address to the actual texture data for each texture
    - `PICTURE pic_sample[]:` Describes the VDP1 VRAM transfer table where the parameters indicates
        - `texno`: Texture number assigned to this texture. This can be used in `polygon.c` to determine which texture to use. The macros `PN_SONIC` initiated to 0, and `PN_AM2` initiated to 1 corresponds with these `texno`.
        - `cmode`: Color mode
        - `pcsrc`: Pointer to the texture data
- In the polygon definitions file `polygon.c` you can find:
    - `PN_SONIC` and `PN_AM2` macro values. These values are not random, they map with the configuration made in `texture.c` (texno) of the `PICTURE` definition
    - `attribute_PLANE[]` attributes to consider 
        - `texture` now contains `PN_SONIC` or `PN_AM2` (you can switch it), instead of `No_Polygon`
        - `color` now uses `No_Palet` as we are mapping a texture instead of colouring manually
        - `mode` includes CL32KRGB|MESHoff (32k RGB colors mode and Normal display)
        - `dir` sprNoFlip to map as it is defined the texture into the plane of the polygon
- In the main program `main.c` there are some new things too:
    - `slInitSystem` usually was used with `NULL` as second parameter, however this time we are sending the `tex_sample[]` pointer which indicates the starting address of memory area where texture data is stored
    - `set_texture` is a routine which helps to load into VDP1 VRAM (starting in SpriteVRAM=0x25c00000) the texture data.
        - Input Parameters:
            - `PICTURE *pcptr` which is just a pointer to the `PICTURE` macro we defined in `texture.c`
            - `Uint32 NbPicture` number of pictures to iterate which are part of the `PICTURE *pcptr`. In the example we send the macro `max_textures 2` as we only have 2 textures defined
        - Code explanation:
            - The loop can be exotic (loop syntax of C), but only says. NbPicture-- (decrease until 0) and iterate to the next `PICDEF` pointer with `pcptr++`
            - The texture pointer `TEXDEF` in SGL can be calculate as `txptr = tex_sample + pcptr->texno;` which is basically accessing to the `texno` index (array) of `tex_sample`
            - `slDMACopy` Used to transfer blocks using the CPU's DMA function
                - `src`: Starting address of source memory area. In this case `pcptr->pcsrc`
                - `dst`: Starting address of the destination memory area. In this case `(void*)(SpriteVRAM+((txptr-> CGadr) << 3))` which is the starting of the VDP1 VRAM address + `(txptr-> CGadr) << 3)` which is shifted 3 bits
                - `cnt`: Indicates the block transfer amount. This is calculated using the current `TEXDEF` of `tex_sample` for this iteration (which corresponds to the current texture data)
                