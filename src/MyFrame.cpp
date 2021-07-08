/*
 * MyFrame.cpp
 *
 *  Created on: 7 juil. 2021
 *      Author: azeddine
 */

#include "MyFrame.h"
WMenuItems MyFrame::menuitems[] = { //
		{ W_CASCADE, 0, -1, "File", 0 },	//
				{ W_PUSH, 0, -1, "Open", 0 },	//
				{ W_SEPARATOR, 0, -1, 0, 0 },	//
				{ W_PUSH, W_ALT | 'Q', -1, "Exit", W_ACTION(MyFrame::Exit) },//
				{ W_CASCADE_END, 0, -1, 0, 0 },	//
				{ 0, 0, 0, 0 },	//
		};
int main(int args, char *argv[]) {
	WApp app(args, argv);
	MyFrame *frame = new MyFrame();
	frame->Create();
	frame->Open();
	return app.Run();
}
MyFrame::MyFrame() {
}

MyFrame::~MyFrame() {
}


bool MyFrame::Create() {

	if (WFrame::Create(
			W_FRAME_TRIM | W_DELETE_ON_DISPOSE | W_DISPOSE_ON_CLOSE )) {

		mLayout.numColumns = 5;
		this->SetLayout(mLayout);

		menuBar.CreateBar(this);
		menuBar.CreateItems(this, NULL, menuitems);
		this->SetMenuBar(menuBar);
		this->SetBounds(100, 100, 600, 500);

		char msg[30];
		WButton* BTN_OK;

		for (int i=0; i<10; i++) {
			BTN_OK = new WButton(this,W_DELETE_ON_DISPOSE | ( i % 2 == 1 ? W_PUSH : W_CHECK));
			sprintf(msg, "Button %d", i); 
			BTN_OK->SetText(msg);
			if(i%2==0)
			mLayout.SetData(BTN_OK,WGridData(W_GRID_FILL_HORIZONTAL));
			// BTN_OK->SetAction(this,W_ACTION(MyFrame::BTN_OK_OnClick));
		}
		

		return true;
	} else
		return false;

	
}


bool MyFrame::Exit(WEvent &e) {
	this->Close();
	return true;
}

bool MyFrame::BTN_OK_OnClick(WEvent &e) {
	this->Close();
	return true;
}
