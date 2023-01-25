/*---------------------------------------------------------
 * SGL���C�u����CD�֐��p	1995.10.30
 *---------------------------------------------------------*/

/* sgl_cd.h */
#if	!defined(SGL_CD_H)
#define	SGL_CD_H
#include	"sl_def.h"
#include        <sega_stm.h>

/*--- ��ʓI�ȃf�[�^�^ -------------------------------------------------*/
/* �t�@�C���n���h��			*/
typedef	StmGrpHn	CDHN;


/*--- �X�g���[���f�[�^�𕪗ނ��邽�߂̃L�[ -----------------------------*/
typedef struct {
    Sint16	cn;			/* �`���l���ԍ�			*/
    Sint16	sm;			/* �T�u���[�h			*/
    Sint16	ci;			/* �R�[�f�B���O���		*/
} CDKEY;

#define	CDKEY_NONE	STM_KEY_NONE	/* �X�g���[���L�[�̑I�������Ȃ�	*/
#define	CDKEY_TERM	(-2)		/* �X�g���[���L�[�̑I���I��	*/


/*--- �ǂݍ��ݗ̈��� -------------------------------------------------*/
typedef struct {			/* ���[�NRAM�ւ̃R�s�[		*/
    void	*addr;			/* �]����̈�(�]�����Ȃ�:NULL)	*/
    Sint32	unit;			/* �]���̈�̃��j�b�g�T�C�Y	*/
    Sint32	size;			/* �]���̈�̃��j�b�g��		*/
} TRANS_COPY;

typedef struct {			/* �]���֐����g�p����ꍇ	*/
    Sint32	(*func )(void *obj, Uint32 *addr, 
                        Sint32 adinc, Sint32 nsct);	/* �]���֐�	*/
    void	*obj;			/* �I�u�W�F�N�g			*/
} TRANS_FUNC;

typedef struct {
    Sint32	type;			/* �]�����@			*/
    union {
	TRANS_COPY	copy;		/* ���[�NRAM�ւ̃R�s�[		*/
	TRANS_FUNC	func;		/* �]���֐����g�p����ꍇ	*/
    } trans;
} CDBUF;

/* �]�����@				*/
enum TRANS_TYPE {
    CDBUF_COPY	= 0,			/* ���[�NRAM�ւ̃R�s�[		*/
    CDBUF_FUNC	= 1,			/* �]���֐����g�p����		*/
    CDBUF_TERM	= 2			/* �ǂݍ��ݗ̈���̎w��I��	*/
};

/* �]���̈�̃��j�b�g�T�C�Y		*/
enum TRANS_UNIT {
    CDBUF_FORM1	= STM_UNIT_FORM1,	/* 2048byte�P��			*/
    CDBUF_FORM2	= STM_UNIT_FORM2,	/* 2324byte�P��			*/
    CDBUF_BYTE	= STM_UNIT_BYTE		/* �o�C�g�P��			*/
};

/* CD�u���b�N�̏�Ԃ��擾���邽�߂̒萔	*/
#define	CDREQ_FREE	((CDHN)0xffffffff)	/* CD�u���b�N�󂫃Z�N�^	*/
#define	CDREQ_FAD	((CDHN)0xfffffffe)	/* �s�b�N�A�b�v�̈ʒu	*/
#define	CDREQ_DRV	((CDHN)0xfffffffd)	/* �h���C�u�̏��	*/

/*--- CD�h���C�u��� ---------------------------------------------------*/
enum CDDRV {
    CDDRV_BUSY	= CDC_ST_BUSY,		/* ��ԑJ�ڒ�			*/
    CDDRV_PAUSE = CDC_ST_PAUSE,		/* �|�[�Y��			*/
    CDDRV_STDBY	= CDC_ST_STANDBY,	/* �X�^���o�C			*/
    CDDRV_PLAY	= CDC_ST_PLAY,		/* �b�c�Đ���			*/
    CDDRV_SEEK	= CDC_ST_SEEK,		/* �V�[�N��			*/
    CDDRV_SCAN	= CDC_ST_SCAN,		/* �X�L�����Đ���		*/
    CDDRV_OPEN	= CDC_ST_OPEN,		/* �g���C���J���Ă���		*/
    CDDRV_NODISC= CDC_ST_NODISC,	/* �f�B�X�N���Ȃ�		*/
    CDDRV_RETRY	= CDC_ST_RETRY,		/* ���[�h���g���C������		*/
    CDDRV_ERROR	= CDC_ST_ERROR,		/* ���[�h�f�[�^�G���[����������	*/
    CDDRV_FATAL	= CDC_ST_FATAL		/* �v���I�G���[����������	*/
};

/*--- �X�e�[�^�X -------------------------------------------------------*/
enum CDSTAT {
    CDSTAT_PAUSE	= STM_EXEC_PAUSE,	/* �ǂݍ��ݒ�~��	*/
    CDSTAT_DOING	= STM_EXEC_DOING,	/* �ǂݍ��ݒ�		*/
    CDSTAT_WAIT		= STM_EXEC_WAIT,	/* �]���҂����		*/
    CDSTAT_COMPLETED	= STM_EXEC_COMPLETED	/* �ǂݍ��݊���		*/
};

/*--- �G���[�R�[�h -----------------------------------------------------*/
enum CDERR {
    CDERR_OK	= STM_ERR_OK,		/* ����I��			*/
    CDERR_RDERR	= STM_ERR_CDRD,		/* ���[�h�G���[			*/
    CDERR_NODISC= STM_ERR_CDNODISC,	/* �f�B�X�N���Z�b�g����Ă��Ȃ�	*/
    CDERR_CDROM	= GFS_ERR_CDROM,	/* �f�B�X�N��CD-ROM�łȂ�       */
    CDERR_IPARA	= GFS_ERR_DIRTBL,	/* �������p�����[�^�s��         */
    CDERR_DIR	= GFS_ERR_DIR,		/* �f�B���N�g���ȊO�ւ̈ړ�     */
    CDERR_NEXIST= GFS_ERR_NEXIST,	/* �t�@�C�������݂��Ȃ�		*/
    CDERR_NUM	= STM_ERR_NUM,		/* �o�C�g���Ȃǂ���             */
    CDERR_PUINUSE=STM_ERR_PUINUSE,	/* �s�b�N�A�b�v���쒆           */
    CDERR_ALIGN	= GFS_ERR_ALIGN,	/* ��Ɨ̈悪4byte���E�ɂȂ�    */
    CDERR_TMOUT	= STM_ERR_TMOUT,	/* �^�C���A�E�g			*/
    CDERR_OPEN	= STM_ERR_CDOPEN,	/* �g���C�I�[�v��		*/
    CDERR_FATAL	= STM_ERR_FATAL,	/* CD�h���C�u��<FATAL>���	*/
    CDERR_BUSY	= (-50)			/* ��ԑJ�ڒ�                   */
};

/*--- ��Ɨ̈�̃T�C�Y -------------------------------------------------*/

/* ���������̍�Ɨ̈�̃T�C�Y		*/
#define	SLCD_MAX_OPEN	24
#define	SLCD_WORK_SIZE(nfile)	(nfile * sizeof(GfsDirName))

/*--- �v���g�^�C�v -----------------------------------------------------*/

/* ������				*/
Sint32	slCdInit(Sint32 nfile, void *work);

/* �f�B���N�g���ړ�			*/
Sint32	slCdChgDir(Sint8 *pathname);

/* �t�@�C���I�[�v��			*/
CDHN	slCdOpen(Sint8 *pathname, CDKEY key[]);

/* �t�@�C���̓ǂݍ���			*/
Sint32	slCdLoadFile(CDHN cdhn, CDBUF buf[]);

/* �X�g���[���̓]��			*/
Sint32	slCdTrans(CDHN cdhn, CDBUF buf[], Sint32 ndata[]);

/* �]���̈�̃��Z�b�g			*/
Bool	slCdResetBuf(CDHN cdhn, CDKEY *key);

/* �ǂݍ��ݒ��f				*/
Sint32	slCdAbort(CDHN cdhn);

/* �ǂݍ��݈ꎞ��~			*/
Sint32	slCdPause(CDHN cdhn);

/* �X�e�[�^�X�擾			*/
Sint32	slCdGetStatus(CDHN cdhn, Sint32 ndata[]);

/* �b�c�p�C�x���g�֐�			*/
void	slCdEvent(void);

#endif