using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Convert_1251_to_demical
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox2.Text = "{";
            char [] split = textBox1.Text.ToCharArray();
            int count = 1;
            foreach (char ch in split)
            {
                count++;
                int num = Convert.ToInt16(ch);
                if (num>=1040)
                    textBox2.Text += (Convert.ToInt16(ch)-848).ToString();
                else
                    textBox2.Text += Convert.ToInt16(ch).ToString();
                textBox2.Text += ", ";
            }
            textBox2.Text += "0};//";
            textBox2.Text += textBox1.Text;
            textBox3.Text = count.ToString();

        }
    }
}
