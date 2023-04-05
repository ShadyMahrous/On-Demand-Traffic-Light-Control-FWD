/*
 * Bit_Math.h
 *
 * Created: 2/22/2023 9:54:15 AM
 *  Author: Shady Mahrous
 */ 
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,PIN) (REG |= (1<<PIN))
#define CLR_BIT(REG,PIN) (REG &= ~(1<<PIN))
#define TOG_BIT(REG,PIN) (REG ^= (1<<PIN))
#define GET_BIT(REG,PIN) ((REG>>PIN) & 0x1)



#endif /* BIT_MATH_H_ */