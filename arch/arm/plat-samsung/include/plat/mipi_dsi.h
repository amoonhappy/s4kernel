/* linux/arm/arch/mach-s5pc110/include/plat/mipi_dsi.h
 *
 *
 * Copyright (c) 2011 Samsung Electronics
 * InKi Dae <inki.dae <at> samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef _MIPI_DSI_H
#define _MIPI_DSI_H

#if defined(CONFIG_LCD_MIPI_S6E8AB0)
extern struct mipi_dsim_lcd_driver s6e8ab0_mipi_lcd_driver;
#elif defined(CONFIG_LCD_MIPI_S6E8AA0)
extern struct mipi_dsim_lcd_driver s6e8aa0_mipi_lcd_driver;
#elif defined(CONFIG_LCD_MIPI_S6E63M0)
extern struct mipi_dsim_lcd_driver s6e63m0_mipi_lcd_driver;
#elif defined(CONFIG_LCD_MIPI_TC358764)
extern struct mipi_dsim_lcd_driver tc358764_mipi_lcd_driver;
#elif defined(CONFIG_LCD_MIPI_HYDISWUXGA)
extern struct mipi_dsim_lcd_driver hydiswuxga_mipi_lcd_driver;
#elif defined(CONFIG_LCD_MIPI_AMS480GYXX)
extern struct mipi_dsim_lcd_driver ams480gyxx_mipi_lcd_driver;
#elif defined(CONFIG_LCD_MIPI_ER63311)
extern struct mipi_dsim_lcd_driver er63311_mipi_lcd_driver;
#elif defined(CONFIG_LCD_MIPI_S6E8FA0)
extern struct mipi_dsim_lcd_driver s6e8fa0_mipi_lcd_driver;
extern struct mipi_dsim_lcd_driver s6e8fa0_6P_mipi_lcd_driver;
extern struct mipi_dsim_lcd_driver s6e8fa0_G_mipi_lcd_driver;
extern struct mipi_dsim_lcd_driver s6e8fa0_I_mipi_lcd_driver;
extern struct mipi_dsim_lcd_driver ea8062_mipi_lcd_driver;
#elif defined(CONFIG_LCD_MIPI_S6E3FA0)
extern struct mipi_dsim_lcd_driver s6e3fa0_mipi_lcd_driver;
#endif

extern int s5p_mipi_dsi_wr_data(struct mipi_dsim_device *dsim,
	u8 cmd, const u8 *buf, u32 len);

extern int s5p_mipi_dsi_rd_data(struct mipi_dsim_device *dsim, u8 data_id,
	u8 addr, u8 count, u8 *buf, u8 rxfifo_done);

enum mipi_ddi_interface {
	RGB_IF = 0x4000,
	I80_IF = 0x8000,
	YUV_601 = 0x10000,
	YUV_656 = 0x20000,
	MIPI_VIDEO = 0x1000,
	MIPI_COMMAND = 0x2000,
};

enum mipi_ddi_panel_select {
	DDI_MAIN_LCD = 0,
	DDI_SUB_LCD = 1,
};

enum mipi_ddi_model {
	S6DR117 = 0,
};

enum mipi_ddi_parameter {
	/* DSIM video interface parameter */
	DSI_VIRTUAL_CH_ID = 0,
	DSI_FORMAT = 1,
	DSI_VIDEO_MODE_SEL = 2,
};

#endif /* _MIPI_DSI_H */
