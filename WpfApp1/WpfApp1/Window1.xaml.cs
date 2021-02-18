using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// Window1.xaml 的交互逻辑
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();

            Random rdm = new Random();
            int Width = rdm.Next(200, 1000);
            int Height = rdm.Next(200, 1000);
            int Left = rdm.Next(0, 900);
            int Top = rdm.Next(0,600);
            Console.WriteLine(string.Format("Width:{0},Height:{1},Left:{2},Top:{3}", Width, Height, Left, Top));
            this.Width = Width;
            this.Height = Height;
            this.Left = Left;
            this.Top = Top;
            Image1.Source = new BitmapImage(new Uri("G" + rdm.Next(1, 5) + ".png", UriKind.RelativeOrAbsolute));
            someMethod();
        }

        private async void someMethod()
        {

            for (int i = 10; i >= 0; i--)
            {

                //  Console.WriteLine((float)i / 10);

                Image1.Opacity = (float)i / 10;
                await Task.Delay(300);
            }
            this.Close();
        }
    }
}
