/*-----------------------------------------------------------------------------
 *  FILE: mem_mall.c
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
 *          <4> MEM_Malloc()    -   �������u���b�N�m��
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
 * NAME:    MEM_Malloc()            - �������u���b�N�m��
 *
 * PARAMETERS :
 *      (1) Uint32 mem_size         - <i>  �v���������u���b�N�T�C�Y(�o�C�g�P��)
 *
 * DESCRIPTION:
 *      �v�����������m�ۂ��܂��D
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

void *MEM_Malloc(Uint32 mem_size)
{
	Uint32	req_size = ( ( mem_size + sizeof( MemHead ) -1 )/(sizeof( MemHead )) +1);
	/* ���蓖�ĂɕK�v�ȃT�C�Y�B�Ō��+1�̓w�b�_�̕� */
	MemHead	*current,*prev,*last;
	if( ( prev = MEM_empty_top ) == NULL )			/* ���X�g�̂Ƃ������� */
		return NULL;								/* �c�薳���̏ꍇ */
	else{
		last = prev;									/* ���X�g�̂����܂� */
		for( current = prev->s.next ;; prev = current, current = prev->s.next ){
			if( current->s.size >= req_size ){			/* �傫���̊m�F */
				if( current->s.size == req_size ){		/* �҂�����̏ꍇ */
					/*	prev->s.next = current->s.next;		 �O�̗̈�Ɍ��̗̈���q�� */
					if( prev == current )				/* �Ō��1�̏ꍇ */
						prev = NULL;					/* �c�薳�� */
					else								/* �܂��c���Ă���ꍇ */
						prev->s.next = current->s.next;	/* �O���A�����Đ؂藣�� */
				}
				else{									/* �]�T������ꍇ */
					current->s.size -= req_size;		/* �̈�̑傫���𒲐� */
					current += current->s.size;			/* �|�C���^�����炷 */
					current->s.size = req_size;			/* �V�̈�̑傫����ݒ� */
				}
				current->s.next = NULL;					/* �����Ă��� */
				MEM_empty_top = prev;					/* ���X�g�̂Ƃ������� */
				return	(void *)( current +1 );			/* �|�C���^��Ԃ� */
			}
			if( current == last )						/* �S���]�������� */
				return	NULL;							/* �Y������ */
		}
	}
}
