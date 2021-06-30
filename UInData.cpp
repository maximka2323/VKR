//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UInData.h"
#include "UHead.h"
#include "ULib.h"
#include "UDraw.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmIn *fmIn;
extern element EL[100];
	extern usel US[100];
	extern int NE, NU;
//---------------------------------------------------------------------------
__fastcall TfmIn::TfmIn(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmIn::Button1Click(TObject *Sender)
{

	Form1->CalcItem->Enabled = True;
	NU = StrToInt(fmIn->StringGrid4->Cells[0][0]);
	NE = StrToInt(fmIn->StringGrid4->Cells[1][0]);
	Getusel();
	Getelem();
	clearAll();
	cDraw();
//	fmDraw->Show();
	Form1->pb1->Visible = true;
		for(int i=0;i<NU;i++)
	{
		if(US[i].R.v(0)!=0) strengthXDraw(i);
		if(US[i].R.v(1)!=0) strengthYDraw(i);
		if(US[i].R.v(2)!=0) momentDraw(i);
	}
	fmIn->Hide();

}
//---------------------------------------------------------------------------
