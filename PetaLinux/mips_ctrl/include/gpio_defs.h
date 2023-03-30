/******************************************************************************
* File:             gpio_defs.h
*
* Author:           Hyunwoo Oh  
* Created:          02/24/22 
* Description:      GPIO Register Address Definitions
*****************************************************************************/

#define GPIO_BASE_ADDR          0xE000A000
#define XGPIOPS_DATA_LSW_OFFSET 0x000
#define XGPIOPS_DATA_MSW_OFFSET 0x004
#define XGPIOPS_DATA_OFFSET     0x040
#define XGPIOPS_DATA_RO_OFFSET  0x060
#define XGPIOPS_DIRM_OFFSET     0x204
#define XGPIOPS_OUTEN_OFFSET    0x208
#define XGPIOPS_INTMASK_OFFSET  0x20C
#define XGPIOPS_INTEN_OFFSET    0x210
#define XGPIOPS_INTDIS_OFFSET   0x214
#define XGPIOPS_INTSTS_OFFSET   0x218
#define XGPIOPS_INTTYPE_OFFSET  0x21C
#define XGPIOPS_INTPOL_OFFSET   0x220
#define XGPIOPS_INTANY_OFFSET   0x224

#define MASK_DATA_LSW(n)        (XGPIOPS_DATA_LSW_OFFSET   + (n << 3))
#define MASK_DATA_MSW(n)        (XGPIOPS_DATA_MSW_OFFSET   + (n << 3))
#define DATA(n)                 (XGPIOPS_DATA_OFFSET       + (n << 2))
#define DATA_RO(n)              (XGPIOPS_DATA_RO_OFFSET    + (n << 2))
#define DIRM(n)                 (XGPIOPS_DIRM_OFFSET       + (n << 6))
#define OEN(n)                  (XGPIOPS_OUTEN_OFFSET      + (n << 6))
#define INT_MASK(n)             (XGPIOPS_INTMASK_OFFSET    + (n << 6))
#define INT_EN(n)               (XGPIOPS_INTEN_OFFSET      + (n << 6))
#define INT_DIS(n)              (XGPIOPS_INTDIS_OFFSET     + (n << 6))
#define INT_STS(n)              (XGPIOPS_INTSTS_OFFSET     + (n << 6))
#define INT_TYPE(n)             (XGPIOPS_INTTYPE_OFFSET    + (n << 6))
#define INT_POL(n)              (XGPIOPS_INTPOL_OFFSET     + (n << 6))
#define INT_ANY(n)              (XGPIOPS_INTANY_OFFSET     + (n << 6))

#define MASK_DATA_0_LSW         MASK_DATA_LSW(0)
#define MASK_DATA_0_MSW         MASK_DATA_MSW(0)
#define DATA_0                  DATA(0)
#define DATA_0_RO               DATA_RO(0)
#define DIRM_0                  DIRM(0)
#define OEN_0                   OEN(0)
#define INT_MASK_0              INT_MASK(0)
#define INT_EN_0                INT_EN(0)
#define INT_DIS_0               INT_DIS(0)
#define INT_STAT_0              INT_STS(0)
#define INT_POL_0               INT_POL(0)
#define INT_ANY_0               INT_ANY(0)

#define MAST_DATA_1_LSW         MASK_DATA_LSW(1)
#define MAST_DATA_1_MSW         MASK_DATA_MSW(1)
#define DATA_1                  DATA(1)
#define DATA_1_RO               DATA_RO(1)
#define DIRM_1                  DIRM(1)
#define OEN_1                   OEN(1)
#define INT_MASK_1              INT_MASK(1)
#define INT_EN_1                INT_EN(1)
#define INT_DIS_1               INT_DIS(1)
#define INT_STAT_1              INT_STS(1)
#define INT_POL_1               INT_POL(1)
#define INT_ANY_1               INT_ANY(1)

#define MASK_DATA_2_LSW         MASK_DATA_LSW(2)
#define MASK_DATA_2_MSW         MASK_DATA_MSW(2)
#define DATA_2                  DATA(2)
#define DATA_2_RO               DATA_RO(2)
#define DIRM_2                  DIRM(2)
#define OEN_2                   OEN(2)
#define INT_MASK_2              INT_MASK(2)
#define INT_EN_2                INT_EN(2)
#define INT_DIS_2               INT_DIS(2)
#define INT_STAT_2              INT_STS(2)
#define INT_POL_2               INT_POL(2)
#define INT_ANY_2               INT_ANY(2)

#define MAST_DATA_3_LSW         MASK_DATA_LSW(3)
#define MAST_DATA_3_MSW         MASK_DATA_MSW(3)
#define DATA_3                  DATA(3)
#define DATA_3_RO               DATA_RO(3)
#define DIRM_3                  DIRM(3)
#define OEN_3                   OEN(3)
#define INT_MASK_3              INT_MASK(3)
#define INT_EN_3                INT_EN(3)
#define INT_DIS_3               INT_DIS(3)
#define INT_STAT_3              INT_STS(3)
#define INT_POL_3               INT_POL(3)
#define INT_ANY_3               INT_ANY(3)




