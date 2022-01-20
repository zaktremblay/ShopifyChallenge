//---------------------------------------------------------------------------
#include <iostream>
#include <fmx.h>
#pragma hdrstop

#include "ShopifyChallenge.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

//Submission by Zachary Tremblay
//The choice of c++ here is to showcase the use of a very powerful programming language
//This particular builder offered a simple GUI to display functions and lists
//The option chosen was the features of deletion comments and undeletion


TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner) //  this part of the code allows the program to create a seperate window that will be the parent to other displays.
{
}

//---------------------------------------------------------------------------
void __fastcall TForm1::AddButtonClick(TObject *Sender) //OnClick event for the "AddButton".
{
	String itemName = AddItemBox->Text; //Store text inside the "AddButton"
	if (itemName!="") {
		ItemListBox->Items->Add(itemName); //Prevents user from adding empty items. Adds Items to the listbox
	}

	AddItemBox->Text="";//Sets the textbox with the item name back to empty
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ItemListBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item) //onitemclick event for the item list box

{

	CommentsListBox->Items->Add(CommentTextBox->Text); //add comment to the comment list box
	DeletedFilesListBox->Items->Add(Item->Text);  //add deleted files to the deleted files list box for future undeletion

	int index = Item->Index; //store index of item to be deleted
	ItemListBox->Items->Delete(index);  //delete item from item list box
	CommentTextBox->Text=""; //set the comment text box to empty
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeletedFilesListBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)  //onitemclick event for the deleted files box

{
	ItemListBox->Items->Add(Item->Text); //Add previously deleted item back to the item list box
	int index = Item->Index;
	CommentsListBox->Items->Delete(index);  //Remove the associated comment of the deleted file
	DeletedFilesListBox->Items->Delete(index); //Remove the undeleted file from the deleted files listbox
}
//---------------------------------------------------------------------------

