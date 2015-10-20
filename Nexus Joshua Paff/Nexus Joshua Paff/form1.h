#pragma once
#include "Drawer.h"
#include "Engine.h"



Engine newGame;

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
			//paint and click handler for board
			this->pictureBoxBoard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &form1::pictureBoxBoard_Paint);
			this->pictureBoxBoard->Click += gcnew System::EventHandler(this, &form1::pictureBoxBoard_Click);
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
			this->labelScore->Location = System::Drawing::Point(495, 589);
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
			// form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(627, 619);
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

		private: System::Void pictureBoxBoard_Click(System::Object^  sender, System::EventArgs^  e) {
				
				Drawer::init(pictureBoxBoard->CreateGraphics());

				//parse click coordinates to game engine
				int y = ((MouseEventArgs^)e)->X / BLOCK_SIZE;
				int x = ((MouseEventArgs^)e)->Y / BLOCK_SIZE;
				newGame.changeCell(x, y, 4);
				newGame.draw();
				pictureBoxBoard->Invalidate();
				labelText->Text = L"Scor7777";
			 }

	private: System::Void pictureBoxBoard_Paint(Object^ sender, PaintEventArgs^ e) {

				Drawer::init(e->Graphics);
				newGame.draw();
				}
				

		private: System::Void buttonStart_Click(System::Object^  sender, System::EventArgs^  e) {

					 Drawer::init(pictureBoxBoard->CreateGraphics());
					 newGame.draw();
					 
				 }
	};
}

 