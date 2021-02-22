using System;
using Android.App;
using Android.OS;
using Android.Runtime;
using Android.Support.Design.Widget;
using Android.Support.V7.App;
using Android.Views;
using Android.Widget;
using carcontrol.Helpers;

namespace carcontrol
{
    [Activity(Label = "@string/app_name", Theme = "@style/AppTheme", MainLauncher = true)]
    public class MainActivity : AppCompatActivity, BottomNavigationView.IOnNavigationItemSelectedListener
    {
        TextView textMessage;
        BottomNavigationView navigation;

        BluetoothHelper bluettoth;

        Button up_button;
        Button right_button;
        Button down_button;
        Button left_button;

        Button connect_button;
        Button disconnect_button;

        bool isBluetoothConnected = false;

        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            SetContentView(Resource.Layout.activity_main);

            this.bluettoth = new BluetoothHelper(this);

            this.FindViews();
            this.SetInitial();
            this.HandleEvents();

        }

        private void HandleEvents()
        {
            this.connect_button.Click += ConnectButton_click;
            this.disconnect_button.Click += DisconnectButton_click;

            this.up_button.Click += Up_button_click;
            this.right_button.Click += Right_button_click;
            this.left_button.Click += Left_button_click;
            this.down_button.Click += Down_button_click;

        }

        private void Right_button_click(object sender, EventArgs e)
        {
            Java.Lang.String dataToSend = new Java.Lang.String("r\n");// up
            this.bluettoth.SendData(dataToSend);// UP
        }

        private void Left_button_click(object sender, EventArgs e)
        {
            Java.Lang.String dataToSend = new Java.Lang.String("l\n");// up
            this.bluettoth.SendData(dataToSend);// UP
        }

        private void Up_button_click(object sender, EventArgs e)
        {
            Java.Lang.String dataToSend = new Java.Lang.String("u\n");// up
            this.bluettoth.SendData(dataToSend);// UP
        }

        private void Down_button_click(object sender, EventArgs e)
        {
            Java.Lang.String dataToSend = new Java.Lang.String("d\n");// up
            this.bluettoth.SendData(dataToSend);// UP
        }

        private void DisconnectButton_click(object sender, EventArgs e)
        {
            this.bluettoth.CloseBluetooth();
            this.disconnect_button.Visibility = ViewStates.Gone;
            this.connect_button.Visibility = ViewStates.Visible;
        }

        private void ConnectButton_click(object sender, EventArgs e)
        {
            this.isBluetoothConnected = this.bluettoth.Connect();
            if (this.isBluetoothConnected)
            {
                this.disconnect_button.Visibility = ViewStates.Visible;
                this.connect_button.Visibility = ViewStates.Gone;
            }
        }

        private void SetInitial()
        {
            this.navigation.SetOnNavigationItemSelectedListener(this);
        }

        private void FindViews()
        {
            this.textMessage = FindViewById<TextView>(Resource.Id.message);
            this.navigation = FindViewById<BottomNavigationView>(Resource.Id.navigation);

            this.up_button = FindViewById<Button>(Resource.Id.up_button);
            this.right_button = FindViewById<Button>(Resource.Id.right_button);
            this.down_button = FindViewById<Button>(Resource.Id.down_button);
            this.left_button = FindViewById<Button>(Resource.Id.left_button);

            this.connect_button = FindViewById<Button>(Resource.Id.connect_button);
            this.disconnect_button = FindViewById<Button>(Resource.Id.disconnect_button);

        }

        public bool OnNavigationItemSelected(IMenuItem item)
        {
            switch (item.ItemId)
            {
                case Resource.Id.navigation_home:
                    textMessage.SetText(Resource.String.title_home);
                    return true;
                case Resource.Id.navigation_dashboard:
                    textMessage.SetText(Resource.String.title_dashboard);
                    return true;
                case Resource.Id.navigation_notifications:
                    textMessage.SetText(Resource.String.title_notifications);
                    return true;
            }
            return false;
        }
    }
}

