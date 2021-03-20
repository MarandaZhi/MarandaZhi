using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.WebSockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using WebSocketSharp;

namespace WpfApp1
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {

        public WebSocketSharp.WebSocket webSocket;
        public  MainWindow  ()
        {
            InitializeComponent();
            this.Topmost = true;
            //someMethod();

            webSocket = new WebSocketSharp.WebSocket("ws://39.108.65.86:8108");
            webSocket.Connect();

            var ws = new WebSocketSharp.WebSocket("ws://39.108.65.86:8109");
            ws.OnMessage += (s, e) => {

                Console.WriteLine(e.Data);
                if (e.Data == "Click") {


                    this.Dispatcher.Invoke(() =>
                    {
                        new Window1().Show();
                    });

                   
                }


            };

            ws.Connect();

        }

        private void Name1_Click(object sender, RoutedEventArgs e)
        {
            webSocket.Send("Click");

            
          
        }
    }
}
