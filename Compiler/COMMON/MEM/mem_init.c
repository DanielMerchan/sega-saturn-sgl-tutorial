/*-----------------------------------------------------------------------------
 *  FILE: mem_init.c
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
 *          <1> MEM_Init()      -   �������Ǘ��̈�ݒ�
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
 *      1994-11/30  H.O Ver.1.10
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

MemHead *MEM_empty_top = NULL;				/* �󂫃Z���̐擪            */

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
 * NAME:    MEM_Init()              - �������Ǘ��̈�ݒ�
 *
 * PARAMETERS :
 *      (1) Uint32 top_address      - <i>  �������Ǘ��̈�擪�A�h���X
 *      (2) Uint32 mem_size         - <i>  �������Ǘ��̈�T�C�Y
 *
 * DESCRIPTION:
 *      �������Ǘ��̈��ݒ肵�܂�.
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

void MEM_Init(Uint32 top_address, Uint32 mem_size){
	MemHead	*top = (MemHead *)(top_address&(~0x03));	/* �[���͐؂�̂� */
	Uint32	num =  (mem_size-(top_address&0x03))/sizeof( MemHead );	/* �[���͐؂�̂� */
	MEM_empty_top = top;							/* �擪�A�h���X�̋L�^ */
	top->s.next = top;								/* �����N���X�g�̍\�z */
	top->s.size = num;								/* �w�b�_���܂ރT�C�Y */
}
