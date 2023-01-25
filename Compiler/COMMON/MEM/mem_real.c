/*-----------------------------------------------------------------------------
 *  FILE: mem_real.c
 *
 *      Copyright(c) 1994 SEGA.
 *
 *  PURPOSE:
 *
 *      ���������C�u�����\�[�X�t�@�C���B
 *
 *  DESCRIPTION:
 *
 *      �������Ǘ�����������B
 *
 *  INTERFACE:
 *
 *      < FUNCTIONS LIST >
 *          <5> MEM_Realloc()   -   �������Ċ���t��
 *
 *  CAVEATS:
 *
 *      �Ȃ��B
 *
 *  AUTHOR(S)
 *
 *      1994-07-06  N.T Ver.1.00
 *
 *  MOD HISTORY:
 *
 *      1995-12-04  H.O Ver.1.01
 *
 *-----------------------------------------------------------------------------
 */

/*
 * C VIRTUAL TYPES DEFINITIONS
 */
#include <stdio.h>
#include "sega_xpt.h"

/*
 * USER SUPPLIED INCLUDE FILES
 */
#define	__MEM_LIB_SOURCE__
#include "sega_mem.h"

/*
 * GLOBAL DECLARATIONS
 */

/*
 * LOCAL DEFINES/MACROS
 */

/*
 * TYPEDEFS
 */

/*
 * STATIC DECLARATIONS
 */

/*
 * STATIC FUNCTION PROTOTYPE DECLARATIONS
 */

/******************************************************************************
 *
 * NAME:    MEM_Realloc()           - �������Ċ���t��
 *
 * PARAMETERS :
 *      (1) void *mem_prt           - <i>  �ȑO�̃������u���b�N�ւ̃|�C���^
 *      (2) Uint32 mem_size         - <i>  �V�����������u���b�N�T�C�Y�i�o�C�g�w��j
 *
 * DESCRIPTION:
 *      ���������Ċ���t�����܂��B
 *
 * PRECONDITIONS:
 *      �Ȃ��B
 *
 * POSTCONDITIONS:
 *      �Ȃ�
 *
 * CAVEATS:
 *      �Ȃ��B
 *
 ******************************************************************************
 */

void *MEM_Realloc(void *mem_ptr, Uint32 mem_size){
    Uint32 i;
    Uint8 *work;
    if((work = (Uint8 *)MEM_Malloc(mem_size)) == NULL)
        return(NULL);
    for(i = 0; i < mem_size; i++){
		*(work + i) = *((Uint8 *)mem_ptr + i);
    };
    MEM_Free(mem_ptr);
    return(work);
}
