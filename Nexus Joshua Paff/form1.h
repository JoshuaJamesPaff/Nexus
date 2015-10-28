#pragma once
#include "Drawer.h"
#include "Engine.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
Engine newGame;

using namespace System;
using namespace System::IO;
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace NexusJoshuaPaff {

	
	public ref class form1 : public System::Windows::Forms::Form
	{
	public:
		form1(void)
		{
			InitializeComponent();

			
		}

	protected:
		
		~form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBoxBoard;
	private: System::Windows::Forms::Button^  buttonStart;

	private: System::Windows::Forms::Label^  labelScore;
	private: System::Windows::Forms::Label^  labelText;
	private: System::Windows::Forms::Label^  labelHigh;
	private: System::Windows::Forms::Label^  labelHighScore;

	private: System::ComponentModel::IContainer^  components;
	protected: 

	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBoxBoard = (gcnew System::Windows::Forms::PictureBox());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->labelScore = (gcnew System::Windows::Forms::Label());
			this->labelText = (gcnew System::Windows::Forms::Label());
			this->labelHigh = (gcnew System::Windows::Forms::Label());
			this->labelHighScore = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxBoard))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxBoard
			// 
			this->pictureBoxBoard->Location = System::Drawing::Point(14, 43);
			this->pictureBoxBoard->Name = L"pictureBoxBoard";
			this->pictureBoxBoard->Size = System::Drawing::Size(400, 400);
			this->pictureBoxBoard->TabIndex = 0;
			this->pictureBoxBoard->TabStop = false;
			this->pictureBoxBoard->Click += gcnew System::EventHandler(this, &form1::pictureBoxBoard_Click);
			this->pictureBoxBoard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &form1::pictureBoxBoard_Paint);
			// 
			// buttonStart
			// 
			this->buttonStart->Location = System::Drawing::Point(97, 584);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(75, 23);
			this->buttonStart->TabIndex = 1;
			this->buttonStart->Text = L"Start Game";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &form1::buttonStart_Click);
			// 
			// labelScore
			// 
			this->labelScore->AutoSize = true;
			this->labelScore->Location = System::Drawing::Point(508, 589);
			this->labelScore->Name = L"labelScore";
			this->labelScore->Size = System::Drawing::Size(13, 13);
			this->labelScore->TabIndex = 2;
			this->labelScore->Text = L"0";
			// 
			// labelText
			// 
			this->labelText->AutoSize = true;
			this->labelText->Location = System::Drawing::Point(443, 589);
			this->labelText->Name = L"labelText";
			this->labelText->Size = System::Drawing::Size(35, 13);
			this->labelText->TabIndex = 3;
			this->labelText->Text = L"Score";
			// 
			// labelHigh
			// 
			this->labelHigh->AutoSize = true;
			this->labelHigh->Location = System::Drawing::Point(418, 554);
			this->labelHigh->Name = L"labelHigh";
			this->labelHigh->Size = System::Drawing::Size(60, 13);
			this->labelHigh->TabIndex = 5;
			this->labelHigh->Text = L"High Score";
			// 
			// labelHighScore
			// 
			this->labelHighScore->AutoSize = true;
			this->labelHighScore->Location = System::Drawing::Point(508, 554);
			this->labelHighScore->Name = L"labelHighScore";
			this->labelHighScore->Size = System::Drawing::Size(13, 13);
			this->labelHighScore->TabIndex = 4;
			this->labelHighScore->Text = L"0";
			// 
			// form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(627, 619);
			this->Controls->Add(this->labelHigh);
			this->Controls->Add(this->labelHighScore);
			this->Controls->Add(this->labelText);
			this->Controls->Add(this->labelScore);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->pictureBoxBoard);
			this->Name = L"form1";
			this->Text = L"Nexus 2k15";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxBoard))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//what happens when the player clicks the board
		private: System::Void pictureBoxBoard_Click(System::Object^  sender, System::EventArgs^  e) {
			
			if((newGame.gameStart() == true) ){
				
				String^ scoreBoard;
				int totalScore;

				Drawer::init(pictureBoxBoard->CreateGraphics());
				
				//parse click coordinates to game engine
				int y = ((MouseEventArgs^)e)->X / BLOCK_SIZE;
				int x = ((MouseEventArgs^)e)->Y / BLOCK_SIZE;

				//checks if cell is free
				
				
				newGame.selectCell(x, y);
				
				newGame.draw();
				pictureBoxBoard->Invalidate();		

			//Scoring system with Live updating and High scores saving
				scoreBoard = labelScore->Text;
				totalScore = int::Parse(scoreBoard);
				
				//scoring to encourage bigger plays
				totalScore += (newGame.getScore() * (newGame.getScore()));
				labelScore->Text = (totalScore +"");

				String^ fileName = "highscore.txt";
				StreamReader^ sr = gcnew StreamReader(fileName);
				
				String^ old = sr->ReadLine();
				labelHighScore->Text = old;
				
				int oldHigh = int::Parse(old); 

				sr->Close();

				if(oldHigh < totalScore)
				{
					StreamWriter^ sw = gcnew StreamWriter(fileName);
					System::String^ str = totalScore.ToString();
					sw->Write(str);
					labelHighScore->Text = str;
					sw->Close();
				}
				//updates scoreboard
				scoreBoard = totalScore.ToString();
				labelScore->Text = scoreBoard;
			}
				 }

	private: System::Void pictureBoxBoard_Paint(Object^ sender, PaintEventArgs^ e) {

				Drawer::init(e->Graphics);
				newGame.draw();
				}	


			 //starts game and resets counters
		private: System::Void buttonStart_Click(System::Object^  sender, System::EventArgs^  e) {
					 Drawer::init(pictureBoxBoard->CreateGraphics());
					 newGame.start();
					 newGame.randCell();
					 newGame.draw();
					 labelScore->Text = "0";
					 }
	};
}

 