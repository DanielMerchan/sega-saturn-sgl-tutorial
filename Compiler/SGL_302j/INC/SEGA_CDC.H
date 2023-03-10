/*
 *     ソフトウェアライブラリ
 *
 *     Copyright (c) 1994 SEGA
 *
 *  Library: ＣＤ通?Mインタフェ?[ス?iCDC?j
 *  Module : CDCライブラリ用ヘッダファイル
 *  File   : sega_cdc.h
 *  Date   : 1995-03-31
 *  Version: 1.20
 *  Author : M.M.
 *
 */

/* 多?dインクル?[ドへの対応 */
#ifndef SEGA_CDC_H
#define SEGA_CDC_H

/*******************************************************************
*       インクル?[ドファイル
*******************************************************************/
#include    "sega_xpt.h"

/*******************************************************************
*       定?買}ク??
*******************************************************************/

/* 割り?桙ﾝ要因レジスタ関係?iHIRQREQ, HIRQMSK?jのビット名 */
#define CDC_HIRQ_CMOK   0x0001  /* bit0 ?Fコマンド発?s可能 */
#define CDC_HIRQ_DRDY   0x0002  /* bit1 ?Fデ?[タ転送??備完了 */
#define CDC_HIRQ_CSCT   0x0004  /* bit2 ?F１セクタ読み?桙ﾝ完了 */
#define CDC_HIRQ_BFUL   0x0008  /* bit3 ?FＣＤバッファフル */
#define CDC_HIRQ_PEND   0x0010  /* bit4 ?FＣＤ?ﾄ?ｶの?I了 */
#define CDC_HIRQ_DCHG   0x0020  /* bit5 ?Fディスク交換の発?ｶ */
#define CDC_HIRQ_ESEL   0x0040  /* bit6 ?Fセレクタ?ﾝ定????の?I了 */
#define CDC_HIRQ_EHST   0x0080  /* bit7 ?Fホスト入?o力????の?I了 */
#define CDC_HIRQ_ECPY   0x0100  /* bit8 ?F複写?^移動????の?I了 */
#define CDC_HIRQ_EFLS   0x0200  /* bit9 ?Fファイルシステム????の?I了 */
#define CDC_HIRQ_SCDQ   0x0400  /* bit10?Fサブコ?[ドＱの?v?X?V完了 */
#define CDC_HIRQ_MPED   0x0800  /* bit11?FMPEG関連????の?I了 */
#define CDC_HIRQ_MPCM   0x1000  /* bit12?FMPEG動??不定区間の?I了 */
#define CDC_HIRQ_MPST   0x2000  /* bit13?FMPEG割り?桙ﾝステ?[タスの通知 */
    
/* バッファ区画のセクタ範囲?iセクタ位置とセクタ???jの特殊指定 */
/* ?iいずれも下位16ビットが有効で?A内部的には0xffffと同値?j */
#define CDC_SPOS_END    -1  /* 区画?ﾅ後のセクタ位置を示す */
#define CDC_SNUM_END    -1  /* 指定ｾｸﾀ位置から区画?ﾅ後までのｾｸﾀ?狽?示す */

/* その他の特殊指定 */
#define CDC_PARA_DFL    0       /* パラ???[タの?ﾈ略値指定 */
#define CDC_PARA_NOCHG  -1      /* パラ???[タの未変?X指定 */
#define CDC_NUL_SEL     0xff    /* セレクタ番??の特殊値 */
#define CDC_NUL_FID     -1      /* ファイル識別子の特殊値 (0xffffff) */

/* ＣＤフラグ */
#define CDC_CDFLG_ROM   0x80    /* CD-ROMデコ?[ド中 */

/* ハ?[ドウェアフラグ?iハ?[ドウェア??報内?j */
#define CDC_HFLAG_MPEG  0x02    /* MPEGあり */
#define CDC_HFLAG_HERR  0x80    /* ハ?[ドウェアエラ?[発?ｶ */

/* ?ﾄ?ｶモ?[ド?iＣＤ?ﾄ?ｶパラ???[タ内?j */
#define CDC_PM_DFL          0x00    /* ?ﾄ?ｶモ?[ドの?ﾈ略値 */
#define CDC_PM_REP_NOCHG    0x7f    /* ?ﾅ大リピ?[ト回?狽?変?Xしない */
#define CDC_PM_PIC_NOCHG    0x80    /* ピックアップ位置を変?Xしない */
#define CDC_PM_NOCHG        -1      /* ?ﾄ?ｶモ?[ドを変?Xしない (0xff) */

/* サブモ?[ド */
#define CDC_SM_EOR      0x01    /* レコ?[ド?ﾅ後のセクタ */
#define CDC_SM_VIDEO    0x02    /* ビデオセクタ */
#define CDC_SM_AUDIO    0x04    /* オ?[ディオセクタ */
#define CDC_SM_DATA     0x08    /* デ?[タセクタ */
#define CDC_SM_TRIG     0x10    /* トリガＯＮ */
#define CDC_SM_FORM     0x20    /* フォ?[ムビット?i1:Form2,  0:Form1?j*/
#define CDC_SM_RT       0x40    /* リアルタイムセクタ */
#define CDC_SM_EOF      0x80    /* ファイル?ﾅ後のセクタ */

/* ファイルアトリビュ?[ト?iファイル??報内?j */
#define CDC_ATR_DIRFG   0x02    /* ディレクトリである */
#define CDC_ATR_FORM1   0x08    /* Form1セクタを含む */
#define CDC_ATR_FORM2   0x10    /* Form2セクタを含む */
#define CDC_ATR_INTLV   0x20    /* インタリ?[ブセクタを含む */
#define CDC_ATR_CDDA    0x40    /* CD-DAファイル */
#define CDC_ATR_DIRXA   0x80    /* ディレクトリファイル */

/* スタンバイタイム */
#define CDC_STNBY_MIN   60      /* ?ﾅ?ｬ値 */
#define CDC_STNBY_MAX   900     /* ?ﾅ大値 */

/* サブコ?[ドフラグ */
#define CDC_SCD_PACK    0x01    /* パックデ?[タエラ?[ */
#define CDC_SCD_OVER    0x02    /* オ?[バ?[ランエラ?[ */

/* ＣＤブ??ックの転送???[ド?? */
#define CDC_DEND_ERR    0xffffff    /* デ?[タ転送でエラ?[が発?ｶ */

/* 実デ?[タサイズ */
#define CDC_ACTSIZ_ERR  0xffffff    /* 計算を実?sできなかった */

/* フレ?[ムアドレス検??結果?iセクタ位置とフレ?[ムアドレス?j */
#define CDC_SPOS_ERR    0xffff      /* 検??でエラ?[が発?ｶ */
#define CDC_FAD_ERR     0xffffff    /* 検??を実?sできなかった */

/* マスクビットパタ?[ン */
#define CDC_STC_MSK     0x0f    /* ステ?[タスコ?[ド */

/*******************************************************************
*       列挙定??
*******************************************************************/

/* エラ?[コ?[ド */
enum CdcErrCode {
    CDC_ERR_OK = OK,    /* 関?狽ｪ?ｳ???I了した */

    CDC_ERR_CMDBUSY=-1, /* コマンド?I了フラグが１になっていない */
    CDC_ERR_CMDNG  =-2, /* コマンド発?s時?ACMOKフラグが１になっていない */
    CDC_ERR_TMOUT  =-3, /* タイムアウト?iﾚｽﾎﾟﾝｽ待ち?Aﾃﾞｰﾀ転送??備待ち?j*/
    CDC_ERR_PUT    =-4, /* ?曹ｫ?桙ﾝ??備で空きセクタを確保できなかった */
    CDC_ERR_REJECT =-5, /* コマンドに対するレスポンスがREJECTとなった */
    CDC_ERR_WAIT   =-6, /* コマンドに対するレスポンスがWAITとなった */
    CDC_ERR_TRNS   =-7, /* デ?[タ転送サイズが異??である */
    CDC_ERR_PERI   =-8  /* 定期レスポンスを取得できなかった */
};

/* ステ?[タス */
enum CdcStatus {
    /* ステ?[タスコ?[ド?iＣＤドライブ??態?j */
    CDC_ST_BUSY     = 0x00,     /* ??態遷移中 */
    CDC_ST_PAUSE    = 0x01,     /* ポ?[ズ中?i一時停止?j */
    CDC_ST_STANDBY  = 0x02,     /* スタンバイ?iドライブ停止??態?j */
    CDC_ST_PLAY     = 0x03,     /* ＣＤ?ﾄ?ｶ中 */
    CDC_ST_SEEK     = 0x04,     /* シ?[ク中 */
    CDC_ST_SCAN     = 0x05,     /* スキャン?ﾄ?ｶ中 */
    CDC_ST_OPEN     = 0x06,     /* トレイが開いている */
    CDC_ST_NODISC   = 0x07,     /* ディスクがない */
    CDC_ST_RETRY    = 0x08,     /* リ?[ドリトライ????中 */
    CDC_ST_ERROR    = 0x09,     /* リ?[ドデ?[タエラ?[が発?ｶした */
    CDC_ST_FATAL    = 0x0a,     /* 致命的エラ?[が発?ｶした */

    /* その他 */
    CDC_ST_PERI     = 0x20,     /* 定期レスポンス */
    CDC_ST_TRNS     = 0x40,     /* デ?[タ転送要??あり */
    CDC_ST_WAIT     = 0x80,     /* WAIT */
    CDC_ST_REJECT   = 0xff      /* REJECT */
};

/* 位置タイプ?i?ﾄ?ｶ?Aシ?[ク時におけるＣＤ位置パラ???[タで指定?j */
enum CdcPosType {
    CDC_PTYPE_DFL,          /* ?ﾈ略値の指定 */
    CDC_PTYPE_FAD,          /* フレ?[ムアドレス指定 */
    CDC_PTYPE_TNO,          /* トラック?^インデックス指定 */
    CDC_PTYPE_NOCHG,        /* 未変?Xの指定?i?ﾝ定値を変?Xしない?j */

    CDC_PTYPE_END
};

/* 転送??備待ちタイプ?iデ?[タ転送の??備待ちで指定?j */
enum CdcDrdyType {
    CDC_DRDY_GET,           /* デ?[タを取り?oす?iCDﾌﾞﾛｯｸ?ｨﾎｽﾄ?j */
    CDC_DRDY_PUT,           /* デ?[タを?曹ｫ?桙ﾞ?iﾎｽﾄ?ｨCDﾌﾞﾛｯｸ?j */

    CDC_DRDY_END
};

/* スキャン方向 */
enum CdcScanDir {
    CDC_SCAN_FWD = 0x00,    /* ??送り?ﾄ?ｶ */
    CDC_SCAN_RVS = 0x01     /* ??戻し?ﾄ?ｶ */
};

/* セクタ長 */
enum CdcSctLen {
    CDC_SLEN_2048  = 0,     /* 2048バイトと2324バイト?iユ?[ザデ?[タ?j*/
    CDC_SLEN_2336  = 1,     /* 2336バイト?iサブヘッダまで?j*/
    CDC_SLEN_2340  = 2,     /* 2340バイト?iヘッダまで?j*/
    CDC_SLEN_2352  = 3,     /* 2352バイト?iセクタ全体?j*/
    CDC_SLEN_NOCHG = -1     /* ?ﾝ定を変?Xしない (0xff) */
};

/* 複写?^移動エラ?[??報 */
enum CdcCopyErr {
    CDC_COPY_OK   = 0,      /* ?ｳ???I了 */
    CDC_COPY_NG   = 1,      /* エラ?[発?ｶ */
    CDC_COPY_BUSY = 0xff    /* 複写?^移動????中 */
};

/*******************************************************************
*       ?\造体アクセス????マク??
*******************************************************************/

/* ＣＤステ?[タス??報 */
#define CDC_STAT_STATUS(stat)       ((stat)->status)
#define CDC_STAT_FLGREP(stat)       ((stat)->report.flgrep)
#define CDC_STAT_CTLADR(stat)       ((stat)->report.ctladr)
#define CDC_STAT_TNO(stat)          ((stat)->report.tno)
#define CDC_STAT_IDX(stat)          ((stat)->report.idx)
#define CDC_STAT_FAD(stat)          ((stat)->report.fad)

/* ハ?[ドウェア??報 */
#define CDC_HW_HFLAG(hw)            ((hw)->hflag)
#define CDC_HW_VER(hw)              ((hw)->ver)
#define CDC_HW_MPVER(hw)            ((hw)->mpver)
#define CDC_HW_DRV(hw)              ((hw)->drv)
#define CDC_HW_REV(hw)              ((hw)->rev)

/* ＣＤ位置パラ???[タ */
#define CDC_POS_PTYPE(pos)          ((pos)->ptype)
#define CDC_POS_FAD(pos)            ((pos)->pbody.fad)
#define CDC_POS_TNO(pos)            ((pos)->pbody.trkidx.tno)
#define CDC_POS_IDX(pos)            ((pos)->pbody.trkidx.idx)

/* ＣＤ?ﾄ?ｶパラ???[タ */
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

/* サブヘッダ???? */
#define CDC_SUBH_FN(subh)           ((subh)->fn)
#define CDC_SUBH_CN(subh)           ((subh)->cn)
#define CDC_SUBH_SMMSK(subh)        ((subh)->smmsk)
#define CDC_SUBH_SMVAL(subh)        ((subh)->smval)
#define CDC_SUBH_CIMSK(subh)        ((subh)->cimsk)
#define CDC_SUBH_CIVAL(subh)        ((subh)->cival)

/* セクタ??報 */
#define CDC_SCT_FAD(sct)            ((sct)->fad)
#define CDC_SCT_FN(sct)             ((sct)->fn)
#define CDC_SCT_CN(sct)             ((sct)->cn)
#define CDC_SCT_SM(sct)             ((sct)->sm)
#define CDC_SCT_CI(sct)             ((sct)->ci)

/* ファイル??報 */
#define CDC_FILE_FAD(file)          ((file)->fad)
#define CDC_FILE_SIZE(file)         ((file)->size)
#define CDC_FILE_UNIT(file)         ((file)->unit)
#define CDC_FILE_GAP(file)          ((file)->gap)
#define CDC_FILE_FN(file)           ((file)->fn)
#define CDC_FILE_ATR(file)          ((file)->atr)

/*******************************************************************
*       ????マク??
*******************************************************************/

/* ＣＤステ?[タス??報からステ?[タスコ?[ドを取得 */
#define CDC_GET_STC(stat)       (CDC_STAT_STATUS(stat) & CDC_STC_MSK)

/* ＣＤステ?[タス??報からリピ?[ト回?狽?取得 */
#define CDC_GET_REPEAT(stat)    (CDC_STAT_FLGREP(stat) & 0x0f)

/* MPEGが使用可能か調べる?iTRUE?F使用可能?AFALSE?F使用不可?j */
/* ??意?Fこのマク??はマニュアルに記?qしない */
#define CDC_IS_MPEG_ENA(hw)     (CDC_HW_MPVER(hw) != 0)

/*******************************************************************
*       デ?[タ型の?骭ｾ
*******************************************************************/

/* ＣＤステ?[タス??報?iステ?[タス?{ＣＤレポ?[ト?j */
typedef struct {
    Uint8   status;         /* ステ?[タス */
    struct {                /* ＣＤレポ?[ト */
        Uint8   flgrep;     /* ＣＤフラグとリピ?[ト回?? */
        Uint8   ctladr;     /* CONTROL/ADRバイト */
        Uint8   tno;        /* トラック番?? */
        Uint8   idx;        /* インデックス番?? */
        Sint32  fad;        /* フレ?[ムアドレス */
    } report;
} CdcStat;

/* ハ?[ドウェア??報 */
typedef struct {
    Uint8   hflag;          /* ハ?[ドウェアフラグ */
    Uint8   ver;            /* ＣＤブ??ックのバ?[ジョン??報 */
    Uint8   mpver;          /* MPEGのバ?[ジョン??報 */
    Uint8   drv;            /* ＣＤドライブ??報 */
    Uint8   rev;            /* ＣＤブ??ックのリビジョン??報 */
} CdcHw;

/* ＣＤ位置パラ???[タ */
typedef struct {
    Sint32 ptype;           /* 位置タイプ?i位置パラ???[タの種類の指定?j*/
    union {
        Sint32 fad;         /* フレ?[ムアドレス?Aセクタ?? */
        struct {
            Uint8 tno;      /* トラック番?? */
            Uint8 idx;      /* インデックス番?? */
        } trkidx;
    } pbody;
} CdcPos;

/* ＣＤ?ﾄ?ｶパラ???[タ */
typedef struct {
    CdcPos  start;          /* 開始位置 */
    CdcPos  end;            /* ?I了位置 */
    Uint8   pmode;          /* ?ﾄ?ｶモ?[ド?iﾋﾟｯｸｱｯﾌﾟ移動?A繰り返し回???j*/
} CdcPly;

/* サブヘッダ???? */
typedef struct {
    Uint8   fn;             /* ファイル番?? */
    Uint8   cn;             /* チャネル番?? */
    Uint8   smmsk;          /* サブモ?[ドのマスクパタ?[ン */
    Uint8   smval;          /* サブモ?[ドの比較値 */
    Uint8   cimsk;          /* コ?[ディング??報のマスクパタ?[ン */
    Uint8   cival;          /* コ?[ディング??報の比較値 */
} CdcSubh;

/* セクタ??報 */
typedef struct {
    Sint32  fad;            /* フレ?[ムアドレス */
    Uint8   fn;             /* ファイル番?? */
    Uint8   cn;             /* チャネル番?? */
    Uint8   sm;             /* サブモ?[ド */
    Uint8   ci;             /* コ?[ディング??報 */
} CdcSct;

/* ファイル??報 */
typedef struct {
    Sint32  fad;            /* ファイル?謫ｪフレ?[ムアドレス */
    Sint32  size;           /* ファイルサイズ?iバイト???j */
    Uint8   unit;           /* ファイルユニットサイズ */
    Uint8   gap;            /* ギャップサイズ */
    Uint8   fn;             /* ファイル番?? */
    Uint8   atr;            /* ファイルアトリビュ?[ト */
} CdcFile;

/*******************************************************************
*       変???骭ｾ
*******************************************************************/

/*******************************************************************
*       関???骭ｾ
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
/*------------------------- ?sMPEGパ?[ト?t -------------------------*/
/*------------------------------------------------------------------*/
/********************************************************************/
/********************************************************************/
/********************************************************************/



/*******************************************************************
*       定?買}ク??
*******************************************************************/

/* ウィンドウサイズと?ﾀ標の?ﾅ大値 */
#define CDC_MPNT_NSX    352           /* NTSC通??Ｘ方向サイズ(352) */
#define CDC_MPNT_NSY    240           /* NTSC通??Ｙ方向サイズ(240) */
#define CDC_MPNT_NPX (CDC_MPNT_NSX-1) /* NTSC通??Ｘ方向?ﾀ標  (351) */
#define CDC_MPNT_NPY (CDC_MPNT_NSY-1) /* NTSC通??Ｙ方向?ﾀ標  (239) */

#define CDC_MPNT_HSX (2*CDC_MPNT_NSX) /* NTSC???ｸ?ﾗＸ方向サイズ(704) */
#define CDC_MPNT_HSY (2*CDC_MPNT_NSY) /* NTSC???ｸ?ﾗＹ方向サイズ(480) */
#define CDC_MPNT_HPX (CDC_MPNT_HSX-1) /* NTSC???ｸ?ﾗＸ方向?ﾀ標  (703) */
#define CDC_MPNT_HPY (CDC_MPNT_HSY-1) /* NTSC???ｸ?ﾗＹ方向?ﾀ標  (479) */

#define CDC_MPPL_NSX    352           /* PAL 通??Ｘ方向サイズ(352) */
#define CDC_MPPL_NSY    288           /* PAL 通??Ｙ方向サイズ(288) */
#define CDC_MPPL_NPX (CDC_MPPL_NSX-1) /* PAL 通??Ｘ方向?ﾀ標  (351) */
#define CDC_MPPL_NPY (CDC_MPPL_NSY-1) /* PAL 通??Ｙ方向?ﾀ標  (287) */

#define CDC_MPPL_HSX (2*CDC_MPPL_NSX) /* PAL ???ｸ?ﾗＸ方向サイズ(704) */
#define CDC_MPPL_HSY (2*CDC_MPPL_NSY) /* PAL ???ｸ?ﾗＹ方向サイズ(576) */
#define CDC_MPPL_HPX (CDC_MPPL_HSX-1) /* PAL ???ｸ?ﾗＸ方向?ﾀ標  (703) */
#define CDC_MPPL_HPY (CDC_MPPL_HSY-1) /* PAL ???ｸ?ﾗＹ方向?ﾀ標  (575) */

/* MPEG/Video動????態?iMPEG動??ステ?[タスのbit0?`2?j */
#define CDC_MPASTV_STOP     0x01    /* 停止 */
#define CDC_MPASTV_PRE1     0x02    /* ??備１ */
#define CDC_MPASTV_PRE2     0x03    /* ??備２ */
#define CDC_MPASTV_TRNS     0x04    /* 転送?i?ﾄ?ｶ?j */
#define CDC_MPASTV_CHG      0x05    /* ?ﾘり替え */
#define CDC_MPASTV_RCV      0x06    /* 復活???? */

/* MPEGデコ?[ド??態?iMPEG動??ステ?[タスのbit3?j */
#define CDC_MPASTD_STOP     0x08    /* MPEGデコ?[ド停止 */

/* MPEG/Audio動????態?iMPEG動??ステ?[タスのbit4?`6?j */
#define CDC_MPASTA_STOP     0x10    /* 停止 */
#define CDC_MPASTA_PRE1     0x20    /* ??備１ */
#define CDC_MPASTA_PRE2     0x30    /* ??備２ */
#define CDC_MPASTA_TRNS     0x40    /* 転送?i?ﾄ?ｶ?j */
#define CDC_MPASTA_CHG      0x50    /* ?ﾘり替え */
#define CDC_MPASTA_RCV      0x60    /* 復活???? */

/* MPEG/Audioステ?[タス */
#define CDC_MPSTA_DEC       0x01    /* オ?[ディオデコ?[ド動??フラグ */
#define CDC_MPSTA_ILG       0x08    /* オ?[ディオイリ?[ガルフラグ */
#define CDC_MPSTA_BEMPTY    0x10    /* オ?[ディオ用バッファ区画空フラグ */
#define CDC_MPSTA_ERR       0x20    /* オ?[ディオエラ?[フラグ */
#define CDC_MPSTA_OUTL      0x40    /* ?ｶチャンネル?o力フラグ */
#define CDC_MPSTA_OUTR      0x80    /* 右チャンネル?o力フラグ */

/* MPEG/Videoステ?[タス */
#define CDC_MPSTV_DEC       0x0001  /* ビデオデコ?[ド動??フラグ */
#define CDC_MPSTV_DISP      0x0002  /* 表示フラグ */
#define CDC_MPSTV_PAUSE     0x0004  /* ポ?[ズフラグ */
#define CDC_MPSTV_FREEZE    0x0008  /* フリ?[ズフラグ */
#define CDC_MPSTV_LSTPIC    0x0010  /* ?ﾅ後ピクチャ表示フラグ */
#define CDC_MPSTV_FIELD     0x0020  /* 奇?買tィ?[ルドフラグ */
#define CDC_MPSTV_UPDPIC    0x0040  /* ピクチャ?X?Vフラグ */
#define CDC_MPSTV_ERR       0x0080  /* ビデオエラ?[フラグ */
#define CDC_MPSTV_RDY       0x0100  /* ?o力??備完了フラグ */
#define CDC_MPSTV_1STPIC    0x0800  /* ?謫ｪピクチャ表示フラグ */
#define CDC_MPSTV_BEMPTY    0x1000  /* ビデオ用バッファ区画空フラグ */

/* MPEG割り?桙ﾝ要因 */
#define CDC_MPINT_VSRDY  0x00000001 /* ビデオストリ?[ム??備完了 */
#define CDC_MPINT_VSCHG  0x00000002 /* ビデオストリ?[ム?ﾘり替え完了 */
#define CDC_MPINT_VORDY  0x00000004 /* ビデオ?o力??備完了 */
#define CDC_MPINT_VOSTRT 0x00000008 /* ビデオ?o力開始 */
#define CDC_MPINT_VDERR  0x00000010 /* ビデオデコ?[ドエラ?[ */
#define CDC_MPINT_VSERR  0x00000020 /* ビデオストリ?[ムデ?[タエラ?[ */
#define CDC_MPINT_VBERR  0x00000040 /* ビデオバッファ区画?ﾚ続エラ?[ */
#define CDC_MPINT_VNERR  0x00000080 /* 次発ﾋﾞﾃﾞｵｽﾄﾘｰﾑのデ?[タエラ?[ */
#define CDC_MPINT_PSTRT  0x00000100 /* ピクチャスタ?[ト検?o */
#define CDC_MPINT_GSTRT  0x00000200 /* GOPスタ?[ト検?o */
#define CDC_MPINT_SQEND  0x00000400 /* シ?[ケンスエンド検?o */
#define CDC_MPINT_SQSTRT 0x00000800 /* シ?[ケンススタ?[ト検?o */
#define CDC_MPINT_VTRG   0x00001000 /* ビデオセクタのトリガビット検?o */
#define CDC_MPINT_VEOR   0x00002000 /* ビデオセクタのEORビット検?o */
#define CDC_MPINT_ATRG   0x00004000 /* オ?[ディオセクタのﾄﾘｶﾞﾋﾞｯﾄ検?o */
#define CDC_MPINT_AEOR   0x00008000 /* オ?[ディオセクタのEORビット検?o */
#define CDC_MPINT_ASRDY  0x00010000 /* オ?[ディオストリ?[ム??備完了 */
#define CDC_MPINT_ASCHG  0x00020000 /* オ?[ディオストリ?[ム?ﾘり替え完了 */
#define CDC_MPINT_AORDY  0x00040000 /* オ?[ディオ?o力??備完了 */
#define CDC_MPINT_AOSTRT 0x00080000 /* オ?[ディオ?o力開始 */
#define CDC_MPINT_ADERR  0x00100000 /* オ?[ディオデコ?[ドエラ?[ */
#define CDC_MPINT_ASERR  0x00200000 /* オ?[ディオストリ?[ムデ?[タエラ?[ */
#define CDC_MPINT_ABERR  0x00400000 /* オ?[ディオバッファ区画?ﾚ続エラ?[ */
#define CDC_MPINT_ANERR  0x00800000 /* 次発ｵｰﾃﾞｨｵｽﾄﾘｰﾑのデ?[タエラ?[ */

/* ?ﾚ続モ?[ド?iMPEGデコ?[ダ?ﾚ続?諠pラ???[タ内?j */
#define CDC_MPCMOD_EOR      0x01    /* EORビットで?ﾘり替える */
#define CDC_MPCMOD_SEC      0x02    /* システムエンド(SEC)で?ﾘり替える */
#define CDC_MPCMOD_DEL      0x04    /* セクタの?ﾁ去 */
#define CDC_MPCMOD_IGPTS    0x08    /* PTS識別をしない */
#define CDC_MPCMOD_VCLR     0x10    /* VBVのクリア */
#define CDC_MPCMOD_VWCLR    0x20    /* VBV+WBCのクリア */
#define CDC_MPCMOD_BEF      0x40    /* 後方?iりの前で?I了????判定 */

/* レイヤ指定?iMPEGデコ?[ダ?ﾚ続?諠pラ???[タ内?j */
#define CDC_MPLAY_SYS       0x00    /* システムレイヤ */
#define CDC_MPLAY_AUDIO     0x01    /* オ?[ディオレイヤ */
#define CDC_MPLAY_VIDEO     0x01    /* ビデオレイヤ */

/* MPEG/Videoのピクチャサ?[チ指定?iMPEGデコ?[ダ?ﾚ続?諠pラ???[タ内?j */
#define CDC_MPSRCH_OFF      0x00    /* ピクチャサ?[チをしない */
#define CDC_MPSRCH_VIDEO    0x80    /* ピクチャサ?[チをする */
#define CDC_MPSRCH_AV       0xc0    /* ﾋﾟｸﾁｬｻｰﾁに??わせｵｰﾃﾞｨｵﾃﾞｰﾀを破棄 */

/* ストリ?[ムモ?[ド?iMPEGストリ?[ムパラ???[タ内?j */
#define CDC_MPSMOD_SNSET    0x01    /* ストリ?[ム番??の?ﾝ定を?sう */
#define CDC_MPSMOD_SNIDF    0x02    /* ストリ?[ム番??を識別する */
#define CDC_MPSMOD_CNSET    0x10    /* チャネル番??の?ﾝ定を?sう */
#define CDC_MPSMOD_CNIDF    0x20    /* チャネル番??を識別する */

/* 補間モ?[ド?i画面特殊効果パラ???[タ内?j */
#define CDC_MPITP_YH        0x01    /* Ｙの??平補間をする */
#define CDC_MPITP_CH        0x02    /* Ｃの??平補間をする */
#define CDC_MPITP_YV        0x04    /* Ｙの?ｒｼ補間をする */
#define CDC_MPITP_CV        0x08    /* Ｃの?ｒｼ補間をする */

/* 透明ビットモ?[ド?i画面特殊効果パラ???[タ内?j */
#define CDC_MPTRP_DFL       0x00    /* 通???i透明ビット????をしない?j */
#define CDC_MPTRP_64        0x01    /* 輝度64 */
#define CDC_MPTRP_128       0x02    /* 輝度128 */
#define CDC_MPTRP_256       0x03    /* 輝度256 */
#define CDC_MPTRP_MAG       0x04    /* 透明領域の拡大をする */

/* ぼかしモ?[ド?i画面特殊効果パラ???[タ内?j */
#define CDC_MPSOFT_ON       0x01    /* ぼかしをかける */

/* MPEG/Audioのミュ?[ト */
#define CDC_MPMUT_DFL       0x04    /* ?ﾈ略値?iミュ?[トしない?j */
#define CDC_MPMUT_R         0x01    /* 右チャンネルのミュ?[トをする */
#define CDC_MPMUT_L         0x02    /* ?ｶチャンネルのミュ?[トをする */

/*******************************************************************
*       列挙定??
*******************************************************************/

/* エラ?[コ?[ド */
enum CdcMpErrCode {
    CDC_ERR_MP_COMU = -20   /* MPCMフラグが１になっていない */
};

/* 次ストリ?[ムフラグ?i現ストリ?[ムと次ストリ?[ムの指定?j */
enum CdcMpStf {
    CDC_MPSTF_CUR  = 0,     /* 現?ﾝの?ﾚ続???^ストリ?[ムの指定?i?謾ｭ?j */
    CDC_MPSTF_NEXT = 1      /* ?@次の?ﾚ続???^ストリ?[ムの指定?i次発?j */
};

/* ピクチャタイプ?i下位３ビットが有効?j */
enum CdcMpPict {
    CDC_MPPICT_I = 0x01,    /* Ｉピクチャ */
    CDC_MPPICT_P = 0x02,    /* Ｐピクチャ */
    CDC_MPPICT_B = 0x03,    /* Ｂピクチャ */
    CDC_MPPICT_D = 0x04     /* Ｄピクチャ */
};

/* MPEG動??モ?[ド */
enum CdcMpAct {
    CDC_MPACT_NMOV = 0,     /* 動画?ﾄ?ｶモ?[ド */
    CDC_MPACT_NSTL = 1,     /* ?ﾃ止画?ﾄ?ｶモ?[ド */
    CDC_MPACT_HMOV = 2,     /* ???ｸ?ﾗの動画?ﾄ?ｶモ?[ド?i未対応?j */
    CDC_MPACT_HSTL = 3,     /* ???ｸ?ﾗの?ﾃ止画?ﾄ?ｶモ?[ド */
    CDC_MPACT_SBUF = 4      /* MPEGセクタバッファモ?[ド */
};

/* デコ?[ドタイミング */
enum CdcMpDec {
    CDC_MPDEC_VSYNC = 0,    /* VSYNC同期によるデコ?[ド */
    CDC_MPDEC_HOST  = 1     /* ホスト同期によるデコ?[ド */
};

/* 画像デ?[タの?o力?? */
enum CdcMpOut {
    CDC_MPOUT_VDP2 = 0,     /* VDP2へ?o力 */
    CDC_MPOUT_HOST = 1      /* ホストへ?o力 */
};

/* MPEG?ﾄ?ｶモ?[ド */
enum CdcMpPly {
    CDC_MPPLY_SYNC = 0,     /* 同期?ﾄ?ｶモ?[ド */
    CDC_MPPLY_INDP = 1      /* 独立?ﾄ?ｶモ?[ド */
};

/* MPEGデコ?[ダの転送モ?[ド */
enum CdcMpTrn {
    CDC_MPTRN_AUTO  = 0,    /* 自動転送モ?[ド */
    CDC_MPTRN_FORCE = 1     /* 強?ｧ転送モ?[ド */
};

/* MPEGデコ?[ダの?ﾚ続?ﾘり替えフラグ */
enum CdcMpCof {
    CDC_MPCOF_ABT = 0,      /* ?ﾘり離し?i強?ｧ?I了?j */
    CDC_MPCOF_CHG = 1       /* 強?ｧ?ﾘり替え */
};

/* MPEG/Audioのクリア方式 */
enum CdcMpCla {
    CDC_MPCLA_OFF = 0,      /* クリアしない */
    CDC_MPCLA_ON  = 1       /* 即?ﾀに１セクタのバッファをクリアする */
};

/* MPEG/Videoのクリア方式 */
enum CdcMpClv {
    CDC_MPCLV_FRM = 0,      /* 即?ﾀにVBVとMPEGﾌﾚｰﾑﾊﾞｯﾌｧをクリアする */
    CDC_MPCLV_VBV = 2       /* 次のIまたはPﾋﾟｸﾁｬｽﾀｰﾄでVBVをクリアする */
};

/*******************************************************************
*       ?\造体アクセス????マク??
*******************************************************************/

/* MPEGステ?[タス??報 */
#define CDC_MPSTAT_STS(mpstat)      ((mpstat)->status)
#define CDC_MPSTAT_AST(mpstat)      ((mpstat)->report.actst)
#define CDC_MPSTAT_PICT(mpstat)     ((mpstat)->report.pict)
#define CDC_MPSTAT_STA(mpstat)      ((mpstat)->report.stat_a)
#define CDC_MPSTAT_STV(mpstat)      ((mpstat)->report.stat_v)
#define CDC_MPSTAT_VCNT(mpstat)     ((mpstat)->report.vcnt)

/* タイムコ?[ド */
#define CDC_MPTC_HOUR(mptc)         ((mptc)->hour)
#define CDC_MPTC_MIN(mptc)          ((mptc)->min)
#define CDC_MPTC_SEC(mptc)          ((mptc)->sec)
#define CDC_MPTC_PIC(mptc)          ((mptc)->pic)

/* MPEGデコ?[ダ?ﾚ続?諠pラ???[タ */
#define CDC_MPCON_CMOD(mpcon)       ((mpcon)->cmod)
#define CDC_MPCON_LAY(mpcon)        ((mpcon)->lay)
#define CDC_MPCON_BN(mpcon)         ((mpcon)->bn)

/* MPEGストリ?[ムパラ???[タ */
#define CDC_MPSTM_SMOD(mpstm)       ((mpstm)->smod)
#define CDC_MPSTM_ID(mpstm)         ((mpstm)->id)
#define CDC_MPSTM_CN(mpstm)         ((mpstm)->cn)

/* 画面特殊効果パラ???[タ */
#define CDC_MPVEF_ITP(mpvef)        ((mpvef)->itp)
#define CDC_MPVEF_TRP(mpvef)        ((mpvef)->trp)
#define CDC_MPVEF_MOZH(mpvef)       ((mpvef)->moz_h)
#define CDC_MPVEF_MOZV(mpvef)       ((mpvef)->moz_v)
#define CDC_MPVEF_SOFTH(mpvef)      ((mpvef)->soft_h)
#define CDC_MPVEF_SOFTV(mpvef)      ((mpvef)->soft_v)

/*******************************************************************
*       ????マク??
*******************************************************************/

/* MPEGステ?[タス??報からステ?[タスコ?[ドを取得する */
#define CDC_MPGET_STC(mpstat)   (CDC_MPSTAT_STS(mpstat) & CDC_STC_MSK)

/* MPEGステ?[タス??報からMPEG/Video動????態を取得する */
#define CDC_MPGET_ASTV(mpstat)   (CDC_MPSTAT_AST(mpstat) & 0x07)

/* MPEGステ?[タス??報からMPEG/Audio動????態を取得する */
#define CDC_MPGET_ASTA(mpstat)   (CDC_MPSTAT_AST(mpstat) & 0x70)

/*******************************************************************
*       デ?[タ型の?骭ｾ
*******************************************************************/

/* MPEGステ?[タス??報?iステ?[タス?{MPEGレポ?[ト?j */
typedef struct {
    Uint8   status;         /* ステ?[タス */
    struct {                /* MPEGレポ?[ト */
        Uint8   actst;      /* MPEG動??ステ?[タス */
        Uint8   pict;       /* ピクチャ??報 */
        Uint8   stat_a;     /* MPEG/Audioステ?[タス */
        Uint16  stat_v;     /* MPEG/Videoステ?[タス */
        Uint16  vcnt;       /* 動??区間?iVSYNC?jカウンタ */
    } report;
} CdcMpStat;

/* タイムコ?[ド */
typedef struct {
    Uint8   hour;           /* 時間 */
    Uint8   min;            /* 分 */
    Uint8   sec;            /* 秒 */
    Uint8   pic;            /* ピクチャ */
} CdcMpTc;

/* MPEGデコ?[ダ?ﾚ続?諠pラ???[タ */
typedef struct {
    Uint8   cmod;           /* ?ﾚ続モ?[ド */
    Uint8   lay;            /* レイヤ指定とピクチャサ?[チ指定 */
    Uint8   bn;             /* バッファ区画番?? */
} CdcMpCon;

/* MPEGストリ?[ムパラ???[タ */
typedef struct {
    Uint8   smod;           /* ストリ?[ムモ?[ド */
    Uint8   id;             /* ストリ?[ム番?? */
    Uint8   cn;             /* チャネル番?? */
} CdcMpStm;

/* 画面特殊効果パラ???[タ */
typedef struct {
    Uint8   itp;            /* 補間モ?[ド */
    Uint8   trp;            /* 透明ビットモ?[ド */
    Uint8   moz_h;          /* ??平方向モザイクモ?[ド */
    Uint8   moz_v;          /* ?ｒｼ方向モザイクモ?[ド */
    Uint8   soft_h;         /* ??平方向ぼかしモ?[ド */
    Uint8   soft_v;         /* ?ｒｼ方向ぼかしモ?[ド */
} CdcMpVef;

/*******************************************************************
*       変???骭ｾ
*******************************************************************/

/*******************************************************************
*       関???骭ｾ
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
/* ??意?F以下の関?狽ﾍ非公開とする */
Sint32  CDC_MpGetLsi(Sint32 r_sw, Sint32 reg_no, Sint32 *rdata);
Sint32  CDC_MpSetLsi(Sint32 rwsw, Sint32 reg_no, Sint32 wdata,
                     Sint32 *rdata);

#endif  /* ifndef SEGA_CDC_H */
