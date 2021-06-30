//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include <comobj.hpp>
#include <iostream>
#include <cstring>
#include <string>
#include "utilcls.h"
#include "UOutData.h"
#include "UHead.h"
#include "ULib.h"
#include "UOutD.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmOut *fmOut;
extern bool med;
extern int nEl;
extern int NE;
extern int NU;
//---------------------------------------------------------------------------
__fastcall TfmOut::TfmOut(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmOut::Button15Click(TObject *Sender)
{
	fmOut->TabControl2->ActiveTab = TabItem14;
}
//---------------------------------------------------------------------------
void __fastcall TfmOut::Button3Click(TObject *Sender)
{
	fmOut->TabControl2->ActiveTab = TabItem15;
}
//---------------------------------------------------------------------------
void __fastcall TfmOut::Button6Click(TObject *Sender)
{
	fmOut->TabControl2->ActiveTab = TabItem17;
}
//---------------------------------------------------------------------------
void __fastcall TfmOut::Edit2Change(TObject *Sender)
{
	med = true;
	if (fmOut->Edit2->Text == NULL)
	{
		med = false;
	}
		else
	if (med) {
		nEl = StrToInt(fmOut->Edit2->Text);
	if (nEl>0&&nEl<=NE) {
		Calc_ParametersNDS(nEl-1);
		pNDS();
		fmOutD->Edit3->Text = nEl;
		}
	else{
		med = false;
	  fmOut->Edit2->Text = 1;
	  fmOutD->Edit3->Text = 1;
	  }
	}
}
//---------------------------------------------------------------------------
void __fastcall TfmOut::Button22Click(TObject *Sender)
{
	Variant
	Ex, //Переменная Excel.Application
	Wb,
	wb, //Переменная WorkBook
	Sh,
	Sh1,
	Sh2,
	Sh3; //Переменная WorkSheet
	OleInitialize(NULL);
  try //Попытка открыть приложение Excel
	{
	  Ex=CreateOleObject("Excel.Application");
	}
	catch (...) //Попытка не удалась
	  {
		ShowMessage("ERROR, NO MS EXCEL.");
		return;
	  }
	Ex.OlePropertySet("Visible", true); //Отключение визуального режима Excel
	Wb = Ex.OlePropertyGet("WorkBooks");
	Ex.OlePropertySet("SheetsInNewWorkbook", 3); //Задание количества листов
	Wb.OleFunction("Add"); //Создание книги Excel
	wb = Wb.OlePropertyGet("Item",1);
	Sh = wb.OlePropertyGet("WorkSheets");
	Sh1 = Sh.OlePropertyGet("Item",1);

	WideString str ( "Параметры напряжённо-деформированного состояния");
	Sh1.OlePropertyGet("Cells", 1, 5).OlePropertySet("Value", str);
	WideString str1 (fmOut->Label8->Text + ' ' + fmOut->Edit2->Text);
	Sh1.OlePropertyGet("Cells", 2, 5).OlePropertySet("Value", str1);
	WideString stri(" x/L");
	Sh1.OlePropertyGet("Cells", 4, 1).OlePropertySet("Value", stri);
	WideString str2(" Nx, Н");
	Sh1.OlePropertyGet("Cells", 4, 2).OlePropertySet("Value", str2);
	WideString str3(" M, Н*мм");
	Sh1.OlePropertyGet("Cells", 4, 3).OlePropertySet("Value", str3);
	WideString str4("Q,  Н");
	Sh1.OlePropertyGet("Cells", 4, 4).OlePropertySet("Value", str4);
	WideString str5("U, мм");
	Sh1.OlePropertyGet("Cells", 4, 5).OlePropertySet("Value", str5);
	WideString str6("W, мм");
	Sh1.OlePropertyGet("Cells", 4, 6).OlePropertySet("Value", str6);
	WideString str7("Fi, рад");
	Sh1.OlePropertyGet("Cells", 4, 7).OlePropertySet("Value", str7);
	WideString str8(" Sigma(+h/2), МПа");
	Sh1.OlePropertyGet("Cells", 4, 8).OlePropertySet("Value", str8);
	WideString str9(" Sigma(-h/2), МПа");
	Sh1.OlePropertyGet("Cells", 4, 9).OlePropertySet("Value", str9);
	for (int IRow=1;IRow<100+2;IRow++)
	for (int k=1;k<10;k++)
	{
	  WideString strk(fmOut->StringGrid29->Cells[k-1][IRow-1]);
	  Sh1.OlePropertyGet("Cells", IRow+4, k).OlePropertySet("Value", strk);
	}
	Sh2 = Sh.OlePropertyGet("Item",2);
	Sh2.OleProcedure("Activate");
	WideString str10 ( "Перемещение узлов");
	Sh2.OlePropertyGet("Cells", 1, 5).OlePropertySet("Value", str10);
	WideString str11("№ Узла");
	Sh2.OlePropertyGet("Cells", 4, 1).OlePropertySet("Value", str11);
	WideString str12("Dx, мм");
	Sh2.OlePropertyGet("Cells", 4, 2).OlePropertySet("Value", str12);
	WideString str13("Dy, мм");
	Sh2.OlePropertyGet("Cells", 4, 3).OlePropertySet("Value", str13);
	WideString str14("Dfi, рад");
	Sh2.OlePropertyGet("Cells", 4, 4).OlePropertySet("Value", str14);
	for (int IRow=1;IRow<NU+1;IRow++)
	for (int k=1;k<5;k++)
	{
	  WideString strk2(fmOut->StringGrid30->Cells[k-1][IRow-1]);
	  Sh2.OlePropertyGet("Cells", IRow+4, k).OlePropertySet("Value", strk2);
	}
	Sh3 = Sh.OlePropertyGet("Item",3);
	WideString str20 ( "Оценка прочности");
	Sh3.OlePropertyGet("Cells", 1, 5).OlePropertySet("Value", str20);
	WideString str21("№ элемента");
	Sh3.OlePropertyGet("Cells", 4, 1).OlePropertySet("Value", str21);
	WideString str22("Координата сечения");
	Sh3.OlePropertyGet("Cells", 4, 2).OlePropertySet("Value", str22);
	WideString str23("SigmaMax, МПа");
	Sh3.OlePropertyGet("Cells", 4, 3).OlePropertySet("Value", str23);
	WideString str24("n коэффициент запаса прочности");
	Sh3.OlePropertyGet("Cells", 4, 4).OlePropertySet("Value", str24);
	for (int IRow=1;IRow<NE+1;IRow++)
	for (int k=1;k<5;k++)
	{
	  WideString strk3(fmOut->StringGrid32->Cells[k-1][IRow-1]);
	  Sh3.OlePropertyGet("Cells", IRow+4, k).OlePropertySet("Value", strk3);
	}

	if (fmOut->SaveDialog1->Execute())
{
 Ex.OlePropertyGet("Workbooks").
        OlePropertyGet("Item",1).
        OleProcedure("SaveAs", WideString(fmOut->SaveDialog1->FileName.c_str()));
}
	Ex.OlePropertySet("DisplayAlerts",false);
 Ex.OleProcedure("Quit");

}
//---------------------------------------------------------------------------

void __fastcall TfmOut::Button22MouseEnter(TObject *Sender)
{
	fmOut->CalloutPanel1->BringToFront();
	fmOut->CalloutPanel1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfmOut::Button22MouseLeave(TObject *Sender)
{
	fmOut->CalloutPanel1->Visible = false;
}
//---------------------------------------------------------------------------



