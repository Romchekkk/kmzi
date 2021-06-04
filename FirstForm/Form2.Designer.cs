namespace FirstForm
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBoxPlainText = new System.Windows.Forms.TextBox();
            this.textBoxAddText = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.buttonPlainText = new System.Windows.Forms.Button();
            this.buttonAddText = new System.Windows.Forms.Button();
            this.buttonStart = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBoxPlainText
            // 
            this.textBoxPlainText.Location = new System.Drawing.Point(82, 175);
            this.textBoxPlainText.Name = "textBoxPlainText";
            this.textBoxPlainText.ReadOnly = true;
            this.textBoxPlainText.Size = new System.Drawing.Size(327, 22);
            this.textBoxPlainText.TabIndex = 0;
            // 
            // textBoxAddText
            // 
            this.textBoxAddText.Location = new System.Drawing.Point(82, 263);
            this.textBoxAddText.Name = "textBoxAddText";
            this.textBoxAddText.ReadOnly = true;
            this.textBoxAddText.Size = new System.Drawing.Size(327, 22);
            this.textBoxAddText.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold);
            this.label1.Location = new System.Drawing.Point(79, 130);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(122, 23);
            this.label1.TabIndex = 2;
            this.label1.Text = "Сообщение:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold);
            this.label2.Location = new System.Drawing.Point(79, 230);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(261, 23);
            this.label2.TabIndex = 3;
            this.label2.Text = "Ассоциированные данные:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold);
            this.label3.Location = new System.Drawing.Point(79, 26);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(459, 23);
            this.label3.TabIndex = 4;
            this.label3.Text = "Князь создал очередную форму, а она ему как раз";
            // 
            // buttonPlainText
            // 
            this.buttonPlainText.Location = new System.Drawing.Point(526, 175);
            this.buttonPlainText.Name = "buttonPlainText";
            this.buttonPlainText.Size = new System.Drawing.Size(105, 29);
            this.buttonPlainText.TabIndex = 5;
            this.buttonPlainText.Text = "Обзор";
            this.buttonPlainText.UseVisualStyleBackColor = true;
            this.buttonPlainText.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // buttonAddText
            // 
            this.buttonAddText.Location = new System.Drawing.Point(526, 263);
            this.buttonAddText.Name = "buttonAddText";
            this.buttonAddText.Size = new System.Drawing.Size(105, 28);
            this.buttonAddText.TabIndex = 6;
            this.buttonAddText.Text = "Обзор";
            this.buttonAddText.UseVisualStyleBackColor = true;
            this.buttonAddText.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // buttonStart
            // 
            this.buttonStart.Location = new System.Drawing.Point(303, 361);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(168, 53);
            this.buttonStart.TabIndex = 7;
            this.buttonStart.Text = "Начать ТУРБОШИФРОВАНИЕ";
            this.buttonStart.UseVisualStyleBackColor = true;
            this.buttonStart.Click += new System.EventHandler(this.buttonStart_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Teal;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonStart);
            this.Controls.Add(this.buttonAddText);
            this.Controls.Add(this.buttonPlainText);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxAddText);
            this.Controls.Add(this.textBoxPlainText);
            this.Name = "Form2";
            this.Text = "Form2";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form2_FormClosing);
            this.Load += new System.EventHandler(this.Form2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxPlainText;
        private System.Windows.Forms.TextBox textBoxAddText;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button buttonPlainText;
        private System.Windows.Forms.Button buttonAddText;
        private System.Windows.Forms.Button buttonStart;
    }
}