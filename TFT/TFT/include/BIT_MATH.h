/*************************************************************************
author: youssef tolba                                                    *
date : 30 / jul/ 2022                                                    *
version: v01                                                             *                                                               
*************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(var, bit)   var |=  (1<< bit)
#define CLR_BIT(var, bit)   var &= ~(1<< bit)
#define TOG_BIT(var, bit)   var ^=  (1<< bit)
#define GET_BIT(var, bit)   ((var>> bit) & 1)

#endif
