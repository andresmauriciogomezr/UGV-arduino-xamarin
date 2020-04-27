﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using carcontrol.Helpers;

namespace carcontrol
{
    [Activity(Label = "CanvasActivity", MainLauncher = false)]
    public class CanvasActivity : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Create your application here
            SetContentView(new CustomCanvas(this));
        }
    }
}