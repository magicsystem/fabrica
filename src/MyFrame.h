/*
 * MyFrame.h
 *
 *  Created on: 7 juil. 2021
 *      Author: azeddine
 */

#ifndef MYFRAME_H_
#define MYFRAME_H_
#include <swtp.h>
class MyFrame: public WFrame {
public:
	static WMenuItems menuitems[];
	WMenu menuBar;
	MyFrame();
	~MyFrame();
	bool Create();
public:
	bool Exit(WEvent &e);
	bool BTN_OK_OnClick(WEvent &e);
	
	WGridLayout mLayout;
	// WButton BTN_OK;
};

#endif /* MYFRAME_H_ */
