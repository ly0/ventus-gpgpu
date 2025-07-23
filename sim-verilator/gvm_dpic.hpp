// DPI-C 函数头文件

#pragma once

#include <vector>
#include <cstdint>
#include "gvm_global_var.hpp"

extern "C" {
// CTA -> Warp 分配
void c_GvmDutCta2Warp(int software_wg_id,
                       int software_warp_id,
                       int sm_id,
                       int hardware_warp_id,
                       int sgpr_base,
                       int vgpr_base);
// Insn Dispatch
void c_GvmDutInsnDispatch(int sm_id,
                            int hardware_warp_id,
                            int pc,
                            int instr,
                            int dispatch_id,
                            bool is_extended);
// XReg Writeback
void c_GvmDutXRegWriteback(int sm_id,
                            int rd,
                            bool is_scalar_wb,
                            int reg_idx,
                            int hardware_warp_id,
                            int pc,
                            int inst,
                            int dispatch_id);
// XRegs
void c_GvmDutXReg(int num_sm,
                   int sm_id,
                   int num_bank,
                   int num_sgpr_slots,
                   int xbanks_word,
                   int xbanks_word_idx);
}