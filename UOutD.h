//---------------------------------------------------------------------------

#ifndef UOutDH
#define UOutDH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMXTee.Chart.hpp>
#include <FMXTee.Engine.hpp>
#include <FMXTee.Procs.hpp>
#include <FMXTee.Series.hpp>
//---------------------------------------------------------------------------
class TfmOutD : public TForm
{
__published:	// IDE-managed Components
	TChart *Chart1;
	TLineSeries *Series1;
	TChart *Chart2;
	TLineSeries *Series2;
	TChart *Chart3;
	TLineSeries *Series3;
	TChart *Chart4;
	TLineSeries *LineSeries1;
	TChart *Chart5;
	TLineSeries *LineSeries2;
	TChart *Chart6;
	TLineSeries *LineSeries3;
	TChart *Chart7;
	TLineSeries *LineSeries4;
	TLineSeries *Series4;
	TChart *Chart8;
	TBarSeries *Series5;
	TToolBar *ToolBar8;
	TButton *Button13;
	TButton *Button14;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button7;
	TButton *Button8;
	TButton *Button19;
	TButton *Button20;
	TButton *Button9;
	TLabel *Label9;
	TEdit *Edit3;
	TButton *Button21;
	TCalloutPanel *CalloutPanel1;
	TLabel *Label1;
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfmOutD(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmOutD *fmOutD;
//---------------------------------------------------------------------------
#endif
