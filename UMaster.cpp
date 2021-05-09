//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include <iostream>
#include <string>
#include <comobj.hpp>
#include "utilcls.h"
#include "UMaster.h"
#include "UHead.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMasterIn *MasterIn;
//---------------------------------------------------------------------------
__fastcall TMasterIn::TMasterIn(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int ne = -1, nu = -1;

void __fastcall TMasterIn::BuUSELClick(TObject *Sender)
{
	int lnu,lne;
	  lnu =	StrToInt(Edit1->Text);
	  lne = StrToInt(Edit2->Text);
	   if(lnu>1&&lne>0&&(lnu-lne)<2)
	   {
          nu =  StrToInt(Edit1->Text);
		  ne = StrToInt(Edit2->Text);

		  Form1->StringGrid4->Cells[0][0] = nu;
		  Form1->StringGrid4->Cells[1][0] = ne;


		  if(nu>0)
		  {
			  MasterIn->Panel2->Enabled = true;
		  }


	   }
}
//---------------------------------------------------------------------------

void __fastcall TMasterIn::BuUSClick(TObject *Sender)
{



	if(Edit3->Text!= ""&& Edit4->Text!= ""&&Edit5->Text!= ""&&Edit6->Text!= ""&&Edit7->Text!= ""&&Edit8->Text!= "")
	{
	 if(nu<2)
	{
		MasterIn->Panel2->Enabled = false;
	}
	 nu--;
	int i = StrToInt(Edit1->Text) - nu;
	double j;
	 Form1->StringGrid5->Cells[0][i-1] = i;
	 j =  StrToFloat(Edit3->Text);
	 Form1->StringGrid5->Cells[1][i-1] = j ;
	 j =  StrToFloat(Edit4->Text);
	 Form1->StringGrid5->Cells[2][i-1] = j;
	 j =  StrToFloat(Edit5->Text);
	 Form1->StringGrid5->Cells[3][i-1] = j;
	 j =  StrToFloat(Edit6->Text);
	 Form1->StringGrid5->Cells[4][i-1] = j;
	 j =  StrToFloat(Edit7->Text);
	 Form1->StringGrid5->Cells[5][i-1] = j;
	 j =  StrToFloat(Edit8->Text);
	 Form1->StringGrid5->Cells[6][i-1] = j;
	 j =  StrToFloat(Edit9->Text);
	 Form1->StringGrid5->Cells[7][i-1] = j;
	 j =  StrToFloat(Edit10->Text);
	 Form1->StringGrid5->Cells[8][i-1] = j;

	}

	if(!(MasterIn->Panel2->Enabled))
		  {
			  MasterIn->Panel3->Enabled = true;
		  }
}
//---------------------------------------------------------------------------

void __fastcall TMasterIn::BuELClick(TObject *Sender)
{


	if((StrToInt(Edit12->Text))>(StrToInt(Edit11->Text))&&Edit11->Text!= ""&&Edit12->Text!= ""&&Edit13->Text!= ""&&Edit14->Text!= ""&&Edit15->Text!= ""&&siEdit->Text!= ""&&pEdit->Text!= ""&&qEdit->Text!= ""&&aEdit->Text!= ""&&tEdit->Text!= "")
	{
        if(ne<2)
	{
		MasterIn->Panel3->Enabled = false;
	}
	 ne--;
	int i = StrToInt(Edit2->Text) - ne;
	double j;

	 Form1->StringGrid6->Cells[0][i-1] = i;
	 j =  StrToFloat(Edit11->Text);
	 Form1->StringGrid6->Cells[1][i-1] = j;
	 j =  StrToFloat(Edit12->Text);
	 Form1->StringGrid6->Cells[2][i-1] = j;
	 j =  StrToFloat(Edit13->Text);
	 Form1->StringGrid6->Cells[3][i-1] = j;
	 j =  StrToFloat(Edit14->Text);
	 Form1->StringGrid6->Cells[4][i-1] = j;
	 j =  StrToFloat(Edit19->Text);
	 Form1->StringGrid6->Cells[5][i-1] = j;
	 j =  StrToFloat(Edit15->Text);
	 Form1->StringGrid6->Cells[6][i-1] = j;
	 j =  StrToFloat(siEdit->Text);
	 Form1->StringGrid16->Cells[7][i-1] = FloatToStrF(j,ffFixed,8,2);
	 j =  StrToFloat(pEdit->Text);
	 Form1->StringGrid6->Cells[8][i-1] = FloatToStrF(j,ffFixed,8,2);
	 j =  StrToFloat(qEdit->Text);
	 Form1->StringGrid6->Cells[9][i-1] = j;
	 j =  StrToFloat(aEdit->Text);
	 Form1->StringGrid6->Cells[10][i-1] = j;
	 j =  StrToFloat(tEdit->Text);
	 Form1->StringGrid6->Cells[11][i-1] = j;

	}
	if(!(MasterIn->Panel3->Enabled)) {
	Form1->CalcItem->Enabled = True;
	MasterIn->Close();
	}
}
//---------------------------------------------------------------------------



