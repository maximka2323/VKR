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
	TStringGrid *StringGrid1;
	TFloatColumn *FloatColumn1;
	TFloatColumn *FloatColumn2;
	TFloatColumn *FloatColumn3;
	TFloatColumn *FloatColumn4;
	TFloatColumn *FloatColumn5;
	TFloatColumn *FloatColumn6;
	TStringGrid *StringGrid2;
	TFloatColumn *FloatColumn7;
	TFloatColumn *FloatColumn8;
	TFloatColumn *FloatColumn9;
	TFloatColumn *FloatColumn10;
	TFloatColumn *FloatColumn11;
	TFloatColumn *FloatColumn12;
	TStringGrid *StringGrid3;
	TFloatColumn *FloatColumn13;
	TFloatColumn *FloatColumn14;
	TFloatColumn *FloatColumn15;
	TFloatColumn *FloatColumn16;
	TFloatColumn *FloatColumn17;
	TFloatColumn *FloatColumn18;
	TButton *Button1;
	TButton *Button2;
	TGridPanelLayout *GridPanelLayout1;
	TGridPanelLayout *GridPanelLayout2;
	TTabControl *TabControl1;
	TTabItem *TabItem1;
	TTabItem *TabItem2;
	TToolBar *ToolBar1;
	TGridPanelLayout *GridPanelLayout3;
	TStringGrid *StringGrid4;
	TFloatColumn *FloatColumn19;
	TFloatColumn *FloatColumn20;
	TStringGrid *StringGrid5;
	TFloatColumn *FloatColumn21;
	TFloatColumn *FloatColumn22;
	TStringGrid *StringGrid6;
	TFloatColumn *FloatColumn23;
	TFloatColumn *FloatColumn24;
	TFloatColumn *FloatColumn25;
	TFloatColumn *FloatColumn26;
	TFloatColumn *FloatColumn27;
	TFloatColumn *FloatColumn28;
	TFloatColumn *FloatColumn29;
	TFloatColumn *FloatColumn30;
	TFloatColumn *FloatColumn31;
	TFloatColumn *FloatColumn32;
	TFloatColumn *FloatColumn33;
	TFloatColumn *FloatColumn34;
	TFloatColumn *FloatColumn35;
	TFloatColumn *FloatColumn36;
	TFloatColumn *FloatColumn37;
	TFloatColumn *FloatColumn38;
	TFloatColumn *FloatColumn39;
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
	TEdit *Edit1;
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
	TTabItem *TabItem8;
	TToolBar *ToolBar5;
	TGridPanelLayout *GridPanelLayout7;
	TStringGrid *StringGrid21;
	TFloatColumn *FloatColumn76;
	TFloatColumn *FloatColumn77;
	TFloatColumn *FloatColumn78;
	TFloatColumn *FloatColumn82;
	TFloatColumn *FloatColumn83;
	TFloatColumn *FloatColumn84;
	TStringGrid *StringGrid22;
	TFloatColumn *FloatColumn88;
	TFloatColumn *FloatColumn89;
	TFloatColumn *FloatColumn90;
	TFloatColumn *FloatColumn94;
	TFloatColumn *FloatColumn95;
	TFloatColumn *FloatColumn96;
	TStringGrid *StringGrid23;
	TFloatColumn *FloatColumn128;
	TFloatColumn *FloatColumn129;
	TFloatColumn *FloatColumn130;
	TFloatColumn *FloatColumn131;
	TFloatColumn *FloatColumn132;
	TFloatColumn *FloatColumn133;
	TStringGrid *StringGrid24;
	TFloatColumn *FloatColumn134;
	TFloatColumn *FloatColumn135;
	TFloatColumn *FloatColumn136;
	TFloatColumn *FloatColumn137;
	TFloatColumn *FloatColumn138;
	TFloatColumn *FloatColumn139;
	TTabItem *TabItem9;
	TToolBar *ToolBar6;
	TGridPanelLayout *GridPanelLayout8;
	TStringGrid *StringGrid25;
	TFloatColumn *FloatColumn140;
	TFloatColumn *FloatColumn141;
	TFloatColumn *FloatColumn142;
	TFloatColumn *FloatColumn143;
	TFloatColumn *FloatColumn144;
	TFloatColumn *FloatColumn145;
	TStringGrid *StringGrid26;
	TFloatColumn *FloatColumn146;
	TFloatColumn *FloatColumn147;
	TFloatColumn *FloatColumn148;
	TFloatColumn *FloatColumn149;
	TFloatColumn *FloatColumn150;
	TFloatColumn *FloatColumn151;
	TStringGrid *StringGrid27;
	TFloatColumn *FloatColumn152;
	TFloatColumn *FloatColumn153;
	TFloatColumn *FloatColumn154;
	TFloatColumn *FloatColumn155;
	TFloatColumn *FloatColumn156;
	TFloatColumn *FloatColumn157;
	TStringGrid *StringGrid28;
	TFloatColumn *FloatColumn158;
	TFloatColumn *FloatColumn159;
	TFloatColumn *FloatColumn160;
	TFloatColumn *FloatColumn161;
	TFloatColumn *FloatColumn162;
	TFloatColumn *FloatColumn163;
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
	TButton *Button11;
	TButton *Button12;
	TTabItem *TabItem12;
	TToolBar *ToolBar8;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TChart *Chart1;
	TLineSeries *Series1;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TTabItem *TabItem13;
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
	TButton *Button4;
	TImage *Image2;
	TChart *Chart3;
	TLineSeries *Series3;
	TChart *Chart2;
	TLineSeries *Series2;
	TMenuItem *Ref;
	TMenuItem *Draw;
	TFloatColumn *FloatColumn173;
	TFloatColumn *FloatColumn174;
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
	TButton *Button7;
	TButton *Button8;
	TButton *Button19;
	TButton *Button20;
	TChart *Chart4;
	TLineSeries *LineSeries1;
	TChart *Chart5;
	TLineSeries *LineSeries2;
	TChart *Chart6;
	TLineSeries *LineSeries3;
	TChart *Chart7;
	TLineSeries *LineSeries4;
	TLineSeries *Series4;
	TLabel *Label8;
	TEdit *Edit2;
	TStringGrid *StringGrid33;
	TFloatColumn *FloatColumn187;
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
//	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
//	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall ExcelInClick(TObject *Sender);
	void __fastcall TablOutClick(TObject *Sender);
	void __fastcall CalcItemClick(TObject *Sender);
	void __fastcall GraphOutClick(TObject *Sender);
	void __fastcall ManualInClick(TObject *Sender);
//	void __fastcall Button4Click(TObject *Sender);
	void __fastcall RefClick(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Button20Click(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall DrawClick(TObject *Sender);


private:	// User declarations
public:
	// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
