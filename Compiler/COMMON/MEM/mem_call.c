/*-----------------------------------------------------------------------------
 *  FILE: mem_call.c
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
 *          <2> MEM_Calloc()    -   �z��̈�m��
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
 * NAME:    MEM_Calloc()            - �z��̈�m��
 *
 * PARAMETERS :
 *      (1) Uint32 arg_num          - <i>  �z��v�f��
 *      (2) Uint32 arg_size         - <i>  �z��v�f���̃o�C�g��
 *
 * DESCRIPTION:
 *      �z��̈���m�ۂ��܂��D
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

void *MEM_Calloc(Uint32 arg_num, Uint32 arg_size){
	Uint32	memsize = arg_num * arg_size;		/* �g�[�^���̑傫�� */
	unsigned char	*ptr;
	if ( ( ptr = (unsigned char *)MEM_Malloc(memsize) ) == NULL )
		return	NULL;							/* �Ȃ������ꍇ */
	else{
		Uint32	cnt;
		for(cnt = 0 ; cnt < memsize ;  cnt++ )
			*(ptr + cnt) = 0;					/* �o�C�g�P�ʂŃN���A */
		return	ptr;
	}
}
