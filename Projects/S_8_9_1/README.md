
# Example S_8_9_1 – Graphic Rotation (RBG0)

## Documentation Reference

_SGL Developer’s Manual Tutorial.pdf_
_Chapter 8: Scroll_
_Example: S_8_9_1 – Graphic Rotation_
  
## Learning
This chapter introduces **Rotational Backgrounds (RBG0)** - one of the most powerful features of the Sega Saturn’s VDP2 graphics hardware.
Earlier examples (`S_8_8_3`) focused on standard background scrolling (NBG0, NBG1), which supports:
- horizontal/vertical scrolling
- basic zoom (enlarge/reduce)
- tile-based backgrounds

However, **RBG0** supports **full 2D affine transformations**, including:
- rotation
- scaling and zooming
- skew and distortion
- Mode 7–style effects (but more powerful)

VDP2 performs these transformations entirely in hardware, making them extremely fast and ideal for:
- racing floor effects
- spinning world maps
- rotating sky/floor planes
- special background effects

This example shows how to set up the RBG0 plane, load required scroll data into VRAM, and apply a continuous rotation around the Z-axis.

## Core Concepts

### VDP2 Background Types

| Background | Type | Features |
--------------- | ---------------------- | ----------------------------------- |
 | **NBG0 / NBG1** | Normal Background | Scroll, zoom, tilemap |
| NBG2 / NBG3 | Additional backgrounds | Depending on display mode |
| **RBG0** | Rotational Background | Rotation, scaling, affine transform |
| RBG1 | Optional (rare) | Duplicated RBG0 on some modes |

### Scroll Structure (Recap)
- A **Cell** is a basic 8×8-pixel block.
- Multiple cells make up a **Character Pattern**.
- A set of character patterns forms a **Page**.
- Pages arranged in memory form a **Map**.

Both NBG and RBG modes use these concepts.

### Step by Step Breakdown
1. **Disable display while setting up VRAM**
```c

slTVOff();

```
2. **Color RAM configuration**
```c

slColRAMMode(CRM16_1024);

slBack1ColSet((void*)RBG0_COL_ADR, CD_Black);

```
3. **Initialise RBG0 Parameter table**

```c

slRparaInitSet((void*)RBG0_PAR_ADR);

```
The parameter table holds the affine matrix that controls:
- rotation
- scaling
- skew
- perspective center

This table updates every frame

4. **Configure RBG0 tiles, pages and map**
```c
slCharRbg0(COL_TYPE_256, CHAR_SIZE_1x1);
slPageRbg0((void*)RBG0_CEL_ADR, 0, PNB_1WORD | CN_10BIT);
slPlaneRA(PL_SIZE_1x1);
slMapRA((void*)RBG0_MAP_ADR);
slOverRA(2);
```
Meaning:
- Use **256-color tiles**
- 1x1 tile size
- Character patterns stored in **A0 VRAM** bank addresses
- Map stored in **B0 VRAM** bank addresses
- Plane size = 1x1
- Priority = 2  (in front of some layers, behind others)

5. **Load VRAM Data**
Using helper functions (not native SGL):
```c
Cel2VRAM()
Map2VRAM()
Pal2CRAM()
```
These load graphics, map layout, and palette into VDP2 memory.

6. **Set rotation parameters**
```c
slDispCenterR(toFIXED(160.0), toFIXED(112.0));
slLookR(toFIXED(128.0), toFIXED(112.0));
```
- `slDispCenterR`: the pixel point around which rotation occurs
- `slLookR`: The "camera look point" of the affine transformation

7. **Enable scroll display**
```c
slScrAutoDisp(NBG0ON | RBG0ON);
```
Displays:
- NBG0 (usually debug text)
- RBG0 (the rotation planes)

8. **Rotation loop**
```c
slZrotR(yama_angz);
yama_angz += DEGtoANG(1.0);
```
Applies of rotation of **1° per frame** around the Z-axis
Because VDP2 handles affine matrix, rotation is smooth and costs almost nothing
## Function Reference Table

### System
| Function|Description|
|--|--|
| `slInitSystem` | Initialises SGL, scroll, and display system  |
| `slTVOff` | Disable video output during setup  |
| `slTVOn` | Re-enable video output  |
| `slSynch` |Sync to VBlank  |
| `slPrint` | Print debug text  |

### Color/Background Configuration
| Function|Description|
|--|--|
| `slColRAMMode` | Set CRAM color mode  |
| `slBack1ColSet` | Set background color  |

### RBG0 Configuration
| Function|Description|
|--|--|
| `slRparaInitSet` | Initialize RBG0 parameter table |
| `slCharRbg0` | Set tile (character) format  |
| `slPageRbg0` | Set VRAM for tile patterns  |
| `slPlaneRA` | Set RBG0 plane size  |
| `sl1MapRA` | Set tile map location |
| slOverRA | Set layer priority  |

### VRAM Transfer Helpers (External)
| Function|Description|
|--|--|
| `Cel2VRAM` | Copy character patterns to VRAM |
| `Map2VRAM` | Copy tile map to VRAM  |
| `Pal2CRAM` | Copy palette to CRAM  |

### Rotation & Camera
| Function|Description|
|--|--|
| `slDispCenterR` | Set rotation center |
| `slLookR` | Set affine "look-at" point  |
| `slZrotR` | Rotate RBG0 around Z-axis  |

### Display Enable
| Function|Description|
|--|--|
| `slScrAutoDisp` | Enable selected background layers |

## Conclusion
Example S_8_9_1 demonstrates how to initialize and manipulate a **Rotational Background (RBG0)**.  
This enables true hardware-accelerated affine transforms, allowing effects otherwise expensive to compute.
Use RBG0 when you need:
-   Mode 7–style floors
-   Rotating backgrounds
-   Scalable world maps    
-   Perspective effects    

This example provides the base for building those features in your own Saturn projects using raw `SGL library`
