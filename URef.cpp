//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "URef.h"
#include "UHead.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmRef *fmRef;
int X0=0, Y0=0;
//---------------------------------------------------------------------------
__fastcall TfmRef::TfmRef(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------






void __fastcall TfmRef::TreeViewItem1Click(TObject *Sender)
{
    tcRef->ActiveTab = tbInfo;
}
//---------------------------------------------------------------------------


void __fastcall TfmRef::TreeViewItem2Click(TObject *Sender)
{
    tcRef->ActiveTab = tb2;
}
//---------------------------------------------------------------------------

void __fastcall TfmRef::TreeViewItem3Click(TObject *Sender)
{
    tcRef->ActiveTab = tb;
}
//---------------------------------------------------------------------------

void __fastcall TfmRef::TreeViewItem5Click(TObject *Sender)
{
    tcRef->ActiveTab = tbOut;
}
//---------------------------------------------------------------------------

void __fastcall TfmRef::TreeViewItem6Click(TObject *Sender)
{
    tcRef->ActiveTab = tbOut1;
}
//---------------------------------------------------------------------------

void __fastcall TfmRef::TreeViewItem7Click(TObject *Sender)
{
    tcRef->ActiveTab = tbOut2;
}
//---------------------------------------------------------------------------

