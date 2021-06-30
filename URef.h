//---------------------------------------------------------------------------

#ifndef URefH
#define URefH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.TreeView.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------
class TfmRef : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tcRef;
	TTabItem *tbIn;
	TTabItem *tbOut;
	TTabItem *tbInfo;
	TTabItem *tb;
	TLabel *Label1;
	TLabel *Label2;
	TGridPanelLayout *GridPanelLayout1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TMemo *Memo1;
	TTreeView *TreeView1;
	TTreeViewItem *TreeViewItem1;
	TTreeViewItem *TreeViewItem2;
	TImage *Image1;
	TMemo *Memo2;
	TLabel *Label21;
	TTreeViewItem *TreeViewItem3;
	TImage *Image2;
	TLabel *Label22;
	TMemo *Memo3;
	TMemo *Memo4;
	TTreeViewItem *TreeViewItem4;
	TTreeViewItem *TreeViewItem5;
	TTreeViewItem *TreeViewItem6;
	TTreeViewItem *TreeViewItem7;
	TScrollBox *ScrollBox2;
	TTabItem *tbOut2;
	TTabItem *tbOut1;
	TTabItem *tb2;
	TLabel *Label23;
	TScrollBox *ScrollBox1;
	TLabel *Label24;
	TImage *Image3;
	TMemo *Memo5;
	TScrollBox *ScrollBox3;
	TLabel *Label25;
	TImage *Image4;
	TMemo *Memo6;
	void __fastcall TreeViewItem1Click(TObject *Sender);
	void __fastcall TreeViewItem2Click(TObject *Sender);
	void __fastcall TreeViewItem3Click(TObject *Sender);
	void __fastcall TreeViewItem5Click(TObject *Sender);
	void __fastcall TreeViewItem6Click(TObject *Sender);
	void __fastcall TreeViewItem7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfmRef(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmRef *fmRef;
//---------------------------------------------------------------------------
#endif
