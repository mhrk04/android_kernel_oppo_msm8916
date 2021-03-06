/*******************************************************************************
* Copyright (c)  2014- 2014  Guangdong OPPO Mobile Telecommunications Corp., Ltd
* CONFIG_VENDOR_EDIT
* Description: Source file for CBufferList.
*           To allocate and free memory block safely.
* Version   : 0.0
* Date      : 2014-07-30
* Author    : Lijiada @Bsp.charge
* ---------------------------------- Revision History: -------------------------
* <version>           <date>          < author >              <desc>
* Revision 0.0        2014-07-30      Lijiada @Bsp.charge
* Modified to be suitable to the new coding rules in all functions.
*******************************************************************************/

#ifndef _OPPO_CHARGER_H_
#define _OPPO_CHARGER_H_

#ifdef OPPO_CHARGER_PAR
#define OPPO_CHARGER_EXT
#else
#define OPPO_CHARGER_EXT extern
#endif

enum {
OPCHG_UNKOWN_ID,
OPCHG_SMB358_ID,
OPCHG_SMB1357_ID,
OPCHG_BQ24196_ID,
};

struct smb_irq_info {
    const char                      *name;
    int                             (*smb_irq)(struct opchg_charger *chip,u8 rt_stat);
    int                             high;
    int                             low;
};

struct irq_handler_info {
    u8                              stat_reg;
    u8                              val;
    u8                              prev_val;
    struct smb_irq_info             irq_info[4];
};

OPPO_CHARGER_EXT int opchg_read_reg(struct opchg_charger *chip, int reg, u8 *val);
OPPO_CHARGER_EXT int opchg_write_reg(struct opchg_charger *chip, int reg, u8 val);
OPPO_CHARGER_EXT int opchg_masked_write(struct opchg_charger *chip, int reg, u8 mask, u8 val);
OPPO_CHARGER_EXT int opchg_regulator_init(struct opchg_charger *chip);
#ifdef OPPO_USE_2CHARGER
OPPO_CHARGER_EXT void opchg_get_prop_fastcharger_type(struct opchg_charger *chip);
#endif
OPPO_CHARGER_EXT void opchg_get_prop_charge_type(struct opchg_charger *chip);
OPPO_CHARGER_EXT void opchg_get_charging_status(struct opchg_charger *chip);
OPPO_CHARGER_EXT int opchg_get_prop_batt_status(struct opchg_charger *chip);
OPPO_CHARGER_EXT void opchg_set_enable_volatile_writes(struct opchg_charger *chip);
OPPO_CHARGER_EXT void opchg_set_complete_charge_timeout(struct opchg_charger *chip, int val);
OPPO_CHARGER_EXT void opchg_set_reset_charger(struct opchg_charger *chip, bool reset);
OPPO_CHARGER_EXT void opchg_set_input_chg_current(struct opchg_charger *chip, int mA, bool aicl);
OPPO_CHARGER_EXT void opchg_set_fast_chg_current(struct opchg_charger *chip, int mA);
OPPO_CHARGER_EXT void opchg_set_float_voltage(struct opchg_charger *chip, int mV);
OPPO_CHARGER_EXT void opchg_set_charging_disable(struct opchg_charger *chip, bool disable);
OPPO_CHARGER_EXT void opchg_set_suspend_enable(struct opchg_charger *chip, bool enable);
OPPO_CHARGER_EXT int opchg_hw_init(struct opchg_charger *chip);
OPPO_CHARGER_EXT int opchg_get_initial_state(struct opchg_charger *chip);
OPPO_CHARGER_EXT void opchg_set_wdt_reset(struct opchg_charger *chip);
OPPO_CHARGER_EXT void opchg_set_wdt_timer(struct opchg_charger *chip, bool enable);
OPPO_CHARGER_EXT int opchg_check_charging_pre_full(struct opchg_charger *chip);
OPPO_CHARGER_EXT irqreturn_t opchg_chg_irq_handler(int irq, void *dev_id);
OPPO_CHARGER_EXT void opchg_dump_regs(struct opchg_charger *chip);
OPPO_CHARGER_EXT int qpnp_charger_type_get(struct opchg_charger *chip);
OPPO_CHARGER_EXT void opchg_switch_to_usbin(struct opchg_charger *chip,bool enable);
OPPO_CHARGER_EXT int opchg_get_otg_regulator_is_enable(struct regulator_dev *rdev);

#endif /*_OPPO_CHARGER_H_*/
