using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Security;

namespace FirstForm
{
    public partial class Form2 : Form
    {
        public Form2(Dictionary<string, string> paramFromForm1)
        {
            parameters = paramFromForm1;
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        public void Form2_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult dialog = MessageBox.Show(
                "Вы действительно хотите выйти из программы?",
                "Завершение программы",
                MessageBoxButtons.YesNo,
                MessageBoxIcon.Warning
            );
            if (dialog == DialogResult.Yes)
            {
                e.Cancel = false;
                Application.Exit();
            }
            else
            {
                e.Cancel = true;
            }
        }


        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void buttonPlainText_Click(object sender, EventArgs e)
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
                    if (name == "buttonPlainText")
                        textBoxPlainText.Text = (filePath);
                    if (name == "buttonAddText")
                        textBoxAddText.Text = (filePath);
                }
                catch (SecurityException ex)
                {
                    MessageBox.Show($"Security error.\n\nError message: {ex.Message}\n\n" +
                    $"Details:\n\n{ex.StackTrace}");
                }
            }
        }

        private void buttonStart_Click(object sender, EventArgs e)
        {
            TextBox[] tbArr = { textBoxPlainText, textBoxAddText };
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

            string sosi = "Ты насобирал вот такой хуйни:\n";          
            for (int i = 0; i < parameters.Count; ++i)
            {
                sosi += parameters.Keys.ElementAt(i) + " -> " + parameters.Values.ElementAt(i) + "\n";
            }
            MessageBox.Show(sosi);
        }

        Dictionary<string, string> parameters = new Dictionary<string, string>();
    }
}
