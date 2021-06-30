//---------------------------------------------------------------------------

#ifndef UOutDataH
#define UOutDataH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMXTee.Chart.hpp>
#include <FMXTee.Engine.hpp>
#include <FMXTee.Procs.hpp>
#include <FMXTee.Series.hpp>
#include <System.Rtti.hpp>
#include <FMX.Dialogs.hpp>
//---------------------------------------------------------------------------
class TfmOut : public TForm
{
__published:	// IDE-managed Components
	TToolBar *ToolBar7;
	TButton *Button10;
	TButton *Button15;
	TButton *Button3;
	TButton *Button5;
	TButton *Button6;
	TLabel *Label8;
	TEdit *Edit2;
	TButton *Button22;
	TTabControl *TabControl2;
	TTabItem *TabItem14;
	TStringGrid *StringGrid29;
	TFloatColumn *FloatColumn164;
	TFloatColumn *FloatColumn165;
	TFloatColumn *FloatColumn166;
	TFloatColumn *FloatColumn167;
	TFloatColumn *FloatColumn168;
	TFloatColumn *FloatColumn169;
	TFloatColumn *FloatColumn170;
	TFloatColumn *FloatColumn171;
	TFloatColumn *FloatColumn172;
	TLabel *Label4;
	TTabItem *TabItem15;
	TStringGrid *StringGrid30;
	TFloatColumn *FloatColumn175;
	TFloatColumn *FloatColumn176;
	TFloatColumn *FloatColumn177;
	TFloatColumn *FloatColumn178;
	TLabel *Label5;
	TTabItem *TabItem16;
	TLabel *Label6;
	TStringGrid *StringGrid31;
	TFloatColumn *FloatColumn179;
	TFloatColumn *FloatColumn180;
	TFloatColumn *FloatColumn181;
	TFloatColumn *FloatColumn182;
	TTabItem *TabItem17;
	TLabel *Label7;
	TStringGrid *StringGrid32;
	TFloatColumn *FloatColumn183;
	TFloatColumn *FloatColumn184;
	TFloatColumn *FloatColumn185;
	TFloatColumn *FloatColumn186;
	TSaveDialog *SaveDialog1;
	TCalloutPanel *CalloutPanel1;
	TLabel *Label1;
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Button22MouseEnter(TObject *Sender);
	void __fastcall Button22MouseLeave(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfmOut(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmOut *fmOut;
//---------------------------------------------------------------------------
#endif
