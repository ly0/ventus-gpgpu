// RTL 信号经由 DPI-C 接口，写入 C++ 全局变量

#pragma once

#include <vector>
#include <cstdint>

// CTA -> Warp 分配
struct Cta2WarpData {
  uint32_t software_wg_id;
  uint32_t software_warp_id;
  uint32_t sm_id;
  uint32_t hardware_warp_id;
  uint32_t sgpr_base;
  uint32_t vgpr_base;
};
std::vector<Cta2WarpData> g_cta2warp_data;
// Instr Dispatch
// at each cycle, the dut will push the dispatched instruction to this vector
// the gvm top module will read this vector and compare with the ref model,
// and clear the vector after each cycle
struct InsnDispatchData {
  uint32_t sm_id;
  uint32_t hardware_warp_id;
  uint32_t pc;
  uint32_t insn;
  uint32_t dispatch_id;
  bool is_extended;
};
std::vector<InsnDispatchData> g_insn_dispatch_data;
// XReg Writeback
struct XRegWritebackData {
  uint32_t sm_id;
  uint32_t rd; // 写回数据
  bool is_scalar_wb;
  uint32_t reg_idx; // 写回地址
  uint32_t hardware_warp_id;
  uint32_t pc;
  uint32_t insn;
  uint32_t dispatch_id;
};
std::vector<XRegWritebackData> g_xreg_wb_data;
struct XRegData {
  uint32_t sm_id;
  uint32_t bank_id;
  uint32_t num_bank;
  uint32_t num_sgpr_slots;
  std::vector<uint32_t> bank_data;
};
std::vector<XRegData> g_xreg_data;
uint32_t g_sgprUsage = 64; // num of sgpr used in one warp