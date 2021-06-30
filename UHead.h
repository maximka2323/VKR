//---------------------------------------------------------------------------

#ifndef UHeadH
#define UHeadH
#include <FMX.Controls.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <System.Classes.hpp>
#include <System.Rtti.hpp>
#include <FMX.ExtCtrls.hpp>
#include <FMXTee.Chart.hpp>
#include <FMXTee.Engine.hpp>
#include <FMXTee.Procs.hpp>
#include <FMXTee.Series.hpp>
#include <FMX.Menus.hpp>
#include <FMX.Objects.hpp>

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTabControl *TabControl1;
	TTabItem *TabItem1;
	TOpenDialog *OpenDialog1;
	TTabItem *TabItem3;
	TToolBar *ToolBar2;
	TStringGrid *StringGrid7;
	TFloatColumn *FloatColumn40;
	TFloatColumn *FloatColumn41;
	TFloatColumn *FloatColumn42;
	TFloatColumn *FloatColumn43;
	TFloatColumn *FloatColumn44;
	TFloatColumn *FloatColumn45;
	TFloatColumn *FloatColumn46;
	TFloatColumn *FloatColumn47;
	TFloatColumn *FloatColumn48;
	TTabItem *TabItem4;
	TToolBar *ToolBar3;
	TGridPanelLayout *GridPanelLayout4;
	TStringGrid *StringGrid8;
	TFloatColumn *FloatColumn49;
	TFloatColumn *FloatColumn50;
	TFloatColumn *FloatColumn51;
	TFloatColumn *FloatColumn52;
	TFloatColumn *FloatColumn53;
	TFloatColumn *FloatColumn54;
	TStringGrid *StringGrid9;
	TFloatColumn *FloatColumn55;
	TFloatColumn *FloatColumn56;
	TFloatColumn *FloatColumn57;
	TFloatColumn *FloatColumn58;
	TFloatColumn *FloatColumn59;
	TFloatColumn *FloatColumn60;
	TStringGrid *StringGrid10;
	TFloatColumn *FloatColumn61;
	TFloatColumn *FloatColumn62;
	TFloatColumn *FloatColumn63;
	TFloatColumn *FloatColumn64;
	TFloatColumn *FloatColumn65;
	TFloatColumn *FloatColumn66;
	TStringGrid *StringGrid11;
	TFloatColumn *FloatColumn67;
	TFloatColumn *FloatColumn68;
	TFloatColumn *FloatColumn69;
	TFloatColumn *FloatColumn70;
	TFloatColumn *FloatColumn71;
	TFloatColumn *FloatColumn72;
	TTabItem *TabItem5;
	TLabel *Label1;
	TGridPanelLayout *GridPanelLayout5;
	TStringGrid *StringGrid12;
	TFloatColumn *FloatColumn73;
	TFloatColumn *FloatColumn74;
	TFloatColumn *FloatColumn75;
	TStringGrid *StringGrid13;
	TFloatColumn *FloatColumn79;
	TFloatColumn *FloatColumn80;
	TFloatColumn *FloatColumn81;
	TStringGrid *StringGrid14;
	TFloatColumn *FloatColumn85;
	TFloatColumn *FloatColumn86;
	TFloatColumn *FloatColumn87;
	TStringGrid *StringGrid15;
	TFloatColumn *FloatColumn91;
	TFloatColumn *FloatColumn92;
	TFloatColumn *FloatColumn93;
	TTabItem *TabItem6;
	TLabel *Label2;
	TStringGrid *StringGrid16;
	TFloatColumn *FloatColumn97;
	TFloatColumn *FloatColumn98;
	TFloatColumn *FloatColumn99;
	TFloatColumn *FloatColumn100;
	TFloatColumn *FloatColumn101;
	TFloatColumn *FloatColumn102;
	TFloatColumn *FloatColumn103;
	TTabItem *TabItem7;
	TToolBar *ToolBar4;
	TGridPanelLayout *GridPanelLayout6;
	TStringGrid *StringGrid17;
	TFloatColumn *FloatColumn104;
	TFloatColumn *FloatColumn105;
	TFloatColumn *FloatColumn106;
	TFloatColumn *FloatColumn107;
	TFloatColumn *FloatColumn108;
	TFloatColumn *FloatColumn109;
	TStringGrid *StringGrid18;
	TFloatColumn *FloatColumn110;
	TFloatColumn *FloatColumn111;
	TFloatColumn *FloatColumn112;
	TFloatColumn *FloatColumn113;
	TFloatColumn *FloatColumn114;
	TFloatColumn *FloatColumn115;
	TStringGrid *StringGrid19;
	TFloatColumn *FloatColumn116;
	TFloatColumn *FloatColumn117;
	TFloatColumn *FloatColumn118;
	TFloatColumn *FloatColumn119;
	TFloatColumn *FloatColumn120;
	TFloatColumn *FloatColumn121;
	TStringGrid *StringGrid20;
	TFloatColumn *FloatColumn122;
	TFloatColumn *FloatColumn123;
	TFloatColumn *FloatColumn124;
	TFloatColumn *FloatColumn125;
	TFloatColumn *FloatColumn126;
	TFloatColumn *FloatColumn127;
	TTabItem *TabItem10;
	TToolBar *ToolBar7;
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
	TTabItem *TabItem11;
	TImageViewer *ImageViewer1;
	TLabel *Label3;
	TStyleBook *StyleBook1;
	TButton *Button10;
	TButton *Button15;
	TMainMenu *MainMenu1;
	TMenuItem *Input;
	TMenuItem *ExcelIn;
	TMenuItem *ManualIn;
	TMenuItem *CalcItem;
	TMenuItem *Output;
	TMenuItem *TablOut;
	TMenuItem *GraphOut;
	TButton *Button3;
	TSaveDialog *SaveDialog1;
	TMenuItem *Ref;
	TMenuItem *Draw;
	TButton *Button5;
	TButton *Button6;
	TTabControl *TabControl2;
	TTabItem *TabItem14;
	TTabItem *TabItem15;
	TTabItem *TabItem16;
	TTabItem *TabItem17;
	TStringGrid *StringGrid30;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TStringGrid *StringGrid31;
	TStringGrid *StringGrid32;
	TFloatColumn *FloatColumn175;
	TFloatColumn *FloatColumn176;
	TFloatColumn *FloatColumn177;
	TFloatColumn *FloatColumn178;
	TFloatColumn *FloatColumn179;
	TFloatColumn *FloatColumn180;
	TFloatColumn *FloatColumn181;
	TFloatColumn *FloatColumn182;
	TFloatColumn *FloatColumn183;
	TFloatColumn *FloatColumn184;
	TFloatColumn *FloatColumn185;
	TFloatColumn *FloatColumn186;
	TLabel *Label8;
	TEdit *Edit2;
	TFloatColumn *FloatColumn188;
	TFloatColumn *FloatColumn189;
	TFloatColumn *FloatColumn190;
	TFloatColumn *FloatColumn191;
	TFloatColumn *FloatColumn192;
	TFloatColumn *FloatColumn193;
	TFloatColumn *FloatColumn194;
	TFloatColumn *FloatColumn195;
	TFloatColumn *FloatColumn196;
	TFloatColumn *FloatColumn197;
	TFloatColumn *FloatColumn198;
	TFloatColumn *FloatColumn199;
	TFloatColumn *FloatColumn200;
	TFloatColumn *FloatColumn201;
	TFloatColumn *FloatColumn202;
	TButton *Button22;
	TPaintBox *pb;
	TPaintBox *pb1;
	TPaintBox *pb2;
	TPopupMenu *PopupMenu1;
	TMenuItem *mItem1;
	TMenuItem *mItem2;
	TMenuItem *Ñorrection;
	TLabel *Label9;
	TScrollBox *ScrollBox1;
//	void __fastcall Button1Click(TObject *Sender);
//	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
//	void __fastcall Button7Click(TObject *Sender);
//	void __fastcall Button8Click(TObject *Sender);
//	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
//	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
//	void __fastcall Button16Click(TObject *Sender);
//	void __fastcall Button17Click(TObject *Sender);
//	void __fastcall Button18Click(TObject *Sender);
	void __fastcall ExcelInClick(TObject *Sender);
	void __fastcall TablOutClick(TObject *Sender);
	void __fastcall CalcItemClick(TObject *Sender);
	void __fastcall GraphOutClick(TObject *Sender);
	void __fastcall ManualInClick(TObject *Sender);
//	void __fastcall Button4Click(TObject *Sender);
	void __fastcall RefClick(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
//	void __fastcall Button19Click(TObject *Sender);
//	void __fastcall Button20Click(TObject *Sender);
//	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall DrawClick(TObject *Sender);
	void __fastcall mItem1Click(TObject *Sender);
	void __fastcall mItem2Click(TObject *Sender);
	void __fastcall ÑorrectionClick(TObject *Sender);
	void __fastcall pb2DblClick(TObject *Sender);
	void __fastcall pb1DblClick(TObject *Sender);


private:	// User declarations
public:
	// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
void Getelem();
void Getusel();
void pNDS();
void Calc_ParametersNDS(int n);
//---------------------------------------------------------------------------
#endif
