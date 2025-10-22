#include <Vcl.Imaging.pngimage.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Card.h"
#include "Deck.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Deck deck; // Declare deck object here

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
		: TForm(Owner)
{
		deck.Shuffle(); // Shuffle the deck when the form is created
}

void __fastcall TForm1::PanelStartClick(TObject *Sender)
{
		PanelStand->Visible = true;
		PanelHit->Visible = true;
		PanelStart->Visible= false;

        deck.giveCardP();
		displayCard(deck.PlayerHand().back(), Pcarte1);
        deck.giveCardD();
	displayCard(deck.DealerHand().back(), Dcarte1);
        deck.giveCardP();
	displayCard(deck.PlayerHand().back(), Pcarte2);
        deck.giveCardD();
	displayCard(deck.DealerHand().back(), Dcarte2);
}

void TForm1::displayCard(Card card, TImage* image)
{
	String filePath = card.getSymbol() + "_of_" + card.getSuit() + ".png";

    if (FileExists(filePath)) {
        try {
            image->Picture->LoadFromFile(filePath);
        } catch (Exception &e) {
            ShowMessage("Error loading image: " + e.Message); //Handle exceptions
        }
    } else {
        ShowMessage("File not found: " + filePath);
    }
}

void __fastcall TForm1::PanelHitClick(TObject *Sender)
{
        deck.giveCardP();
    if(deck.PlayerHand().size()==3)
        displayCard(deck.PlayerHand().back(), Pcarte3);
	if(deck.PlayerHand().size()==4)
        displayCard(deck.PlayerHand().back(), Pcarte4);
    if(deck.PlayerHand().size()==5)
        displayCard(deck.PlayerHand().back(), Pcarte5);
	if(deck.PlayerHand().size()>5)
        ShowMessage("You can't have more than 5 cards");
}

void __fastcall TForm1::PanelStandClick(TObject *Sender)
{
        while(deck.ScoreD()<17){ //Dealer hits until 17 or more
                deck.giveCardD();
        if(deck.DealerHand().size()==3)
        displayCard(deck.DealerHand().back(), Dcarte3);
        if(deck.DealerHand().size()==4)
        displayCard(deck.DealerHand().back(), Dcarte4);
        if(deck.DealerHand().size()==5)
        displayCard(deck.DealerHand().back(), Dcarte5);
        }

		String message;
        if(deck.ScoreP()>21)
                message = "Player's Score: "+ IntToStr(deck.ScoreP())+ " - Dealer's Score: " +IntToStr(deck.ScoreD())+ " -> Player Busts! Dealer Wins!";
        else if(deck.ScoreD()>21)
                message = "Player's Score: "+ IntToStr(deck.ScoreP())+ " - Dealer's Score: " +IntToStr(deck.ScoreD())+ " -> Dealer Busts! Player Wins!";
        else if(deck.ScoreP()>deck.ScoreD())
                message = "Player's Score: "+ IntToStr(deck.ScoreP())+ " - Dealer's Score: " +IntToStr(deck.ScoreD())+ " -> Player Wins!";
        else if(deck.ScoreP()<deck.ScoreD())
                message = "Player's Score: "+ IntToStr(deck.ScoreP())+ " - Dealer's Score: " +IntToStr(deck.ScoreD())+ " -> Dealer Wins!";
        else
                message = "Player's Score: "+ IntToStr(deck.ScoreP())+ " - Dealer's Score: " +IntToStr(deck.ScoreD())+ " -> Draw";

    ShowMessage(message);
}//---------------------------------------------------------------------------
