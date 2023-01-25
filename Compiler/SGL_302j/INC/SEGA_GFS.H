/******************************************************************************
 *      �\�t�g�E�F�A���C�u����
 *
 *      Copyright (c) 1994,1995,1996 SEGA
 *
 * Library:�t�@�C���V�X�e��
 * Module :���C�u�����w�b�_
 * File   :sega_gfs.h
 * Date   :1996-02-18
 * Version:2.11
 * Author :H.T.
 *
 *************************************************************************** */

#if !defined(SEGA_GFS_H)
#define SEGA_GFS_H

/*****************************************************************************
 *      �C���N���[�h�t�@�C��
 *****************************************************************************/
#include "sega_cdc.h"

/* �o�[�W����   */
                            /*             1         2         3         4  */
                            /*    1234567890123456789012345678901234567890  */
                            /*    ++++++++++++++++++++++++++++++++          */
#if defined(USE_SGL)
    #define GFS_VERSION_STR     ("GFS_SGL Version 2.11 1996-02-18")
#else
    #define GFS_VERSION_STR     ("GFS_SBL Version 2.11 1996-02-18")
#endif
#define GFS_VERSION_LEN 32

/*****************************************************************************
 *      �萔�}�N��
 *****************************************************************************/
#define GFS_FNAME_LEN   12              /* �t�@�C�����̒���                 */

/* �t�@�C���̑��� */
#define GFS_ATR_DIR     0x80            /* �f�B���N�g��                     */
#define GFS_ATR_CDDA    0x40            /* CDDA�t�@�C��                     */
#define GFS_ATR_INTLV   0x20            /* �C���^�[���[�u�Z�N�^���܂�       */
#define GFS_ATR_FORM2   0x10            /* Form2�Z�N�^���܂�                */
#define GFS_ATR_FORM1   0x08            /* Form1�Z�N�^���܂�                */
#define GFS_ATR_END_TBL 0x01            /* �f�B���N�g���e�[�u���̍Ō�       */

#define GFS_BUFSIZ_INF  -1              /* �ǂݍ��ݗ̈�T�C�Y�ɐ����͂Ȃ�   */
#define GFS_RPARA_DFL   0x7fffffff      /* �ǂݍ��݃p�����[�^�̏����l       */

/* �f���f���p   */
#define GFS_DDS_ADDR    0x6000ccc       /* �f���f�����Q�Ɨ̈�̃A�h���X   */
#define GFS_DDS_EXEC    0x01            /* DDS���s��������                  */
#define GFS_DDS_ID()    (*(Uint8 *)(GFS_DDS_ADDR+0))  /* DDS���ʎq�̒l      */
#define GFS_DDS_TNO()   (*(Uint8 *)(GFS_DDS_ADDR+1))  /* �擪CDDA�g���b�NNo */
#define GFS_DDS_FID()   (*(Uint16 *)(GFS_DDS_ADDR+2)) /* �f�B���N�g�����ʎq */
#define GFS_IS_DDS()    (GFS_DDS_ID()==GFS_DDS_EXEC)  /* DDS���s���̔��f    */

/* �G���[�R�[�h */
#define GFS_ERR_OK              0       /* ����I��                         */
#define GFS_ERR_CDRD            (-1)    /* CD���[�h�G���[                   */
#define GFS_ERR_CDNODISC        (-2)    /* CD���Z�b�g����Ă��Ȃ�           */
#define GFS_ERR_CDROM           (-3)    /* �f�B�X�N��CD-ROM�łȂ�           */
#define GFS_ERR_DIRTBL          (-4)    /* �f�B���N�g���Ǘ��e�[�u�����s��   */
#define GFS_ERR_OPENMAX         (-5)    /* �ő�I�[�v�����̒l���s��         */
#define GFS_ERR_DIR             (-6)    /* �w��t�@�C���̓f�B���N�g���łȂ� */
#define GFS_ERR_CDBFS           (-7)    /* CD�u���b�N�t�@�C���V�X�e����     */
                                        /* �g�p�錾���Ă��Ȃ�               */
#define GFS_ERR_NONAME          (-8)    /* �t�@�C�����������Ȃ�             */
#define GFS_ERR_NEXIST          (-9)    /* �w�肳�ꂽ�t�@�C���͑��݂��Ȃ�   */
#define GFS_ERR_FID             (-10)   /* �s���ȃt�@�C�����ʎq             */
#define GFS_ERR_HNDL            (-11)   /* �t�@�C���n���h�����s��           */
#define GFS_ERR_SEEK            (-12)   /* �V�[�N�ʒu���s��                 */
#define GFS_ERR_ORG             (-13)   /* ��ʒl���s��                   */
#define GFS_ERR_NUM             (-14)   /* �o�C�g������                     */
#define GFS_ERR_OFS             (-15)   /* �I�t�Z�b�g���s��                 */
#define GFS_ERR_FBUSY           (-16)   /* �w��t�@�C���̏������c���Ă���   */
#define GFS_ERR_PARA            (-17)   /* �p�����[�^���s��                 */
#define GFS_ERR_BUSY            (-18)   /* ���C�u�����֐����s��             */
#define GFS_ERR_NOHNDL          (-19)   /* �t�@�C���n���h���ɋ󂫂��Ȃ�     */
#define GFS_ERR_PUINUSE         (-20)   /* �s�b�N�A�b�v���쒆               */
#define GFS_ERR_ALIGN           (-21)   /* ��Ɨ̈悪4byte���E�ɂȂ�        */
#define GFS_ERR_TMOUT           (-22)   /* �^�C���A�E�g                     */
#define GFS_ERR_CDOPEN          (-23)   /* �g���C���J���Ă���               */
#define GFS_ERR_BFUL            (-24)   /* �o�b�t�@�t���œǂݍ��ݒ��~       */
#define GFS_ERR_FATAL           (-25)   /* CD��FATAL���                    */

/*****************************************************************************
 *      �񋓒萔
 *****************************************************************************/
/* �A�N�Z�X���[�h(GfsFile:amode) */
enum GfsAccessMode {
    GFS_NWSTAT_NOACT = 0,               /* �������Ă��Ȃ�              */
    GFS_NWSTAT_FREAD,                   /* �ǂݍ��ݒ�                  */
    GFS_NWSTAT_CDREAD                   /* �b�c���[�h��                */
};


/* �V�[�N���[�h(GFS_Seek)               */
enum GfsSeekMode {
    GFS_SEEK_SET = 0,                   /* �擪����V�[�N               */
    GFS_SEEK_CUR,                       /* ���݂̈ʒu����V�[�N         */
    GFS_SEEK_END                        /* �I�[����V�[�N               */
};


/* ���o�����[�h(GFS_SetGmode:gmode) */
enum GfsGetMode {
    GFS_GMODE_ERASE = 0,                /* �]����A�o�b�t�@����폜     */
    GFS_GMODE_RESIDENT                  /* �b�c�o�b�t�@�ɏ풓           */
};


/* �]�����[�h(GFS_SetTmode) */
enum GfsTransMode {
    GFS_TMODE_SCU = 0,                  /* �r�b�t�ɂ��c�l�`�]��    */
    GFS_TMODE_SDMA0,                    /* �c�l�`�T�C�N���X�`�[���]��   cn=0 */
    GFS_TMODE_SDMA1,                    /*                              cn=1 */
    GFS_TMODE_CPU,                      /* �\�t�g�E�F�A�]�� */
    GFS_TMODE_STM,                      /* �X�g���[���p�]�� */
    GFS_TMODE_END
};

/* �A�N�Z�X�T�[�o���(GFS_NwExecServer) */
enum GfsServerStatus {
    GFS_SVR_COMPLETED = 0,              /* �S�t�@�C���̃A�N�Z�X�I��     */
    GFS_SVR_BUSY,                       /* �t�@�C���A�N�Z�X��           */
    GFS_SVR_CDPAUSE,                    /* �b�c�o�b�t�@�t���̈׈ꎞ��~ */
    GFS_SVR_ERROR                       /* �G���[���� */
};


/* �f�B���N�g�����(GFS_LoadDir, GFS_SetDir)     */
enum GfsDirType {
    GFS_DIR_ID          = 0,            /* �t�@�C�����ɂ��A�N�Z�X�s�� */
    GFS_DIR_NAME                        /* �t�@�C�����ɂ��A�N�Z�X��   */
};


/*****************************************************************************
 *      �����}�N��
 *****************************************************************************/
#define GFS_WORK_SIZE(open_max) \
            (sizeof(GfsMng) + ((open_max) - 1) * sizeof(GfsFile))

/*****************************************************************************
 *      �\���̃A�N�Z�X�����}�N��
 *****************************************************************************/

/* �f�B���N�g�����R�[�h�\����  */
#define GFS_DIR_REC(rec)        ((rec)->dirrec)
#define GFS_DIR_FAD(rec)        CDC_FILE_FAD(&GFS_DIR_REC(rec))
#define GFS_DIR_SIZE(rec)       CDC_FILE_SIZE(&GFS_DIR_REC(rec))
#define GFS_DIR_UNIT(rec)       CDC_FILE_UNIT(&GFS_DIR_REC(rec))
#define GFS_DIR_GAP(rec)        CDC_FILE_GAP(&GFS_DIR_REC(rec))
#define GFS_DIR_FN(rec)         CDC_FILE_FN(&GFS_DIR_REC(rec))
#define GFS_DIR_ATR(rec)        CDC_FILE_ATR(&GFS_DIR_REC(rec))
#define GFS_DIR_FNAME(rec)      ((rec)->fname)


/* �f�B���N�g�����Ǘ��\���� */
#define GFS_DIRTBL_TYPE(dirtbl)         ((dirtbl)->type)
#define GFS_DIRTBL_NDIR(dirtbl)         ((dirtbl)->ndir)
#define GFS_DIRTBL_DIRID(dirtbl)        ((dirtbl)->dir.dir_i)
#define GFS_DIRTBL_DIRNAME(dirtbl)      ((dirtbl)->dir.dir_n)


/* �G���[��� */
#define GFS_ERR_FUNC(err)       ((err)->func)
#define GFS_ERR_OBJ(err)        ((err)->obj)
#define GFS_ERR_CODE(err)       ((err)->code)


/*****************************************************************************
 *      �f�[�^�^�̒�`
 *****************************************************************************/

typedef Sint32 (*GfsTransFunc)(void *obj, Sint32 nsct);

     /* �t�@�C����� */
typedef struct {
    Sint32      fid;                    /* �t�@�C�����ʎq */
    CdcFile     finfo;
    Sint32      sctsz;                  /* �Z�N�^�� */
    Sint32      nsct;                   /* �Z�N�^�� */
    Sint32      lstrm;                  /* �ŏI�Z�N�^���̖����f�[�^��   */
} GfsFinfo;


/* CD�o�b�t�@�̎����Ǘ� */
typedef struct {
    Sint32      bufno;                  /* �o�b�t�@���ԍ� */
    Sint32      sctsz;                  /* �b�c�o�b�t�@�̃Z�N�^�T�C�Y   */
    Sint32      flt;                    /* �i��ԍ� */
    CdcSubh     subh;                   /* �T�u�w�b�_ */
    Sint32      fmode;                  /* �i�胂�[�h */
    Sint32      puid;                   /* �擾�s�b�N�A�b�v�̃��[�UID */
    Sint32      filepos;                /* �擪�f�[�^�̃t�@�C����̈ʒu */
    Sint32      sctpos;                 /* �]���ʒu */
    /* �Đ��͈� */
    Sint32      sfad;                   /* �J�nFAD */
    Sint32      efad;                   /* �I��FAD */
} GfsCdRsrc;


/* SCSI�t�@�C���̉��zCD�o�b�t�@�Ǘ� */
typedef struct {
    Sint32      fid;                    /* SCSI�t�@�C�����ʎq   */
    Sint32      filepos;                /* �擪�f�[�^�̃t�@�C����̈ʒu */
    Sint32      sctpos;                 /* �o�b�t�@��̃Z�N�^�ʒu */
    Sint32      sctnum;                 /* �o�b�t�@���̃Z�N�^�� */
} GfsScsiRsrc;


/* �������t�@�C���̉��zCD�o�b�t�@�Ǘ� */
typedef struct {
    void        *data;                  /* �f�[�^�̈�           */
    Sint32      filepos;                /* �擪�f�[�^�̃t�@�C����̈ʒu */
    Sint32      sctpos;                 /* �o�b�t�@��̃Z�N�^�ʒu */
    Sint32      sctnum;                 /* �o�b�t�@���̃Z�N�^�� */
} GfsMemRsrc;


/* �ǂݍ��݌��Ǘ� */
typedef struct {
    /* �ǂݍ��݌��Ǘ� */
    Sint32      ftype;                  /* �t�@�C�����         */
    union {
        GfsCdRsrc       cd;             /* CD�̎���             */
        GfsScsiRsrc     scsi;           /* SCSI�t�@�C���̎���   */
        GfsMemRsrc      mem;            /* �������t�@�C���̎��� */
    } rsrc;
} GfsDtsrc;


/* CD����̓ǂݍ��݂��Ǘ����� */
typedef struct {
    GfsFinfo    finfo;                  /* �t�@�C�����         */
    GfsDtsrc    dtsrc;                  /* �ǂݍ��݌�           */
    Sint32      gmode;                  /* ���o�����[�h       */
    Sint32      stat;                   /* ���s���             */
    /* flow in�Ǘ� */
    Sint32      sct;                    /* �ǂݍ��݃Z�N�^��     */
    Sint32      sctcnt;                 /* �ǂݍ��݃J�E���^     */
    Sint32      sctmax;                 /* �ǂݍ��ݍő�Z�N�^�� */
} GfsFlow;


/* �f�[�^�p�b�N�\���� */
typedef struct {
    void        *data;                  /* �f�[�^�̈�           */
    Sint32      adlt;                   /* �A�h���X�̑�����     */
    Sint32      len;                    /* �]���o�C�g��         */
    Sint32      nsct;                   /* �]���Z�N�^��         */
    Bool        use;                    /* �g�p�t���O           */
} GfsDataPack;


typedef GfsDataPack *GfdpHn;

/* �]���Ǘ� */
/* CD�o�b�t�@����̓]�����Ǘ����� */
typedef struct {
    void        *buf;                   /* �]����A�h���X */
    Sint32      size;                   /* �f�[�^�̈�̃T�C�Y */
    Sint32      wp;                     /* �������݃I�t�Z�b�g */
    /* �]���Ǘ� */
    GfdpHn      dps;                    /* �]�����̃f�[�^�p�b�N */
    GfdpHn      dpd;                    /* �]���悩��̃f�[�^�p�b�N */
    Sint32      tsctmax;                /* �P��̓]���̍ő�Z�N�^�� */
    Sint32      tsct;                   /* �]���ڕW�Z�N�^�� */
    Sint32      tsctcnt;                /* ���݂܂œ]���Z�N�^�� */
    Sint32      tbytcnt;                /* �Z�N�^���̓]���o�C�g�� */
    /* �]���֐� */
    void        *obj;                   /* �]���֐��ւ̑�P���� */
    GfsTransFunc tfunc;                 /* �]���֐� */
    Sint32      unit;                   /* �]���P�� */
    Bool        active;                 /* ���쒆�t���O */
    Sint32      stat;                   /* ��� */
    Sint32      mode;                   /* �]�����[�h */
} GfsTrans;


typedef GfsTrans *GftrHn;


/* �I�[�v�������t�@�C�����Ǘ����� */
typedef struct {
    Bool        used;                   /* ���̍\���̂��g�p�����ǂ��� */
    Sint32      amode;                  /* �A�N�Z�X���[�h */
    Sint32      astat;                  /* �A�N�Z�X��� */
    GfsFlow     flow;
    GfsTrans    trans;
} GfsFile;


/* �t�@�C���n���h�� */
typedef GfsFile *GfsHn;


/* ���[�U�o�^�]���֐� */
typedef Sint32 (*GfsTrFunc)(GfsHn gfs, Sint32 nsct);
     

/* �f�B���N�g�����R�[�h�\����(�t�@�C�����Ȃ�)   */
typedef struct {
    CdcFile     dirrec;
} GfsDirId;


/* �f�B���N�g�����R�[�h�\����(�t�@�C��������)   */
typedef struct {
    CdcFile     dirrec;
    Sint8       fname[GFS_FNAME_LEN];   /* �t�@�C���� */
} GfsDirName;


/* �f�B���N�g�����Ǘ��\���� */
typedef struct {
    Sint32      type;                   /* ��� */
    Sint32      ndir;                   /* �ő�v�f�� */
    union {
        GfsDirId *dir_i;                /* �t�@�C�����Ȃ��f�B���N�g����� */
        GfsDirName *dir_n;              /* �t�@�C�������f�B���N�g����� */
    } dir;
} GfsDirTbl;


/* �G���[�����֐� */
typedef void (*GfsErrFunc)(void *obj, Sint32 ec);

/* �G���[��� */
typedef struct {
    GfsErrFunc  func;                   /* �G���[�������̌Ăяo���֐�   */
    void        *obj;                   /* �Ăяo���֐��ɓn��������   */
    Sint32      code;                   /* �G���[�R�[�h                 */
} GfsErrStat;


/*****************************************************************************
 *      �֐��̐錾
 *****************************************************************************/

/* �t�@�C���V�X�e���̏����� */
Sint32 GFS_Init(Sint32 open_max, void *work, GfsDirTbl *dirtbl);

/* �f�B���N�g�����R�[�h�̓ǂݍ��� */
Sint32 GFS_LoadDir(Sint32 fid, GfsDirTbl *dirtbl);

/* �J�����g�f�B���N�g�����R�[�h�̐ݒ� */
Sint32 GFS_SetDir(GfsDirTbl *dirtbl);

/* ���O����t�@�C�����ʎq�ւ̕ϊ� */
Sint32 GFS_NameToId(Sint8 *fname);

/* �t�@�C�����ʎq����t�@�C�����ւ̕ϊ� */
Sint8 *GFS_IdToName(Sint32 fid);

/* �t�@�C�����ʎq����f�B���N�g�����R�[�h�擾 */
Sint32 GFS_GetDirInfo(Sint32 fid, GfsDirId *dirrec);

/*  �t�@�C���V�X�e���̃��Z�b�g  */
void    GFS_Reset(void);

/* �t�@�C���n���h���̊����� */
GfsHn GFS_Open(Sint32 fid);

/* �t�@�C���n���h���̊����ĉ��� */
void GFS_Close(GfsHn gfs);

/* �A�N�Z�X�|�C���^�̈ړ� */
Sint32 GFS_Seek(GfsHn gfs, Sint32 ofs, Sint32 org);

/* �A�N�Z�X�|�C���^�̎擾 */
Sint32 GFS_Tell(GfsHn gfs);

/* �t�@�C���I���̃`�F�b�N */
Bool GFS_IsEof(GfsHn gfs);

/* �o�C�g�T�C�Y����Z�N�^�T�C�Y�ւ̕ϊ� */
Sint32 GFS_ByteToSct(GfsHn gfs, Sint32 nbyte);

/* �t�@�C���T�C�Y�Ɋւ�����̎擾 */
void GFS_GetFileSize(GfsHn gfs, Sint32 *sctsz, Sint32 *nsct, Sint32 *lstsz);

/* �t�@�C�����̎擾 */
void GFS_GetFileInfo(GfsHn gfs, Sint32 *fid, Sint32 *fn, Sint32 *fsize,
                     Sint32 *atr);

/*  CD�o�b�t�@���̃Z�N�^���̎擾      */
Sint32 GFS_GetNumCdbuf(GfsHn gfs);

/* �ꊇ�ǂݍ��� */
Sint32 GFS_Load(Sint32 fid, Sint32 ofs, void *buf, Sint32 bsize);

/* �������A�^�ǂݍ��� */
Sint32 GFS_Fread(GfsHn gfs, Sint32 nsct, void *buf, Sint32 bsize);

/* �������A�^�ǂݍ��� */
Sint32 GFS_NwFread(GfsHn gfs, Sint32 nsct, void *buf, Sint32 bsize);

/* �������A�^�b�c�o�b�t�@�ǂݍ��� */
Sint32 GFS_NwCdRead(GfsHn gfs, Sint32 nsct);

/* �A�N�Z�X���슮���`�F�b�N */
Bool GFS_NwIsComplete(GfsHn gfs);

/* �A�N�Z�X����̒��~ */
Sint32 GFS_NwStop(GfsHn gfs);

/* �A�N�Z�X��Ԃ̎擾 */
void GFS_NwGetStat(GfsHn gfs, Sint32 *amode, Sint32 *ndata);

/* �t�@�C���P�ʂł̃A�N�Z�X����̎��s */
Sint32 GFS_NwExecOne(GfsHn gfs);

/* �T�[�o�A�N�Z�X����̎��s */
Sint32 GFS_NwExecServer(GfsHn *now_gfs);

/* �b�c�o�b�t�@����̎��o�����[�h�̐ݒ� */
Sint32 GFS_SetGmode(GfsHn gfs, Sint32 gmode);

/* �]�����[�h�̐ݒ� */
Sint32 GFS_SetTmode(GfsHn gfs, Sint32 tmode);

/* �\�[�X�o�b�t�@�ւ̓ǂݍ��݃Z�N�^���̐ݒ� */
Sint32 GFS_SetReadPara(GfsHn gfs, Sint32 nsct);

/* �\�[�X�o�b�t�@����z�X�g�ւ̓]���Z�N�^���̐ݒ� */
Sint32 GFS_SetTransPara(GfsHn gfs, Sint32 tsize);

/* �]���֐��̓o�^       */
void    GFS_SetTrFunc(GfsHn gfs, GfsTrFunc func);

/* �]���֐��ɂ�����]���J�n     */
Uint32  *GFS_StartTrans(GfsHn gfs, Sint32 *dadr);

/* �s�b�N�A�b�v���A�N�Z�X�|�C���^�̈ʒu�Ɉړ����� */
Sint32 GFS_CdMovePickup(GfsHn gfs);

/* �G���[�����֐��̓o�^ */
void GFS_SetErrFunc(GfsErrFunc func, void *obj);

/* �G���[��Ԃ̎擾 */
void GFS_GetErrStat(GfsErrStat *stat);

/*  �g���b�N�ԍ��̕ϊ�      */
Sint32  GFS_ConvTno(Sint32 logtno);

/* fid�ƃI�t�Z�b�g����t���[���A�h���X���擾���� */
Sint32 GFS_GetFad(Sint32 fid, Sint32 ofs);


/*****************************************************************************
 *      �V�X�e���p���
 *****************************************************************************/

/*---�萔--------------------------------------------------------------------*/
#define GFS_OPEN_MAX    24              /* �ő�I�[�v���t�@�C���� */
#define GFS_TBUF_NR     2               /* �]���o�b�t�@�̐� */
#define GFS_FTYPE_NR    3               /* �t�@�C����ʐ� */
#define GFS_SCTBUF_SIZ  2048            /* �Z�N�^�o�b�t�@�̑傫�� */
#define GFS_CDBBUF_NR   24              /* CD�u���b�N�̋�搔 */
#define GFS_SELQ_MAX    24              /* �i��ݒ�R�}���h�L���[�̍ő咷 */
#define GFS_FCONQ_MAX   24              /* �ڑ��R�}���h�L���[�̍ő咷 */

/*---�f�[�^�^----------------------------------------------------------------*/

/* �t�@�C������p�֐�(�Ǘ��e�[�u��, GfsMng�̃����o) */
typedef struct {
    Sint32 (*flowin)(GfsFlow *);        /* �\�[�X�o�b�t�@�ǂݍ��݊֐�   */
    void (*stopin)(GfsFlow *, Bool);    /* �ǂݍ��ݒ��~�֐�             */
    Sint32 (*seek)(GfsFlow *, Sint32);  /* �A�N�Z�X�|�C���^�ݒ�֐�     */
    Sint32 (*tell)(GfsFlow *);          /* �A�N�Z�X�|�C���^�擾�֐�     */
} GfsFileFunc;

/* �A�N�Z�X�T�[�o�Ǘ��\����(�Ǘ��e�[�u��, GfsMng�̃����o) */
typedef struct {
    GfsHn   access_file[GFS_OPEN_MAX];  /* �A�N�Z�X���[�h�w��σt�@�C�� */
    Sint32  nfile;                      /* �o�^�t�@�C����               */
} GfsSvr;


/* �f�B���N�g���Ǘ��\����(�Ǘ��e�[�u��, GfsMng�̃����o) */
typedef struct {
    GfsDirTbl   dirtbl;                 /* �f�B���N�g�����Ǘ� */
    Sint32      nfile;                  /* �t�@�C���� */
} GfsDirMng;


/* �i��ݒ�R�}���h�L���[�̗v�f(CD�u���b�N�Ǘ��\����, GfsCdbMng�̃����o) */
typedef struct {
    Uint8 flt;                          /* �ݒ��i��ԍ� */
    Uint8 fmode;                        /* �i�胂�[�h */
    CdcSubh subh;                       /* �T�u�w�b�_ */
    Sint32 fad;                         /* �J�nFAD */
    Sint32 snum;                        /* FAD�Z�N�^�� */
} GfcdSelQu;

/* �ڑ��R�}���h�L���[�̗v�f(CD�u���b�N�Ǘ��\����, GfsCdbMng�̃����o) */
typedef struct {
    Sint32 flt;                         /* �ݒ�i�� */
    Sint32 buf;                         /* �^�o�͐ڑ��o�b�t�@ */
    Sint32 flnout;                      /* �U�o�͐ڑ��i��(���̒l���g�p) */
} GfcdFconQu;    

/* CD�u���b�N�Ǘ��\����(�Ǘ��e�[�u��, GfsMng�̃����o) */
typedef struct {
    /* �����Ǘ� */
    Sint8 use_buf[GFS_CDBBUF_NR];       /* �o�b�t�@���g�p��� */
    Sint8 use_filt[GFS_CDBBUF_NR];      /* �i��g�p��� */
    Bool use_pu;                        /* �s�b�N�A�b�v�g�p��� */
    Sint32 tr_bufno;                    /* �f�[�^�]�����̃o�b�t�@���   */
    Sint32 puid;                        /* �s�b�N�A�b�v�̏��L��ID */
    Sint32 timer;                       /* �^�C���A�E�g�J�E���^ */
    CdcStat stat;                       /* CD�u���b�N�̏�� */
    void (*func)(void *);               /* CSCT�n���h�� */
    void *obj;                          /* CSCT�n���h���̈��� */
    /* GFCD_SetFilt�^�X�N */
    struct {
        Sint32 len;                     /* �i��ݒ�R�}���h�L���[�̒��� */
        Sint32 stat;                    /* �R�}���h�L���[�擪�̏�� */
        GfcdSelQu selq[GFS_SELQ_MAX];   /* �i��ݒ�R�}���h�L���[ */
    } tsk_setflt;
    /* GFCD_SetFiltCon�^�X�N */
    struct {
        Sint32 len;                     /* �ڑ��R�}���h�L���[�̒��� */
        Sint32 stat;                    /* �^�X�N�I���t���O */
        GfcdFconQu fconq[GFS_FCONQ_MAX]; /* �ڑ��R�}���h�L���[ */
    } tsk_fltcon;
    /* GFCD_SetCon�^�X�N */
    struct {
        Sint32 stat;                    /* �^�X�N�I���t���O */
        Sint32 flt;                     /* CD�ڑ���i�� */
    } tsk_setcon;
    /* GFCD_GetLenData�^�X�N */
    struct {
        Sint32 stat;                    /* �^�X�N�I���t���O */
        Sint32 bufno;                   /* �Ώۋ�� */
        Sint32 spos;                    /* �擪�Z�N�^�ʒu */
        Sint32 usct;                    /* �v���Z�N�^�� */
        Sint32 cnt;                     /* �^�X�N�̎��s�� */
        Sint32 *nsct;                   /* �����Z�N�^���i�[�� */
        Sint32 *nbyte;                  /* �����o�C�g���i�[�� */
    }tsk_getlen;
    /* GFCD_ReqData�^�X�N */
    struct {
        Sint32 stat;                    /* �^�X�N�I���t���O */
        Sint32 bufno;                   /* �Ώۋ�� */
        Sint32 sctpos;                  /* �Z�N�^�ʒu */
        Sint32 nsct;                    /* �v���Z�N�^�� */
    } tsk_reqdat;
    /* GFCD_DelSctData�^�X�N */
    struct {
        Sint32 stat;                    /* �^�X�N�I���t���O */
        Sint32 bufno;                   /* �Ώۋ�� */
        Sint32 sctpos;                  /* �폜�J�n�Z�N�^�ʒu */
        Sint32 nsct;                    /* �폜�Z�N�^�� */
    } tsk_delsct;
    /* GFCD_MoveSctData�^�X�N */
    struct {
        Sint32 stat;                    /* �^�X�N�I���t���O */
        Sint32 dst;                     /* �ړ����� */
        Sint32 src;                     /* �ړ������ */
        Sint32 spos;                    /* �ړ��J�n�Z�N�^�ʒu */
        Sint32 snum;                    /* �ړ��Z�N�^�� */
        Sint32 fmode;                   /* �ړ���Z���N�^�̍i�胂�[�h�ۑ� */
    } tsk_movsct;
    /* GFCD_ChgDir�^�X�N */
    struct {
        Sint32 stat;                    /* �^�X�N�I���t���O */
        Sint16 fid;                     /* �ݒ�t�@�C�����ʎq */
        Sint16 work;                    /* ��ƃo�b�t�@ */
        Sint32 *ndir;                   /* �ێ��f�B���N�g������ */
    } tsk_chgdir;
} GfsCdbMng;

/* �Ǘ��e�[�u�� */
typedef struct {
    Sint32      openmax;                /* �I�[�v���t�@�C���̍ő吔 */
    GfsFileFunc functbl[GFS_FTYPE_NR];  /* �t�@�C������p�֐� */
    GfsSvr      svr;                    /* �A�N�Z�X�T�[�o */
    GfsDirMng   curdir;                 /* �J�����g�f�B���N�g�� */
    GfsHn       pickup;                 /* �s�b�N�A�b�v���䒆�t�@�C�� */
    Sint32      sfad;                   /* �Đ��͈�:�J�nFAD */
    Sint32      efad;                   /* �Đ��͈�:�I��FAD+1 */
    GfsHn       trans;                  /* �f�[�^�]�����t�@�C�� */
    GfsErrStat  error;                  /* �G���[��� */
    Uint32      flags;                  /* �f�o�C�X�ڑ����Ȃ� */
    Sint32      timer;                  /* �^�C���A�E�g�J�E���^ */
    GfsCdbMng   cdb;                    /* CD�u���b�N�Ǘ��\���� */
    GfsDataPack srcpk;                  /* �]�����f�[�^�p�b�N */
    GfsDataPack dstpk;                  /* �]����f�[�^�p�b�N */
    Uint8       sect_buf[GFS_SCTBUF_SIZ]; /* �P�Z�N�^�̓ǂݍ��ݗp�o�b�t�@ */
    GfsFile     file[1];                /* �S�n���h���̔z��i�ϒ��j */
} GfsMng;

#endif      /* !defined(SEGA_GFS_H) */

/* end of file */