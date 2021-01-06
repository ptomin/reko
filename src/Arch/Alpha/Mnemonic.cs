#region License
/* 
 * Copyright (C) 1999-2021 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

namespace Reko.Arch.Alpha
{
    public enum Mnemonic
    {
        invalid,

        addl,
        addl_v,
        addq,
        addq_v,
        and,
        beq,
        bge,
        bgt,
        bic,
        bis,
        blbc,
        blbs,
        ble,
        blt,
        bne,
        br,
        bsr,
        cmovge,
        cmovgt,
        cmovlbc,
        cmovlbs,
        cmovlt,
        cmovne,
        cmpbge,
        cmpeq,
        cmple,
        cmplt,
        cmpule,
        cmpult,
        extbl,
        extlh,
        extll,
        extqh,
        extql,
        extwh,
        extwl,
        fbeq,
        fbge,
        fbgt,
        fble,
        fblt,
        fbne,
        halt,
        implver,
        insbl,
        inslh,
        insll,
        insqh,
        insql,
        inswh,
        inswl,
        jmp,
        jsr,
        jsr_coroutine,
        lda,
        ldah,
        ldbu,
        ldf,
        ldg,
        ldl,
        ldl_l,
        ldq,
        ldq_l,
        ldq_u,
        lds,
        ldt,
        ldwu,
        mskbl,
        msklh,
        mskll,
        mskqh,
        mskql,
        mskwh,
        mskwl,
        mull,
        mull_v,
        mulq,
        mulq_v,
        ornot,
        ret,
        s4addl,
        s4addq,
        s4subl,
        s4subq,
        s8addl,
        s8addq,
        s8subl,
        s8subq,
        sll,
        src,
        srl,
        stb,
        stf,
        stg,
        stl,
        stl_c,
        stq,
        stq_c,
        stq_u,
        sts,
        stt,
        stw,
        subl,
        subl_v,
        subq,
        subq_v,
        umulh,
        xor,
        zap,
        zapnot,

        cvtlq,
        cpys,
        cpysn,
        cpyse,
        mt_fpcr,
        mf_fpcr,
        fcmoveq,
        fcmovne,
        fcmovlt,
        fcmovge,
        fcmovle,
        fcmovgt,
        cvtql,
        cvtql_v,
        cvtql_sv,
        itofs,
        sqrtf_c,
        sqrts_c,
        itoff,
        itoft,
        sqrtg_c,
        sqrtt_c,
        sqrts_m,
        sqrtt_m,
        sqrtf,
        sqrts,
        sqrtg,
        sqrtt,
        sqrts_d,
        sqrtt_d,
        sqrtf_uc,
        sqrts_uc,
        sqrtg_uc,
        sqrtt_uc,
        sqrts_um,
        sqrtt_um,
        sqrtf_u,
        sqrts_u,
        sqrtg_u,
        sqrtt_u,
        sqrts_ud,
        sqrtt_ud,
        sqrtf_sc,
        sqrtg_sc,
        sqrtf_s,
        sqrtg_s,
        sqrtf_suc,
        sqrts_suc,
        sqrtg_suc,
        sqrtt_suc,
        sqrts_sum,
        sqrtt_sum,
        sqrtf_su,
        sqrts_su,
        sqrtg_su,
        sqrtt_su,
        sqrts_sud,
        sqrtt_sud,
        sqrts_suic,
        sqrtt_suic,
        sqrts_suim,
        sqrtt_suim,
        sqrts_sui,
        sqrtt_sui,
        sqrts_suid,
        sqrtt_suid,

        addf_c,
        subf_c,
        mulf_c,
        divf_c,
        cvtdg_c,
        addg_c,
        subg_c,
        mulg_c,
        divg_c,
        cvtgf_c,
        cvtgd_c,
        cvtgq_c,
        cvtqf_c,
        cvtqg_c,
        addf,
        negf,

        subf,
        mulf,
        divf,
        cvtdg,
        addg,
        negg,

        subg,
        mulg,
        divg,
        cmpgeq,
        cmpglt,
        cmpgle,
        cvtgf,
        cvtgd,
        cvtgq,
        cvtqf,
        cvtqg,
        addf_uc,
        subf_uc,
        mulf_uc,
        divf_uc,
        cvtdg_uc,
        addg_uc,
        subg_uc,
        mulg_uc,
        divg_uc,
        cvtgf_uc,
        cvtgd_uc,
        cvtgq_vc,
        addf_u,
        subf_u,
        mulf_u,
        divf_u,
        cvtdg_u,
        addg_u,
        subg_u,
        mulg_u,
        divg_u,
        cvtgf_u,
        cvtgd_u,
        cvtgq_v,
        addf_sc,
        subf_sc,
        mulf_sc,
        divf_sc,
        cvtdg_sc,
        addg_sc,
        subg_sc,
        mulg_sc,
        divg_sc,
        cvtgf_sc,
        cvtgd_sc,
        cvtgq_sc,
        addf_s,
        negf_s,

        subf_s,
        mulf_s,
        divf_s,
        cvtdg_s,
        addg_s,
        negg_s,

        subg_s,
        mulg_s,
        divg_s,
        cmpgeq_s,
        cmpglt_s,
        cmpgle_s,
        cvtgf_s,
        cvtgd_s,
        cvtgq_s,
        addf_suc,
        subf_suc,
        mulf_suc,
        divf_suc,
        cvtdg_suc,
        addg_suc,
        subg_suc,
        mulg_suc,
        divg_suc,
        cvtgf_suc,
        cvtgd_suc,
        cvtgq_svc,
        addf_su,
        subf_su,
        mulf_su,
        divf_su,
        cvtdg_su,
        addg_su,
        subg_su,
        mulg_su,
        divg_su,
        cvtgf_su,
        cvtgd_su,
        cvtgq_sv,

        adds_c,
        subs_c,
        muls_c,
        divs_c,
        addt_c,
        subt_c,
        mult_c,
        divt_c,
        cvtts_c,
        cvttq_c,
        cvtqs_c,
        cvtqt_c,
        adds_m,
        subs_m,
        muls_m,
        divs_m,
        addt_m,
        subt_m,
        mult_m,
        divt_m,
        cvtts_m,
        cvttq_m,
        cvtqs_m,
        cvtqt_m,
        adds,
        negs,

        subs,
        muls,
        divs,
        addt,
        negt,

        subt,
        mult,
        divt,
        cmptun,
        cmpteq,
        cmptlt,
        cmptle,
        cvtts,
        cvttq,
        cvtqs,
        cvtqt,
        adds_d,
        subs_d,
        muls_d,
        divs_d,
        addt_d,
        subt_d,
        mult_d,
        divt_d,
        cvtts_d,
        cvttq_d,
        cvtqs_d,
        cvtqt_d,
        adds_uc,
        subs_uc,
        muls_uc,
        divs_uc,
        addt_uc,
        subt_uc,
        mult_uc,
        divt_uc,
        cvtts_uc,
        cvttq_vc,
        adds_um,
        subs_um,
        muls_um,
        divs_um,
        addt_um,
        subt_um,
        mult_um,
        divt_um,
        cvtts_um,
        cvttq_vm,
        adds_u,
        subs_u,
        muls_u,
        divs_u,
        addt_u,
        subt_u,
        mult_u,
        divt_u,
        cvtts_u,
        cvttq_v,
        adds_ud,
        subs_ud,
        muls_ud,
        divs_ud,
        addt_ud,
        subt_ud,
        mult_ud,
        divt_ud,
        cvtts_ud,
        cvttq_vd,
        cvtst,
        adds_suc,
        subs_suc,
        muls_suc,
        divs_suc,
        addt_suc,
        subt_suc,
        mult_suc,
        divt_suc,
        cvtts_suc,
        cvttq_svc,
        adds_sum,
        subs_sum,
        muls_sum,
        divs_sum,
        addt_sum,
        subt_sum,
        mult_sum,
        divt_sum,
        cvtts_sum,
        cvttq_svm,
        adds_su,
        negs_su,

        subs_su,
        muls_su,
        divs_su,
        addt_su,
        negt_su,

        subt_su,
        mult_su,
        divt_su,
        cmptun_su,
        cmpteq_su,
        cmptlt_su,
        cmptle_su,
        cvtts_su,
        cvttq_sv,
        adds_sud,
        subs_sud,
        muls_sud,
        divs_sud,
        addt_sud,
        subt_sud,
        mult_sud,
        divt_sud,
        cvtts_sud,
        cvttq_svd,
        cvtst_s,
        adds_suic,
        subs_suic,
        muls_suic,
        divs_suic,
        addt_suic,
        subt_suic,
        mult_suic,
        divt_suic,
        cvtts_suic,
        cvttq_svic,
        cvtqs_suic,
        cvtqt_suic,
        adds_suim,
        subs_suim,
        muls_suim,
        divs_suim,
        addt_suim,
        subt_suim,
        mult_suim,
        divt_suim,
        cvtts_suim,
        cvttq_svim,
        cvtqs_suim,
        cvtqt_suim,
        adds_sui,
        negs_sui,

        subs_sui,
        muls_sui,
        divs_sui,
        addt_sui,
        negt_sui,

        subt_sui,
        mult_sui,
        divt_sui,
        cvtts_sui,
        cvttq_svi,
        cvtqs_sui,
        cvtqt_sui,
        adds_suid,
        subs_suid,
        muls_suid,
        divs_suid,
        addt_suid,
        subt_suid,
        mult_suid,
        divt_suid,
        cvtts_suid,
        cvttq_svid,
        cvtqs_suid,
        cvtqt_suid,

        fnop,
        fclr,
        fabs,
        fmov,
        fneg,
        trapb,
    }
}