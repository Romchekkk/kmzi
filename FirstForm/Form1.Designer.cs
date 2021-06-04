using System;
namespace FirstForm
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBoxKey = new System.Windows.Forms.TextBox();
            this.textBoxVI = new System.Windows.Forms.TextBox();
            this.textBoxAlpha = new System.Windows.Forms.TextBox();
            this.textBoxI0 = new System.Windows.Forms.TextBox();
            this.textBoxMatrix = new System.Windows.Forms.TextBox();
            this.textBoxOLK1 = new System.Windows.Forms.TextBox();
            this.textBoxOLK2 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.labelI = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.buttonKey = new System.Windows.Forms.Button();
            this.buttonIV = new System.Windows.Forms.Button();
            this.buttonAlpha = new System.Windows.Forms.Button();
            this.buttonI0 = new System.Windows.Forms.Button();
            this.buttonMatrix = new System.Windows.Forms.Button();
            this.buttonOLK1 = new System.Windows.Forms.Button();
            this.buttonOLK2 = new System.Windows.Forms.Button();
            this.Send = new System.Windows.Forms.Button();
            this.label8 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // textBoxKey
            // 
            this.textBoxKey.Location = new System.Drawing.Point(48, 53);
            this.textBoxKey.Name = "textBoxKey";
            this.textBoxKey.ReadOnly = true;
            this.textBoxKey.Size = new System.Drawing.Size(382, 22);
            this.textBoxKey.TabIndex = 0;
            this.textBoxKey.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // textBoxVI
            // 
            this.textBoxVI.Location = new System.Drawing.Point(47, 118);
            this.textBoxVI.Name = "textBoxVI";
            this.textBoxVI.ReadOnly = true;
            this.textBoxVI.Size = new System.Drawing.Size(382, 22);
            this.textBoxVI.TabIndex = 1;
            this.textBoxVI.TextChanged += new System.EventHandler(this.textBoxVI_TextChanged);
            // 
            // textBoxAlpha
            // 
            this.textBoxAlpha.Location = new System.Drawing.Point(47, 172);
            this.textBoxAlpha.Name = "textBoxAlpha";
            this.textBoxAlpha.ReadOnly = true;
            this.textBoxAlpha.Size = new System.Drawing.Size(382, 22);
            this.textBoxAlpha.TabIndex = 2;
            // 
            // textBoxI0
            // 
            this.textBoxI0.Location = new System.Drawing.Point(47, 232);
            this.textBoxI0.Name = "textBoxI0";
            this.textBoxI0.ReadOnly = true;
            this.textBoxI0.Size = new System.Drawing.Size(382, 22);
            this.textBoxI0.TabIndex = 3;
            // 
            // textBoxMatrix
            // 
            this.textBoxMatrix.Location = new System.Drawing.Point(47, 283);
            this.textBoxMatrix.Name = "textBoxMatrix";
            this.textBoxMatrix.ReadOnly = true;
            this.textBoxMatrix.Size = new System.Drawing.Size(382, 22);
            this.textBoxMatrix.TabIndex = 4;
            // 
            // textBoxOLK1
            // 
            this.textBoxOLK1.Location = new System.Drawing.Point(47, 337);
            this.textBoxOLK1.Name = "textBoxOLK1";
            this.textBoxOLK1.ReadOnly = true;
            this.textBoxOLK1.Size = new System.Drawing.Size(382, 22);
            this.textBoxOLK1.TabIndex = 5;
            // 
            // textBoxOLK2
            // 
            this.textBoxOLK2.Location = new System.Drawing.Point(47, 399);
            this.textBoxOLK2.Name = "textBoxOLK2";
            this.textBoxOLK2.ReadOnly = true;
            this.textBoxOLK2.Size = new System.Drawing.Size(382, 22);
            this.textBoxOLK2.TabIndex = 6;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(44, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(68, 23);
            this.label1.TabIndex = 7;
            this.label1.Text = "Ключ:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold);
            this.label2.Location = new System.Drawing.Point(44, 92);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(276, 23);
            this.label2.TabIndex = 8;
            this.label2.Text = "Инициализирующий вектор:";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold);
            this.label3.Location = new System.Drawing.Point(44, 146);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(75, 23);
            this.label3.TabIndex = 9;
            this.label3.Text = "Альфа:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold);
            this.label4.Location = new System.Drawing.Point(44, 204);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(28, 23);
            this.label4.TabIndex = 10;
            this.label4.Text = "i₀:";
            // 
            // labelI
            // 
            this.labelI.AutoSize = true;
            this.labelI.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold);
            this.labelI.Location = new System.Drawing.Point(44, 257);
            this.labelI.Name = "labelI";
            this.labelI.Size = new System.Drawing.Size(239, 23);
            this.labelI.TabIndex = 11;
            this.labelI.Text = "Подстановочная матрица";
            this.labelI.Click += new System.EventHandler(this.label5_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold);
            this.label6.Location = new System.Drawing.Point(44, 311);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(65, 23);
            this.label6.TabIndex = 12;
            this.label6.Text = "ОЛК1";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Times New Roman", 12F, System.Drawing.FontStyle.Bold);
            this.label7.Location = new System.Drawing.Point(44, 373);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(65, 23);
            this.label7.TabIndex = 13;
            this.label7.Text = "ОЛК2";
            // 
            // buttonKey
            // 
            this.buttonKey.Location = new System.Drawing.Point(505, 48);
            this.buttonKey.Name = "buttonKey";
            this.buttonKey.Size = new System.Drawing.Size(113, 28);
            this.buttonKey.TabIndex = 14;
            this.buttonKey.Tag = "";
            this.buttonKey.Text = "Обзор";
            this.buttonKey.UseVisualStyleBackColor = true;
            this.buttonKey.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // buttonIV
            // 
            this.buttonIV.Location = new System.Drawing.Point(505, 115);
            this.buttonIV.Name = "buttonIV";
            this.buttonIV.Size = new System.Drawing.Size(113, 28);
            this.buttonIV.TabIndex = 15;
            this.buttonIV.Text = "Обзор";
            this.buttonIV.UseVisualStyleBackColor = true;
            this.buttonIV.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // buttonAlpha
            // 
            this.buttonAlpha.Location = new System.Drawing.Point(505, 172);
            this.buttonAlpha.Name = "buttonAlpha";
            this.buttonAlpha.Size = new System.Drawing.Size(113, 28);
            this.buttonAlpha.TabIndex = 16;
            this.buttonAlpha.Text = "Обзор";
            this.buttonAlpha.UseVisualStyleBackColor = true;
            this.buttonAlpha.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // buttonI0
            // 
            this.buttonI0.Location = new System.Drawing.Point(505, 229);
            this.buttonI0.Name = "buttonI0";
            this.buttonI0.Size = new System.Drawing.Size(113, 28);
            this.buttonI0.TabIndex = 17;
            this.buttonI0.Text = "Обзор";
            this.buttonI0.UseVisualStyleBackColor = true;
            this.buttonI0.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // buttonMatrix
            // 
            this.buttonMatrix.Location = new System.Drawing.Point(505, 277);
            this.buttonMatrix.Name = "buttonMatrix";
            this.buttonMatrix.Size = new System.Drawing.Size(113, 28);
            this.buttonMatrix.TabIndex = 18;
            this.buttonMatrix.Text = "Обзор";
            this.buttonMatrix.UseVisualStyleBackColor = true;
            this.buttonMatrix.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // buttonOLK1
            // 
            this.buttonOLK1.Location = new System.Drawing.Point(505, 331);
            this.buttonOLK1.Name = "buttonOLK1";
            this.buttonOLK1.Size = new System.Drawing.Size(113, 28);
            this.buttonOLK1.TabIndex = 19;
            this.buttonOLK1.Text = "Обзор";
            this.buttonOLK1.UseVisualStyleBackColor = true;
            this.buttonOLK1.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // buttonOLK2
            // 
            this.buttonOLK2.Location = new System.Drawing.Point(505, 393);
            this.buttonOLK2.Name = "buttonOLK2";
            this.buttonOLK2.Size = new System.Drawing.Size(113, 28);
            this.buttonOLK2.TabIndex = 20;
            this.buttonOLK2.Text = "Обзор";
            this.buttonOLK2.UseVisualStyleBackColor = true;
            this.buttonOLK2.Click += new System.EventHandler(this.SelectButton_Click);
            // 
            // Send
            // 
            this.Send.Location = new System.Drawing.Point(343, 450);
            this.Send.Name = "Send";
            this.Send.Size = new System.Drawing.Size(135, 29);
            this.Send.TabIndex = 21;
            this.Send.Text = "Далее";
            this.Send.UseVisualStyleBackColor = true;
            this.Send.Click += new System.EventHandler(this.Send_Click);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label8.Font = new System.Drawing.Font("Times New Roman", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label8.Location = new System.Drawing.Point(12, 492);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(757, 34);
            this.label8.TabIndex = 22;
            this.label8.Text = "ИСПРАВЬ ЕБАНЫЙ ДИЗАЙН А ТО ЧЕ ЭТО ЗА ХУЙНЯ";
            this.label8.Click += new System.EventHandler(this.label8_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Teal;
            this.ClientSize = new System.Drawing.Size(800, 535);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.Send);
            this.Controls.Add(this.buttonOLK2);
            this.Controls.Add(this.buttonOLK1);
            this.Controls.Add(this.buttonMatrix);
            this.Controls.Add(this.buttonI0);
            this.Controls.Add(this.buttonAlpha);
            this.Controls.Add(this.buttonIV);
            this.Controls.Add(this.buttonKey);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.labelI);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxOLK2);
            this.Controls.Add(this.textBoxOLK1);
            this.Controls.Add(this.textBoxMatrix);
            this.Controls.Add(this.textBoxI0);
            this.Controls.Add(this.textBoxAlpha);
            this.Controls.Add(this.textBoxVI);
            this.Controls.Add(this.textBoxKey);
            this.Name = "Form1";
            this.Text = "Выбор параметров";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxKey;
        private System.Windows.Forms.TextBox textBoxVI;
        private System.Windows.Forms.TextBox textBoxAlpha;
        private System.Windows.Forms.TextBox textBoxI0;
        private System.Windows.Forms.TextBox textBoxMatrix;
        private System.Windows.Forms.TextBox textBoxOLK1;
        private System.Windows.Forms.TextBox textBoxOLK2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label labelI;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button buttonKey;
        private System.Windows.Forms.Button buttonIV;
        private System.Windows.Forms.Button buttonAlpha;
        private System.Windows.Forms.Button buttonI0;
        private System.Windows.Forms.Button buttonMatrix;
        private System.Windows.Forms.Button buttonOLK1;
        private System.Windows.Forms.Button buttonOLK2;
        private System.Windows.Forms.Button Send;
        private System.Windows.Forms.Label label8;
    }
}

