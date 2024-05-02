# Example S_7_6
 
## Documentation reference

_SGL Developer's Manual Tutorial.pdf_

_Chapter 7: Polygon Face Attributes_

_Example: S_7_6 Gouraud Shading_

## Learning  

This chapter explains the attributes which are used to describe a polygon / plane, apply texture mapping and other important settings.

The specification of the polygons used in the samples are in the `polygon.c` source file.

**Note:** In this example we will play with the `gouraud` attribute (which is the fifth one in a polyfon / plane definition).
The Gouraud Shading is a technique opposed to flat shading. Gouraud shading is a technique used to interpolate vertex colors across the faces of polygons. The Gouraud shading process involves calculating vertex colors and then interpolating those colors across the pixels of each face using the calculated values at the vertices.

Explaining how the example works.

In the source file `main.c` we can find the following:

- `VRAMaddr` is a macro which is default to 0x25c7000. This memory address is close to the end of VDP1 VRAM and where Goraud tables are stored. SpriteVRAM defines the beginning address (Check Developer's Manual Reference, VDP1 VRAM Memory Map).

- `GRoffsetTBL(r,g,b) (((b & 0x1f) << 10) | ((g & 0x1f) << 5) | (r & 0x1f))` is a macro helping to produce color information in RGB.
    - `r`, `g`, `b` represents red, green and blue
    - The macro performs *bitwise* operations to pack the color into an Uint16
    - Each color is masked with `0x1f` to ensure it fits withing 5 bits (since 0x1f = 11111), accomodating the color intensity
    - These values are shifted to their position `<<`
    - The values are concatenated using **bitwise OR** `|` to form the final color value 
    - Example: `GRoffsetTBL(0,-16,-16)`
        - `Masking and Shifting for Blue (b)`: b & 0x1f masks the value of b to fit within 5 bits (since 0x1f is binary 11111). In this case, -16 & 0x1f evaluates to 0x10.
        0x10 (binary 00010000) is shifted left by 10 bits: (0x10 << 10) becomes 0x10000.

        - `Masking and Shifting for Green (g)`: g & 0x1f masks the value of g to fit within 5 bits. In this case, -16 & 0x1f also evaluates to 0x10. 0x10 (binary 00010000) is shifted left by 5 bits: (0x10 << 5) becomes 0x800.

        - `Masking for Red (r)`: r & 0x1f masks the value of r to fit within 5 bits. Since r = 0, r & 0x1f evaluates to 0x00.

        - `Combining the Results`: The shifted and masked values for blue and green are combined using bitwise OR (|): 0x10000 | 0x800 gives 0x10800. The result is combined with the masked value for red (0x00) using another bitwise OR operation: 0x10800 | 0x00 remains 0x10800.
        
        - `GRoffsetTBL(0, -16, -16)` therefore is translated to 0x10800 in hexadecimal. This value represents the color information for a vertex, where the red, green, and blue components are 0, -16, and -16, respectively, packed into a single Uint16 value.

- `GRdata` contains the Gouraud table configuration. 6 tables and 4 color definition for each vertex. The color definition uses the macro explained before `GRoffsetTBL(r,g,b)`

- `slDMACopy` load the Goraud table by using CPU DMA into the VDP1 VRAM identified by `VRAMaddr`

In the source file `polygon.c` the following attributes are configured:

- `GRaddr 0xe000` defines the offset memory used to access to the Gouraud tables stored in VDP1 VRAM
- The attributes of the faces of the polygon contains:
    `mode`: MESHoff|**CL_Gouraud**
    `gouraud`: `GRaddr` and incremental to access each colouring defined in `GRdata`

**Note**: I did my best trying to understand and explain the VRAM memory positions. Refresh hexadecimal and memory addresses / bits shifting operations. You can get lost very easy (as I get).
