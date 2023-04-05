/*
 * STD_Types.h
 *
 * Created: 2/22/2023 9:54:34 AM
 *  Author: Shady Mahrous
 */ 
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char			uint8_t;
typedef signed 	 char			sint8_t;

typedef unsigned short int		uint16_t;
typedef signed   short int		sint16_t;

typedef unsigned long int		uint32_t;
typedef signed   long int		sint32_t;

typedef unsigned long long int	uint64_t;
typedef signed   long long int	sint64_t;

typedef enum EN_mode_t
{
	NORMAL, PEDESTRIAN
}EN_mode_t;

typedef enum EN_carColor_t
{
	RED,YELLOW,GREEN
}EN_carColor_t;

typedef enum EN_buttonPressed_t
{
	NO,YES
}EN_buttonPressed_t;


#endif /* STD_TYPES_H_ */