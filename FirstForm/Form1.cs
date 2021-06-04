using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Security;

namespace FirstForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {
           
        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }


        private OpenFileDialog openFileDialog1 = new OpenFileDialog();

        private void SelectButton_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {

                    var filePath = openFileDialog1.FileName;
                    //var sr = new StreamReader(openFileDialog1.FileName);
                    string name = ((Button)sender).Name;
                    if (name == "buttonKey")
                        textBoxKey.Text = (filePath);
                    if (name == "buttonIV")
                        textBoxVI.Text = (filePath);
                    if (name == "buttonAlpha")
                        textBoxAlpha.Text = (filePath);
                    if (name == "buttonI0")
                        textBoxI0.Text = (filePath);
                    if (name == "buttonMatrix")
                        textBoxMatrix.Text = (filePath);
                    if (name == "buttonOLK1")
                        textBoxOLK1.Text = (filePath);
                    if (name == "buttonOLK2")
                        textBoxOLK2.Text = (filePath);
                }
                catch (SecurityException ex)
                {
                    MessageBox.Show($"Security error.\n\nError message: {ex.Message}\n\n" +
                    $"Details:\n\n{ex.StackTrace}");
                }
            }
        }

        private void Form1_Load_1(object sender, EventArgs e)
        {

        }

        private void Send_Click(object sender, EventArgs e)
        {
            TextBox[] tbArr = { textBoxKey, textBoxVI, textBoxAlpha, textBoxI0, textBoxMatrix, textBoxOLK1, textBoxOLK2 };
            for (int i = 0; i < tbArr.Length; ++i)
            {
                if (tbArr[i].Text == "" || tbArr[i].Text == "Заполните это поле!")
                {
                    tbArr[i].Text = "Заполните это поле!";
                    return;
                }
                if (parameters.ContainsKey(tbArr[i].Name))
                {
                    parameters[tbArr[i].Name] = tbArr[i].Text;
                }
                else
                {
                    parameters.Add(tbArr[i].Name, tbArr[i].Text);
                }
               
            }
            //создание новой формы
            Form2 newForm = new Form2(parameters);
            this.Hide();
            newForm.Show();
        }

        private void label8_Click(object sender, EventArgs e)
        {
            
        }

        Dictionary<string, string> parameters = new Dictionary<string, string>();

        private void textBoxVI_TextChanged(object sender, EventArgs e)
        {

        }
    }

}

