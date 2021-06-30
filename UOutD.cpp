//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UOutD.h"
#include "UHead.h"
#include "ULib.h"
#include "UOutData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmOutD *fmOutD;
extern bool med;
extern int nEl;
extern int NE;
extern element EL[100];
//---------------------------------------------------------------------------
__fastcall TfmOutD::TfmOutD(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmOutD::Button18Click(TObject *Sender)
{
	 Series3->Clear();
	 if(fmOutD->Chart1->Visible)
	 fmOutD->Chart1->Visible = false;
	 else if(fmOutD->Chart2->Visible)
	 fmOutD->Chart2->Visible = false;
	 else if(fmOutD->Chart4->Visible)
	 fmOutD->Chart4->Visible = false;
	 else if(fmOutD->Chart5->Visible)
	 fmOutD->Chart5->Visible = false;
	 else if(fmOutD->Chart6->Visible)
	 fmOutD->Chart6->Visible = false;
	 else if(fmOutD->Chart7->Visible)
	 fmOutD->Chart7->Visible = false;
	 else if(fmOutD->Chart8->Visible)
	 fmOutD->Chart8->Visible = false;
	 fmOutD->Chart3->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(fmOut->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(fmOut->StringGrid29->Cells[5][i]);
		Series3->AddXY(Ax[i],Ay[i]);
	}
	fmOutD->Chart3->BottomAxis->Title->Text = "x, ìì" ;
	fmOutD->Chart3->LeftAxis->Title->Text = "W, ìì" ;
}
//---------------------------------------------------------------------------
void __fastcall TfmOutD::Button17Click(TObject *Sender)
{
	Series2->Clear();
	if(fmOutD->Chart3->Visible)
	fmOutD->Chart3->Visible = false;
	 else if(fmOutD->Chart1->Visible)
	 fmOutD->Chart1->Visible = false;
	 else if(fmOutD->Chart4->Visible)
	 fmOutD->Chart4->Visible = false;
	  else if(fmOutD->Chart5->Visible)
	 fmOutD->Chart5->Visible = false;
	  else if(fmOutD->Chart6->Visible)
	 fmOutD->Chart6->Visible = false;
	  else if(fmOutD->Chart7->Visible)
	 fmOutD->Chart7->Visible = false;
	 else if(fmOutD->Chart8->Visible)
	 fmOutD->Chart8->Visible = false;

	fmOutD->Chart2->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(fmOut->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(fmOut->StringGrid29->Cells[2][i]);
		Series2->AddXY(Ax[i],Ay[i]);
//
	}
	fmOutD->Chart2->BottomAxis->Title->Text = "x, ìì" ;
	fmOutD->Chart2->LeftAxis->Title->Text = "M, Í*ìì" ;
}
//---------------------------------------------------------------------------
void __fastcall TfmOutD::Button16Click(TObject *Sender)
{
	double Ax[101], Ay[101];
	Series1->Clear();
	if(fmOutD->Chart2->Visible)
	fmOutD->Chart2->Visible = false;
	 else if(fmOutD->Chart3->Visible)
	 fmOutD->Chart3->Visible = false;
	  else if(fmOutD->Chart4->Visible)
	 fmOutD->Chart4->Visible = false;
	  else if(fmOutD->Chart5->Visible)
	 fmOutD->Chart5->Visible = false;
	  else if(fmOutD->Chart6->Visible)
	 fmOutD->Chart6->Visible = false;
	  else if(fmOutD->Chart7->Visible)
	 fmOutD->Chart7->Visible = false;
	 else if(fmOutD->Chart8->Visible)
	 fmOutD->Chart8->Visible = false;
	 fmOutD->Chart1->Visible = true;
	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(fmOut->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(fmOut->StringGrid29->Cells[1][i]);
		Series1->AddXY(Ax[i],Ay[i]);
	}

	fmOutD->Chart1->BottomAxis->Title->Text = "x, ìì" ;
	fmOutD->Chart1->LeftAxis->Title->Text = "N, Í" ;
}
//---------------------------------------------------------------------------
void __fastcall TfmOutD::Button7Click(TObject *Sender)
{
		 LineSeries1->Clear();
	if(fmOutD->Chart1->Visible)
	fmOutD->Chart1->Visible = false;
	 else if(fmOutD->Chart2->Visible)
	 fmOutD->Chart2->Visible = false;
	 else if(fmOutD->Chart3->Visible)
	 fmOutD->Chart3->Visible = false;
	 else if(fmOutD->Chart5->Visible)
	 fmOutD->Chart5->Visible = false;
	 else if(fmOutD->Chart6->Visible)
	 fmOutD->Chart6->Visible = false;
	 else if(fmOutD->Chart7->Visible)
	 fmOutD->Chart7->Visible = false;
	 else if(fmOutD->Chart8->Visible)
	 fmOutD->Chart8->Visible = false;
	 fmOutD->Chart4->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(fmOut->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(fmOut->StringGrid29->Cells[4][i]);
		LineSeries1->AddXY(Ax[i],Ay[i]);
	}
	fmOutD->Chart4->BottomAxis->Title->Text = "x, ìì" ;
	fmOutD->Chart4->LeftAxis->Title->Text = "U, ìì" ;
}
//---------------------------------------------------------------------------
void __fastcall TfmOutD::Button8Click(TObject *Sender)
{
		LineSeries2->Clear();
	if(fmOutD->Chart1->Visible)
	fmOutD->Chart1->Visible = false;
	 else if(fmOutD->Chart2->Visible)
	 fmOutD->Chart2->Visible = false;
	 else if(fmOutD->Chart3->Visible)
	 fmOutD->Chart3->Visible = false;
	 else if(fmOutD->Chart4->Visible)
	 fmOutD->Chart4->Visible = false;
	 else if(fmOutD->Chart6->Visible)
	 fmOutD->Chart6->Visible = false;
	 else if(fmOutD->Chart7->Visible)
	 fmOutD->Chart7->Visible = false;
	 else if(fmOutD->Chart8->Visible)
	 fmOutD->Chart8->Visible = false;
	 fmOutD->Chart5->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(fmOut->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(fmOut->StringGrid29->Cells[3][i]);
		LineSeries2->AddXY(Ax[i],Ay[i]);
	}
	fmOutD->Chart5->BottomAxis->Title->Text = "x, ìì" ;
	fmOutD->Chart5->LeftAxis->Title->Text = "Q, Í" ;
}
//---------------------------------------------------------------------------
void __fastcall TfmOutD::Button19Click(TObject *Sender)
{
		LineSeries3->Clear();
	if(fmOutD->Chart1->Visible)
	fmOutD->Chart1->Visible = false;
	 else if(fmOutD->Chart2->Visible)
	 fmOutD->Chart2->Visible = false;
	 else if(fmOutD->Chart3->Visible)
	 fmOutD->Chart3->Visible = false;
	 else if(fmOutD->Chart4->Visible)
	 fmOutD->Chart4->Visible = false;
	 else if(fmOutD->Chart5->Visible)
	 fmOutD->Chart5->Visible = false;
	 else if(fmOutD->Chart7->Visible)
	 fmOutD->Chart7->Visible = false;
	 else if(fmOutD->Chart8->Visible)
	 fmOutD->Chart8->Visible = false;
	 fmOutD->Chart6->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(fmOut->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(fmOut->StringGrid29->Cells[6][i]);
		LineSeries3->AddXY(Ax[i],Ay[i]);
	}
	fmOutD->Chart6->BottomAxis->Title->Text = "x, ìì" ;
	fmOutD->Chart6->LeftAxis->Title->Text = "fi, ðàä" ;
}
//---------------------------------------------------------------------------
void __fastcall TfmOutD::Button20Click(TObject *Sender)
{
		LineSeries4->Clear();
	Series4->Clear();
	if(fmOutD->Chart1->Visible)
	fmOutD->Chart1->Visible = false;
	 else if(fmOutD->Chart2->Visible)
	 fmOutD->Chart2->Visible = false;
	 else if(fmOutD->Chart3->Visible)
	 fmOutD->Chart3->Visible = false;
	 else if(fmOutD->Chart4->Visible)
	 fmOutD->Chart4->Visible = false;
	 else if(fmOutD->Chart6->Visible)
	 fmOutD->Chart6->Visible = false;
	 else if(fmOutD->Chart8->Visible)
	 fmOutD->Chart8->Visible = false;
	 else if(fmOutD->Chart5->Visible)
	 fmOutD->Chart5->Visible = false;
	 fmOutD->Chart7->Visible = true;
	double Ax[101], Ay[101], By[101];

	for(int i=0;i<101;i++)
	{
		Ax[i] =  EL[nEl-1].L*StrToFloat(fmOut->StringGrid29->Cells[0][i]);
		Ay[i] = StrToFloat(fmOut->StringGrid29->Cells[7][i]);
		By[i] = StrToFloat(fmOut->StringGrid29->Cells[8][i]);
		LineSeries4->AddXY(Ax[i],Ay[i]);
		Series4->AddXY(Ax[i],By[i]);
	}
	fmOutD->Chart5->BottomAxis->Title->Text = "x, ìì" ;
	fmOutD->Chart5->LeftAxis->Title->Text = "Sigma, ÌÏà" ;
}
//---------------------------------------------------------------------------
void __fastcall TfmOutD::Button9Click(TObject *Sender)
{
    	Series5->Clear();
	if(fmOutD->Chart1->Visible)
	fmOutD->Chart1->Visible = false;
	 else if(fmOutD->Chart2->Visible)
	 fmOutD->Chart2->Visible = false;
	 else if(fmOutD->Chart3->Visible)
	 fmOutD->Chart3->Visible = false;
	 else if(fmOutD->Chart4->Visible)
	 fmOutD->Chart4->Visible = false;
	 else if(fmOutD->Chart5->Visible)
	 fmOutD->Chart5->Visible = false;
	 else if(fmOutD->Chart7->Visible)
	 fmOutD->Chart7->Visible = false;
	 else if(fmOutD->Chart6->Visible)
	 fmOutD->Chart6->Visible = false;
	 fmOutD->Chart8->Visible = true;
	double Ax[101], Ay[101];

	for(int i=0;i<NE;i++)
	{
		Ax[i] =  i+1;
		Ay[i] = StrToFloat(fmOut->StringGrid32->Cells[3][i]);
		Series5->AddXY(Ax[i],Ay[i]);
	}
	fmOutD->Chart8->BottomAxis->Title->Text = "¹ ýëåìåíòà" ;
	fmOutD->Chart8->LeftAxis->Title->Text = "êîýôèöèåíò çàïàñà" ;
}
//---------------------------------------------------------------------------
void __fastcall TfmOutD::Edit3Change(TObject *Sender)
{
    fmOutD->Chart1->Visible = false;
	fmOutD->Chart2->Visible = false;
	fmOutD->Chart3->Visible = false;
	fmOutD->Chart4->Visible = false;
	fmOutD->Chart6->Visible = false;
	fmOutD->Chart8->Visible = false;
	fmOutD->Chart5->Visible = false;
	fmOutD->Chart7->Visible = false;
    med = true;
	if (fmOutD->Edit3->Text == NULL)
	{
		med = false;
	}
		else
	if (med) {
		nEl = StrToInt(fmOutD->Edit3->Text);
	if (nEl>0&&nEl<=NE) {
		Calc_ParametersNDS(nEl-1);
		pNDS();
		fmOut->Edit2->Text = nEl;
		}
	else{
		med = false;
	  fmOut->Edit2->Text = 1;
	  fmOutD->Edit3->Text = 1;
	  }
	}
}
//---------------------------------------------------------------------------
