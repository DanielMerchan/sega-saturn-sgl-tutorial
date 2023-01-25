/*-----------------------------------------------------------------------------
 *  FILE: mem_free.c
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
 *          <3> MEM_Free()      -   �������Ǘ��̈�ݒ�
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
 *      1995-12-06  H.O Ver.1.01
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
 * NAME:    MEM_Free()              - �������u���b�N���
 *
 * PARAMETERS :
 *      (1) void *mem_ptr           - <i>  �������u���b�N�ւ̃|�C���^
 *
 * DESCRIPTION:
 *      �������u���b�N��������܂��D
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

void MEM_Free(void *mem_ptr){
	MemHead	*list;								/* ���X�g�����p */
	MemHead	*free = (MemHead *)mem_ptr -1;		/* �J���������̈� */
	if( ( list = MEM_empty_top ) == NULL ){		/* ���X�g�̎擾 */
		MEM_empty_top = free;					/* �󂫃��X�g�������ꍇ */
		free->s.next = free;					/* �v�f��1�̏z���X�g */
	}
	else{
		while( !( (free > list) && (free < list->s.next) )){
		/* �v�fn�Ɨv�fn+1�̊ԂɊJ���̈悪���݂����Ȃ��Ԃ̓��[�v */
			if(list >= list->s.next)			/* �󃊃X�g�̌q���߂��v�f���P��̏ꍇ */
				if( (free > list)||(free < list->s.next) )	/* �q���ڂɘA������ׂ��� */
					break;							/* �q���ڂɘA������ */
			list = list->s.next;					/* ���̗v�f */
		}
		if( free+free->s.size == list->s.next ){	/* ����̗v�f�ƍ��̂ł���ꍇ */
			free->s.size += list->s.size;			/* �T�C�Y�̕ύX */
			free->s.next = list->s.next->s.next;	/* �q���ւ� */
		}
		else{										/* ���̂ł��Ȃ��ꍇ */
			free->s.next = list->s.next;			/* ��芸�����O�ɘA�� */
		}
		if( list+list->s.size == free ){			/* ���O�̗v�f�ƍ��̂ł���ꍇ */
			list->s.size += free->s.size;			/* �T�C�Y�̕ύX */
			list->s.next = free->s.next;			/* �q���ւ� */
		}
		else{										/* ���̂ł��Ȃ��ꍇ */
			list->s.next = free;					/* �q���ւ� */
		}
		MEM_empty_top = list;						/* �㏈�� */
	}
}
