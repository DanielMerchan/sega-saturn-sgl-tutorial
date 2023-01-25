/*
 *     �\�t�g�E�F�A���C�u����
 *
 *     Copyright (c) 1994 SEGA
 *
 *  Library: �b�c��?M�C���^�t�F?[�X?iCDC?j
 *  Module : CDC���C�u�����p�w�b�_�t�@�C��
 *  File   : sega_cdc.h
 *  Date   : 1995-03-31
 *  Version: 1.20
 *  Author : M.M.
 *
 */

/* ��?d�C���N��?[�h�ւ̑Ή� */
#ifndef SEGA_CDC_H
#define SEGA_CDC_H

/*******************************************************************
*       �C���N��?[�h�t�@�C��
*******************************************************************/
#include    "sega_xpt.h"

/*******************************************************************
*       ��?��}�N�?
*******************************************************************/

/* ����?��ݗv�����W�X�^�֌W?iHIRQREQ, HIRQMSK?j�̃r�b�g�� */
#define CDC_HIRQ_CMOK   0x0001  /* bit0 ?F�R�}���h��?s�\ */
#define CDC_HIRQ_DRDY   0x0002  /* bit1 ?F�f?[�^�]��?������� */
#define CDC_HIRQ_CSCT   0x0004  /* bit2 ?F�P�Z�N�^�ǂ�?��݊��� */
#define CDC_HIRQ_BFUL   0x0008  /* bit3 ?F�b�c�o�b�t�@�t�� */
#define CDC_HIRQ_PEND   0x0010  /* bit4 ?F�b�c?�?���?I�� */
#define CDC_HIRQ_DCHG   0x0020  /* bit5 ?F�f�B�X�N�����̔�?� */
#define CDC_HIRQ_ESEL   0x0040  /* bit6 ?F�Z���N�^?ݒ�?��?��?I�� */
#define CDC_HIRQ_EHST   0x0080  /* bit7 ?F�z�X�g��?o��?��?��?I�� */
#define CDC_HIRQ_ECPY   0x0100  /* bit8 ?F����?^�ړ�?��?��?I�� */
#define CDC_HIRQ_EFLS   0x0200  /* bit9 ?F�t�@�C���V�X�e��?��?��?I�� */
#define CDC_HIRQ_SCDQ   0x0400  /* bit10?F�T�u�R?[�h�p��?v?X?V���� */
#define CDC_HIRQ_MPED   0x0800  /* bit11?FMPEG�֘A?��?��?I�� */
#define CDC_HIRQ_MPCM   0x1000  /* bit12?FMPEG��?�s���Ԃ�?I�� */
#define CDC_HIRQ_MPST   0x2000  /* bit13?FMPEG����?��݃X�e?[�^�X�̒ʒm */
    
/* �o�b�t�@���̃Z�N�^�͈�?i�Z�N�^�ʒu�ƃZ�N�^?�?j�̓���w�� */
/* ?i�����������16�r�b�g���L����?A�����I�ɂ�0xffff�Ɠ��l?j */
#define CDC_SPOS_END    -1  /* ���?Ō�̃Z�N�^�ʒu������ */
#define CDC_SNUM_END    -1  /* �w�辸��ʒu������?Ō�܂ł̾��?������� */

/* ���̑��̓���w�� */
#define CDC_PARA_DFL    0       /* �p���??[�^��?ȗ��l�w�� */
#define CDC_PARA_NOCHG  -1      /* �p���??[�^�̖���?X�w�� */
#define CDC_NUL_SEL     0xff    /* �Z���N�^��?��̓���l */
#define CDC_NUL_FID     -1      /* �t�@�C�����ʎq�̓���l (0xffffff) */

/* �b�c�t���O */
#define CDC_CDFLG_ROM   0x80    /* CD-ROM�f�R?[�h�� */

/* �n?[�h�E�F�A�t���O?i�n?[�h�E�F�A?���?j */
#define CDC_HFLAG_MPEG  0x02    /* MPEG���� */
#define CDC_HFLAG_HERR  0x80    /* �n?[�h�E�F�A�G��?[��?� */

/* ?�?���?[�h?i�b�c?�?��p���??[�^��?j */
#define CDC_PM_DFL          0x00    /* ?�?���?[�h��?ȗ��l */
#define CDC_PM_REP_NOCHG    0x7f    /* ?ő僊�s?[�g��?����?X���Ȃ� */
#define CDC_PM_PIC_NOCHG    0x80    /* �s�b�N�A�b�v�ʒu���?X���Ȃ� */
#define CDC_PM_NOCHG        -1      /* ?�?���?[�h���?X���Ȃ� (0xff) */

/* �T�u��?[�h */
#define CDC_SM_EOR      0x01    /* ���R?[�h?Ō�̃Z�N�^ */
#define CDC_SM_VIDEO    0x02    /* �r�f�I�Z�N�^ */
#define CDC_SM_AUDIO    0x04    /* �I?[�f�B�I�Z�N�^ */
#define CDC_SM_DATA     0x08    /* �f?[�^�Z�N�^ */
#define CDC_SM_TRIG     0x10    /* �g���K�n�m */
#define CDC_SM_FORM     0x20    /* �t�H?[���r�b�g?i1:Form2,  0:Form1?j*/
#define CDC_SM_RT       0x40    /* ���A���^�C���Z�N�^ */
#define CDC_SM_EOF      0x80    /* �t�@�C��?Ō�̃Z�N�^ */

/* �t�@�C���A�g���r��?[�g?i�t�@�C��?���?j */
#define CDC_ATR_DIRFG   0x02    /* �f�B���N�g���ł��� */
#define CDC_ATR_FORM1   0x08    /* Form1�Z�N�^���܂� */
#define CDC_ATR_FORM2   0x10    /* Form2�Z�N�^���܂� */
#define CDC_ATR_INTLV   0x20    /* �C���^��?[�u�Z�N�^���܂� */
#define CDC_ATR_CDDA    0x40    /* CD-DA�t�@�C�� */
#define CDC_ATR_DIRXA   0x80    /* �f�B���N�g���t�@�C�� */

/* �X�^���o�C�^�C�� */
#define CDC_STNBY_MIN   60      /* ?�?��l */
#define CDC_STNBY_MAX   900     /* ?ő�l */

/* �T�u�R?[�h�t���O */
#define CDC_SCD_PACK    0x01    /* �p�b�N�f?[�^�G��?[ */
#define CDC_SCD_OVER    0x02    /* �I?[�o?[�����G��?[ */

/* �b�c�u�?�b�N�̓]���??[�h?� */
#define CDC_DEND_ERR    0xffffff    /* �f?[�^�]���ŃG��?[����?� */

/* ���f?[�^�T�C�Y */
#define CDC_ACTSIZ_ERR  0xffffff    /* �v�Z����?s�ł��Ȃ����� */

/* �t��?[���A�h���X��?�����?i�Z�N�^�ʒu�ƃt��?[���A�h���X?j */
#define CDC_SPOS_ERR    0xffff      /* ��?��ŃG��?[����?� */
#define CDC_FAD_ERR     0xffffff    /* ��?�����?s�ł��Ȃ����� */

/* �}�X�N�r�b�g�p�^?[�� */
#define CDC_STC_MSK     0x0f    /* �X�e?[�^�X�R?[�h */

/*******************************************************************
*       �񋓒�?�
*******************************************************************/

/* �G��?[�R?[�h */
enum CdcErrCode {
    CDC_ERR_OK = OK,    /* ��?���?�?�?I������ */

    CDC_ERR_CMDBUSY=-1, /* �R�}���h?I���t���O���P�ɂȂ��Ă��Ȃ� */
    CDC_ERR_CMDNG  =-2, /* �R�}���h��?s��?ACMOK�t���O���P�ɂȂ��Ă��Ȃ� */
    CDC_ERR_TMOUT  =-3, /* �^�C���A�E�g?iڽ��ݽ�҂�?A�ް��]��?����҂�?j*/
    CDC_ERR_PUT    =-4, /* ?���?���?����ŋ󂫃Z�N�^���m�ۂł��Ȃ����� */
    CDC_ERR_REJECT =-5, /* �R�}���h�ɑ΂��郌�X�|���X��REJECT�ƂȂ��� */
    CDC_ERR_WAIT   =-6, /* �R�}���h�ɑ΂��郌�X�|���X��WAIT�ƂȂ��� */
    CDC_ERR_TRNS   =-7, /* �f?[�^�]���T�C�Y����?�ł��� */
    CDC_ERR_PERI   =-8  /* ������X�|���X���擾�ł��Ȃ����� */
};

/* �X�e?[�^�X */
enum CdcStatus {
    /* �X�e?[�^�X�R?[�h?i�b�c�h���C�u?��?j */
    CDC_ST_BUSY     = 0x00,     /* ?�ԑJ�ڒ� */
    CDC_ST_PAUSE    = 0x01,     /* �|?[�Y��?i�ꎞ��~?j */
    CDC_ST_STANDBY  = 0x02,     /* �X�^���o�C?i�h���C�u��~?��?j */
    CDC_ST_PLAY     = 0x03,     /* �b�c?�?��� */
    CDC_ST_SEEK     = 0x04,     /* �V?[�N�� */
    CDC_ST_SCAN     = 0x05,     /* �X�L����?�?��� */
    CDC_ST_OPEN     = 0x06,     /* �g���C���J���Ă��� */
    CDC_ST_NODISC   = 0x07,     /* �f�B�X�N���Ȃ� */
    CDC_ST_RETRY    = 0x08,     /* ��?[�h���g���C?��?�� */
    CDC_ST_ERROR    = 0x09,     /* ��?[�h�f?[�^�G��?[����?����� */
    CDC_ST_FATAL    = 0x0a,     /* �v���I�G��?[����?����� */

    /* ���̑� */
    CDC_ST_PERI     = 0x20,     /* ������X�|���X */
    CDC_ST_TRNS     = 0x40,     /* �f?[�^�]���v�?���� */
    CDC_ST_WAIT     = 0x80,     /* WAIT */
    CDC_ST_REJECT   = 0xff      /* REJECT */
};

/* �ʒu�^�C�v?i?�?�?A�V?[�N���ɂ�����b�c�ʒu�p���??[�^�Ŏw��?j */
enum CdcPosType {
    CDC_PTYPE_DFL,          /* ?ȗ��l�̎w�� */
    CDC_PTYPE_FAD,          /* �t��?[���A�h���X�w�� */
    CDC_PTYPE_TNO,          /* �g���b�N?^�C���f�b�N�X�w�� */
    CDC_PTYPE_NOCHG,        /* ����?X�̎w��?i?ݒ�l���?X���Ȃ�?j */

    CDC_PTYPE_END
};

/* �]��?����҂��^�C�v?i�f?[�^�]����?����҂��Ŏw��?j */
enum CdcDrdyType {
    CDC_DRDY_GET,           /* �f?[�^�����?o��?iCD��ۯ�?�ν�?j */
    CDC_DRDY_PUT,           /* �f?[�^��?���?���?iν�?�CD��ۯ�?j */

    CDC_DRDY_END
};

/* �X�L�������� */
enum CdcScanDir {
    CDC_SCAN_FWD = 0x00,    /* �?����?�?� */
    CDC_SCAN_RVS = 0x01     /* �?�߂�?�?� */
};

/* �Z�N�^�� */
enum CdcSctLen {
    CDC_SLEN_2048  = 0,     /* 2048�o�C�g��2324�o�C�g?i��?[�U�f?[�^?j*/
    CDC_SLEN_2336  = 1,     /* 2336�o�C�g?i�T�u�w�b�_�܂�?j*/
    CDC_SLEN_2340  = 2,     /* 2340�o�C�g?i�w�b�_�܂�?j*/
    CDC_SLEN_2352  = 3,     /* 2352�o�C�g?i�Z�N�^�S��?j*/
    CDC_SLEN_NOCHG = -1     /* ?ݒ���?X���Ȃ� (0xff) */
};

/* ����?^�ړ��G��?[?�� */
enum CdcCopyErr {
    CDC_COPY_OK   = 0,      /* ?�?�?I�� */
    CDC_COPY_NG   = 1,      /* �G��?[��?� */
    CDC_COPY_BUSY = 0xff    /* ����?^�ړ�?��?�� */
};

/*******************************************************************
*       ?\���̃A�N�Z�X?��?�}�N�?
*******************************************************************/

/* �b�c�X�e?[�^�X?�� */
#define CDC_STAT_STATUS(stat)       ((stat)->status)
#define CDC_STAT_FLGREP(stat)       ((stat)->report.flgrep)
#define CDC_STAT_CTLADR(stat)       ((stat)->report.ctladr)
#define CDC_STAT_TNO(stat)          ((stat)->report.tno)
#define CDC_STAT_IDX(stat)          ((stat)->report.idx)
#define CDC_STAT_FAD(stat)          ((stat)->report.fad)

/* �n?[�h�E�F�A?�� */
#define CDC_HW_HFLAG(hw)            ((hw)->hflag)
#define CDC_HW_VER(hw)              ((hw)->ver)
#define CDC_HW_MPVER(hw)            ((hw)->mpver)
#define CDC_HW_DRV(hw)              ((hw)->drv)
#define CDC_HW_REV(hw)              ((hw)->rev)

/* �b�c�ʒu�p���??[�^ */
#define CDC_POS_PTYPE(pos)          ((pos)->ptype)
#define CDC_POS_FAD(pos)            ((pos)->pbody.fad)
#define CDC_POS_TNO(pos)            ((pos)->pbody.trkidx.tno)
#define CDC_POS_IDX(pos)            ((pos)->pbody.trkidx.idx)

/* �b�c?�?��p���??[�^ */
#define CDC_PLY_START(ply)          ((ply)->start)
#define CDC_PLY_END(ply)            ((ply)->end)
#define CDC_PLY_PMODE(ply)          ((ply)->pmode)

#define CDC_PLY_STYPE(ply)          CDC_POS_PTYPE(&CDC_PLY_START(ply))
#define CDC_PLY_SFAD(ply)           CDC_POS_FAD(&CDC_PLY_START(ply))
#define CDC_PLY_STNO(ply)           CDC_POS_TNO(&CDC_PLY_START(ply))
#define CDC_PLY_SIDX(ply)           CDC_POS_IDX(&CDC_PLY_START(ply))

#define CDC_PLY_ETYPE(ply)          CDC_POS_PTYPE(&CDC_PLY_END(ply))
#define CDC_PLY_EFAS(ply)           CDC_POS_FAD(&CDC_PLY_END(ply))
#define CDC_PLY_ETNO(ply)           CDC_POS_TNO(&CDC_PLY_END(ply))
#define CDC_PLY_EIDX(ply)           CDC_POS_IDX(&CDC_PLY_END(ply))

/* �T�u�w�b�_?��? */
#define CDC_SUBH_FN(subh)           ((subh)->fn)
#define CDC_SUBH_CN(subh)           ((subh)->cn)
#define CDC_SUBH_SMMSK(subh)        ((subh)->smmsk)
#define CDC_SUBH_SMVAL(subh)        ((subh)->smval)
#define CDC_SUBH_CIMSK(subh)        ((subh)->cimsk)
#define CDC_SUBH_CIVAL(subh)        ((subh)->cival)

/* �Z�N�^?�� */
#define CDC_SCT_FAD(sct)            ((sct)->fad)
#define CDC_SCT_FN(sct)             ((sct)->fn)
#define CDC_SCT_CN(sct)             ((sct)->cn)
#define CDC_SCT_SM(sct)             ((sct)->sm)
#define CDC_SCT_CI(sct)             ((sct)->ci)

/* �t�@�C��?�� */
#define CDC_FILE_FAD(file)          ((file)->fad)
#define CDC_FILE_SIZE(file)         ((file)->size)
#define CDC_FILE_UNIT(file)         ((file)->unit)
#define CDC_FILE_GAP(file)          ((file)->gap)
#define CDC_FILE_FN(file)           ((file)->fn)
#define CDC_FILE_ATR(file)          ((file)->atr)

/*******************************************************************
*       ?��?�}�N�?
*******************************************************************/

/* �b�c�X�e?[�^�X?�񂩂�X�e?[�^�X�R?[�h���擾 */
#define CDC_GET_STC(stat)       (CDC_STAT_STATUS(stat) & CDC_STC_MSK)

/* �b�c�X�e?[�^�X?�񂩂烊�s?[�g��?����擾 */
#define CDC_GET_REPEAT(stat)    (CDC_STAT_FLGREP(stat) & 0x0f)

/* MPEG���g�p�\�����ׂ�?iTRUE?F�g�p�\?AFALSE?F�g�p�s��?j */
/* �?��?F���̃}�N�?�̓}�j���A���ɋL?q���Ȃ� */
#define CDC_IS_MPEG_ENA(hw)     (CDC_HW_MPVER(hw) != 0)

/*******************************************************************
*       �f?[�^�^��?錾
*******************************************************************/

/* �b�c�X�e?[�^�X?��?i�X�e?[�^�X?{�b�c���|?[�g?j */
typedef struct {
    Uint8   status;         /* �X�e?[�^�X */
    struct {                /* �b�c���|?[�g */
        Uint8   flgrep;     /* �b�c�t���O�ƃ��s?[�g��?� */
        Uint8   ctladr;     /* CONTROL/ADR�o�C�g */
        Uint8   tno;        /* �g���b�N��?� */
        Uint8   idx;        /* �C���f�b�N�X��?� */
        Sint32  fad;        /* �t��?[���A�h���X */
    } report;
} CdcStat;

/* �n?[�h�E�F�A?�� */
typedef struct {
    Uint8   hflag;          /* �n?[�h�E�F�A�t���O */
    Uint8   ver;            /* �b�c�u�?�b�N�̃o?[�W����?�� */
    Uint8   mpver;          /* MPEG�̃o?[�W����?�� */
    Uint8   drv;            /* �b�c�h���C�u?�� */
    Uint8   rev;            /* �b�c�u�?�b�N�̃��r�W����?�� */
} CdcHw;

/* �b�c�ʒu�p���??[�^ */
typedef struct {
    Sint32 ptype;           /* �ʒu�^�C�v?i�ʒu�p���??[�^�̎�ނ̎w��?j*/
    union {
        Sint32 fad;         /* �t��?[���A�h���X?A�Z�N�^?� */
        struct {
            Uint8 tno;      /* �g���b�N��?� */
            Uint8 idx;      /* �C���f�b�N�X��?� */
        } trkidx;
    } pbody;
} CdcPos;

/* �b�c?�?��p���??[�^ */
typedef struct {
    CdcPos  start;          /* �J�n�ʒu */
    CdcPos  end;            /* ?I���ʒu */
    Uint8   pmode;          /* ?�?���?[�h?i�߯����߈ړ�?A�J��Ԃ���?�?j*/
} CdcPly;

/* �T�u�w�b�_?��? */
typedef struct {
    Uint8   fn;             /* �t�@�C����?� */
    Uint8   cn;             /* �`���l����?� */
    Uint8   smmsk;          /* �T�u��?[�h�̃}�X�N�p�^?[�� */
    Uint8   smval;          /* �T�u��?[�h�̔�r�l */
    Uint8   cimsk;          /* �R?[�f�B���O?��̃}�X�N�p�^?[�� */
    Uint8   cival;          /* �R?[�f�B���O?��̔�r�l */
} CdcSubh;

/* �Z�N�^?�� */
typedef struct {
    Sint32  fad;            /* �t��?[���A�h���X */
    Uint8   fn;             /* �t�@�C����?� */
    Uint8   cn;             /* �`���l����?� */
    Uint8   sm;             /* �T�u��?[�h */
    Uint8   ci;             /* �R?[�f�B���O?�� */
} CdcSct;

/* �t�@�C��?�� */
typedef struct {
    Sint32  fad;            /* �t�@�C��?擪�t��?[���A�h���X */
    Sint32  size;           /* �t�@�C���T�C�Y?i�o�C�g?�?j */
    Uint8   unit;           /* �t�@�C�����j�b�g�T�C�Y */
    Uint8   gap;            /* �M���b�v�T�C�Y */
    Uint8   fn;             /* �t�@�C����?� */
    Uint8   atr;            /* �t�@�C���A�g���r��?[�g */
} CdcFile;

/*******************************************************************
*       ��?�?錾
*******************************************************************/

/*******************************************************************
*       ��?�?錾
*******************************************************************/

/* cdc_cmn.c */
Sint32  CDC_GetCurStat(CdcStat *stat);
Sint32  CDC_GetLastStat(CdcStat *stat);
Sint32  CDC_GetHwInfo(CdcHw *hw);
Sint32  CDC_TgetToc(Uint32 *toc);
Sint32  CDC_GetSes(Sint32 sesno, Uint32 *ses);
Sint32  CDC_CdInit(Sint32 iflag, Sint32 stnby, Sint32 ecc, Sint32 retry);
Sint32  CDC_CdOpen(void);
Sint32  CDC_DataReady(Sint32 dtype);
Sint32  CDC_DataEnd(Sint32 *cdwnum);
Sint32  CDC_GetPeriStat(CdcStat *stat);

/* cdc_drv.c */
Sint32  CDC_CdPlay(CdcPly *ply);
Sint32  CDC_CdSeek(CdcPos *pos);
Sint32  CDC_CdScan(Sint32 scandir);

/* cdc_scd.c */
Sint32  CDC_TgetScdQch(Uint16 *qcode);
Sint32  CDC_TgetScdRwch(Uint16 *rwcode, Sint32 *scdflag);

/* cdc_dev.c */
Sint32  CDC_CdSetCon(Sint32 filtno);
Sint32  CDC_CdGetCon(Sint32 *filtno);
Sint32  CDC_CdGetLastBuf(Sint32 *bufno);

/* cdc_sel.c */
Sint32  CDC_SetFiltRange(Sint32 filtno, Sint32 fad, Sint32 fasnum);
Sint32  CDC_GetFiltRange(Sint32 filtno, Sint32 *fad, Sint32 *fasnum);
Sint32  CDC_SetFiltSubh(Sint32 filtno, CdcSubh *subh);
Sint32  CDC_GetFiltSubh(Sint32 filtno, CdcSubh *subh);
Sint32  CDC_SetFiltMode(Sint32 filtno, Sint32 fmode);
Sint32  CDC_GetFiltMode(Sint32 filtno, Sint32 *fmode);
Sint32  CDC_SetFiltCon(Sint32 filtno, Sint32 cflag, Sint32 bufno,
                       Sint32 flnout);
Sint32  CDC_GetFiltCon(Sint32 filtno, Sint32 *bufno, Sint32 *flnout);
Sint32  CDC_ResetSelector(Sint32 rflag, Sint32 bufno);

/* cdc_bif.c */
Sint32  CDC_GetBufSiz(Sint32 *totalsiz, Sint32 *bufnum, Sint32 *freesiz);
Sint32  CDC_GetSctNum(Sint32 bufno, Sint32 *snum);
Sint32  CDC_CalActSiz(Sint32 bufno, Sint32 spos, Sint32 snum);
Sint32  CDC_GetActSiz(Sint32 *actwnum);
Sint32  CDC_GetSctInfo(Sint32 bufno, Sint32 spos, CdcSct *sct);
Sint32  CDC_ExeFadSearch(Sint32 bufno, Sint32 spos, Sint32 fad);
Sint32  CDC_GetFadSearch(Sint32 *bufno, Sint32 *spos, Sint32 *fad);

/* cdc_bio.c */
Sint32  CDC_SetSctLen(Sint32 getslen, Sint32 putslen);
Sint32  CDC_GetSctData(Sint32 bufno, Sint32 spos, Sint32 snum);
Sint32  CDC_DelSctData(Sint32 bufno, Sint32 spos, Sint32 snum);
Sint32  CDC_GetdelSctData(Sint32 bufno, Sint32 spos, Sint32 snum);
Sint32  CDC_PutSctData(Sint32 filtno, Sint32 snum);
Sint32  CDC_CopySctData(Sint32 srcbn, Sint32 spos, Sint32 snum,
                        Sint32 dstfln);
Sint32  CDC_MoveSctData(Sint32 srcbn, Sint32 spos, Sint32 snum,
                        Sint32 dstfln);
Sint32  CDC_GetCopyErr(Sint32 *cpyerr);

/* cdc_cfs.c */
Sint32  CDC_ChgDir(Sint32 filtno, Sint32 fid);
Sint32  CDC_ReadDir(Sint32 filtno, Sint32 fid);
Sint32  CDC_GetFileScope(Sint32 *fid, Sint32 *infnum, Bool *drend);
Sint32  CDC_TgetFileInfo(Sint32 fid, CdcFile *file);
Sint32  CDC_ReadFile(Sint32 filtno, Sint32 fid, Sint32 offset);
Sint32  CDC_AbortFile(void);

/* cdc_reg.c */
Uint32  *CDC_GetDataPtr(void);
Sint32  CDC_GetHirqReq(void);
void    CDC_ClrHirqReq(Sint32 bitpat);
Sint32  CDC_GetHirqMsk(void);
void    CDC_SetHirqMsk(Sint32 bitpat);
Uint32  *CDC_GetMpegPtr(void);



/********************************************************************/
/********************************************************************/
/********************************************************************/
/*------------------------------------------------------------------*/
/*------------------------- ?sMPEG�p?[�g?t -------------------------*/
/*------------------------------------------------------------------*/
/********************************************************************/
/********************************************************************/
/********************************************************************/



/*******************************************************************
*       ��?��}�N�?
*******************************************************************/

/* �E�B���h�E�T�C�Y��?��W��?ő�l */
#define CDC_MPNT_NSX    352           /* NTSC��?�w�����T�C�Y(352) */
#define CDC_MPNT_NSY    240           /* NTSC��?�x�����T�C�Y(240) */
#define CDC_MPNT_NPX (CDC_MPNT_NSX-1) /* NTSC��?�w����?��W  (351) */
#define CDC_MPNT_NPY (CDC_MPNT_NSY-1) /* NTSC��?�x����?��W  (239) */

#define CDC_MPNT_HSX (2*CDC_MPNT_NSX) /* NTSC?�?�?ׂw�����T�C�Y(704) */
#define CDC_MPNT_HSY (2*CDC_MPNT_NSY) /* NTSC?�?�?ׂx�����T�C�Y(480) */
#define CDC_MPNT_HPX (CDC_MPNT_HSX-1) /* NTSC?�?�?ׂw����?��W  (703) */
#define CDC_MPNT_HPY (CDC_MPNT_HSY-1) /* NTSC?�?�?ׂx����?��W  (479) */

#define CDC_MPPL_NSX    352           /* PAL ��?�w�����T�C�Y(352) */
#define CDC_MPPL_NSY    288           /* PAL ��?�x�����T�C�Y(288) */
#define CDC_MPPL_NPX (CDC_MPPL_NSX-1) /* PAL ��?�w����?��W  (351) */
#define CDC_MPPL_NPY (CDC_MPPL_NSY-1) /* PAL ��?�x����?��W  (287) */

#define CDC_MPPL_HSX (2*CDC_MPPL_NSX) /* PAL ?�?�?ׂw�����T�C�Y(704) */
#define CDC_MPPL_HSY (2*CDC_MPPL_NSY) /* PAL ?�?�?ׂx�����T�C�Y(576) */
#define CDC_MPPL_HPX (CDC_MPPL_HSX-1) /* PAL ?�?�?ׂw����?��W  (703) */
#define CDC_MPPL_HPY (CDC_MPPL_HSY-1) /* PAL ?�?�?ׂx����?��W  (575) */

/* MPEG/Video��?�?��?iMPEG��?�X�e?[�^�X��bit0?`2?j */
#define CDC_MPASTV_STOP     0x01    /* ��~ */
#define CDC_MPASTV_PRE1     0x02    /* ?����P */
#define CDC_MPASTV_PRE2     0x03    /* ?����Q */
#define CDC_MPASTV_TRNS     0x04    /* �]��?i?�?�?j */
#define CDC_MPASTV_CHG      0x05    /* ?؂�ւ� */
#define CDC_MPASTV_RCV      0x06    /* ����?��? */

/* MPEG�f�R?[�h?��?iMPEG��?�X�e?[�^�X��bit3?j */
#define CDC_MPASTD_STOP     0x08    /* MPEG�f�R?[�h��~ */

/* MPEG/Audio��?�?��?iMPEG��?�X�e?[�^�X��bit4?`6?j */
#define CDC_MPASTA_STOP     0x10    /* ��~ */
#define CDC_MPASTA_PRE1     0x20    /* ?����P */
#define CDC_MPASTA_PRE2     0x30    /* ?����Q */
#define CDC_MPASTA_TRNS     0x40    /* �]��?i?�?�?j */
#define CDC_MPASTA_CHG      0x50    /* ?؂�ւ� */
#define CDC_MPASTA_RCV      0x60    /* ����?��? */

/* MPEG/Audio�X�e?[�^�X */
#define CDC_MPSTA_DEC       0x01    /* �I?[�f�B�I�f�R?[�h��?�t���O */
#define CDC_MPSTA_ILG       0x08    /* �I?[�f�B�I�C��?[�K���t���O */
#define CDC_MPSTA_BEMPTY    0x10    /* �I?[�f�B�I�p�o�b�t�@����t���O */
#define CDC_MPSTA_ERR       0x20    /* �I?[�f�B�I�G��?[�t���O */
#define CDC_MPSTA_OUTL      0x40    /* ?��`�����l��?o�̓t���O */
#define CDC_MPSTA_OUTR      0x80    /* �E�`�����l��?o�̓t���O */

/* MPEG/Video�X�e?[�^�X */
#define CDC_MPSTV_DEC       0x0001  /* �r�f�I�f�R?[�h��?�t���O */
#define CDC_MPSTV_DISP      0x0002  /* �\���t���O */
#define CDC_MPSTV_PAUSE     0x0004  /* �|?[�Y�t���O */
#define CDC_MPSTV_FREEZE    0x0008  /* �t��?[�Y�t���O */
#define CDC_MPSTV_LSTPIC    0x0010  /* ?Ō�s�N�`���\���t���O */
#define CDC_MPSTV_FIELD     0x0020  /* ��?��t�B?[���h�t���O */
#define CDC_MPSTV_UPDPIC    0x0040  /* �s�N�`��?X?V�t���O */
#define CDC_MPSTV_ERR       0x0080  /* �r�f�I�G��?[�t���O */
#define CDC_MPSTV_RDY       0x0100  /* ?o��?��������t���O */
#define CDC_MPSTV_1STPIC    0x0800  /* ?擪�s�N�`���\���t���O */
#define CDC_MPSTV_BEMPTY    0x1000  /* �r�f�I�p�o�b�t�@����t���O */

/* MPEG����?��ݗv�� */
#define CDC_MPINT_VSRDY  0x00000001 /* �r�f�I�X�g��?[��?������� */
#define CDC_MPINT_VSCHG  0x00000002 /* �r�f�I�X�g��?[��?؂�ւ����� */
#define CDC_MPINT_VORDY  0x00000004 /* �r�f�I?o��?������� */
#define CDC_MPINT_VOSTRT 0x00000008 /* �r�f�I?o�͊J�n */
#define CDC_MPINT_VDERR  0x00000010 /* �r�f�I�f�R?[�h�G��?[ */
#define CDC_MPINT_VSERR  0x00000020 /* �r�f�I�X�g��?[���f?[�^�G��?[ */
#define CDC_MPINT_VBERR  0x00000040 /* �r�f�I�o�b�t�@���?ڑ��G��?[ */
#define CDC_MPINT_VNERR  0x00000080 /* �������޵��ذт̃f?[�^�G��?[ */
#define CDC_MPINT_PSTRT  0x00000100 /* �s�N�`���X�^?[�g��?o */
#define CDC_MPINT_GSTRT  0x00000200 /* GOP�X�^?[�g��?o */
#define CDC_MPINT_SQEND  0x00000400 /* �V?[�P���X�G���h��?o */
#define CDC_MPINT_SQSTRT 0x00000800 /* �V?[�P���X�X�^?[�g��?o */
#define CDC_MPINT_VTRG   0x00001000 /* �r�f�I�Z�N�^�̃g���K�r�b�g��?o */
#define CDC_MPINT_VEOR   0x00002000 /* �r�f�I�Z�N�^��EOR�r�b�g��?o */
#define CDC_MPINT_ATRG   0x00004000 /* �I?[�f�B�I�Z�N�^���ض��ޯČ�?o */
#define CDC_MPINT_AEOR   0x00008000 /* �I?[�f�B�I�Z�N�^��EOR�r�b�g��?o */
#define CDC_MPINT_ASRDY  0x00010000 /* �I?[�f�B�I�X�g��?[��?������� */
#define CDC_MPINT_ASCHG  0x00020000 /* �I?[�f�B�I�X�g��?[��?؂�ւ����� */
#define CDC_MPINT_AORDY  0x00040000 /* �I?[�f�B�I?o��?������� */
#define CDC_MPINT_AOSTRT 0x00080000 /* �I?[�f�B�I?o�͊J�n */
#define CDC_MPINT_ADERR  0x00100000 /* �I?[�f�B�I�f�R?[�h�G��?[ */
#define CDC_MPINT_ASERR  0x00200000 /* �I?[�f�B�I�X�g��?[���f?[�^�G��?[ */
#define CDC_MPINT_ABERR  0x00400000 /* �I?[�f�B�I�o�b�t�@���?ڑ��G��?[ */
#define CDC_MPINT_ANERR  0x00800000 /* �������ި���ذт̃f?[�^�G��?[ */

/* ?ڑ���?[�h?iMPEG�f�R?[�_?ڑ�?�p���??[�^��?j */
#define CDC_MPCMOD_EOR      0x01    /* EOR�r�b�g��?؂�ւ��� */
#define CDC_MPCMOD_SEC      0x02    /* �V�X�e���G���h(SEC)��?؂�ւ��� */
#define CDC_MPCMOD_DEL      0x04    /* �Z�N�^��?��� */
#define CDC_MPCMOD_IGPTS    0x08    /* PTS���ʂ����Ȃ� */
#define CDC_MPCMOD_VCLR     0x10    /* VBV�̃N���A */
#define CDC_MPCMOD_VWCLR    0x20    /* VBV+WBC�̃N���A */
#define CDC_MPCMOD_BEF      0x40    /* ���?i��̑O��?I��?��?���� */

/* ���C���w��?iMPEG�f�R?[�_?ڑ�?�p���??[�^��?j */
#define CDC_MPLAY_SYS       0x00    /* �V�X�e�����C�� */
#define CDC_MPLAY_AUDIO     0x01    /* �I?[�f�B�I���C�� */
#define CDC_MPLAY_VIDEO     0x01    /* �r�f�I���C�� */

/* MPEG/Video�̃s�N�`���T?[�`�w��?iMPEG�f�R?[�_?ڑ�?�p���??[�^��?j */
#define CDC_MPSRCH_OFF      0x00    /* �s�N�`���T?[�`�����Ȃ� */
#define CDC_MPSRCH_VIDEO    0x80    /* �s�N�`���T?[�`������ */
#define CDC_MPSRCH_AV       0xc0    /* �߸�������?��킹���ި��ް���j�� */

/* �X�g��?[����?[�h?iMPEG�X�g��?[���p���??[�^��?j */
#define CDC_MPSMOD_SNSET    0x01    /* �X�g��?[����?���?ݒ��?s�� */
#define CDC_MPSMOD_SNIDF    0x02    /* �X�g��?[����?������ʂ��� */
#define CDC_MPSMOD_CNSET    0x10    /* �`���l����?���?ݒ��?s�� */
#define CDC_MPSMOD_CNIDF    0x20    /* �`���l����?������ʂ��� */

/* ��ԃ�?[�h?i��ʓ�����ʃp���??[�^��?j */
#define CDC_MPITP_YH        0x01    /* �x��?�����Ԃ����� */
#define CDC_MPITP_CH        0x02    /* �b��?�����Ԃ����� */
#define CDC_MPITP_YV        0x04    /* �x��?�����Ԃ����� */
#define CDC_MPITP_CV        0x08    /* �b��?�����Ԃ����� */

/* �����r�b�g��?[�h?i��ʓ�����ʃp���??[�^��?j */
#define CDC_MPTRP_DFL       0x00    /* ��?�?i�����r�b�g?��?�����Ȃ�?j */
#define CDC_MPTRP_64        0x01    /* �P�x64 */
#define CDC_MPTRP_128       0x02    /* �P�x128 */
#define CDC_MPTRP_256       0x03    /* �P�x256 */
#define CDC_MPTRP_MAG       0x04    /* �����̈�̊g������� */

/* �ڂ�����?[�h?i��ʓ�����ʃp���??[�^��?j */
#define CDC_MPSOFT_ON       0x01    /* �ڂ����������� */

/* MPEG/Audio�̃~��?[�g */
#define CDC_MPMUT_DFL       0x04    /* ?ȗ��l?i�~��?[�g���Ȃ�?j */
#define CDC_MPMUT_R         0x01    /* �E�`�����l���̃~��?[�g������ */
#define CDC_MPMUT_L         0x02    /* ?��`�����l���̃~��?[�g������ */

/*******************************************************************
*       �񋓒�?�
*******************************************************************/

/* �G��?[�R?[�h */
enum CdcMpErrCode {
    CDC_ERR_MP_COMU = -20   /* MPCM�t���O���P�ɂȂ��Ă��Ȃ� */
};

/* ���X�g��?[���t���O?i���X�g��?[���Ǝ��X�g��?[���̎w��?j */
enum CdcMpStf {
    CDC_MPSTF_CUR  = 0,     /* ��?݂�?ڑ�?�?^�X�g��?[���̎w��?i?攭?j */
    CDC_MPSTF_NEXT = 1      /* ?@����?ڑ�?�?^�X�g��?[���̎w��?i����?j */
};

/* �s�N�`���^�C�v?i���ʂR�r�b�g���L��?j */
enum CdcMpPict {
    CDC_MPPICT_I = 0x01,    /* �h�s�N�`�� */
    CDC_MPPICT_P = 0x02,    /* �o�s�N�`�� */
    CDC_MPPICT_B = 0x03,    /* �a�s�N�`�� */
    CDC_MPPICT_D = 0x04     /* �c�s�N�`�� */
};

/* MPEG��?샂?[�h */
enum CdcMpAct {
    CDC_MPACT_NMOV = 0,     /* ����?�?���?[�h */
    CDC_MPACT_NSTL = 1,     /* ?Î~��?�?���?[�h */
    CDC_MPACT_HMOV = 2,     /* ?�?�?ׂ̓���?�?���?[�h?i���Ή�?j */
    CDC_MPACT_HSTL = 3,     /* ?�?�?ׂ�?Î~��?�?���?[�h */
    CDC_MPACT_SBUF = 4      /* MPEG�Z�N�^�o�b�t�@��?[�h */
};

/* �f�R?[�h�^�C�~���O */
enum CdcMpDec {
    CDC_MPDEC_VSYNC = 0,    /* VSYNC�����ɂ��f�R?[�h */
    CDC_MPDEC_HOST  = 1     /* �z�X�g�����ɂ��f�R?[�h */
};

/* �摜�f?[�^��?o��?� */
enum CdcMpOut {
    CDC_MPOUT_VDP2 = 0,     /* VDP2��?o�� */
    CDC_MPOUT_HOST = 1      /* �z�X�g��?o�� */
};

/* MPEG?�?���?[�h */
enum CdcMpPly {
    CDC_MPPLY_SYNC = 0,     /* ����?�?���?[�h */
    CDC_MPPLY_INDP = 1      /* �Ɨ�?�?���?[�h */
};

/* MPEG�f�R?[�_�̓]����?[�h */
enum CdcMpTrn {
    CDC_MPTRN_AUTO  = 0,    /* �����]����?[�h */
    CDC_MPTRN_FORCE = 1     /* ��?��]����?[�h */
};

/* MPEG�f�R?[�_��?ڑ�?؂�ւ��t���O */
enum CdcMpCof {
    CDC_MPCOF_ABT = 0,      /* ?؂藣��?i��?�?I��?j */
    CDC_MPCOF_CHG = 1       /* ��?�?؂�ւ� */
};

/* MPEG/Audio�̃N���A���� */
enum CdcMpCla {
    CDC_MPCLA_OFF = 0,      /* �N���A���Ȃ� */
    CDC_MPCLA_ON  = 1       /* ��?��ɂP�Z�N�^�̃o�b�t�@���N���A���� */
};

/* MPEG/Video�̃N���A���� */
enum CdcMpClv {
    CDC_MPCLV_FRM = 0,      /* ��?���VBV��MPEG�ڰ��ޯ̧���N���A���� */
    CDC_MPCLV_VBV = 2       /* ����I�܂���P�߸�����Ă�VBV���N���A���� */
};

/*******************************************************************
*       ?\���̃A�N�Z�X?��?�}�N�?
*******************************************************************/

/* MPEG�X�e?[�^�X?�� */
#define CDC_MPSTAT_STS(mpstat)      ((mpstat)->status)
#define CDC_MPSTAT_AST(mpstat)      ((mpstat)->report.actst)
#define CDC_MPSTAT_PICT(mpstat)     ((mpstat)->report.pict)
#define CDC_MPSTAT_STA(mpstat)      ((mpstat)->report.stat_a)
#define CDC_MPSTAT_STV(mpstat)      ((mpstat)->report.stat_v)
#define CDC_MPSTAT_VCNT(mpstat)     ((mpstat)->report.vcnt)

/* �^�C���R?[�h */
#define CDC_MPTC_HOUR(mptc)         ((mptc)->hour)
#define CDC_MPTC_MIN(mptc)          ((mptc)->min)
#define CDC_MPTC_SEC(mptc)          ((mptc)->sec)
#define CDC_MPTC_PIC(mptc)          ((mptc)->pic)

/* MPEG�f�R?[�_?ڑ�?�p���??[�^ */
#define CDC_MPCON_CMOD(mpcon)       ((mpcon)->cmod)
#define CDC_MPCON_LAY(mpcon)        ((mpcon)->lay)
#define CDC_MPCON_BN(mpcon)         ((mpcon)->bn)

/* MPEG�X�g��?[���p���??[�^ */
#define CDC_MPSTM_SMOD(mpstm)       ((mpstm)->smod)
#define CDC_MPSTM_ID(mpstm)         ((mpstm)->id)
#define CDC_MPSTM_CN(mpstm)         ((mpstm)->cn)

/* ��ʓ�����ʃp���??[�^ */
#define CDC_MPVEF_ITP(mpvef)        ((mpvef)->itp)
#define CDC_MPVEF_TRP(mpvef)        ((mpvef)->trp)
#define CDC_MPVEF_MOZH(mpvef)       ((mpvef)->moz_h)
#define CDC_MPVEF_MOZV(mpvef)       ((mpvef)->moz_v)
#define CDC_MPVEF_SOFTH(mpvef)      ((mpvef)->soft_h)
#define CDC_MPVEF_SOFTV(mpvef)      ((mpvef)->soft_v)

/*******************************************************************
*       ?��?�}�N�?
*******************************************************************/

/* MPEG�X�e?[�^�X?�񂩂�X�e?[�^�X�R?[�h���擾���� */
#define CDC_MPGET_STC(mpstat)   (CDC_MPSTAT_STS(mpstat) & CDC_STC_MSK)

/* MPEG�X�e?[�^�X?�񂩂�MPEG/Video��?�?�Ԃ��擾���� */
#define CDC_MPGET_ASTV(mpstat)   (CDC_MPSTAT_AST(mpstat) & 0x07)

/* MPEG�X�e?[�^�X?�񂩂�MPEG/Audio��?�?�Ԃ��擾���� */
#define CDC_MPGET_ASTA(mpstat)   (CDC_MPSTAT_AST(mpstat) & 0x70)

/*******************************************************************
*       �f?[�^�^��?錾
*******************************************************************/

/* MPEG�X�e?[�^�X?��?i�X�e?[�^�X?{MPEG���|?[�g?j */
typedef struct {
    Uint8   status;         /* �X�e?[�^�X */
    struct {                /* MPEG���|?[�g */
        Uint8   actst;      /* MPEG��?�X�e?[�^�X */
        Uint8   pict;       /* �s�N�`��?�� */
        Uint8   stat_a;     /* MPEG/Audio�X�e?[�^�X */
        Uint16  stat_v;     /* MPEG/Video�X�e?[�^�X */
        Uint16  vcnt;       /* ��?���?iVSYNC?j�J�E���^ */
    } report;
} CdcMpStat;

/* �^�C���R?[�h */
typedef struct {
    Uint8   hour;           /* ���� */
    Uint8   min;            /* �� */
    Uint8   sec;            /* �b */
    Uint8   pic;            /* �s�N�`�� */
} CdcMpTc;

/* MPEG�f�R?[�_?ڑ�?�p���??[�^ */
typedef struct {
    Uint8   cmod;           /* ?ڑ���?[�h */
    Uint8   lay;            /* ���C���w��ƃs�N�`���T?[�`�w�� */
    Uint8   bn;             /* �o�b�t�@����?� */
} CdcMpCon;

/* MPEG�X�g��?[���p���??[�^ */
typedef struct {
    Uint8   smod;           /* �X�g��?[����?[�h */
    Uint8   id;             /* �X�g��?[����?� */
    Uint8   cn;             /* �`���l����?� */
} CdcMpStm;

/* ��ʓ�����ʃp���??[�^ */
typedef struct {
    Uint8   itp;            /* ��ԃ�?[�h */
    Uint8   trp;            /* �����r�b�g��?[�h */
    Uint8   moz_h;          /* ?����������U�C�N��?[�h */
    Uint8   moz_v;          /* ?����������U�C�N��?[�h */
    Uint8   soft_h;         /* ?��������ڂ�����?[�h */
    Uint8   soft_v;         /* ?��������ڂ�����?[�h */
} CdcMpVef;

/*******************************************************************
*       ��?�?錾
*******************************************************************/

/*******************************************************************
*       ��?�?錾
*******************************************************************/

/* cdc_mdc.c */
Sint32  CDC_MpGetCurStat(CdcMpStat *mpstat);
Sint32  CDC_MpGetLastStat(CdcMpStat *mpstat);
Sint32  CDC_MpGetInt(Sint32 *intreq);
Sint32  CDC_MpSetIntMsk(Sint32 intmsk);
Sint32  CDC_MpInit(Bool sw);
Sint32  CDC_MpSetMode(Sint32 actmod, Sint32 dectim, Sint32 out,
                      Sint32 scnmod);
Sint32  CDC_MpPlay(Sint32 plymod, Sint32 tmod_a, Sint32 tmod_v,
                   Sint32 dec_v);
Sint32  CDC_MpSetDec(Sint32 mute, Sint32 pautim, Sint32 frztim);
Sint32  CDC_MpOutDsync(Sint32 fbn);
Sint32  CDC_MpGetTc(Sint32 *bnk, Sint32 *pictyp, Sint32 *tr, CdcMpTc *mptc);
Sint32  CDC_MpGetPts(Sint32 *pts_a);

/* cdc_mst.c */
Sint32  CDC_MpSetCon(Sint32 next, CdcMpCon *mpcon_a, CdcMpCon *mpcon_v);
Sint32  CDC_MpGetCon(Sint32 next, CdcMpCon *mpcon_a, CdcMpCon *mpcon_v);
Sint32  CDC_MpChgCon(Sint32 chg_a, Sint32 chg_v,
                     Sint32 clr_a, Sint32 clr_v);
Sint32  CDC_MpSetStm(Sint32 next, CdcMpStm *mpstm_a, CdcMpStm *mpstm_v);
Sint32  CDC_MpGetStm(Sint32 next, CdcMpStm *mpstm_a, CdcMpStm *mpstm_v);
Sint32  CDC_MpGetPictSiz(Sint32 *siz_h, Sint32 *siz_v);

/* cdc_mwn.c */
Sint32  CDC_MpDisp(Bool dspsw, Sint32 fbn);
Sint32  CDC_MpSetWinFpos(Bool chgflg, Sint32 fpx, Sint32 fpy);
Sint32  CDC_MpSetWinFrat(Bool chgflg, Sint32 frx, Sint32 fry);
Sint32  CDC_MpSetWinDpos(Bool chgflg, Sint32 dpx, Sint32 dpy);
Sint32  CDC_MpSetWinDsiz(Bool chgflg, Sint32 dsx, Sint32 dsy);
Sint32  CDC_MpSetWinDofs(Bool chgflg, Sint32 dox, Sint32 doy);
Sint32  CDC_MpSetBcolor(Sint32 bcolor);
Sint32  CDC_MpSetFade(Sint32 gain_y, Sint32 gain_c);
Sint32  CDC_MpSetVeff(CdcMpVef *mpvef);

/* cdc_mfb.c */
Sint32  CDC_MpGetImg(Sint32 *dwnum);
Sint32  CDC_MpSetImgPos(Sint32 fbn, Sint32 ipx, Sint32 ipy);
Sint32  CDC_MpSetImgSiz(Sint32 fbn, Sint32 isx, Sint32 isy);
Sint32  CDC_MpReadImg(Sint32 srcfbn,
                      Sint32 fln_y, Sint32 fln_cr, Sint32 fln_cb);
Sint32  CDC_MpWriteImg(Sint32 bn_y, Sint32 bn_cr, Sint32 bn_cb,
                       Sint32 dstfbn, Sint32 clrmod);

/* cdc_mbu.c */
Sint32  CDC_MpReadSct(Sint32 srcmsp, Sint32 snum, Sint32 dstfln);
Sint32  CDC_MpWriteSct(Sint32 srcbn, Sint32 sp, Sint32 snum,
                       Sint32 dstmsp);

/* cdc_mls.c */
/* �?��?F�ȉ��̊�?��͔���J�Ƃ��� */
Sint32  CDC_MpGetLsi(Sint32 r_sw, Sint32 reg_no, Sint32 *rdata);
Sint32  CDC_MpSetLsi(Sint32 rwsw, Sint32 reg_no, Sint32 wdata,
                     Sint32 *rdata);

#endif  /* ifndef SEGA_CDC_H */