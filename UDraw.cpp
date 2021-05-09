//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "math.h"
#include "UDraw.h"
#include "UHead.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmDraw *fmDraw;
//---------------------------------------------------------------------------

double FW, FH;
__fastcall TfmDraw::TfmDraw(TComponent* Owner)
	: TForm(Owner)
{
	fmDraw->Width = 640;
	fmDraw->Height = 480;
	FW = fmDraw->Width;
	FH = fmDraw->Height;


}
//---------------------------------------------------------------------------
void __fastcall TfmDraw::FormShow(TObject *Sender)
{

	int NE, NU;
	double x,y,xi,yi, sc,is,ic, L;
	sc = 0.3;
	NU = StrToInt(Form1->StringGrid4->Cells[0][0]);
	NE = StrToInt(Form1->StringGrid4->Cells[1][0]);
	for (int i = 0; i < NE; i++) {
		 xi = StrToInt(Form1->StringGrid7->Cells[1][i]);
		 yi = StrToInt(Form1->StringGrid7->Cells[2][i]);
		 L = StrToInt(Form1->StringGrid7->Cells[5][i]);
		 is = StrToInt(Form1->StringGrid7->Cells[6][i]);
		 ic = StrToInt(Form1->StringGrid7->Cells[7][i]);

		 TRectangle *conta = new TRectangle(this);
		 conta->Parent = fmDraw;
		 conta->Height = 20;
		 conta->Width = L*sc ;
		 conta->RotationAngle = 180 * (asin(is)/3.14);
		 conta->Position->X = xi*sc + 10 + 0.1 * FW + is*L*sc/2;
		 conta->Position->Y = -yi*sc + 0.5 * FH - is*L*sc/2;

	}
	for (int i = 0; i < NU; i++) {
		x = StrToInt(Form1->StringGrid5->Cells[1][i]);
		y = StrToInt(Form1->StringGrid5->Cells[2][i]);
		TEllipse *conta1 = new TEllipse(this);
		conta1->Parent = fmDraw;
		conta1->Width = 20;
		conta1->Height = 20;
		conta1->Position->X = x*sc + 0.1 * FW ;
		conta1->Position->Y = -y*sc + 0.5 * FH;
}
}
//---------------------------------------------------------------------------
void __fastcall TfmDraw::FormClose(TObject *Sender, TCloseAction &Action)
{
		fmDraw->DestroyComponents();
}
//---------------------------------------------------------------------------

