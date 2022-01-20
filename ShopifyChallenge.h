//---------------------------------------------------------------------------

#ifndef ShopifyChallengeH
#define ShopifyChallengeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <iostream>
#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *AddItemBox;
	TListBox *ItemListBox;
	TLabel *Label3;
	TEdit *CommentTextBox;
	TButton *AddButton;
	TListBox *DeletedFilesListBox;
	TLabel *Label4;
	TListBox *CommentsListBox;
	TLabel *Comments;
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall ItemListBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall DeletedFilesListBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
